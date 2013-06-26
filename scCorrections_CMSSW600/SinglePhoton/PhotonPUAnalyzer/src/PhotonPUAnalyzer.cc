// -*- C++ -*-
//
// Package:    PhotonPUAnalyzer
// Class:      PhotonPUAnalyzer
// 
/**\class PhotonPUAnalyzer PhotonPUAnalyzer.cc Analysis/PhotonPUAnalyzer/src/PhotonPUAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Nicolas Pierre Chanon,32 2-C13,+41227674539,
//         Created:  Tue Mar  8 12:23:45 CET 2011
// $Id: PhotonPUAnalyzer.cc,v 1.4 2012/09/21 10:37:34 peruzzi Exp $
//
//

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"

#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
//#include "Geometry/CaloTopology/interface/CaloTopology.h"
//#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
//#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
//#include "RecoEcal/EgammaCoreTools/interface/PositionCalc.h"

#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

//ParticleFlowReco/interface/PFCluster.h
#include "DataFormats/ParticleFlowReco/interface/PFBlock.h"
#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFBlockElement.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "RecoParticleFlow/PFClusterTools/interface/ClusterClusterMapping.h"
#include "CommonTools/ParticleFlow/plugins/PFPileUp.h"
#include "DataFormats/ParticleFlowCandidate/interface/PileUpPFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PileUpPFCandidateFwd.h"

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
//#include "applyScCorrections_PHOTON.C"

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterFunctionBaseClass.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterFunctionFactory.h"

#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFwd.h"
#include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalEndcapGeometry.h"


//#include "fLocalCorr.h"

#include "CondFormats/EcalObjects/interface/EcalClusterLocalContCorrParameters.h"
#include "CondFormats/DataRecord/interface/EcalClusterLocalContCorrParametersRcd.h"
#include "CondFormats/EcalObjects/interface/EcalClusterCrackCorrParameters.h"
#include "CondFormats/DataRecord/interface/EcalClusterCrackCorrParametersRcd.h"

//#include "RecoEcal/EgammaCoreTools/plugins/EcalClusterEnergyCorrectionObjectSpecificBaseClass.h"

#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/GeometryVector/interface/GlobalVector.h"
#include "DataFormats/Common/interface/AssociationVector.h"


#include <Math/VectorUtil.h>

#include "TLorentzVector.h"
#include "TVector.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TH1F.h"
#include "TH1I.h"
//#include "TBranch.h"

//
// class declaration
//


using namespace ROOT::Math::VectorUtil;
typedef math::XYZTLorentzVector LorentzVector;
typedef math::XYZPoint Point;
typedef math::XYZVector Vector;


using namespace std;

class PhotonPUAnalyzer : public edm::EDAnalyzer {
   public:
  explicit PhotonPUAnalyzer(const edm::ParameterSet&);
      ~PhotonPUAnalyzer();


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;


  double DeltaR(double phi1, double phi2, double eta1, double eta2);
  double DeltaPhi(double phi1, double phi2);

  bool isInPhiCracks(double phi, double eta);
  bool isInEtaCracks(double eta);

  double f5x5(double iEta);

  typedef std::pair<float,int> OrderPair;
  struct IndexByPt {
    const bool operator()(const OrderPair& j1, const OrderPair& j2 ) const {
      return j1.first > j2.first;
    }
  };

  IndexByPt indexComparator;

  TH1F *GenParticles_Phi;
  TH1F *RecoParticles_Phi;
  TH1I *n_RecoParticles;

  //  edm::ESHandle<CaloTopology> theCaloTopo_;
  edm::ESHandle<CaloGeometry> theCaloGeom_;

  edm::InputTag srcRho_;
  edm::InputTag srcSigma_;  
  edm::InputTag srcRhoPhotons_;
  edm::InputTag srcSigmaPhotons_;
  edm::InputTag srcRhoChargedHadrons_;
  edm::InputTag srcSigmaChargedHadrons_;
  edm::InputTag srcRhoNeutralHadrons_;
  edm::InputTag srcSigmaNeutralHadrons_;
  
  edm::InputTag HepMCPileUp_;
  edm::InputTag vertexProducer_;
  edm::InputTag alternativeVertexProducer_;
  edm::InputTag photonsProducer_;
  edm::InputTag pfphotonsProducer_;
  edm::InputTag SCProducer_;
  edm::InputTag jetsProducer_;
  edm::InputTag jetsProducerPhotons_;
  edm::InputTag jetsProducerChargedHadrons_;
  edm::InputTag jetsProducerNeutralHadrons_;
  edm::InputTag pfProducer_;
  edm::InputTag genParticlesProducer_;
  bool doMC_;
  bool doElectrons_;
  bool doEgammaOnly_;
  bool doRndCones_;
  edm::InputTag electronsProducer_;
  edm::InputTag reducedBarrelEcalRecHitCollection_;
  edm::InputTag reducedEndcapEcalRecHitCollection_;
  std::string OutputFile_;



  EcalClusterFunctionBaseClass *f;

  TFile* fOutput;
  TTree* myTree_;

  //event info
  int event_number;
  int event_run;
  int event_ls;
  int event_SCindex;
  int event_nGenVertex;
  int event_nGenOOTPileUpMinus;
  int event_nGenOOTPileUpPlus;
  int event_nRecoVertex;

  float event_rho;
  float event_IsolationConePUenergy;
  float event_sigma;
  float event_IsolationConePUfluctuation;
  float event_rhoPhotons;
  float event_sigmaPhotons;
  float event_rhoChargedHadrons;
  float event_sigmaChargedHadrons;
  float event_rhoNeutralHadrons;
  float event_sigmaNeutralHadrons;

  //photon kinematics
  int pho_isPrompt;

  int pho_isPFPhoton;
  int pho_isPFElectron;

  float pho_et;
  float pho_energy;
  float pho_px;
  float pho_py;
  float pho_pz;
  float pho_eta;
  float pho_phi;

  float pho_SCenergyETHPhotonCorr;
  float pho_SCenergyETHElectronCorr;
  float pho_energyETHPhotonCorrComplete;
  float pho_energyETHElectronCorrComplete;

  float pho_energyETHPhotonCorrCompleteQ40;
  float pho_energyETHPhotonCorrCompleteQ50;

  float GenEnergy;
  float GenEta;
  float GenPhi;

  int pho_hasConvTracks;

  float pho_PosEcalX;
  float pho_PosEcalY;
  float pho_PosEcalZ;
  float pho_GeomEta;
  float pho_GeomPhi;
  float pho_vx;
  float pho_vy;
  float pho_vz;

  float phoSC_GeomEta;
  float phoSC_GeomPhi;

  float phoSC_et;
  float phoSC_RawEt;
  float phoSC_RawEtCetaCorr;
  float phoSC_RawEnergyCetaCorr;
  //float phoSC_RawEnergyCetaTourneurCorr;
  //float phoSC_RawEnergyCetaCrackSC;
  //float phoSC_RawEnergyCetaCrackSCseed;
  //float pho_e5x5CrackCorr;
  float pho_crackcorrSC;
  float pho_crackcorrSCseedOnly;
  float pho_crackcorrSeedOnly;


  //photon tags
  int pho_isEB;
  int pho_isEE;

  //int pho_isInCrack;
  int pho_isInPhiCrack;
  int pho_isInEtaCrack;
  int pho_isInEBEEGap;

  //photon Id
  float pho_r9;
  float pho_sigmaIetaIeta;
  float pho_sigmaEtaEta ;
  float pho_e1x5 ;
  float pho_e2x5 ;
  float pho_e3x3 ;
  float pho_e5x5 ;
  float pho_maxEnergyXtal ; 
  float pho_etaWidth;
  float pho_phiWidth;
  float pho_Brem;
  float phoSC_energy;
  float phoSC_RawEnergy;
  

  float pho_hoe;
  float pho_IsoEcalRechit;
  float pho_IsoHcalRechit;
  float pho_IsoHollowTrkCone;
  float pho_IsoEcalRechit03;
  float pho_IsoHcalRechit03;
  float pho_IsoHollowTrkCone03;
  int pho_hasPixelSeed;

  float pho_IsoEcalHcal;
  float pho_IsoEcalHcalPUcorrected;
  float pho_CombIso;
  float pho_CombIsoPUcorrected;

  //photon seen as jet
  float pho_DrJetClosest;
  float pho_jetEMfraction;
  //float pho_jetArea;
  //float pho_jetPUenergy;
  //float pho_jetEmPUenergy;
  //float pho_jetHadPUenergy;
  
  //pflow iso
  int pho_Cone06NbPfCand;
  int pho_Cone06PfCandType[500];
  int pho_Cone06PfCandOverlap[500];
  float pho_Cone06PfCandEta[500];
  float pho_Cone06PfCandPhi[500];
  float pho_Cone06PfCandDeltaR[500];
  float pho_Cone06PfCandDeltaEta[500];
  float pho_Cone06PfCandDeltaPhi[500];
  float pho_Cone06PfCandPt[500];
  float pho_Cone06PfCandDz[500]; 
  float pho_Cone06PfCandDxy[500]; 
  int pho_Cone06PfCandIsFromPU[500];
  float pho_Cone06PfCandDeltaRrecomputed[500];
  float pho_Cone06PfCandDeltaEtarecomputed[500];
  float pho_Cone06PfCandDeltaPhirecomputed[500];
  float pho_Cone06PfCandPtrecomputed[500];	       



  //pflow iso rnd cones
  int rndCone_Cone06NbPfCand;
  int rndCone_Cone06PfCandType[500];
  int rndCone_Cone06PfCandOverlap[500];
  float rndCone_Cone06PfCandEta[500];
  float rndCone_Cone06PfCandPhi[500];
  float rndCone_Cone06PfCandDeltaR[500];
  float rndCone_Cone06PfCandDeltaEta[500];
  float rndCone_Cone06PfCandDeltaPhi[500];
  float rndCone_Cone06PfCandPt[500];
  float rndCone_Cone06PfCandDz[500];
  int rndCone_Cone06PfCandIsFromPU[500];

  //int pho_Cone06PfCandRegionalFlag[500];

  /*
  float pho_Cone06PfCandRegionalFlag_NORMAL[500];
  float pho_Cone06PfCandRegionalFlag_E_PHI_SMODULES[500];
  float pho_Cone06PfCandRegionalFlag_E_ETA_0[500];
  float pho_Cone06PfCandRegionalFlag_E_ETA_MODULES[500];
  float pho_Cone06PfCandRegionalFlag_E_BARREL_ENDCAP[500];
  float pho_Cone06PfCandRegionalFlag_E_PRESHOWER_EDGE[500];
  float pho_Cone06PfCandRegionalFlag_E_PRESHOWER[500];
  float pho_Cone06PfCandRegionalFlag_E_ENDCAP_EDGE[500];
  

  //float pho_Cone06PfCandDeltaEta[500];
  //float pho_Cone06PfCandDeltaPhi[500];
  float pho_Cone06PfCandEta[500];
  float pho_Cone06PfCandPhi[500];
  //float pho_Cone06PfCandPosEcalX[500];
  //float pho_Cone06PfCandPosEcalY[500];
  //float pho_Cone06PfCandPosEcalZ[500];
  //float pho_Cone06PfCandPosX[500];
  //float pho_Cone06PfCandPosY[500];
  //float pho_Cone06PfCandPosZ[500];
  //float pho_Cone06PfCandGeomEta[500];
  //float pho_Cone06PfCandGeomPhi[500];
  //float pho_Cone06PfCandPx[500];
  //float pho_Cone06PfCandPy[500];
  //float pho_Cone06PfCandPz[500];
  //float pho_Cone06PfCandEnergy[500];
  //float pho_Cone06PfCandVx[500];
  //float pho_Cone06PfCandVy[500];
  //float pho_Cone06PfCandVz[500]; 
  //int pho_Cone06PfCandVtxFlag[500];
  float pho_Cone06PfCandDz[500];  
  //float pho_Cone06PfCandDxy[500];  
  float pho_Cone06PfCandDeltaR[500];
  float pho_Cone06PfCandPt[500];
  

  float pho_Cone04NeutralHadronIso;
  float pho_Cone04ChargedHadronIso;
  float pho_Cone04PhotonIso;

  float pho_Cone03NeutralHadronIso;
  float pho_Cone03ChargedHadronIso;
  float pho_Cone03PhotonIso;
  */
  
  //Photon iso
  float pho_Cone04PhotonIso_dR0_dEta0_pt0;
  float pho_Cone04PhotonIso_dR0_dEta0_pt5; //pour reference
  float pho_Cone04PhotonIso_dR8_dEta0_pt0;
  float pho_Cone04PhotonIso_dR8_dEta0_pt5;

  float pho_Cone01PhotonIso_dR045EB070EE_dEta015_pt08EB1EE_mvVtx;
  float pho_Cone02PhotonIso_dR045EB070EE_dEta015_pt08EB1EE_mvVtx;
  float pho_Cone03PhotonIso_dR045EB070EE_dEta015_pt08EB1EE_mvVtx;  
  float pho_Cone04PhotonIso_dR045EB070EE_dEta015_pt08EB1EE_mvVtx;
  
  //Neutral hadron iso
  float pho_Cone04NeutralHadronIso_dR0_dEta0_pt0;
  float pho_Cone04NeutralHadronIso_dR0_dEta0_pt5; //pour reference
  float pho_Cone04NeutralHadronIso_dR0_dEta0_pt0_nocracks;
  float pho_Cone04NeutralHadronIso_dR0_dEta0_pt5_nocracks;
  float pho_Cone04NeutralHadronIso_dR7_dEta0_pt0;
  float pho_Cone04NeutralHadronIso_dR7_dEta0_pt5;

  float pho_Cone01NeutralHadronIso_dR0_dEta0_pt0_mvVtx;
  float pho_Cone02NeutralHadronIso_dR0_dEta0_pt0_mvVtx;
  float pho_Cone03NeutralHadronIso_dR0_dEta0_pt0_mvVtx;
  float pho_Cone04NeutralHadronIso_dR0_dEta0_pt0_mvVtx;

  //Charged hadron iso
  float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_dz0_old;
  float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_PFnoPU_old;
  float pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_dz0_old;
  float pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_PFnoPU_old;

  //pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_dz0_old

  float pho_Cone01ChargedHadronIso_dR0_dEta0_pt0_dz0;
  float pho_Cone01ChargedHadronIso_dR0_dEta0_pt0_dz1_dxy01;
  float pho_Cone01ChargedHadronIso_dR0_dEta0_pt0_PFnoPU;
  float pho_Cone01ChargedHadronIso_dR015_dEta0_pt0_dz0;
  float pho_Cone01ChargedHadronIso_dR015_dEta0_pt0_dz1_dxy01;
  float pho_Cone01ChargedHadronIso_dR015_dEta0_pt0_PFnoPU;

  float pho_Cone02ChargedHadronIso_dR0_dEta0_pt0_dz0;
  float pho_Cone02ChargedHadronIso_dR0_dEta0_pt0_dz1_dxy01;
  float pho_Cone02ChargedHadronIso_dR0_dEta0_pt0_PFnoPU;
  float pho_Cone02ChargedHadronIso_dR015_dEta0_pt0_dz0;
  float pho_Cone02ChargedHadronIso_dR015_dEta0_pt0_dz1_dxy01;
  float pho_Cone02ChargedHadronIso_dR015_dEta0_pt0_PFnoPU;

  float pho_Cone03ChargedHadronIso_dR0_dEta0_pt0_dz0;
  float pho_Cone03ChargedHadronIso_dR0_dEta0_pt0_dz1_dxy01;
  float pho_Cone03ChargedHadronIso_dR0_dEta0_pt0_PFnoPU;
  float pho_Cone03ChargedHadronIso_dR015_dEta0_pt0_dz0;
  float pho_Cone03ChargedHadronIso_dR015_dEta0_pt0_dz1_dxy01;
  float pho_Cone03ChargedHadronIso_dR015_dEta0_pt0_PFnoPU;

  float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_dz0;
  float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_dz1_dxy01;
  float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_PFnoPU; //pour reference
  float pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_dz0;
  float pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_dz1_dxy01;
  float pho_Cone04ChargedHadronIso_dR015_dEta0_pt0_PFnoPU;

  //float pho_Cone04ChargedHadronIso_dR0_dEta0_pt0_dz1;
  //float pho_Cone04ChargedHadronIso_dR0_dEta0_pt5_dz1;
  //float pho_Cone04ChargedHadronIso_dR0_dEta1_pt5_dz1;
  //float pho_Cone04ChargedHadronIso_dR4_dEta0_pt5_dz1;
  
  //float pho_Cone04NeutralHadronIsoDeltaRptdensity_dR0_dEta0_pt0_nocracks;
  
  float pho_ChargedHadronIso;
  float pho_NeutralHadronIso;
  float pho_PhotonIso;

  float pho_SCarea;
  float pho_SCarea_shoelace;

  int pho_SCnbc;
  int pho_SCnxtals;

  float pho_BCenergy[100];
  int pho_BCnXtals[100];
  int pho_BCisSeed[100];

   EcalClusterLazyTools* lazyTools;  

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
PhotonPUAnalyzer::PhotonPUAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  srcRho_ = iConfig.getParameter<edm::InputTag>("srcRho");
  srcSigma_ = iConfig.getParameter<edm::InputTag>("srcSigma");
//  srcRhoPhotons_ = iConfig.getParameter<edm::InputTag>("srcRhoPhotons");
//  srcSigmaPhotons_ = iConfig.getParameter<edm::InputTag>("srcSigmaPhotons");
//  srcRhoChargedHadrons_ = iConfig.getParameter<edm::InputTag>("srcRhoChargedHadrons");
//  srcSigmaChargedHadrons_ = iConfig.getParameter<edm::InputTag>("srcSigmaChargedHadrons");
//  srcRhoNeutralHadrons_ = iConfig.getParameter<edm::InputTag>("srcRhoNeutralHadrons");
//  srcSigmaNeutralHadrons_ = iConfig.getParameter<edm::InputTag>("srcSigmaNeutralHadrons");
//  HepMCPileUp_ = iConfig.getParameter<edm::InputTag>("HepMCPileUp");
  vertexProducer_ = iConfig.getParameter<edm::InputTag>("vertexProducer");
//  alternativeVertexProducer_ = iConfig.getParameter<edm::InputTag>("alternativeVertexProducer");
  photonsProducer_ = iConfig.getParameter<edm::InputTag>("photonsProducer");
//  SCProducer_ = iConfig.getParameter<edm::InputTag>("SCProducer");
//  pfphotonsProducer_ = iConfig.getParameter<edm::InputTag>("pfphotonsProducer");
//  jetsProducer_ = iConfig.getParameter<edm::InputTag>("jetsProducer");
//  jetsProducerPhotons_ = iConfig.getParameter<edm::InputTag>("jetsProducerPhotons");
//  jetsProducerChargedHadrons_ = iConfig.getParameter<edm::InputTag>("jetsProducerChargedHadrons");
//  jetsProducerNeutralHadrons_ = iConfig.getParameter<edm::InputTag>("jetsProducerNeutralHadrons");
//  pfProducer_ = iConfig.getParameter<edm::InputTag>("pfProducer");
  genParticlesProducer_ = iConfig.getParameter<edm::InputTag>("genParticlesProducer");
  doMC_ = iConfig.getParameter<bool>("doMC");
  //  doElectrons_ = iConfig.getParameter<bool>("doElectrons");
  doElectrons_ = 0;
//  doEgammaOnly_ = iConfig.getParameter<bool>("doEgammaOnly");
//  doRndCones_ = iConfig.getParameter<bool>("doRndCones");
//  electronsProducer_ = iConfig.getParameter<edm::InputTag>("electronsProducer");
  reducedBarrelEcalRecHitCollection_ = iConfig.getParameter<edm::InputTag>("reducedBarrelEcalRecHitCollection");
  reducedEndcapEcalRecHitCollection_ = iConfig.getParameter<edm::InputTag>("reducedEndcapEcalRecHitCollection");
  OutputFile_ = iConfig.getParameter<std::string>("OutputFile");

  GenParticles_Phi = new TH1F("GenParticles_Phi","GenParticles_Phi",128,-3.2,+3.2);
  RecoParticles_Phi = new TH1F("RecoParticles_Phi","RecoParticles_Phi",128,-3.2,+3.2);
  n_RecoParticles = new TH1I("n_RecoParticles","n_RecoParticles",5,0,5);

  //f = EcalClusterFunctionFactory::get()->create("EcalClusterCrackCorrection", iConfig);
  //  f = EcalClusterFunctionFactory::get()->create("EcalClusterEnergyCorrectionObjectSpecific", iConfig);
  //f = EcalClusterFunctionFactory::get()->create("EcalClusterEnergyCorrection", iConfig);

  cout << "Creating "<<OutputFile_.c_str()<<endl;
  fOutput = new TFile(OutputFile_.c_str(),"RECREATE");
  myTree_ = new TTree("Tree","PileUp info");

  myTree_->Branch("event_number",&event_number,"event_number/I");
  myTree_->Branch("event_run",&event_run,"event_run/I");
  myTree_->Branch("event_ls",&event_ls,"event_ls/I");
  myTree_->Branch("event_SCindex",&event_SCindex,"event_SCindex/I");
//  myTree_->Branch("event_nGenVertex",&event_nGenVertex,"event_nGenVertex/I");
//  myTree_->Branch("event_nGenOOTPileUpMinus",&event_nGenOOTPileUpMinus,"event_nGenOOTPileUpMinus/I");
//  myTree_->Branch("event_nGenOOTPileUpPlus",&event_nGenOOTPileUpPlus,"event_nGenOOTPileUpPlus/I");
// 
  myTree_->Branch("event_nRecoVertex",&event_nRecoVertex,"event_nRecoVertex/I");
  myTree_->Branch("event_rho",&event_rho,"event_rho/F");
//  myTree_->Branch("event_IsolationConePUenergy",&event_IsolationConePUenergy,"event_IsolationConePUenergy/F");
  myTree_->Branch("event_sigma",&event_sigma,"event_sigma/F");
//  myTree_->Branch("event_IsolationConePUfluctuation",&event_IsolationConePUfluctuation,"event_IsolationConePUfluctuation/F");
//  myTree_->Branch("event_rhoPhotons",&event_rhoPhotons,"event_rhoPhotons/F");
//  myTree_->Branch("event_sigmaPhotons",&event_sigmaPhotons,"event_sigmaPhotons/F");
//  myTree_->Branch("event_rhoChargedHadrons",&event_rhoChargedHadrons,"event_rhoChargedHadrons/F");
//  myTree_->Branch("event_sigmaChargedHadrons",&event_sigmaChargedHadrons,"event_sigmaChargedHadrons/F");
//  myTree_->Branch("event_rhoNeutralHadrons",&event_rhoNeutralHadrons,"event_rhoNeutralHadrons/F");
//  myTree_->Branch("event_sigmaNeutralHadrons",&event_sigmaNeutralHadrons,"event_sigmaNeutralHadrons/F");
//
  myTree_->Branch("pho_isPrompt",&pho_isPrompt,"pho_isPrompt/I");
  myTree_->Branch("GenEnergy",&GenEnergy,"GenEnergy/F");
  myTree_->Branch("GenEta",&GenEta,"GenEta/F");
  myTree_->Branch("GenPhi",&GenPhi,"GenPhi/F");

  //  myTree_->Branch("pho_isPFPhoton",&pho_isPFPhoton,"pho_isPFPhoton/I");
  //  myTree_->Branch("pho_isPFElectron",&pho_isPFElectron,"pho_isPFElectron/I");

  myTree_->Branch("pho_isEB",&pho_isEB,"pho_isEB/I");
  myTree_->Branch("pho_isEE",&pho_isEE,"pho_isEE/I");
  //myTree_->Branch("pho_isInCrack",&pho_isInCrack,"pho_isInCrack/I");
  myTree_->Branch("pho_isInPhiCrack",&pho_isInPhiCrack,"pho_isInPhiCrack/I");
  myTree_->Branch("pho_isInEtaCrack",&pho_isInEtaCrack,"pho_isInEtaCrack/I");
  myTree_->Branch("pho_isInEBEEGap",&pho_isInEBEEGap,"pho_isInEBEEGap/I");

//  myTree_->Branch("pho_et",&pho_et,"pho_et/F");
//  myTree_->Branch("pho_energy",&pho_energy,"pho_energy/F");
//  myTree_->Branch("pho_px",&pho_px,"pho_px/F");
//  myTree_->Branch("pho_py",&pho_py,"pho_py/F");
//  myTree_->Branch("pho_pz",&pho_pz,"pho_pz/F");
//  myTree_->Branch("pho_eta",&pho_eta,"pho_eta/F");
//  myTree_->Branch("pho_phi",&pho_phi,"pho_phi/F");


  myTree_->Branch("phoSC_energy",&phoSC_energy,"phoSC_energy/F");
  myTree_->Branch("phoSC_RawEnergy",&phoSC_RawEnergy,"phoSC_RawEnergy/F");
  myTree_->Branch("phoSC_et",&phoSC_et,"phoSC_et/F");
  myTree_->Branch("phoSC_RawEt",&phoSC_RawEt,"phoSC_RawEt/F");
  myTree_->Branch("phoSC_RawEtCetaCorr",&phoSC_RawEtCetaCorr,"phoSC_RawEtCetaCorr/F");
  myTree_->Branch("phoSC_RawEnergyCetaCorr",&phoSC_RawEnergyCetaCorr,"phoSC_RawEnergyCetaCorr/F");


  myTree_->Branch("pho_hasConvTracks",&pho_hasConvTracks,"pho_hasConvTracks/I");

  myTree_->Branch("pho_PosEcalX", &pho_PosEcalX, "pho_PosEcalX/F");
  myTree_->Branch("pho_PosEcalY", &pho_PosEcalY, "pho_PosEcalY/F");
  myTree_->Branch("pho_PosEcalZ", &pho_PosEcalZ, "pho_PosEcalZ/F");
  myTree_->Branch("pho_GeomEta", &pho_GeomEta, "pho_GeomEta/F");
  myTree_->Branch("pho_GeomPhi", &pho_GeomPhi, "pho_GeomPhi/F");

  myTree_->Branch("phoSC_GeomEta", &phoSC_GeomEta, "phoSC_GeomEta/F");
  myTree_->Branch("phoSC_GeomPhi", &phoSC_GeomPhi, "phoSC_GeomPhi/F");

  myTree_->Branch("pho_vx",&pho_vx,"pho_vx/F");
  myTree_->Branch("pho_vy",&pho_vy,"pho_vy/F");
  myTree_->Branch("pho_vz",&pho_vz,"pho_vz/F");

  myTree_->Branch("pho_r9",&pho_r9,"pho_r9/F");
  myTree_->Branch("pho_sigmaIetaIeta",&pho_sigmaIetaIeta,"pho_sigmaIetaIeta/F");
  myTree_->Branch("pho_sigmaEtaEta",&pho_sigmaEtaEta,"pho_sigmaEtaEta/F");
  myTree_->Branch("pho_e1x5",&pho_e1x5,"pho_e1x5/F");
  myTree_->Branch("pho_e2x5",&pho_e2x5,"pho_e2x5/F");
  myTree_->Branch("pho_e3x3",&pho_e3x3,"pho_e3x3/F");
  myTree_->Branch("pho_e5x5",&pho_e5x5,"pho_e5x5/F");
  myTree_->Branch("pho_maxEnergyXtal",&pho_maxEnergyXtal,"pho_maxEnergyXtal/F");
  myTree_->Branch("pho_etaWidth",&pho_etaWidth,"pho_etaWidth/F");
  myTree_->Branch("pho_phiWidth",&pho_phiWidth,"pho_phiWidth/F");
  myTree_->Branch("pho_Brem",&pho_Brem,"pho_Brem/F");

  myTree_->Branch("pho_hoe",&pho_hoe,"pho_hoe/F");

  myTree_->Branch("pho_SCarea",&pho_SCarea,"pho_SCarea/F");
  myTree_->Branch("pho_SCarea_shoelace",&pho_SCarea_shoelace,"pho_SCarea_shoelace/F");

  myTree_->Branch("pho_SCnbc",&pho_SCnbc,"pho_SCnbc/I");
  myTree_->Branch("pho_SCnxtals",&pho_SCnxtals,"pho_SCnxtals/I");

  myTree_->Branch("pho_BCenergy",&pho_BCenergy,"pho_BCenergy[pho_SCnbc]/F");
  myTree_->Branch("pho_BCnXtals",&pho_BCnXtals,"pho_BCnXtals[pho_SCnbc]/I");
  myTree_->Branch("pho_BCisSeed",&pho_BCisSeed,"pho_BCisSeed[pho_SCnbc]/I");

}


PhotonPUAnalyzer::~PhotonPUAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

  //  fOutput->WriteObject(myTree_,myTree_->GetName());
  fOutput->WriteObject(GenParticles_Phi,GenParticles_Phi->GetName());
  fOutput->WriteObject(RecoParticles_Phi,RecoParticles_Phi->GetName());
  fOutput->WriteObject(n_RecoParticles,n_RecoParticles->GetName());
  fOutput->Write();
  fOutput->Close();
}


//
// member functions
//

// ------------ method called to for each event  ------------
void
PhotonPUAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   
   //Rho, sigma
   edm::Handle<double> rhoHandle;
   iEvent.getByLabel(srcRho_,rhoHandle);
   double rho = *rhoHandle;
   //cout << "rho=" << rho << std::endl;
   edm::Handle<double> sigmaHandle;
   iEvent.getByLabel(srcSigma_,sigmaHandle);
   double sigma = *sigmaHandle;
   //cout << "sigma="<<sigma<<endl;
   
   //Vertex   
   edm::Handle<reco::VertexCollection> vertexHandle;
   iEvent.getByLabel(vertexProducer_, vertexHandle);
//   //cout << "nRecoVertex=" << vertexHandle->size() << std::endl;
//   
//   //PFcandidates
//   edm::Handle<reco::PFCandidateCollection> pfCandidates;
//   iEvent.getByLabel(pfProducer_, pfCandidates);
//
//   //cout << "PFcandidates loaded" << endl;
   
   //Photon collection
   edm::Handle<reco::PhotonCollection> photonHandle;
   iEvent.getByLabel(photonsProducer_,photonHandle);
//   //cout << "nPhotons=" << photonHandle->size() << std::endl;
   
   //cout << "Photons loaded"<<endl;

   //   edm::Handle<reco::SuperClusterCollection> SCHandle;
   //   iEvent.getByLabel(SCProducer_,SCHandle);

//   //Photon collection
//   edm::Handle<reco::PhotonCollection> pfPhotonHandle;
//   iEvent.getByLabel(pfphotonsProducer_,pfPhotonHandle);
//   //cout << "nPFPhotons=" << pfPhotonHandle->size() << std::endl;
//   
//   //cout << "PFPhotons loaded"<<endl;
   

   //MC truth
   edm::Handle <reco::GenParticleCollection> genParticles;
   if (doMC_){
     iEvent.getByLabel( genParticlesProducer_, genParticles );
     //cout << "nGenParticles="<<genParticles->size()<<std::endl;
   }

//   //Electron collection
//   edm::Handle<reco::GsfElectronCollection> electronHandle;
//   if (doElectrons_){
//     iEvent.getByLabel(electronsProducer_,electronHandle);
//     //cout << "nElectrons=" << electronHandle->size() << std::endl;
//   }
//     //cout << "Photons loaded"<<endl;


   //EcalClusterTools

   iSetup.get<CaloGeometryRecord>().get(theCaloGeom_); 
   //   const CaloSubdetectorGeometry* geom=theCaloGeom_->getSubdetectorGeometry(DetId::Ecal,EcalBarrel);//EcalBarrel = 1
   const CaloSubdetectorGeometry *barrelGeometry = theCaloGeom_->getSubdetectorGeometry(DetId::Ecal, EcalBarrel);
   const CaloSubdetectorGeometry *endcapGeometry = theCaloGeom_->getSubdetectorGeometry(DetId::Ecal, EcalEndcap);
   //   cout << "CaloGeometryRecord loaded" << endl;

   //   iSetup.get<CaloTopologyRecord>().get(theCaloTopo_);
         
   //cout << "CaloTopologyRecord"<<endl;

   edm::Handle<EcalRecHitCollection> EBRecHits_;
   edm::Handle<EcalRecHitCollection> EERecHits_;
   iEvent.getByLabel(reducedBarrelEcalRecHitCollection_, EBRecHits_);
   iEvent.getByLabel(reducedEndcapEcalRecHitCollection_, EERecHits_);

   lazyTools = new EcalClusterLazyTools( iEvent, iSetup, reducedBarrelEcalRecHitCollection_, reducedEndcapEcalRecHitCollection_ );

   for(unsigned int j=0; j<genParticles->size(); ++j ){
     const reco::GenParticle & p = (*genParticles)[ j ];
     if (p.status()==1 && (p.pdgId()==22 || p.pdgId()==11 || p.pdgId()==-11)) GenParticles_Phi->Fill(p.phi());
   }

   int number_matched=0;
   
   for (unsigned int index=0; index<photonHandle->size(); index++){

     {	 //genparticle matching

       const reco::SuperCluster& SCIter = *((*photonHandle)[index].superCluster());

       float scpt = SCIter.rawEnergy() * sin(SCIter.position().theta());;
       
       if (doMC_){
	 double bestPtdiff=500.0;
	 int igpsl=-1;
	 for(unsigned int j=0; j<genParticles->size(); ++j ){
	   const reco::GenParticle & p = (*genParticles)[ j ];
	   if (p.status()==1){
	     if (DeltaR(SCIter.phi(), p.phi(), SCIter.eta(), p.eta())<0.2){
	       if (fabs(p.pt()-scpt)<bestPtdiff){
		 bestPtdiff=fabs(p.pt()-scpt);
		 igpsl=j;
	       }
	     }
	   }
	 }

	 if (igpsl!=-1){
	   const reco::GenParticle & myGenPart = (*genParticles)[ igpsl ];
	   int pdg_to_match;
	   if (!doElectrons_) pdg_to_match=22;
	   else pdg_to_match=11;
	   if(myGenPart.pdgId()==pdg_to_match || myGenPart.pdgId()==-pdg_to_match){// && mom->pdgId()==22){
	     number_matched++;
	   }
	 }
       }
     }

   }

   if (number_matched!=2) return;

   int times_filled=0;

   for (unsigned int index=0; index<2; index++){

     const reco::SuperCluster& SCIter = *((*photonHandle)[index].superCluster());
     
     if (times_filled>=2) continue;
    
     //Event variables
     event_number = iEvent.id().event();
     event_run = iEvent.id().run(); 
     event_ls = iEvent.luminosityBlock();
     
     event_rho=rho;
     event_sigma=sigma;
     event_nRecoVertex=vertexHandle->size();



     //SC default
     phoSC_energy = SCIter.energy();
     phoSC_et = SCIter.energy() * sin(SCIter.position().theta());

     //SC Raw
     phoSC_RawEnergy = SCIter.rawEnergy();
     phoSC_RawEt = SCIter.rawEnergy() * sin(SCIter.position().theta());

     //SC Raw + C(eta)
     if (fabs(SCIter.eta())<1.5) phoSC_RawEnergyCetaCorr = SCIter.rawEnergy()/f5x5((int)(fabs(SCIter.eta())*(5/0.087)));
     else phoSC_RawEnergyCetaCorr = SCIter.rawEnergy() + SCIter.preshowerEnergy();
     phoSC_RawEtCetaCorr = phoSC_RawEnergyCetaCorr * sin(SCIter.position().theta());


     phoSC_GeomEta = SCIter.eta();
     phoSC_GeomPhi = SCIter.phi();

     pho_isInPhiCrack = isInPhiCracks(SCIter.phi(), SCIter.eta());
     pho_isInEtaCrack = isInEtaCracks(SCIter.eta());

     if (fabs(SCIter.eta())<1.44 || fabs(SCIter.eta())>1.56) pho_isInEBEEGap = false;
     else pho_isInEBEEGap = true;


	 {	 //genparticle matching
	 pho_isPrompt=0;
	 GenEnergy=-9;
	 GenEta=-9;
	 GenPhi=-9;

	 if (doMC_){
	   double bestPtdiff=500.0;
	   int igpsl=-1;
	   for(unsigned int j=0; j<genParticles->size(); ++j ){
	     const reco::GenParticle & p = (*genParticles)[ j ];
//	     std::cout << "Matching to genparticle " << j << std::endl;
//	     std::cout << "phoSC_RawEtCetaCorr " << phoSC_RawEtCetaCorr << std::endl;
//	     std::cout << "gen pt " << p.pt() << std::endl;
//	     std::cout << "deltaR " << DeltaR(SCIter.phi(), p.phi(), SCIter.eta(), p.eta()) << std::endl;
	     if (p.status()==1){
	       if (DeltaR(SCIter.phi(), p.phi(), SCIter.eta(), p.eta())<0.2){
		 if (fabs(p.pt()-phoSC_RawEtCetaCorr)<bestPtdiff){
		   bestPtdiff=fabs(p.pt()-phoSC_RawEtCetaCorr);
		   igpsl=j;
		 }
	       }
	     }
	   }
	   //cout << "igpsl="<<igpsl<<endl;
	   if (igpsl!=-1){
	     const reco::GenParticle & myGenPart = (*genParticles)[ igpsl ];
	     //if (myGenPart.numberOfMothers() > 0 ){
	     //	 const reco::Candidate * mom = myGenPart.mother();
	     int pdg_to_match;
	     if (!doElectrons_) pdg_to_match=22;
	     else pdg_to_match=11;
	     if(myGenPart.pdgId()==pdg_to_match || myGenPart.pdgId()==-pdg_to_match){// && mom->pdgId()==22){
	       pho_isPrompt = 1;
	       GenEnergy = myGenPart.energy();
	       GenEta = myGenPart.eta();
	       GenPhi = myGenPart.phi();
	       //}
	     }
	   }
	 }
	 }

	 if (!pho_isPrompt) { 
	   //std::cout << "Matching failed, continuing" << std::endl; 
	   continue;}
	 //	 else { std::cout << "Matching OK" << std::endl;}

	   //	 pho_sigmaEtaEta = SCIter.sigmaEtaEta();


	 //	 std::cout << "SC " << SCIter.rawEnergy() << " " << SCIter.eta() << " " << SCIter.phi() << std::endl;
	 //	 std::cout << "seed " << SCIter.seed()->energy() << std::endl;

	 pho_sigmaIetaIeta = (lazyTools->scLocalCovariances(SCIter)).at(0);

	 const reco::CaloClusterPtr phoSeed = SCIter.seed();
	 pho_e3x3 = lazyTools->e3x3(*phoSeed);

	 pho_r9 = pho_e3x3/phoSC_RawEnergy;
	 pho_e5x5 = lazyTools->e5x5(*phoSeed); //is already C(eta) corrected in EB R9>0.94 (in PhotonProducer, not in EcalClusterTools)
//     pho_maxEnergyXtal = SCIter.maxEnergyXtal();
     pho_etaWidth = SCIter.etaWidth();
     pho_phiWidth = SCIter.phiWidth();
     if (pho_etaWidth!=0) pho_Brem = pho_phiWidth/pho_etaWidth;
     else pho_Brem = -1; 


     float area=0;
     float area_shoelace=0;

     int ibc=0;

     std::vector<DetId> cristalli;

     for (int i=0; i<100; i++) {pho_BCenergy[i]=-999; pho_BCnXtals[i]=-999; pho_BCisSeed[i]=0;}
     
     for (reco::CaloCluster_iterator bc=SCIter.clustersBegin(); bc!=SCIter.clustersEnd(); ++bc){ // bc loop
              
       const std::vector< std::pair<DetId, float> > & seedrechits = (*bc)->hitsAndFractions();

       if (*bc == SCIter.seed()) pho_BCisSeed[ibc] = 1;
       else pho_BCisSeed[ibc] = 0;

       pho_BCenergy[ibc] = (*bc)->energy();
       pho_BCnXtals[ibc] = seedrechits.size();
 
       for (uint i=0; i<seedrechits.size(); i++) cristalli.push_back(seedrechits[i].first);

       ibc++;

     } // end bc loop
     
     pho_SCnbc = SCIter.clustersSize();
     
     //for (uint i=0; i<cristalli.size(); i++) std::cout << cristalli.at(i).rawId() << std::endl;
     //std::cout << cristalli.size() << " ";
     
     {
       int sizebefore = cristalli.size();
       sort(cristalli.begin(),cristalli.end());
       std::vector<DetId>::iterator it;
       it = unique(cristalli.begin(),cristalli.end());
       cristalli.resize(it-cristalli.begin());
       int sizeafter = cristalli.size();
       //       if (sizebefore!=sizeafter) std::cout << "DetId shared among BCs: from " << sizebefore << " to " << sizeafter << std::endl;
     }

     pho_SCnxtals = cristalli.size();

     //for (uint i=0; i<cristalli.size(); i++) std::cout << cristalli.at(i).rawId() << std::endl;
     //std::cout << cristalli.size() << std::endl;

     for (uint i=0; i<cristalli.size(); i++){
       CaloCellGeometry *cellGeometry = NULL;

       //  std::cout << cristalli.at(i).rawId() << std::endl;
       //  std::cout << cristalli.at(i).subdetId() << std::endl;
  
       if (cristalli.at(i).subdetId()==EcalBarrel){
	 EBDetId ebDetId  = cristalli.at(i);
	 area += (dynamic_cast<const EcalBarrelGeometry*>(barrelGeometry))->deltaPhi(ebDetId)*(dynamic_cast<const EcalBarrelGeometry*>(barrelGeometry))->deltaEta(ebDetId);
	 //    std::cout << (dynamic_cast<const EcalBarrelGeometry*>(barrelGeometry))->deltaEta(ebDetId) << " " << (dynamic_cast<const EcalBarrelGeometry*>(barrelGeometry))->deltaPhi(ebDetId) << " " << phoSC_GeomEta << std::endl;
	 cellGeometry = (CaloCellGeometry*)(barrelGeometry->getGeometry(ebDetId));
       }
       else if (cristalli.at(i).subdetId()==EcalEndcap){
	 EEDetId eeDetId  = cristalli.at(i);
	 area += (dynamic_cast<const EcalEndcapGeometry*>(endcapGeometry))->deltaPhi(eeDetId)*(dynamic_cast<const EcalEndcapGeometry*>(endcapGeometry))->deltaEta(eeDetId);
	 cellGeometry = (CaloCellGeometry*)(endcapGeometry->getGeometry(eeDetId));
       }
       else continue; // ci sono casi dove e' altre cose, v. DataFormats/EcalDetId/interface/EcalSubdetector.h
  
       const CaloCellGeometry::CornersVec& cellCorners (cellGeometry->getCorners());
       float temp=0;
       for (int i=0; i<4; i++) {
	 int iplus1 = i==3 ? 0 : i+1;
	 temp += cellCorners[i].eta()*float(cellCorners[iplus1].phi()) - cellCorners[iplus1].eta()*float(cellCorners[i].phi());
       }
       area_shoelace += fabs(temp)/2.0;
  
     } // end loop on cristalli

     pho_SCarea = area;
     pho_SCarea_shoelace = area_shoelace;


     event_SCindex = times_filled;
     myTree_->Fill();
     //     std::cout << "Fill tree" << std::endl;
     times_filled++;
     
       } // END loop on superclusters


       delete lazyTools;


}


// ------------ method called once each job just before starting event loop  ------------
void 
PhotonPUAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PhotonPUAnalyzer::endJob() {
}

double PhotonPUAnalyzer::DeltaR(double phi1, double phi2, double eta1, double eta2){

  double dphi=phi2-phi1;
  if (dphi>TMath::Pi()) dphi=2*TMath::Pi()-dphi;
  if (dphi<-TMath::Pi()) dphi=-2*TMath::Pi()-dphi;
  double dR=sqrt(dphi*dphi+(eta2-eta1)*(eta2-eta1));

  return dR;
}

double PhotonPUAnalyzer::DeltaPhi(double phi1, double phi2){

  double dphi=phi1-phi2;
  if (dphi>TMath::Pi()) dphi=2*TMath::Pi()-dphi;
  if (dphi<-TMath::Pi()) dphi=-2*TMath::Pi()-dphi;

  return dphi;
}

bool PhotonPUAnalyzer::isInPhiCracks(double phi, double eta){


  // tranform radiants [-pi,pi] in degrees [0,360]
  phi = (phi+TMath::Pi()) *180/TMath::Pi();

  // each supermodule is 20 degrees wide
  Double_t moduleWidth = 20;

  // the first module is centered at phi=0, so the first cracks are +10 and -10
  Double_t phi0 = 10.;

  // set a fiducial cut around the crack of +2-2 degrees
  Double_t fiducialCut = 2.;

  bool OK = false;
  if (fabs(eta)<1.44){
  for (Int_t i = 0 ; i < 18; ++i){
    if ((phi0 + moduleWidth*i -fiducialCut) <= phi && phi <= (phi0 + moduleWidth*i + fiducialCut)) OK = true;
    //        cout << " PHI " << (phi0 + moduleWidth*i -fiducialCut) << " " << phi << " " <<  (phi0 + moduleWidth*i + fiducialCut)  << " " << OK << endl ;
  }
  }

  //  cout << "is in phi crack ? " << OK << endl;
  return OK;
}

bool PhotonPUAnalyzer::isInEtaCracks(double eta){

     /*
       Yuri Maravin eta cracks def :
     double emAbsEta = fabs(phoSC_GeomEta);
     pho_isInCrack = 0;
     if ( emAbsEta < 0.018 ||
	 (emAbsEta > 0.423 && emAbsEta < 0.461) || 
	 (emAbsEta > 0.770 && emAbsEta < 0.806) || 
	 (emAbsEta > 1.127 && emAbsEta < 1.163) || 
	 (emAbsEta > 1.460 && emAbsEta < 1.558) )
       pho_isInCrack = 1;
     */

  const Int_t nBinsEta = 5;
  Double_t leftEta [nBinsEta]       = {0.00, 0.42, 0.77, 1.13, 1.46};
  Double_t rightEta[nBinsEta]       = {0.02, 0.46, 0.81, 1.16, 9999.};

  bool OK = false;
  if (TMath::Abs(eta)<1.44) {
          for (Int_t i = 0; i< nBinsEta; ++i){
                  if (leftEta[i] < TMath::Abs(eta) && TMath::Abs(eta) < rightEta[i] ) OK = true;
          }
  }
  else if (TMath::Abs(eta)>1.44 && TMath::Abs(eta)<1.56) OK = true;
  else if (TMath::Abs(eta)>1.56) OK = false;
    //    cout << leftEta[i] << " " << TMath::Abs(eta) << " " << rightEta[i] <<  " " << OK << endl;

  //  cout << "IS IN CRACK ? " << OK << endl;
  return OK;
}

double PhotonPUAnalyzer::f5x5( double iEta ) {
  if ( iEta < 40.2198 ) return 1;
  return 1 - 3.03103e-6*(iEta - 40.2198)*(iEta - 40.2198);
}





//define this as a plug-in
DEFINE_FWK_MODULE(PhotonPUAnalyzer);
