import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('START53_V4::All')
process.load("Configuration.StandardSequences.MagneticField_cff")

process.load('Configuration.StandardSequences.Reconstruction_cff')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)

#        'file:/afs/cern.ch/user/p/peruzzi/work/SinglePhoton_600pre4.root'

options = VarParsing.VarParsing ('standard') # set 'standard'  options
options.parseArguments()

process.source = cms.Source("PoolSource",
                            # replace 'myfile.root' with the source file you want to use
                            fileNames = cms.untracked.vstring(options.files)
                            )

process.demo = cms.EDAnalyzer("PhotonPUAnalyzer",
                              photonsProducer = cms.InputTag("photons"),
                              genParticlesProducer = cms.InputTag("genParticles"),
                              doMC = cms.bool(True),
                              doElectrons = cms.bool(True),
                              electronsProducer = cms.InputTag("gsfElectrons"),
                              reducedBarrelEcalRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
                              reducedEndcapEcalRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
                              OutputFile = cms.string("outfile.root")
                              )

process.p = cms.Path(process.demo)
