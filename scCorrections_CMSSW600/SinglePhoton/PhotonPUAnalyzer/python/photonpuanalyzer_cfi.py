import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer("PhotonPUAnalyzer",
                      photonsProducer = cms.untracked.InputTag("photons"),
                      genParticlesProducer = cms.untracked.InputTag("genParticles"),
                      doMC = cms.untracked.bool(True),
                      doElectrons = cms.untracked.bool(False),
                      electronsProducer = cms.untracked.InputTag("gsfElectrons"),
                      reducedBarrelEcalRecHitCollection = cms.untracked.InputTag("reducedEcalRecHitsEB"),
                      reducedEndcapEcalRecHitCollection = cms.untracked.InputTag("reducedEcalRecHitsEE"),
                      OutputFile = cms.untracked.string("outfile.root")
                      )
