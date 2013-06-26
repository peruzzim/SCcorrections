#ifndef scCorrections_h
#define scCorrections_h
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TH1F.h"
#include "TH2F.h"


enum correctionType {none, brEta, brEtaET, R9Eta, R9EtaET, C3D, brEtaE };

class scCorrections {
 public :

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           event_number;
   Int_t           pho_isPrompt;
   Float_t         GenEnergy;
   Float_t         GenEta;
   Float_t         GenPhi;
   Int_t           pho_isEB;
   Int_t           pho_isEE;
   Int_t           pho_isInPhiCrack;
   Int_t           pho_isInEtaCrack;
   Int_t           pho_isInEBEEGap;
   Float_t         pho_et;
   Float_t         pho_energy;
   Float_t         pho_px;
   Float_t         pho_py;
   Float_t         pho_pz;
   Float_t         pho_eta;
   Float_t         pho_phi;
   Float_t         phoSC_energy;
   Float_t         phoSC_RawEnergy;
   Float_t         phoSC_et;
   Float_t         phoSC_RawEt;
   Float_t         phoSC_RawEtCetaCorr;
   Float_t         phoSC_RawEnergyCetaCorr;
   Int_t           pho_hasConvTracks;
   Float_t         pho_PosEcalX;
   Float_t         pho_PosEcalY;
   Float_t         pho_PosEcalZ;
   Float_t         pho_GeomEta;
   Float_t         pho_GeomPhi;
   Float_t         phoSC_GeomEta;
   Float_t         phoSC_GeomPhi;
   Float_t         pho_vx;
   Float_t         pho_vy;
   Float_t         pho_vz;
   Float_t         pho_r9;
   Float_t         pho_sigmaIetaIeta;
   Float_t         pho_sigmaEtaEta;
   Float_t         pho_e1x5;
   Float_t         pho_e2x5;
   Float_t         pho_e3x3;
   Float_t         pho_e5x5;
   Float_t         pho_maxEnergyXtal;
   Float_t         pho_etaWidth;
   Float_t         pho_phiWidth;
   Float_t         pho_Brem;
   Float_t         pho_hoe;

   // List of branches
   TBranch        *b_event_number;   //!
   TBranch        *b_pho_isPrompt;   //!
   TBranch        *b_GenEnergy;   //!
   TBranch        *b_GenEta;   //!
   TBranch        *b_GenPhi;   //!
   TBranch        *b_pho_isEB;   //!
   TBranch        *b_pho_isEE;   //!
   TBranch        *b_pho_isInPhiCrack;   //!
   TBranch        *b_pho_isInEtaCrack;   //!
   TBranch        *b_pho_isInEBEEGap;   //!
   TBranch        *b_pho_et;   //!
   TBranch        *b_pho_energy;   //!
   TBranch        *b_pho_px;   //!
   TBranch        *b_pho_py;   //!
   TBranch        *b_pho_pz;   //!
   TBranch        *b_pho_eta;   //!
   TBranch        *b_pho_phi;   //!
   TBranch        *b_phoSC_energy;   //!
   TBranch        *b_phoSC_RawEnergy;   //!
   TBranch        *b_phoSC_et;   //!
   TBranch        *b_phoSC_RawEt;   //!
   TBranch        *b_phoSC_RawEtCetaCorr;   //!
   TBranch        *b_phoSC_RawEnergyCetaCorr;   //!
   TBranch        *b_pho_hasConvTracks;   //!
   TBranch        *b_pho_PosEcalX;   //!
   TBranch        *b_pho_PosEcalY;   //!
   TBranch        *b_pho_PosEcalZ;   //!
   TBranch        *b_pho_GeomEta;   //!
   TBranch        *b_pho_GeomPhi;   //!
   TBranch        *b_phoSC_GeomEta;   //!
   TBranch        *b_phoSC_GeomPhi;   //!
   TBranch        *b_pho_vx;   //!
   TBranch        *b_pho_vy;   //!
   TBranch        *b_pho_vz;   //!
   TBranch        *b_pho_r9;   //!
   TBranch        *b_pho_sigmaIetaIeta;   //!
   TBranch        *b_pho_sigmaEtaEta;   //!
   TBranch        *b_pho_e1x5;   //!
   TBranch        *b_pho_e2x5;   //!
   TBranch        *b_pho_e3x3;   //!
   TBranch        *b_pho_e5x5;   //!
   TBranch        *b_pho_maxEnergyXtal;   //!
   TBranch        *b_pho_etaWidth;   //!
   TBranch        *b_pho_phiWidth;   //!
   TBranch        *b_pho_Brem;   //!
   TBranch        *b_pho_hoe;   //!


  scCorrections(TTree *tree=0);
  virtual ~scCorrections();
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
  virtual void     initHistograms();
  virtual void     initHistograms_R9();
  virtual void     initHistograms_3D();
  virtual void     initHistograms_E();
  virtual void     fillHistograms(correctionType);
  virtual void     fillHistograms_R9(correctionType);
  virtual void     fillHistograms_3D(correctionType);
  virtual void     fillHistograms_E(correctionType);
  virtual void     fitCB(TH1F*, Double_t&, Double_t&, Double_t&, Double_t& );
  virtual void     getErecEgenFits_BrEta(correctionType, bool);
  virtual void     getErecEgenFits_BrEta_E(correctionType, bool);
  virtual void     deriveCorrections_BrEta();
  virtual void     deriveCorrections_BrEta_E();
  virtual void     deriveCorrections_BrEtaET();
  virtual void     deriveCorrections_BrEtaE();
  virtual void     getErecEgenFits_R9Eta(correctionType, bool);
  virtual void     deriveCorrections_R9Eta();
  virtual void     deriveCorrections_R9EtaET();
  virtual void     run_brEta();
  virtual void     run_brEta_E();
  virtual void     run_apply_brEta();
  virtual void     run_apply_brEta_E();
  virtual void     run_apply_brEtaE();
  virtual void     run_brEtaET();
  virtual void     run_brEtaE();
  virtual void     run_apply_brEtaET();
  virtual void     run_R9Eta();
  virtual void     run_R9EtaET();
  virtual void     run_apply_R9Eta();
  virtual void     run_apply_R9EtaET();
  virtual void     run_3D();
  virtual void     getErecEgenFits_3D(correctionType, bool);
  virtual void     deriveCorrections_3D();
  virtual void     run_apply_3D();
};

#endif

#ifdef scCorrections_cxx
scCorrections::scCorrections(TTree *tree)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../DATA/NTUPLES/PhotonGun_Summer11_NPC/ggtree_mc_9.root");
    if (!f) {
      f = new TFile("../DATA/NTUPLES/PhotonGun_Summer11_NPC/ggtree_mc_9.root");
      f->cd("Rint:/");
    }
    tree = (TTree*)gDirectory->Get("ggNtuplizer/EventTree");

  }
  Init(tree);
}

scCorrections::~scCorrections()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t scCorrections::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t scCorrections::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (!fChain->InheritsFrom(TChain::Class()))  return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void scCorrections::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
   fChain->SetBranchAddress("pho_isPrompt", &pho_isPrompt, &b_pho_isPrompt);
   fChain->SetBranchAddress("GenEnergy", &GenEnergy, &b_GenEnergy);
   fChain->SetBranchAddress("GenEta", &GenEta, &b_GenEta);
   fChain->SetBranchAddress("GenPhi", &GenPhi, &b_GenPhi);
   fChain->SetBranchAddress("pho_isEB", &pho_isEB, &b_pho_isEB);
   fChain->SetBranchAddress("pho_isEE", &pho_isEE, &b_pho_isEE);
   fChain->SetBranchAddress("pho_isInPhiCrack", &pho_isInPhiCrack, &b_pho_isInPhiCrack);
   fChain->SetBranchAddress("pho_isInEtaCrack", &pho_isInEtaCrack, &b_pho_isInEtaCrack);
   fChain->SetBranchAddress("pho_isInEBEEGap", &pho_isInEBEEGap, &b_pho_isInEBEEGap);
   fChain->SetBranchAddress("pho_et", &pho_et, &b_pho_et);
   fChain->SetBranchAddress("pho_energy", &pho_energy, &b_pho_energy);
   fChain->SetBranchAddress("pho_px", &pho_px, &b_pho_px);
   fChain->SetBranchAddress("pho_py", &pho_py, &b_pho_py);
   fChain->SetBranchAddress("pho_pz", &pho_pz, &b_pho_pz);
   fChain->SetBranchAddress("pho_eta", &pho_eta, &b_pho_eta);
   fChain->SetBranchAddress("pho_phi", &pho_phi, &b_pho_phi);
   fChain->SetBranchAddress("phoSC_energy", &phoSC_energy, &b_phoSC_energy);
   fChain->SetBranchAddress("phoSC_RawEnergy", &phoSC_RawEnergy, &b_phoSC_RawEnergy);
   fChain->SetBranchAddress("phoSC_et", &phoSC_et, &b_phoSC_et);
   fChain->SetBranchAddress("phoSC_RawEt", &phoSC_RawEt, &b_phoSC_RawEt);
   fChain->SetBranchAddress("phoSC_RawEtCetaCorr", &phoSC_RawEtCetaCorr, &b_phoSC_RawEtCetaCorr);
   fChain->SetBranchAddress("phoSC_RawEnergyCetaCorr", &phoSC_RawEnergyCetaCorr, &b_phoSC_RawEnergyCetaCorr);
   fChain->SetBranchAddress("pho_hasConvTracks", &pho_hasConvTracks, &b_pho_hasConvTracks);
   fChain->SetBranchAddress("pho_PosEcalX", &pho_PosEcalX, &b_pho_PosEcalX);
   fChain->SetBranchAddress("pho_PosEcalY", &pho_PosEcalY, &b_pho_PosEcalY);
   fChain->SetBranchAddress("pho_PosEcalZ", &pho_PosEcalZ, &b_pho_PosEcalZ);
   fChain->SetBranchAddress("pho_GeomEta", &pho_GeomEta, &b_pho_GeomEta);
   fChain->SetBranchAddress("pho_GeomPhi", &pho_GeomPhi, &b_pho_GeomPhi);
   fChain->SetBranchAddress("phoSC_GeomEta", &phoSC_GeomEta, &b_phoSC_GeomEta);
   fChain->SetBranchAddress("phoSC_GeomPhi", &phoSC_GeomPhi, &b_phoSC_GeomPhi);
   fChain->SetBranchAddress("pho_vx", &pho_vx, &b_pho_vx);
   fChain->SetBranchAddress("pho_vy", &pho_vy, &b_pho_vy);
   fChain->SetBranchAddress("pho_vz", &pho_vz, &b_pho_vz);
   fChain->SetBranchAddress("pho_r9", &pho_r9, &b_pho_r9);
   fChain->SetBranchAddress("pho_sigmaIetaIeta", &pho_sigmaIetaIeta, &b_pho_sigmaIetaIeta);
   fChain->SetBranchAddress("pho_sigmaEtaEta", &pho_sigmaEtaEta, &b_pho_sigmaEtaEta);
   fChain->SetBranchAddress("pho_e1x5", &pho_e1x5, &b_pho_e1x5);
   fChain->SetBranchAddress("pho_e2x5", &pho_e2x5, &b_pho_e2x5);
   fChain->SetBranchAddress("pho_e3x3", &pho_e3x3, &b_pho_e3x3);
   fChain->SetBranchAddress("pho_e5x5", &pho_e5x5, &b_pho_e5x5);
   fChain->SetBranchAddress("pho_maxEnergyXtal", &pho_maxEnergyXtal, &b_pho_maxEnergyXtal);
   fChain->SetBranchAddress("pho_etaWidth", &pho_etaWidth, &b_pho_etaWidth);
   fChain->SetBranchAddress("pho_phiWidth", &pho_phiWidth, &b_pho_phiWidth);
   fChain->SetBranchAddress("pho_Brem", &pho_Brem, &b_pho_Brem);
   fChain->SetBranchAddress("pho_hoe", &pho_hoe, &b_pho_hoe);
   Notify();

}

Bool_t scCorrections::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void scCorrections::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
#endif // #ifdef scCorrections_cxx
