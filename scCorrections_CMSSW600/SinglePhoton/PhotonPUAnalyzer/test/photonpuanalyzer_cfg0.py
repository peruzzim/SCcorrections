import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('START53_V7A::All')
process.load("Configuration.StandardSequences.MagneticField_cff")

from SinglePhoton.PhotonPUAnalyzer.listarerecostrategy_cfi import *

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = lista_pu0
)

process.demo = cms.EDAnalyzer("PhotonPUAnalyzer",
                              genParticlesProducer = cms.InputTag("genParticles"),
                              doMC = cms.bool(True),
                              reducedBarrelEcalRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
                              reducedEndcapEcalRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
                              OutputFile = cms.string("outfile_pu0.root"),
                              srcRho = cms.InputTag('kt6PFJets','rho'),
                              srcSigma = cms.InputTag('kt6PFJets','sigma'),
                              vertexProducer = cms.InputTag('offlinePrimaryVerticesWithBS'),
#                              SCProducer = cms.InputTag('particleFlowSuperClusterECAL:particleFlowSuperClusterECAL')
                              photonsProducer = cms.InputTag("photons")
                              )



process.p = cms.Path(process.demo)
