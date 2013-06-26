//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 29 18:06:47 2011 by ROOT version 5.28/00c
// from TTree EventTree/Event data
// found on file: ggtree_mc_1.root
//////////////////////////////////////////////////////////

#ifndef compareSCcorrections_h
#define compareSCcorrections_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>

class compareSCcorrections {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           event_number;
   Int_t           event_run;
   Int_t           event_ls;
   Int_t           event_SCindex;
   Int_t           event_coll_size;
   Int_t           event_nRecoVertex;
   Float_t         event_rho;
   Float_t         event_sigma;
   Float_t         GenEnergy;
   Float_t         GenEta;
   Float_t         GenPhi;
   Int_t           event_genPU;
   Int_t           event_genPUtrue;
   Int_t           ele_looseID;
   Int_t           ele_mediumID;
   Int_t           ele_tightID;
   Float_t         track_pt;
   Float_t         track_eta;
   Float_t         track_phi;
   Int_t           pixelseed;
   Int_t           pho_isInPhiCrack;
   Int_t           pho_isInEtaCrack;
   Int_t           pho_isInEBEEGap;
   Float_t         phoSC_correctedenergy;
   Float_t         phoSC_energy;
   Float_t         phoSC_RawEnergy;
   Float_t         phoSC_et;
   Float_t         phoSC_RawEt;
   Float_t         phoSC_RawEtCetaCorr;
   Float_t         phoSC_RawEnergyCetaCorr;
   Float_t         phoSC_GeomEta;
   Float_t         phoSC_GeomPhi;
   Float_t         phoSC_r9;
   Float_t         pho_sigmaIetaIeta;
   Float_t         pho_e3x3;
   Float_t         pho_e5x5;
   Float_t         pho_etaWidth;
   Float_t         pho_phiWidth;
   Float_t         pho_Brem;

   // List of branches
   TBranch        *b_event_number;   //!
   TBranch        *b_event_run;   //!
   TBranch        *b_event_ls;   //!
   TBranch        *b_event_SCindex;   //!
   TBranch        *b_event_coll_size;   //!
   TBranch        *b_event_nRecoVertex;   //!
   TBranch        *b_event_rho;   //!
   TBranch        *b_event_sigma;   //!
   TBranch        *b_GenEnergy;   //!
   TBranch        *b_GenEta;   //!
   TBranch        *b_GenPhi;   //!
   TBranch        *b_event_genPU;   //!
   TBranch        *b_event_genPUtrue;   //!
   TBranch        *b_ele_looseID;   //!
   TBranch        *b_ele_mediumID;   //!
   TBranch        *b_ele_tightID;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_pixelseed;   //!
   TBranch        *b_pho_isInPhiCrack;   //!
   TBranch        *b_pho_isInEtaCrack;   //!
   TBranch        *b_pho_isInEBEEGap;   //!
   TBranch        *b_phoSC_correctedenergy;   //!
   TBranch        *b_phoSC_energy;   //!
   TBranch        *b_phoSC_RawEnergy;   //!
   TBranch        *b_phoSC_et;   //!
   TBranch        *b_phoSC_RawEt;   //!
   TBranch        *b_phoSC_RawEtCetaCorr;   //!
   TBranch        *b_phoSC_RawEnergyCetaCorr;   //!
   TBranch        *b_phoSC_GeomEta;   //!
   TBranch        *b_phoSC_GeomPhi;   //!
   TBranch        *b_phoSC_r9;   //!
   TBranch        *b_pho_sigmaIetaIeta;   //!
   TBranch        *b_pho_e3x3;   //!
   TBranch        *b_pho_e5x5;   //!
   TBranch        *b_pho_etaWidth;   //!
   TBranch        *b_pho_phiWidth;   //!
   TBranch        *b_pho_Brem;   //!



   compareSCcorrections(TTree *tree=0);
   virtual ~compareSCcorrections();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual void     initHistograms();
   virtual void     fitCB(TH1F*, Double_t&, Double_t&, Double_t&, Double_t& );
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef compareSCcorrections_cxx
compareSCcorrections::compareSCcorrections(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
//      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ggtree_mc_1.root");
//      if (!f) {
//         f = new TFile("ggtree_mc_1.root");
//         f->cd("ggtree_mc_1.root:/ggNtuplizer");
//      }
      tree = (TTree*)gDirectory->Get("Tree");

   }
   Init(tree);
}

compareSCcorrections::~compareSCcorrections()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t compareSCcorrections::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t compareSCcorrections::LoadTree(Long64_t entry)
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

void compareSCcorrections::Init(TTree *tree)
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
   fChain->SetBranchAddress("event_run", &event_run, &b_event_run);
   fChain->SetBranchAddress("event_ls", &event_ls, &b_event_ls);
   fChain->SetBranchAddress("event_SCindex", &event_SCindex, &b_event_SCindex);
   fChain->SetBranchAddress("event_coll_size", &event_coll_size, &b_event_coll_size);
   fChain->SetBranchAddress("event_nRecoVertex", &event_nRecoVertex, &b_event_nRecoVertex);
   fChain->SetBranchAddress("event_rho", &event_rho, &b_event_rho);
   fChain->SetBranchAddress("event_sigma", &event_sigma, &b_event_sigma);
   fChain->SetBranchAddress("GenEnergy", &GenEnergy, &b_GenEnergy);
   fChain->SetBranchAddress("GenEta", &GenEta, &b_GenEta);
   fChain->SetBranchAddress("GenPhi", &GenPhi, &b_GenPhi);
   fChain->SetBranchAddress("event_genPU", &event_genPU, &b_event_genPU);
   fChain->SetBranchAddress("event_genPUtrue", &event_genPUtrue, &b_event_genPUtrue);
   fChain->SetBranchAddress("ele_looseID", &ele_looseID, &b_ele_looseID);
   fChain->SetBranchAddress("ele_mediumID", &ele_mediumID, &b_ele_mediumID);
   fChain->SetBranchAddress("ele_tightID", &ele_tightID, &b_ele_tightID);
   fChain->SetBranchAddress("track_pt", &track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_eta", &track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_phi", &track_phi, &b_track_phi);
   fChain->SetBranchAddress("pixelseed", &pixelseed, &b_pixelseed);
   fChain->SetBranchAddress("pho_isInPhiCrack", &pho_isInPhiCrack, &b_pho_isInPhiCrack);
   fChain->SetBranchAddress("pho_isInEtaCrack", &pho_isInEtaCrack, &b_pho_isInEtaCrack);
   fChain->SetBranchAddress("pho_isInEBEEGap", &pho_isInEBEEGap, &b_pho_isInEBEEGap);
   fChain->SetBranchAddress("phoSC_correctedenergy", &phoSC_correctedenergy, &b_phoSC_correctedenergy);
   fChain->SetBranchAddress("phoSC_energy", &phoSC_energy, &b_phoSC_energy);
   fChain->SetBranchAddress("phoSC_RawEnergy", &phoSC_RawEnergy, &b_phoSC_RawEnergy);
   fChain->SetBranchAddress("phoSC_et", &phoSC_et, &b_phoSC_et);
   fChain->SetBranchAddress("phoSC_RawEt", &phoSC_RawEt, &b_phoSC_RawEt);
   fChain->SetBranchAddress("phoSC_RawEtCetaCorr", &phoSC_RawEtCetaCorr, &b_phoSC_RawEtCetaCorr);
   fChain->SetBranchAddress("phoSC_RawEnergyCetaCorr", &phoSC_RawEnergyCetaCorr, &b_phoSC_RawEnergyCetaCorr);
   fChain->SetBranchAddress("phoSC_GeomEta", &phoSC_GeomEta, &b_phoSC_GeomEta);
   fChain->SetBranchAddress("phoSC_GeomPhi", &phoSC_GeomPhi, &b_phoSC_GeomPhi);
   fChain->SetBranchAddress("phoSC_r9", &phoSC_r9, &b_phoSC_r9);
   fChain->SetBranchAddress("pho_sigmaIetaIeta", &pho_sigmaIetaIeta, &b_pho_sigmaIetaIeta);
   fChain->SetBranchAddress("pho_e3x3", &pho_e3x3, &b_pho_e3x3);
   fChain->SetBranchAddress("pho_e5x5", &pho_e5x5, &b_pho_e5x5);
   fChain->SetBranchAddress("pho_etaWidth", &pho_etaWidth, &b_pho_etaWidth);
   fChain->SetBranchAddress("pho_phiWidth", &pho_phiWidth, &b_pho_phiWidth);
   fChain->SetBranchAddress("pho_Brem", &pho_Brem, &b_pho_Brem);


   Notify();


}

Bool_t compareSCcorrections::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void compareSCcorrections::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t compareSCcorrections::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef compareSCcorrections_cxx
