#define compareSCcorrections_cxx
#include "compareSCcorrections.h"


#include <TStyle.h>
#include <TCanvas.h>
#include "Utils.C"
#include <iostream>
#include <fstream>
#include <sstream>
#include "TROOT.h"
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include "TMath.h"
#include <TStyle.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TBox.h>
#include "TFile.h"
#include "RooGlobalFunc.h"
#include "RooRealVar.h"
#include "RooCBShape.h"
#include "RooDataHist.h"
#include "RooPlot.h"

using std::cout;
using std::endl;


#include "./effSigma.C"

bool DBG = false;			                                

//Particle
//TString partType = "photon";
TString partType = "electron";

//Binning final plots
const Int_t nCorr = 9;


//To derive corrections put everything to true
bool doEB = 0;
bool doEE = !doEB;
//bool doDeriveCorr = true;

using namespace RooFit;


const Double_t etaCrackMin = 1.44;
const Double_t etaCrackMax = 1.56;


  //STD 
  const Int_t    nBinsEta              = 14; 
  Double_t       leftEta  [nBinsEta]   = { 0.02, 0.25, 0.46, 0.81, 0.91, 1.01, 1.16,           etaCrackMax,  1.653,  1.8, 2.0, 2.2, 2.3, 2.4 };  
  Double_t       rightEta [nBinsEta]   = { 0.25, 0.42, 0.77, 0.91, 1.01, 1.13, etaCrackMin,    1.653,        1.8  ,  2.0, 2.2, 2.3, 2.4, 2.5 };  

  const Int_t    nBinsBr  = 18;                           
  Double_t brbins[36];                                




  const Int_t    nBinsET             = 13;             
  Double_t       leftET  [nBinsET];                    
  Double_t       rightET [nBinsET];                    
  Double_t       ETBins  [nBinsET*2];                  

  const Int_t    nBinsE             = 26;             
  Double_t       leftE  [nBinsE];                    
  Double_t       rightE [nBinsE];                    
  Double_t       EBins  [nBinsE*2];                  

TH1F *h_CBET_EB_PHOTONS;
TH1F *h_CBET_EE_PHOTONS;
TH1F *h_CBE_EB_PHOTONS;
TH1F *h_CBE_EE_PHOTONS;

TH1F *h_CBET_EB_ELECTRONS;
TH1F *h_CBET_EE_ELECTRONS;
TH1F *h_CBE_EB_ELECTRONS;
TH1F *h_CBE_EE_ELECTRONS;

TH1F *h_corr_PHOTONS[nBinsEta];
TH1F *h_corr_ELECTRONS[nBinsEta];

//Fit
Int_t minEntries      = 100;
Double_t EgenFrac = 0.3;
Double_t nBinsErecEgen = 650;//650;
Double_t ErecEgenMin   = 0.0;
Double_t ErecEgenMax   = 1.3;
bool plot_gaussian = false; // true; // 
bool plots         = false; // true; // 


//Pt
const Int_t   nBinsPt = 39;
const Double_t PtMin = 5;
const Double_t PtMax = 200;
TH1F* h_ErecEgen_pt[nCorr][nBinsPt];
const Double_t binwidth_pt = (PtMax - PtMin) / ((Double_t)nBinsPt);
TH1F* ErecEgenMean_vsPt[nCorr];
TH1F* ErecEgenSigmaEff_vsPt[nCorr];

//Eta
const Int_t   nBinsEtaEBEE = 50;
TH1F* h_ErecEgen_eta[nCorr][nBinsEtaEBEE];
TH1F* ErecEgenMean_vsEta[nCorr];
TH1F* ErecEgenSigmaEff_vsEta[nCorr];

//Phi
const Int_t   nBinsPhi = 50;
const Double_t PhiMin = -3.14159265;
const Double_t PhiMax = 3.14159265;
TH1F* h_ErecEgen_phi[nCorr][nBinsPhi];
const Double_t binwidth_phi = (PhiMax - PhiMin) / ((Double_t)nBinsPhi);
TH1F* ErecEgenMean_vsPhi[nCorr];
TH1F* ErecEgenSigmaEff_vsPhi[nCorr];

//Brem
const Int_t   nBinsBrem = 50;
const Double_t BremMin = 0.88;
const Double_t BremMax = 5;
TH1F* h_ErecEgen_brem[nCorr][nBinsBrem];
const Double_t binwidth_brem = (BremMax - BremMin) / ((Double_t)nBinsBrem);
TH1F* ErecEgenMean_vsBrem[nCorr];
TH1F* ErecEgenSigmaEff_vsBrem[nCorr];

//R9
const Int_t   nBinsR9 = 18;
const Double_t R9Min = 0.;
TH1F* h_ErecEgen_r9[nCorr][nBinsR9];
TH1F* ErecEgenMean_vsR9[nCorr];
TH1F* ErecEgenSigmaEff_vsR9[nCorr];

//Energy
const Int_t   nBinsEnergy = 50;
const Double_t EnergyMin = 0.;
const Double_t EnergyMax = 1000.;
TH1F* h_ErecEgen_energy[nCorr][nBinsEnergy];
const Double_t binwidth_energy = (EnergyMax - EnergyMin) / ((Double_t)nBinsEnergy);
TH1F* ErecEgenMean_vsEnergy[nCorr];
TH1F* ErecEgenSigmaEff_vsEnergy[nCorr];



// fitted corrections
#include "PHOTONS_corrections_brEta.C_61"
#include "PHOTONS_corrections_E_EE.C_61"
#include "PHOTONS_corrections_ET_EB.C_61"
#include "ELECTRONS_corrections_brEta.C_61"
#include "ELECTRONS_corrections_E_EE.C_61"
#include "ELECTRONS_corrections_ET_EB.C_61"

//#include "corrections_brEta_ELECTRONS_nofit.C"
//#include "corrections_brEta_PHOTONS_nofit.C"
//#include "./applyScCorrections_ET_PHOTONS_nofit.C"
//#include "./applyScCorrections_E_PHOTONS_nofit.C"
//#include "./applyScCorrections_ET_ELECTRONS_nofit.C"
//#include "./applyScCorrections_E_ELECTRONS_nofit.C"





void compareSCcorrections::initHistograms()
{
	
	cout << "compareSCcorrections : "<< nCorr << " corrections for " << partType << endl;
	if (doEB) cout << "BARREL" << endl;
	if (doEE) cout << "ENDCAP" << endl;
	
	cout << "Load energy corrections" << endl;
}


void compareSCcorrections::Loop()
{




  brbins[0] =  0.8 ; 
  brbins[1] =  1 ; 
  brbins[2] =  1 ; 
  brbins[3] =  1.2 ; 
  brbins[4] =  1.2 ; 
  brbins[5] =  1.4 ; 
  brbins[6] =  1.4 ; 
  brbins[7] =  1.6 ; 
  brbins[8] =  1.6 ; 
  brbins[9] =  1.8 ; 
  brbins[10] =  1.8 ; 
  brbins[11] =  2 ; 
  brbins[12] =  2 ; 
  brbins[13] =  2.2 ; 
  brbins[14] =  2.2 ; 
  brbins[15] =  2.4 ; 
  brbins[16] =  2.4 ; 
  brbins[17] =  2.6 ; 
  brbins[18] =  2.6 ; 
  brbins[19] =  2.8 ; 
  brbins[20] =  2.8 ; 
  brbins[21] =  3 ; 
  brbins[22] =  3 ; 
  brbins[23] =  3.2 ; 
  brbins[24] =  3.2 ; 
  brbins[25] =  3.4 ; 
  brbins[26] =  3.4 ; 
  brbins[27] =  3.6 ; 
  brbins[28] =  3.6 ; 
  brbins[29] =  3.8 ; 
  brbins[30] =  3.8 ; 
  brbins[31] =  4 ; 
  brbins[32] =  4 ; 
  brbins[33] =  5 ; 
  brbins[34] =  5 ; 
  brbins[35] =  10 ; 


  /*
 // new 610
  for (Int_t i = 0; i<nBinsEta; ++i){                                                   
    h_corr_PHOTONS[i] = new TH1F(Form("h_corr_PHOTONS_%d",i),Form("h_corr_PHOTONS_%d",i),nBinsBr*2-1, brbins);  
  }                                                                                     
  h_corr_PHOTONS[0]->SetBinContent(1,1.00911 );
  h_corr_PHOTONS[0]->SetBinContent(3,1.00195 );
  h_corr_PHOTONS[0]->SetBinContent(5,1.00448 );
  h_corr_PHOTONS[0]->SetBinContent(7,1.00537 );
  h_corr_PHOTONS[0]->SetBinContent(9,1.00515 );
  h_corr_PHOTONS[0]->SetBinContent(11,1.00532 );
  h_corr_PHOTONS[0]->SetBinContent(13,1.00522 );
  h_corr_PHOTONS[0]->SetBinContent(15,1.00522 );
  h_corr_PHOTONS[0]->SetBinContent(17,1.00508 );
  h_corr_PHOTONS[0]->SetBinContent(19,1.0043 );
  h_corr_PHOTONS[0]->SetBinContent(21,1.0031 );
  h_corr_PHOTONS[0]->SetBinContent(23,1.00451 );
  h_corr_PHOTONS[0]->SetBinContent(25,1.00369 );
  h_corr_PHOTONS[0]->SetBinContent(27,1.00341 );
  h_corr_PHOTONS[0]->SetBinContent(29,1.00161 );
  h_corr_PHOTONS[0]->SetBinContent(31,1.0014 );
  h_corr_PHOTONS[0]->SetBinContent(33,1.0029 );
  h_corr_PHOTONS[0]->SetBinContent(35,0.997805 );

  h_corr_PHOTONS[1]->SetBinContent(1,1.01103 );
  h_corr_PHOTONS[1]->SetBinContent(3,1.0044 );
  h_corr_PHOTONS[1]->SetBinContent(5,1.00518 );
  h_corr_PHOTONS[1]->SetBinContent(7,1.00564 );
  h_corr_PHOTONS[1]->SetBinContent(9,1.00478 );
  h_corr_PHOTONS[1]->SetBinContent(11,1.0045 );
  h_corr_PHOTONS[1]->SetBinContent(13,1.00464 );
  h_corr_PHOTONS[1]->SetBinContent(15,1.00406 );
  h_corr_PHOTONS[1]->SetBinContent(17,1.00452 );
  h_corr_PHOTONS[1]->SetBinContent(19,1.00281 );
  h_corr_PHOTONS[1]->SetBinContent(21,1.00181 );
  h_corr_PHOTONS[1]->SetBinContent(23,1.00301 );
  h_corr_PHOTONS[1]->SetBinContent(25,1.00153 );
  h_corr_PHOTONS[1]->SetBinContent(27,1.00105 );
  h_corr_PHOTONS[1]->SetBinContent(29,1.0036 );
  h_corr_PHOTONS[1]->SetBinContent(31,1.00087 );
  h_corr_PHOTONS[1]->SetBinContent(33,0.999447 );
  h_corr_PHOTONS[1]->SetBinContent(35,0.996071 );

  h_corr_PHOTONS[2]->SetBinContent(1,1.00755 );
  h_corr_PHOTONS[2]->SetBinContent(3,1.00203 );
  h_corr_PHOTONS[2]->SetBinContent(5,1.00518 );
  h_corr_PHOTONS[2]->SetBinContent(7,1.00399 );
  h_corr_PHOTONS[2]->SetBinContent(9,1.00382 );
  h_corr_PHOTONS[2]->SetBinContent(11,1.00366 );
  h_corr_PHOTONS[2]->SetBinContent(13,1.00316 );
  h_corr_PHOTONS[2]->SetBinContent(15,1.00278 );
  h_corr_PHOTONS[2]->SetBinContent(17,1.00278 );
  h_corr_PHOTONS[2]->SetBinContent(19,1.00218 );
  h_corr_PHOTONS[2]->SetBinContent(21,1.00115 );
  h_corr_PHOTONS[2]->SetBinContent(23,1.00156 );
  h_corr_PHOTONS[2]->SetBinContent(25,1.00125 );
  h_corr_PHOTONS[2]->SetBinContent(27,0.999759 );
  h_corr_PHOTONS[2]->SetBinContent(29,0.999675 );
  h_corr_PHOTONS[2]->SetBinContent(31,0.998803 );
  h_corr_PHOTONS[2]->SetBinContent(33,0.997966 );
  h_corr_PHOTONS[2]->SetBinContent(35,0.99159 );

  h_corr_PHOTONS[3]->SetBinContent(1,1.00755 );
  h_corr_PHOTONS[3]->SetBinContent(3,1.00198 );
  h_corr_PHOTONS[3]->SetBinContent(5,1.00234 );
  h_corr_PHOTONS[3]->SetBinContent(7,1.00237 );
  h_corr_PHOTONS[3]->SetBinContent(9,1.00422 );
  h_corr_PHOTONS[3]->SetBinContent(11,1.00203 );
  h_corr_PHOTONS[3]->SetBinContent(13,1.00025 );
  h_corr_PHOTONS[3]->SetBinContent(15,0.999455 );
  h_corr_PHOTONS[3]->SetBinContent(17,0.999964 );
  h_corr_PHOTONS[3]->SetBinContent(19,0.998423 );
  h_corr_PHOTONS[3]->SetBinContent(21,0.999232 );
  h_corr_PHOTONS[3]->SetBinContent(23,0.998635 );
  h_corr_PHOTONS[3]->SetBinContent(25,0.996475 );
  h_corr_PHOTONS[3]->SetBinContent(27,0.997508 );
  h_corr_PHOTONS[3]->SetBinContent(29,0.995793 );
  h_corr_PHOTONS[3]->SetBinContent(31,0.997236 );
  h_corr_PHOTONS[3]->SetBinContent(33,0.993536 );
  h_corr_PHOTONS[3]->SetBinContent(35,0.986535 );

  h_corr_PHOTONS[4]->SetBinContent(1,1.00755 );
  h_corr_PHOTONS[4]->SetBinContent(3,0.999715 );
  h_corr_PHOTONS[4]->SetBinContent(5,1.00087 );
  h_corr_PHOTONS[4]->SetBinContent(7,1.00135 );
  h_corr_PHOTONS[4]->SetBinContent(9,1.00022 );
  h_corr_PHOTONS[4]->SetBinContent(11,0.998876 );
  h_corr_PHOTONS[4]->SetBinContent(13,0.999437 );
  h_corr_PHOTONS[4]->SetBinContent(15,0.996879 );
  h_corr_PHOTONS[4]->SetBinContent(17,0.995211 );
  h_corr_PHOTONS[4]->SetBinContent(19,0.995829 );
  h_corr_PHOTONS[4]->SetBinContent(21,0.994191 );
  h_corr_PHOTONS[4]->SetBinContent(23,0.992941 );
  h_corr_PHOTONS[4]->SetBinContent(25,0.992971 );
  h_corr_PHOTONS[4]->SetBinContent(27,0.992722 );
  h_corr_PHOTONS[4]->SetBinContent(29,0.989664 );
  h_corr_PHOTONS[4]->SetBinContent(31,0.989544 );
  h_corr_PHOTONS[4]->SetBinContent(33,0.984077 );
  h_corr_PHOTONS[4]->SetBinContent(35,0.975884 );

  h_corr_PHOTONS[5]->SetBinContent(1,1.00755 );
  h_corr_PHOTONS[5]->SetBinContent(3,0.999649 );
  h_corr_PHOTONS[5]->SetBinContent(5,0.997419 );
  h_corr_PHOTONS[5]->SetBinContent(7,0.997699 );
  h_corr_PHOTONS[5]->SetBinContent(9,0.996926 );
  h_corr_PHOTONS[5]->SetBinContent(11,0.996159 );
  h_corr_PHOTONS[5]->SetBinContent(13,0.994407 );
  h_corr_PHOTONS[5]->SetBinContent(15,0.991623 );
  h_corr_PHOTONS[5]->SetBinContent(17,0.990541 );
  h_corr_PHOTONS[5]->SetBinContent(19,0.987653 );
  h_corr_PHOTONS[5]->SetBinContent(21,0.985283 );
  h_corr_PHOTONS[5]->SetBinContent(23,0.986988 );
  h_corr_PHOTONS[5]->SetBinContent(25,0.985919 );
  h_corr_PHOTONS[5]->SetBinContent(27,0.97931 );
  h_corr_PHOTONS[5]->SetBinContent(29,0.980458 );
  h_corr_PHOTONS[5]->SetBinContent(31,0.976297 );
  h_corr_PHOTONS[5]->SetBinContent(33,0.973508 );
  h_corr_PHOTONS[5]->SetBinContent(35,0.961739 );

  h_corr_PHOTONS[6]->SetBinContent(1,1.00755 );
  h_corr_PHOTONS[6]->SetBinContent(3,0.998084 );
  h_corr_PHOTONS[6]->SetBinContent(5,0.996585 );
  h_corr_PHOTONS[6]->SetBinContent(7,0.996382 );
  h_corr_PHOTONS[6]->SetBinContent(9,0.995253 );
  h_corr_PHOTONS[6]->SetBinContent(11,0.993395 );
  h_corr_PHOTONS[6]->SetBinContent(13,0.992929 );
  h_corr_PHOTONS[6]->SetBinContent(15,0.990296 );
  h_corr_PHOTONS[6]->SetBinContent(17,0.988461 );
  h_corr_PHOTONS[6]->SetBinContent(19,0.986458 );
  h_corr_PHOTONS[6]->SetBinContent(21,0.984312 );
  h_corr_PHOTONS[6]->SetBinContent(23,0.982401 );
  h_corr_PHOTONS[6]->SetBinContent(25,0.98005 );
  h_corr_PHOTONS[6]->SetBinContent(27,0.978624 );
  h_corr_PHOTONS[6]->SetBinContent(29,0.974662 );
  h_corr_PHOTONS[6]->SetBinContent(31,0.973472 );
  h_corr_PHOTONS[6]->SetBinContent(33,0.9666 );
  h_corr_PHOTONS[6]->SetBinContent(35,0.961739 );

  h_corr_PHOTONS[7]->SetBinContent(1,0.973756 );
  h_corr_PHOTONS[7]->SetBinContent(3,0.974773 );
  h_corr_PHOTONS[7]->SetBinContent(5,0.974204 );
  h_corr_PHOTONS[7]->SetBinContent(7,0.974139 );
  h_corr_PHOTONS[7]->SetBinContent(9,0.974032 );
  h_corr_PHOTONS[7]->SetBinContent(11,0.972481 );
  h_corr_PHOTONS[7]->SetBinContent(13,0.97031 );
  h_corr_PHOTONS[7]->SetBinContent(15,0.967816 );
  h_corr_PHOTONS[7]->SetBinContent(17,0.965199 );
  h_corr_PHOTONS[7]->SetBinContent(19,0.962478 );
  h_corr_PHOTONS[7]->SetBinContent(21,0.961222 );
  h_corr_PHOTONS[7]->SetBinContent(23,0.957902 );
  h_corr_PHOTONS[7]->SetBinContent(25,0.956655 );
  h_corr_PHOTONS[7]->SetBinContent(27,0.94847 );
  h_corr_PHOTONS[7]->SetBinContent(29,0.946364 );
  h_corr_PHOTONS[7]->SetBinContent(31,0.943846 );
  h_corr_PHOTONS[7]->SetBinContent(33,0.93199 );
  h_corr_PHOTONS[7]->SetBinContent(35,0.903582 );

  h_corr_PHOTONS[8]->SetBinContent(1,0.979872 );
  h_corr_PHOTONS[8]->SetBinContent(3,0.978604 );
  h_corr_PHOTONS[8]->SetBinContent(5,0.978455 );
  h_corr_PHOTONS[8]->SetBinContent(7,0.97707 );
  h_corr_PHOTONS[8]->SetBinContent(9,0.976315 );
  h_corr_PHOTONS[8]->SetBinContent(11,0.973663 );
  h_corr_PHOTONS[8]->SetBinContent(13,0.970326 );
  h_corr_PHOTONS[8]->SetBinContent(15,0.968126 );
  h_corr_PHOTONS[8]->SetBinContent(17,0.965351 );
  h_corr_PHOTONS[8]->SetBinContent(19,0.962038 );
  h_corr_PHOTONS[8]->SetBinContent(21,0.960899 );
  h_corr_PHOTONS[8]->SetBinContent(23,0.950201 );
  h_corr_PHOTONS[8]->SetBinContent(25,0.943317 );
  h_corr_PHOTONS[8]->SetBinContent(27,0.942918 );
  h_corr_PHOTONS[8]->SetBinContent(29,0.936381 );
  h_corr_PHOTONS[8]->SetBinContent(31,0.932375 );
  h_corr_PHOTONS[8]->SetBinContent(33,0.919942 );
  h_corr_PHOTONS[8]->SetBinContent(35,0.87488 );

  h_corr_PHOTONS[9]->SetBinContent(1,0.981161 );
  h_corr_PHOTONS[9]->SetBinContent(3,0.978441 );
  h_corr_PHOTONS[9]->SetBinContent(5,0.97769 );
  h_corr_PHOTONS[9]->SetBinContent(7,0.977881 );
  h_corr_PHOTONS[9]->SetBinContent(9,0.976922 );
  h_corr_PHOTONS[9]->SetBinContent(11,0.973494 );
  h_corr_PHOTONS[9]->SetBinContent(13,0.970774 );
  h_corr_PHOTONS[9]->SetBinContent(15,0.966917 );
  h_corr_PHOTONS[9]->SetBinContent(17,0.959063 );
  h_corr_PHOTONS[9]->SetBinContent(19,0.962411 );
  h_corr_PHOTONS[9]->SetBinContent(21,0.951703 );
  h_corr_PHOTONS[9]->SetBinContent(23,0.941883 );
  h_corr_PHOTONS[9]->SetBinContent(25,0.936695 );
  h_corr_PHOTONS[9]->SetBinContent(27,0.93186 );
  h_corr_PHOTONS[9]->SetBinContent(29,0.93208 );
  h_corr_PHOTONS[9]->SetBinContent(31,0.930355 );
  h_corr_PHOTONS[9]->SetBinContent(33,0.893809 );
  h_corr_PHOTONS[9]->SetBinContent(35,0.87488 );

  h_corr_PHOTONS[10]->SetBinContent(1,0.981023 );
  h_corr_PHOTONS[10]->SetBinContent(3,0.980024 );
  h_corr_PHOTONS[10]->SetBinContent(5,0.97949 );
  h_corr_PHOTONS[10]->SetBinContent(7,0.979971 );
  h_corr_PHOTONS[10]->SetBinContent(9,0.978824 );
  h_corr_PHOTONS[10]->SetBinContent(11,0.976202 );
  h_corr_PHOTONS[10]->SetBinContent(13,0.973203 );
  h_corr_PHOTONS[10]->SetBinContent(15,0.969889 );
  h_corr_PHOTONS[10]->SetBinContent(17,0.963938 );
  h_corr_PHOTONS[10]->SetBinContent(19,0.960585 );
  h_corr_PHOTONS[10]->SetBinContent(21,0.954658 );
  h_corr_PHOTONS[10]->SetBinContent(23,0.948633 );
  h_corr_PHOTONS[10]->SetBinContent(25,0.933944 );
  h_corr_PHOTONS[10]->SetBinContent(27,0.948763 );
  h_corr_PHOTONS[10]->SetBinContent(29,0.93208 );
  h_corr_PHOTONS[10]->SetBinContent(31,0.930355 );
  h_corr_PHOTONS[10]->SetBinContent(33,0.893809 );
  h_corr_PHOTONS[10]->SetBinContent(35,0.87488 );

  h_corr_PHOTONS[11]->SetBinContent(1,0.981028 );
  h_corr_PHOTONS[11]->SetBinContent(3,0.980314 );
  h_corr_PHOTONS[11]->SetBinContent(5,0.979225 );
  h_corr_PHOTONS[11]->SetBinContent(7,0.97997 );
  h_corr_PHOTONS[11]->SetBinContent(9,0.979587 );
  h_corr_PHOTONS[11]->SetBinContent(11,0.978107 );
  h_corr_PHOTONS[11]->SetBinContent(13,0.971492 );
  h_corr_PHOTONS[11]->SetBinContent(15,0.971792 );
  h_corr_PHOTONS[11]->SetBinContent(17,0.963637 );
  h_corr_PHOTONS[11]->SetBinContent(19,0.956738 );
  h_corr_PHOTONS[11]->SetBinContent(21,0.954658 );
  h_corr_PHOTONS[11]->SetBinContent(23,0.948633 );
  h_corr_PHOTONS[11]->SetBinContent(25,0.933944 );
  h_corr_PHOTONS[11]->SetBinContent(27,0.948763 );
  h_corr_PHOTONS[11]->SetBinContent(29,0.93208 );
  h_corr_PHOTONS[11]->SetBinContent(31,0.930355 );
  h_corr_PHOTONS[11]->SetBinContent(33,0.893809 );
  h_corr_PHOTONS[11]->SetBinContent(35,0.87488 );

  h_corr_PHOTONS[12]->SetBinContent(1,0.979634 );
  h_corr_PHOTONS[12]->SetBinContent(3,0.98311 );
  h_corr_PHOTONS[12]->SetBinContent(5,0.983679 );
  h_corr_PHOTONS[12]->SetBinContent(7,0.980413 );
  h_corr_PHOTONS[12]->SetBinContent(9,0.977107 );
  h_corr_PHOTONS[12]->SetBinContent(11,0.976334 );
  h_corr_PHOTONS[12]->SetBinContent(13,0.969681 );
  h_corr_PHOTONS[12]->SetBinContent(15,0.964521 );
  h_corr_PHOTONS[12]->SetBinContent(17,0.964822 );
  h_corr_PHOTONS[12]->SetBinContent(19,0.956738 );
  h_corr_PHOTONS[12]->SetBinContent(21,0.954658 );
  h_corr_PHOTONS[12]->SetBinContent(23,0.948633 );
  h_corr_PHOTONS[12]->SetBinContent(25,0.933944 );
  h_corr_PHOTONS[12]->SetBinContent(27,0.948763 );
  h_corr_PHOTONS[12]->SetBinContent(29,0.93208 );
  h_corr_PHOTONS[12]->SetBinContent(31,0.930355 );
  h_corr_PHOTONS[12]->SetBinContent(33,0.893809 );
  h_corr_PHOTONS[12]->SetBinContent(35,0.87488 );

  h_corr_PHOTONS[13]->SetBinContent(1,0.979634 );
  h_corr_PHOTONS[13]->SetBinContent(3,0.976508 );
  h_corr_PHOTONS[13]->SetBinContent(5,0.981052 );
  h_corr_PHOTONS[13]->SetBinContent(7,0.978603 );
  h_corr_PHOTONS[13]->SetBinContent(9,0.977332 );
  h_corr_PHOTONS[13]->SetBinContent(11,0.981104 );
  h_corr_PHOTONS[13]->SetBinContent(13,0.965046 );
  h_corr_PHOTONS[13]->SetBinContent(15,0.964521 );
  h_corr_PHOTONS[13]->SetBinContent(17,0.964822 );
  h_corr_PHOTONS[13]->SetBinContent(19,0.956738 );
  h_corr_PHOTONS[13]->SetBinContent(21,0.954658 );
  h_corr_PHOTONS[13]->SetBinContent(23,0.948633 );
  h_corr_PHOTONS[13]->SetBinContent(25,0.933944 );
  h_corr_PHOTONS[13]->SetBinContent(27,0.948763 );
  h_corr_PHOTONS[13]->SetBinContent(29,0.93208 );
  h_corr_PHOTONS[13]->SetBinContent(31,0.930355 );
  h_corr_PHOTONS[13]->SetBinContent(33,0.893809 );
  h_corr_PHOTONS[13]->SetBinContent(35,0.87488 );

  for (Int_t i = 0; i<nBinsEta; ++i){                                                   
    h_corr_ELECTRONS[i] = new TH1F(Form("h_corr_ELECTRONS_%d",i),Form("h_corr_ELECTRONS_%d",i),nBinsBr*2-1, brbins);  
  }                                                                                     
  h_corr_ELECTRONS[0]->SetBinContent(1,1.00312 );
  h_corr_ELECTRONS[0]->SetBinContent(3,1.0038 );
  h_corr_ELECTRONS[0]->SetBinContent(5,1.00565 );
  h_corr_ELECTRONS[0]->SetBinContent(7,1.00524 );
  h_corr_ELECTRONS[0]->SetBinContent(9,1.00418 );
  h_corr_ELECTRONS[0]->SetBinContent(11,1.00339 );
  h_corr_ELECTRONS[0]->SetBinContent(13,1.00447 );
  h_corr_ELECTRONS[0]->SetBinContent(15,1.00304 );
  h_corr_ELECTRONS[0]->SetBinContent(17,1.00266 );
  h_corr_ELECTRONS[0]->SetBinContent(19,1.00268 );
  h_corr_ELECTRONS[0]->SetBinContent(21,1.00285 );
  h_corr_ELECTRONS[0]->SetBinContent(23,1.00216 );
  h_corr_ELECTRONS[0]->SetBinContent(25,1.00122 );
  h_corr_ELECTRONS[0]->SetBinContent(27,1.00171 );
  h_corr_ELECTRONS[0]->SetBinContent(29,1.00275 );
  h_corr_ELECTRONS[0]->SetBinContent(31,1.00253 );
  h_corr_ELECTRONS[0]->SetBinContent(33,1.00141 );
  h_corr_ELECTRONS[0]->SetBinContent(35,0.998228 );

  h_corr_ELECTRONS[1]->SetBinContent(1,1.00353 );
  h_corr_ELECTRONS[1]->SetBinContent(3,1.00375 );
  h_corr_ELECTRONS[1]->SetBinContent(5,1.00482 );
  h_corr_ELECTRONS[1]->SetBinContent(7,1.0045 );
  h_corr_ELECTRONS[1]->SetBinContent(9,1.00388 );
  h_corr_ELECTRONS[1]->SetBinContent(11,1.00288 );
  h_corr_ELECTRONS[1]->SetBinContent(13,1.00331 );
  h_corr_ELECTRONS[1]->SetBinContent(15,1.00219 );
  h_corr_ELECTRONS[1]->SetBinContent(17,1.00134 );
  h_corr_ELECTRONS[1]->SetBinContent(19,1.00165 );
  h_corr_ELECTRONS[1]->SetBinContent(21,1.00135 );
  h_corr_ELECTRONS[1]->SetBinContent(23,1.00004 );
  h_corr_ELECTRONS[1]->SetBinContent(25,1.00049 );
  h_corr_ELECTRONS[1]->SetBinContent(27,1.00135 );
  h_corr_ELECTRONS[1]->SetBinContent(29,0.998285 );
  h_corr_ELECTRONS[1]->SetBinContent(31,0.999249 );
  h_corr_ELECTRONS[1]->SetBinContent(33,0.997015 );
  h_corr_ELECTRONS[1]->SetBinContent(35,0.991827 );

  h_corr_ELECTRONS[2]->SetBinContent(1,1.00268 );
  h_corr_ELECTRONS[2]->SetBinContent(3,1.00317 );
  h_corr_ELECTRONS[2]->SetBinContent(5,1.00427 );
  h_corr_ELECTRONS[2]->SetBinContent(7,1.00353 );
  h_corr_ELECTRONS[2]->SetBinContent(9,1.0031 );
  h_corr_ELECTRONS[2]->SetBinContent(11,1.00198 );
  h_corr_ELECTRONS[2]->SetBinContent(13,1.00109 );
  h_corr_ELECTRONS[2]->SetBinContent(15,1.00099 );
  h_corr_ELECTRONS[2]->SetBinContent(17,1.00044 );
  h_corr_ELECTRONS[2]->SetBinContent(19,0.999942 );
  h_corr_ELECTRONS[2]->SetBinContent(21,1.00025 );
  h_corr_ELECTRONS[2]->SetBinContent(23,0.999839 );
  h_corr_ELECTRONS[2]->SetBinContent(25,0.999343 );
  h_corr_ELECTRONS[2]->SetBinContent(27,0.997805 );
  h_corr_ELECTRONS[2]->SetBinContent(29,0.9976 );
  h_corr_ELECTRONS[2]->SetBinContent(31,0.99801 );
  h_corr_ELECTRONS[2]->SetBinContent(33,0.997174 );
  h_corr_ELECTRONS[2]->SetBinContent(35,0.990273 );

  h_corr_ELECTRONS[3]->SetBinContent(1,1.00239 );
  h_corr_ELECTRONS[3]->SetBinContent(3,1.0025 );
  h_corr_ELECTRONS[3]->SetBinContent(5,1.00277 );
  h_corr_ELECTRONS[3]->SetBinContent(7,1.0021 );
  h_corr_ELECTRONS[3]->SetBinContent(9,1.00082 );
  h_corr_ELECTRONS[3]->SetBinContent(11,1.00044 );
  h_corr_ELECTRONS[3]->SetBinContent(13,0.999265 );
  h_corr_ELECTRONS[3]->SetBinContent(15,0.99849 );
  h_corr_ELECTRONS[3]->SetBinContent(17,0.998506 );
  h_corr_ELECTRONS[3]->SetBinContent(19,0.99663 );
  h_corr_ELECTRONS[3]->SetBinContent(21,0.998309 );
  h_corr_ELECTRONS[3]->SetBinContent(23,0.996356 );
  h_corr_ELECTRONS[3]->SetBinContent(25,0.994358 );
  h_corr_ELECTRONS[3]->SetBinContent(27,0.992014 );
  h_corr_ELECTRONS[3]->SetBinContent(29,0.994974 );
  h_corr_ELECTRONS[3]->SetBinContent(31,0.995158 );
  h_corr_ELECTRONS[3]->SetBinContent(33,0.990216 );
  h_corr_ELECTRONS[3]->SetBinContent(35,0.981146 );

  h_corr_ELECTRONS[4]->SetBinContent(1,1.00042 );
  h_corr_ELECTRONS[4]->SetBinContent(3,1.00066 );
  h_corr_ELECTRONS[4]->SetBinContent(5,1.00071 );
  h_corr_ELECTRONS[4]->SetBinContent(7,0.999997 );
  h_corr_ELECTRONS[4]->SetBinContent(9,0.999141 );
  h_corr_ELECTRONS[4]->SetBinContent(11,0.997244 );
  h_corr_ELECTRONS[4]->SetBinContent(13,0.996322 );
  h_corr_ELECTRONS[4]->SetBinContent(15,0.995331 );
  h_corr_ELECTRONS[4]->SetBinContent(17,0.994275 );
  h_corr_ELECTRONS[4]->SetBinContent(19,0.994044 );
  h_corr_ELECTRONS[4]->SetBinContent(21,0.994801 );
  h_corr_ELECTRONS[4]->SetBinContent(23,0.991458 );
  h_corr_ELECTRONS[4]->SetBinContent(25,0.990905 );
  h_corr_ELECTRONS[4]->SetBinContent(27,0.99098 );
  h_corr_ELECTRONS[4]->SetBinContent(29,0.98939 );
  h_corr_ELECTRONS[4]->SetBinContent(31,0.986875 );
  h_corr_ELECTRONS[4]->SetBinContent(33,0.986076 );
  h_corr_ELECTRONS[4]->SetBinContent(35,0.974445 );

  h_corr_ELECTRONS[5]->SetBinContent(1,0.999443 );
  h_corr_ELECTRONS[5]->SetBinContent(3,0.998372 );
  h_corr_ELECTRONS[5]->SetBinContent(5,0.997611 );
  h_corr_ELECTRONS[5]->SetBinContent(7,0.997083 );
  h_corr_ELECTRONS[5]->SetBinContent(9,0.994134 );
  h_corr_ELECTRONS[5]->SetBinContent(11,0.993345 );
  h_corr_ELECTRONS[5]->SetBinContent(13,0.991468 );
  h_corr_ELECTRONS[5]->SetBinContent(15,0.990873 );
  h_corr_ELECTRONS[5]->SetBinContent(17,0.987817 );
  h_corr_ELECTRONS[5]->SetBinContent(19,0.987057 );
  h_corr_ELECTRONS[5]->SetBinContent(21,0.985594 );
  h_corr_ELECTRONS[5]->SetBinContent(23,0.98525 );
  h_corr_ELECTRONS[5]->SetBinContent(25,0.982653 );
  h_corr_ELECTRONS[5]->SetBinContent(27,0.980509 );
  h_corr_ELECTRONS[5]->SetBinContent(29,0.977234 );
  h_corr_ELECTRONS[5]->SetBinContent(31,0.976602 );
  h_corr_ELECTRONS[5]->SetBinContent(33,0.971231 );
  h_corr_ELECTRONS[5]->SetBinContent(35,0.974445 );

  h_corr_ELECTRONS[6]->SetBinContent(1,0.997196 );
  h_corr_ELECTRONS[6]->SetBinContent(3,0.994881 );
  h_corr_ELECTRONS[6]->SetBinContent(5,0.994344 );
  h_corr_ELECTRONS[6]->SetBinContent(7,0.993436 );
  h_corr_ELECTRONS[6]->SetBinContent(9,0.991051 );
  h_corr_ELECTRONS[6]->SetBinContent(11,0.990067 );
  h_corr_ELECTRONS[6]->SetBinContent(13,0.988207 );
  h_corr_ELECTRONS[6]->SetBinContent(15,0.990873 );
  h_corr_ELECTRONS[6]->SetBinContent(17,0.984409 );
  h_corr_ELECTRONS[6]->SetBinContent(19,0.982966 );
  h_corr_ELECTRONS[6]->SetBinContent(21,0.981727 );
  h_corr_ELECTRONS[6]->SetBinContent(23,0.980146 );
  h_corr_ELECTRONS[6]->SetBinContent(25,0.977137 );
  h_corr_ELECTRONS[6]->SetBinContent(27,0.975534 );
  h_corr_ELECTRONS[6]->SetBinContent(29,0.974315 );
  h_corr_ELECTRONS[6]->SetBinContent(31,0.972407 );
  h_corr_ELECTRONS[6]->SetBinContent(33,0.965858 );
  h_corr_ELECTRONS[6]->SetBinContent(35,0.974445 );

  h_corr_ELECTRONS[7]->SetBinContent(1,0.976982 );
  h_corr_ELECTRONS[7]->SetBinContent(3,0.974051 );
  h_corr_ELECTRONS[7]->SetBinContent(5,0.970804 );
  h_corr_ELECTRONS[7]->SetBinContent(7,0.969995 );
  h_corr_ELECTRONS[7]->SetBinContent(9,0.969812 );
  h_corr_ELECTRONS[7]->SetBinContent(11,0.968786 );
  h_corr_ELECTRONS[7]->SetBinContent(13,0.965999 );
  h_corr_ELECTRONS[7]->SetBinContent(15,0.963978 );
  h_corr_ELECTRONS[7]->SetBinContent(17,0.961398 );
  h_corr_ELECTRONS[7]->SetBinContent(19,0.961739 );
  h_corr_ELECTRONS[7]->SetBinContent(21,0.958883 );
  h_corr_ELECTRONS[7]->SetBinContent(23,0.957226 );
  h_corr_ELECTRONS[7]->SetBinContent(25,0.951642 );
  h_corr_ELECTRONS[7]->SetBinContent(27,0.949062 );
  h_corr_ELECTRONS[7]->SetBinContent(29,0.942751 );
  h_corr_ELECTRONS[7]->SetBinContent(31,0.943376 );
  h_corr_ELECTRONS[7]->SetBinContent(33,0.965858 );
  h_corr_ELECTRONS[7]->SetBinContent(35,0.886708 );

  h_corr_ELECTRONS[8]->SetBinContent(1,0.981664 );
  h_corr_ELECTRONS[8]->SetBinContent(3,0.980179 );
  h_corr_ELECTRONS[8]->SetBinContent(5,0.977598 );
  h_corr_ELECTRONS[8]->SetBinContent(7,0.975469 );
  h_corr_ELECTRONS[8]->SetBinContent(9,0.974405 );
  h_corr_ELECTRONS[8]->SetBinContent(11,0.972435 );
  h_corr_ELECTRONS[8]->SetBinContent(13,0.971144 );
  h_corr_ELECTRONS[8]->SetBinContent(15,0.96725 );
  h_corr_ELECTRONS[8]->SetBinContent(17,0.965171 );
  h_corr_ELECTRONS[8]->SetBinContent(19,0.960089 );
  h_corr_ELECTRONS[8]->SetBinContent(21,0.956982 );
  h_corr_ELECTRONS[8]->SetBinContent(23,0.955285 );
  h_corr_ELECTRONS[8]->SetBinContent(25,0.951823 );
  h_corr_ELECTRONS[8]->SetBinContent(27,0.941622 );
  h_corr_ELECTRONS[8]->SetBinContent(29,0.933324 );
  h_corr_ELECTRONS[8]->SetBinContent(31,0.928404 );
  h_corr_ELECTRONS[8]->SetBinContent(33,0.916041 );
  h_corr_ELECTRONS[8]->SetBinContent(35,0.864879 );

  h_corr_ELECTRONS[9]->SetBinContent(1,0.984746 );
  h_corr_ELECTRONS[9]->SetBinContent(3,0.982545 );
  h_corr_ELECTRONS[9]->SetBinContent(5,0.980126 );
  h_corr_ELECTRONS[9]->SetBinContent(7,0.979537 );
  h_corr_ELECTRONS[9]->SetBinContent(9,0.976052 );
  h_corr_ELECTRONS[9]->SetBinContent(11,0.97363 );
  h_corr_ELECTRONS[9]->SetBinContent(13,0.971982 );
  h_corr_ELECTRONS[9]->SetBinContent(15,0.96612 );
  h_corr_ELECTRONS[9]->SetBinContent(17,0.962722 );
  h_corr_ELECTRONS[9]->SetBinContent(19,0.956838 );
  h_corr_ELECTRONS[9]->SetBinContent(21,0.954617 );
  h_corr_ELECTRONS[9]->SetBinContent(23,0.946593 );
  h_corr_ELECTRONS[9]->SetBinContent(25,0.930908 );
  h_corr_ELECTRONS[9]->SetBinContent(27,0.915928 );
  h_corr_ELECTRONS[9]->SetBinContent(29,0.920631 );
  h_corr_ELECTRONS[9]->SetBinContent(31,0.897547 );
  h_corr_ELECTRONS[9]->SetBinContent(33,0.876156 );
  h_corr_ELECTRONS[9]->SetBinContent(35,0.818965 );

  h_corr_ELECTRONS[10]->SetBinContent(1,0.988036 );
  h_corr_ELECTRONS[10]->SetBinContent(3,0.987029 );
  h_corr_ELECTRONS[10]->SetBinContent(5,0.983871 );
  h_corr_ELECTRONS[10]->SetBinContent(7,0.983178 );
  h_corr_ELECTRONS[10]->SetBinContent(9,0.980495 );
  h_corr_ELECTRONS[10]->SetBinContent(11,0.977938 );
  h_corr_ELECTRONS[10]->SetBinContent(13,0.975138 );
  h_corr_ELECTRONS[10]->SetBinContent(15,0.971418 );
  h_corr_ELECTRONS[10]->SetBinContent(17,0.962834 );
  h_corr_ELECTRONS[10]->SetBinContent(19,0.958912 );
  h_corr_ELECTRONS[10]->SetBinContent(21,0.948436 );
  h_corr_ELECTRONS[10]->SetBinContent(23,0.943919 );
  h_corr_ELECTRONS[10]->SetBinContent(25,0.92384 );
  h_corr_ELECTRONS[10]->SetBinContent(27,0.95076 );
  h_corr_ELECTRONS[10]->SetBinContent(29,0.904529 );
  h_corr_ELECTRONS[10]->SetBinContent(31,0.897547 );
  h_corr_ELECTRONS[10]->SetBinContent(33,0.868972 );
  h_corr_ELECTRONS[10]->SetBinContent(35,0.818965 );

  h_corr_ELECTRONS[11]->SetBinContent(1,0.990345 );
  h_corr_ELECTRONS[11]->SetBinContent(3,0.989017 );
  h_corr_ELECTRONS[11]->SetBinContent(5,0.986475 );
  h_corr_ELECTRONS[11]->SetBinContent(7,0.983991 );
  h_corr_ELECTRONS[11]->SetBinContent(9,0.981781 );
  h_corr_ELECTRONS[11]->SetBinContent(11,0.976278 );
  h_corr_ELECTRONS[11]->SetBinContent(13,0.97069 );
  h_corr_ELECTRONS[11]->SetBinContent(15,0.96604 );
  h_corr_ELECTRONS[11]->SetBinContent(17,0.94535 );
  h_corr_ELECTRONS[11]->SetBinContent(19,0.940475 );
  h_corr_ELECTRONS[11]->SetBinContent(21,0.9201 );
  h_corr_ELECTRONS[11]->SetBinContent(23,0.943919 );
  h_corr_ELECTRONS[11]->SetBinContent(25,0.92384 );
  h_corr_ELECTRONS[11]->SetBinContent(27,0.95076 );
  h_corr_ELECTRONS[11]->SetBinContent(29,0.904529 );
  h_corr_ELECTRONS[11]->SetBinContent(31,0.897547 );
  h_corr_ELECTRONS[11]->SetBinContent(33,0.868972 );
  h_corr_ELECTRONS[11]->SetBinContent(35,0.818965 );

  h_corr_ELECTRONS[12]->SetBinContent(1,0.990751 );
  h_corr_ELECTRONS[12]->SetBinContent(3,0.991295 );
  h_corr_ELECTRONS[12]->SetBinContent(5,0.988907 );
  h_corr_ELECTRONS[12]->SetBinContent(7,0.985201 );
  h_corr_ELECTRONS[12]->SetBinContent(9,0.982325 );
  h_corr_ELECTRONS[12]->SetBinContent(11,0.979082 );
  h_corr_ELECTRONS[12]->SetBinContent(13,0.970264 );
  h_corr_ELECTRONS[12]->SetBinContent(15,0.966628 );
  h_corr_ELECTRONS[12]->SetBinContent(17,0.952817 );
  h_corr_ELECTRONS[12]->SetBinContent(19,0.9342 );
  h_corr_ELECTRONS[12]->SetBinContent(21,0.9201 );
  h_corr_ELECTRONS[12]->SetBinContent(23,0.943919 );
  h_corr_ELECTRONS[12]->SetBinContent(25,0.92384 );
  h_corr_ELECTRONS[12]->SetBinContent(27,0.95076 );
  h_corr_ELECTRONS[12]->SetBinContent(29,0.904529 );
  h_corr_ELECTRONS[12]->SetBinContent(31,0.897547 );
  h_corr_ELECTRONS[12]->SetBinContent(33,0.868972 );
  h_corr_ELECTRONS[12]->SetBinContent(35,0.818965 );

  h_corr_ELECTRONS[13]->SetBinContent(1,0.991375 );
  h_corr_ELECTRONS[13]->SetBinContent(3,0.990764 );
  h_corr_ELECTRONS[13]->SetBinContent(5,0.98988 );
  h_corr_ELECTRONS[13]->SetBinContent(7,0.986238 );
  h_corr_ELECTRONS[13]->SetBinContent(9,0.98494 );
  h_corr_ELECTRONS[13]->SetBinContent(11,0.979488 );
  h_corr_ELECTRONS[13]->SetBinContent(13,0.974038 );
  h_corr_ELECTRONS[13]->SetBinContent(15,0.975949 );
  h_corr_ELECTRONS[13]->SetBinContent(17,0.927693 );
  h_corr_ELECTRONS[13]->SetBinContent(19,0.9342 );
  h_corr_ELECTRONS[13]->SetBinContent(21,0.9201 );
  h_corr_ELECTRONS[13]->SetBinContent(23,0.943919 );
  h_corr_ELECTRONS[13]->SetBinContent(25,0.92384 );
  h_corr_ELECTRONS[13]->SetBinContent(27,0.95076 );
  h_corr_ELECTRONS[13]->SetBinContent(29,0.904529 );
  h_corr_ELECTRONS[13]->SetBinContent(31,0.897547 );
  h_corr_ELECTRONS[13]->SetBinContent(33,0.868972 );
  h_corr_ELECTRONS[13]->SetBinContent(35,0.818965 );
  */


  /*
  // new 610
  h_CBET_EB_PHOTONS    = new TH1F("h_CBET_EB_PHOTONS"    ,"h_CBET_EB_PHOTONS"    ,nBinsET*2-1, ETBins); 
  h_CBET_EB_PHOTONS->SetBinContent(1, 1); 	  
  h_CBET_EB_PHOTONS->SetBinContent(3, 1.00303);   
  h_CBET_EB_PHOTONS->SetBinContent(5, 1.00119);   
  h_CBET_EB_PHOTONS->SetBinContent(7, 1.00117);   
  h_CBET_EB_PHOTONS->SetBinContent(9, 1.00021);   
  h_CBET_EB_PHOTONS->SetBinContent(11, 1.00035);  
  h_CBET_EB_PHOTONS->SetBinContent(13, 1.00014);  
  h_CBET_EB_PHOTONS->SetBinContent(15, 1.00005); // CRAZY FIT FIXED BY HAND  
  h_CBET_EB_PHOTONS->SetBinContent(17, 0.99996);  
  h_CBET_EB_PHOTONS->SetBinContent(19, 0.999874); 
  h_CBET_EB_PHOTONS->SetBinContent(21, 0.999847); 
  h_CBET_EB_PHOTONS->SetBinContent(23, 0.999819); 
  h_CBET_EB_PHOTONS->SetBinContent(25, 0.999608); 

  h_CBET_EE_PHOTONS    = new TH1F("h_CBET_EE_PHOTONS"    ,"h_CBET_EE_PHOTONS"    ,nBinsET*2-1, ETBins); 
  h_CBET_EE_PHOTONS->SetBinContent(1, 1); 	 
  h_CBET_EE_PHOTONS->SetBinContent(3, 0.996547);  
  h_CBET_EE_PHOTONS->SetBinContent(5, 0.995308); 
  h_CBET_EE_PHOTONS->SetBinContent(7, 0.99712);  
  h_CBET_EE_PHOTONS->SetBinContent(9, 0.99693);  
  h_CBET_EE_PHOTONS->SetBinContent(11, 0.997823); 
  h_CBET_EE_PHOTONS->SetBinContent(13, 0.998411); 
  h_CBET_EE_PHOTONS->SetBinContent(15, 0.998947); 
  h_CBET_EE_PHOTONS->SetBinContent(17, 0.999935); 
  h_CBET_EE_PHOTONS->SetBinContent(19, 1.00044); 
  h_CBET_EE_PHOTONS->SetBinContent(21, 1.00131); 
  h_CBET_EE_PHOTONS->SetBinContent(23, 1.00186); 
  h_CBET_EE_PHOTONS->SetBinContent(25, 1.0027);  
  */
  h_CBE_EB_PHOTONS    = new TH1F("h_CBE_EB_PHOTONS"    ,"h_CBE_EB_PHOTONS"    ,nBinsE*2-1, EBins); 
  h_CBE_EB_PHOTONS->SetBinContent(1, 1.00232); 	    
  h_CBE_EB_PHOTONS->SetBinContent(3, 1.00052); 	    
  h_CBE_EB_PHOTONS->SetBinContent(5, 1.00057); 	    
  h_CBE_EB_PHOTONS->SetBinContent(7, 1.00033); 	    
  h_CBE_EB_PHOTONS->SetBinContent(9, 0.999998);     
  h_CBE_EB_PHOTONS->SetBinContent(11, 0.999642);    
  h_CBE_EB_PHOTONS->SetBinContent(13, 1.00013);     
  h_CBE_EB_PHOTONS->SetBinContent(15, 0.999744);    
  h_CBE_EB_PHOTONS->SetBinContent(17, 0.999726);    
  h_CBE_EB_PHOTONS->SetBinContent(19, 0.999707);    
  h_CBE_EB_PHOTONS->SetBinContent(21, 1.00008);     
  h_CBE_EB_PHOTONS->SetBinContent(23, 1.00028);     
  h_CBE_EB_PHOTONS->SetBinContent(25, 1.00046);     
  h_CBE_EB_PHOTONS->SetBinContent(27, 0.999905);    
  h_CBE_EB_PHOTONS->SetBinContent(29, 1.00014);     
  h_CBE_EB_PHOTONS->SetBinContent(31, 1.00029);     
  h_CBE_EB_PHOTONS->SetBinContent(33, 0.999585);    
  h_CBE_EB_PHOTONS->SetBinContent(35, 1.00085);     
  h_CBE_EB_PHOTONS->SetBinContent(37, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(39, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(41, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(43, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(45, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(47, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(49, 1); 	    
  h_CBE_EB_PHOTONS->SetBinContent(51, 1);           
  /*

  h_CBE_EE_PHOTONS    = new TH1F("h_CBE_EE_PHOTONS"    ,"h_CBE_EE_PHOTONS"    ,nBinsE*2-1, EBins); 
  h_CBE_EE_PHOTONS->SetBinContent(1, 1); 	 
  h_CBE_EE_PHOTONS->SetBinContent(3, 0.992836);  
  h_CBE_EE_PHOTONS->SetBinContent(5, 0.996175);  
  h_CBE_EE_PHOTONS->SetBinContent(7, 0.994136);  
  h_CBE_EE_PHOTONS->SetBinContent(9, 0.996067);  
  h_CBE_EE_PHOTONS->SetBinContent(11, 0.995012); 
  h_CBE_EE_PHOTONS->SetBinContent(13, 0.996377); 
  h_CBE_EE_PHOTONS->SetBinContent(15, 0.997417); 
  h_CBE_EE_PHOTONS->SetBinContent(17, 0.997449); 
  h_CBE_EE_PHOTONS->SetBinContent(19, 0.998589); 
  h_CBE_EE_PHOTONS->SetBinContent(21, 0.998367); 
  h_CBE_EE_PHOTONS->SetBinContent(23, 0.99895);  
  h_CBE_EE_PHOTONS->SetBinContent(25, 0.998895); 
  h_CBE_EE_PHOTONS->SetBinContent(27, 1.00053);  
  h_CBE_EE_PHOTONS->SetBinContent(29, 0.999709); 
  h_CBE_EE_PHOTONS->SetBinContent(31, 1.00063);  
  h_CBE_EE_PHOTONS->SetBinContent(33, 1.00045);  
  h_CBE_EE_PHOTONS->SetBinContent(35, 1.00059);  
  h_CBE_EE_PHOTONS->SetBinContent(37, 1.00071);  
  h_CBE_EE_PHOTONS->SetBinContent(39, 1.00192);  
  h_CBE_EE_PHOTONS->SetBinContent(41, 1.0019); 	 
  h_CBE_EE_PHOTONS->SetBinContent(43, 1.00332);  
  h_CBE_EE_PHOTONS->SetBinContent(45, 1.00263);  
  h_CBE_EE_PHOTONS->SetBinContent(47, 1.00316);  
  h_CBE_EE_PHOTONS->SetBinContent(49, 0.999199); 
  h_CBE_EE_PHOTONS->SetBinContent(51, 1.00046);  
  

  h_CBET_EB_ELECTRONS    = new TH1F("h_CBET_EB_ELECTRONS"    ,"h_CBET_EB_ELECTRONS"    ,nBinsET*2-1, ETBins); 
  h_CBET_EB_ELECTRONS->SetBinContent(1, 0.974329); 
  h_CBET_EB_ELECTRONS->SetBinContent(3, 0.992527); 
  h_CBET_EB_ELECTRONS->SetBinContent(5, 0.996456); 
  h_CBET_EB_ELECTRONS->SetBinContent(7, 0.997728); 
  h_CBET_EB_ELECTRONS->SetBinContent(9, 0.999039); 
  h_CBET_EB_ELECTRONS->SetBinContent(11, 0.999084);
  h_CBET_EB_ELECTRONS->SetBinContent(13, 0.999814);
  h_CBET_EB_ELECTRONS->SetBinContent(15, 1.00002); 
  h_CBET_EB_ELECTRONS->SetBinContent(17, 1.00009); 
  h_CBET_EB_ELECTRONS->SetBinContent(19, 1.0002);  
  h_CBET_EB_ELECTRONS->SetBinContent(21, 1.00031); 
  h_CBET_EB_ELECTRONS->SetBinContent(23, 1.00046); 
  h_CBET_EB_ELECTRONS->SetBinContent(25, 1.00032); 
  
  h_CBET_EE_ELECTRONS    = new TH1F("h_CBET_EE_ELECTRONS"    ,"h_CBET_EE_ELECTRONS"    ,nBinsET*2-1, ETBins); 
  h_CBET_EE_ELECTRONS->SetBinContent(1, 0.94162);  
  h_CBET_EE_ELECTRONS->SetBinContent(3, 0.976471);  
  h_CBET_EE_ELECTRONS->SetBinContent(5, 0.985092); 
  h_CBET_EE_ELECTRONS->SetBinContent(7, 0.990078); 
  h_CBET_EE_ELECTRONS->SetBinContent(9, 0.992357); 
  h_CBET_EE_ELECTRONS->SetBinContent(11, 0.994591); 
  h_CBET_EE_ELECTRONS->SetBinContent(13, 0.997071); 
  h_CBET_EE_ELECTRONS->SetBinContent(15, 0.999214); 
  h_CBET_EE_ELECTRONS->SetBinContent(17, 1.00025); 
  h_CBET_EE_ELECTRONS->SetBinContent(19, 1.00125); 
  h_CBET_EE_ELECTRONS->SetBinContent(21, 1.00212); 
  h_CBET_EE_ELECTRONS->SetBinContent(23, 1.00272); 
  h_CBET_EE_ELECTRONS->SetBinContent(25, 1.00291); 
  */  
  h_CBE_EB_ELECTRONS    = new TH1F("h_CBE_EB_ELECTRONS"    ,"h_CBE_EB_ELECTRONS"    ,nBinsE*2-1, EBins); 
  h_CBE_EB_ELECTRONS->SetBinContent(1, 0.992169);   
  h_CBE_EB_ELECTRONS->SetBinContent(3, 0.998226);   
  h_CBE_EB_ELECTRONS->SetBinContent(5, 0.999316);   
  h_CBE_EB_ELECTRONS->SetBinContent(7, 0.999764);   
  h_CBE_EB_ELECTRONS->SetBinContent(9, 1.00022); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(11, 1.00028);   
  h_CBE_EB_ELECTRONS->SetBinContent(13, 0.999973);  
  h_CBE_EB_ELECTRONS->SetBinContent(15, 1.00006);   
  h_CBE_EB_ELECTRONS->SetBinContent(17, 1.00012);   
  h_CBE_EB_ELECTRONS->SetBinContent(19, 1.00035);   
  h_CBE_EB_ELECTRONS->SetBinContent(21, 1.00069);   
  h_CBE_EB_ELECTRONS->SetBinContent(23, 1.00106);   
  h_CBE_EB_ELECTRONS->SetBinContent(25, 1.00154);   
  h_CBE_EB_ELECTRONS->SetBinContent(27, 1.00139);   
  h_CBE_EB_ELECTRONS->SetBinContent(29, 1.00177);   
  h_CBE_EB_ELECTRONS->SetBinContent(31, 1.00158);   
  h_CBE_EB_ELECTRONS->SetBinContent(33, 1.00132);   
  h_CBE_EB_ELECTRONS->SetBinContent(35, 1.00079);   
  h_CBE_EB_ELECTRONS->SetBinContent(37, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(39, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(41, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(43, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(45, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(47, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(49, 1); 	  
  h_CBE_EB_ELECTRONS->SetBinContent(51, 1);         
  /*
  h_CBE_EE_ELECTRONS    = new TH1F("h_CBE_EE_ELECTRONS"    ,"h_CBE_EE_ELECTRONS"    ,nBinsE*2-1, EBins); 
  h_CBE_EE_ELECTRONS->SetBinContent(1, 0.882783);  
  h_CBE_EE_ELECTRONS->SetBinContent(3, 0.942349);  
  h_CBE_EE_ELECTRONS->SetBinContent(5, 0.968664);  
  h_CBE_EE_ELECTRONS->SetBinContent(7, 0.979249);  
  h_CBE_EE_ELECTRONS->SetBinContent(9, 0.98328); 	 
  h_CBE_EE_ELECTRONS->SetBinContent(11, 0.988222); 
  h_CBE_EE_ELECTRONS->SetBinContent(13, 0.990444); 
  h_CBE_EE_ELECTRONS->SetBinContent(15, 0.992744); 
  h_CBE_EE_ELECTRONS->SetBinContent(17, 0.994365); 
  h_CBE_EE_ELECTRONS->SetBinContent(19, 0.995717); 
  h_CBE_EE_ELECTRONS->SetBinContent(21, 0.996661); 
  h_CBE_EE_ELECTRONS->SetBinContent(23, 0.997681); 
  h_CBE_EE_ELECTRONS->SetBinContent(25, 0.999025); 
  h_CBE_EE_ELECTRONS->SetBinContent(27, 0.999434); 
  h_CBE_EE_ELECTRONS->SetBinContent(29, 0.999831); 
  h_CBE_EE_ELECTRONS->SetBinContent(31, 1.00012);  
  h_CBE_EE_ELECTRONS->SetBinContent(33, 1.00123);  
  h_CBE_EE_ELECTRONS->SetBinContent(35, 1.00111);  
  h_CBE_EE_ELECTRONS->SetBinContent(37, 1.00166);  
  h_CBE_EE_ELECTRONS->SetBinContent(39, 1.00189);  
  h_CBE_EE_ELECTRONS->SetBinContent(41, 1.00232);  
  h_CBE_EE_ELECTRONS->SetBinContent(43, 1.00238);  
  h_CBE_EE_ELECTRONS->SetBinContent(45, 1.00222);  
  h_CBE_EE_ELECTRONS->SetBinContent(47, 1.00245);  
  h_CBE_EE_ELECTRONS->SetBinContent(49, 1.00167);  
  h_CBE_EE_ELECTRONS->SetBinContent(51, 1.00091);  
  */

  leftET[0] =  5 ; 
  leftET[1] =  10 ; 
  leftET[2] =  20 ; 
  leftET[3] =  30 ; 
  leftET[4] =  40 ; 
  leftET[5] =  50 ; 
  leftET[6] =  60 ; 
  leftET[7] =  80 ; 
  leftET[8] =  100 ; 
  leftET[9] =  120 ; 
  leftET[10] =  140 ; 
  leftET[11] =  160 ; 
  leftET[12] =  180 ; 
  rightET[0] =  10 ; 
  rightET[1] =  20 ; 
  rightET[2] =  30 ; 
  rightET[3] =  40 ; 
  rightET[4] =  50 ; 
  rightET[5] =  60 ; 
  rightET[6] =  80 ; 
  rightET[7] =  100 ; 
  rightET[8] =  120 ; 
  rightET[9] =  140 ; 
  rightET[10] =  160 ; 
  rightET[11] =  180 ; 
  rightET[12] =  200 ; 
  ETBins[0] =  5 ; 
  ETBins[1] =  10 ; 
  ETBins[2] =  10 ; 
  ETBins[3] =  20 ; 
  ETBins[4] =  20 ; 
  ETBins[5] =  30 ; 
  ETBins[6] =  30 ; 
  ETBins[7] =  40 ; 
  ETBins[8] =  40 ; 
  ETBins[9] =  50 ; 
  ETBins[10] =  50 ; 
  ETBins[11] =  60 ; 
  ETBins[12] =  60 ; 
  ETBins[13] =  80 ; 
  ETBins[14] =  80 ; 
  ETBins[15] =  100 ; 
  ETBins[16] =  100 ; 
  ETBins[17] =  120 ; 
  ETBins[18] =  120 ; 
  ETBins[19] =  140 ; 
  ETBins[20] =  140 ; 
  ETBins[21] =  160 ; 
  ETBins[22] =  160 ; 
  ETBins[23] =  180 ; 
  ETBins[24] =  180 ; 
  ETBins[25] =  200 ; 



  leftE[0] =  0 ; 
  leftE[1] =  25 ; 
  leftE[2] =  50 ; 
  leftE[3] =  75 ; 
  leftE[4] =  100 ; 
  leftE[5] =  125 ; 
  leftE[6] =  150 ; 
  leftE[7] =  175 ; 
  leftE[8] =  200 ; 
  leftE[9] =  225 ; 
  leftE[10] =  250 ; 
  leftE[11] =  275 ; 
  leftE[12] =  300 ; 
  leftE[13] =  325 ; 
  leftE[14] =  350 ; 
  leftE[15] =  375 ; 
  leftE[16] =  400 ; 
  leftE[17] =  425 ; 
  leftE[18] =  450 ; 
  leftE[19] =  475 ; 
  leftE[20] =  500 ; 
  leftE[21] =  600 ; 
  leftE[22] =  700 ; 
  leftE[23] =  800 ; 
  leftE[24] =  900 ; 
  leftE[25] =  1000 ; 
  rightE[0] =  25 ; 
  rightE[1] =  50 ; 
  rightE[2] =  75 ; 
  rightE[3] =  100 ; 
  rightE[4] =  125 ; 
  rightE[5] =  150 ; 
  rightE[6] =  175 ; 
  rightE[7] =  200 ; 
  rightE[8] =  225 ; 
  rightE[9] =  250 ; 
  rightE[10] =  275 ; 
  rightE[11] =  300 ; 
  rightE[12] =  325 ; 
  rightE[13] =  350 ; 
  rightE[14] =  375 ; 
  rightE[15] =  400 ; 
  rightE[16] =  425 ; 
  rightE[17] =  450 ; 
  rightE[18] =  475 ; 
  rightE[19] =  500 ; 
  rightE[20] =  600 ; 
  rightE[21] =  700 ; 
  rightE[22] =  800 ; 
  rightE[23] =  900 ; 
  rightE[24] =  1000 ; 
  rightE[25] =  2000 ; 
  EBins[0] =  0 ; 
  EBins[1] =  25 ; 
  EBins[2] =  25 ; 
  EBins[3] =  50 ; 
  EBins[4] =  50 ; 
  EBins[5] =  75 ; 
  EBins[6] =  75 ; 
  EBins[7] =  100 ; 
  EBins[8] =  100 ; 
  EBins[9] =  125 ; 
  EBins[10] =  125 ; 
  EBins[11] =  150 ; 
  EBins[12] =  150 ; 
  EBins[13] =  175 ; 
  EBins[14] =  175 ; 
  EBins[15] =  200 ; 
  EBins[16] =  200 ; 
  EBins[17] =  225 ; 
  EBins[18] =  225 ; 
  EBins[19] =  250 ; 
  EBins[20] =  250 ; 
  EBins[21] =  275 ; 
  EBins[22] =  275 ; 
  EBins[23] =  300 ; 
  EBins[24] =  300 ; 
  EBins[25] =  325 ; 
  EBins[26] =  325 ; 
  EBins[27] =  350 ; 
  EBins[28] =  350 ; 
  EBins[29] =  375 ; 
  EBins[30] =  375 ; 
  EBins[31] =  400 ; 
  EBins[32] =  400 ; 
  EBins[33] =  425 ; 
  EBins[34] =  425 ; 
  EBins[35] =  450 ; 
  EBins[36] =  450 ; 
  EBins[37] =  475 ; 
  EBins[38] =  475 ; 
  EBins[39] =  500 ; 
  EBins[40] =  500 ; 
  EBins[41] =  600 ; 
  EBins[42] =  600 ; 
  EBins[43] =  700 ; 
  EBins[44] =  700 ; 
  EBins[45] =  800 ; 
  EBins[46] =  800 ; 
  EBins[47] =  900 ; 
  EBins[48] =  900 ; 
  EBins[49] =  1000 ; 
  EBins[50] =  1000 ; 
  EBins[51] =  2000 ; 





	Double_t EtaMin;
	Double_t EtaMax;
	Double_t R9Max;
Double_t BinsR9[2*nBinsR9];
	
	
	if (doEB){
		EtaMin = etaCrackMin*(-1);
		EtaMax = etaCrackMin;
	}
	if (doEE){
		EtaMin = -2.5;
		EtaMax = 2.5;
	}
	
	const Double_t binwidth_eta = (EtaMax - EtaMin) / ((Double_t)nBinsEtaEBEE);
	
	if (doEB) {
		R9Max = 0.94;
	}
	if (doEE){
		R9Max = 0.95;
	}
	
	BinsR9[0] = 0.;
	BinsR9[1] = 0.3;
	BinsR9[2] = 0.3;
	BinsR9[3] = 0.4;
	BinsR9[4] = 0.4;
	BinsR9[5] = 0.45;
	BinsR9[6] = 0.45;
	BinsR9[7] = 0.5;
	BinsR9[8] = 0.5;
	BinsR9[9] = 0.55;
	BinsR9[10] = 0.55;
	BinsR9[11] = 0.6;
	BinsR9[12] = 0.6;
	BinsR9[13] = 0.65;
	BinsR9[14] = 0.65;
	BinsR9[15] = 0.7;
	BinsR9[16] = 0.7;
	BinsR9[17] = 0.74;
	BinsR9[18] = 0.74;
	BinsR9[19] = 0.78;
	BinsR9[20] = 0.78;
	BinsR9[21] = 0.8;
	BinsR9[22] = 0.8;
	BinsR9[23] = 0.82;
	BinsR9[24] = 0.82;
	BinsR9[25] = 0.84;
	BinsR9[26] = 0.84;
	BinsR9[27] = 0.86;
	BinsR9[28] = 0.86;
	BinsR9[29] = 0.88;
	BinsR9[30] = 0.88;	
	BinsR9[31] = 0.9;
	BinsR9[32] = 0.9;		
	BinsR9[33] = 0.92;
	BinsR9[34] = 0.92;
	
	
	if (doEB){
		
		BinsR9[35] = 0.94;
	}
	if (doEE){
		BinsR9[35] = 0.95;
	}
	
	const Double_t binwidth_r9 = (R9Max - R9Min) / ((Double_t)nBinsR9);
	
	cout << "Initializing histograms for correction validation" <<endl;
	
	string sCorr;
	for (Int_t j = 0; j<nCorr; j++){
		
		
	  //		if (j==0) sCorr = "Raw";		
		if (j==1) sCorr = "Ceta";
//		if (j==3) sCorr = "ElecCMSSWnew";	
//		if (j==4) sCorr = "PhotonOldAFbremOnly";
//		if (j==5) sCorr = "PhotonOldAF";		
		if (j==2) sCorr = "PhotonNewETHbremetaOnly";
		if (j==3) sCorr = "PhotonNewETH";
		//if (j==8) sCorr = "PhotonNewETHbremetaOnlyEnergyScheme";
		if (j==4) sCorr = "PhotonNewETHEnergyScheme";		
		if (j==5) sCorr = "ElectronNewETHbremetaOnly";
		if (j==6) sCorr = "ElectronNewETH";
		//if (j==12) sCorr = "ElectronNewETHbremetaOnlyEnergyScheme";
		if (j==7) sCorr = "ElectronNewETHEnergyScheme";				
		if (j==8) sCorr = "DefaultCorrEnergy";
//		if (j==12) sCorr = "ElectronNewETH2x2D";
//		if (j==13) sCorr = "PhotonNewETH2x2D";
		
		//if (j==0) sCorr = "PhotonNewETHbremetaOnly";	
		
		//Pt
		for (Int_t i = 0; i<nBinsPt; ++i){
			h_ErecEgen_pt[j][i] = new TH1F(Form("h_ErecEgen_pt_%d_%d",j,i),Form("h_ErecEgen_pt_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string PtMeanTitle = "ErecEgenMean_vsPt"+sCorr;
		string PtSigmaTitle = "ErecEgenSigmaEff_vsPt"+sCorr;
		ErecEgenMean_vsPt[j] = new TH1F(PtMeanTitle.c_str(),PtMeanTitle.c_str(),nBinsPt,PtMin,PtMax);
		ErecEgenSigmaEff_vsPt[j] = new TH1F(PtSigmaTitle.c_str(),PtSigmaTitle.c_str(),nBinsPt,PtMin,PtMax);
		
		//Eta
		for (Int_t i = 0; i<nBinsEtaEBEE; ++i){
			h_ErecEgen_eta[j][i] = new TH1F(Form("h_ErecEgen_eta_%d_%d",j,i),Form("h_ErecEgen_eta_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string EtaMeanTitle = "ErecEgenMean_vsEta"+sCorr;
		string EtaSigmaTitle = "ErecEgenSigmaEff_vsEta"+sCorr;
		ErecEgenMean_vsEta[j] = new TH1F(EtaMeanTitle.c_str(),EtaMeanTitle.c_str(),nBinsEtaEBEE,EtaMin,EtaMax);
		ErecEgenSigmaEff_vsEta[j] = new TH1F(EtaSigmaTitle.c_str(),EtaSigmaTitle.c_str(),nBinsEtaEBEE,EtaMin,EtaMax);
		
		//Phi
		for (Int_t i = 0; i<nBinsPhi; ++i){
			h_ErecEgen_phi[j][i] = new TH1F(Form("h_ErecEgen_phi_%d_%d",j,i),Form("h_ErecEgen_phi_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string PhiMeanTitle = "ErecEgenMean_vsPhi"+sCorr;
		string PhiSigmaTitle = "ErecEgenSigmaEff_vsPhi"+sCorr;
		ErecEgenMean_vsPhi[j] = new TH1F(PhiMeanTitle.c_str(),PhiMeanTitle.c_str(),nBinsPhi,PhiMin,PhiMax);
		ErecEgenSigmaEff_vsPhi[j] = new TH1F(PhiSigmaTitle.c_str(),PhiSigmaTitle.c_str(),nBinsPhi,PhiMin,PhiMax);
		
		//Brem
		for (Int_t i = 0; i<nBinsBrem; ++i){
			h_ErecEgen_brem[j][i] = new TH1F(Form("h_ErecEgen_brem_%d_%d",j,i),Form("h_ErecEgen_brem_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string BremMeanTitle = "ErecEgenMean_vsBrem"+sCorr;
		string BremSigmaTitle = "ErecEgenSigmaEff_vsBrem"+sCorr;
		ErecEgenMean_vsBrem[j] = new TH1F(BremMeanTitle.c_str(),BremMeanTitle.c_str(),nBinsBrem,BremMin,BremMax);
		ErecEgenSigmaEff_vsBrem[j] = new TH1F(BremSigmaTitle.c_str(),BremSigmaTitle.c_str(),nBinsBrem,BremMin,BremMax);
		
		//R9
		for (Int_t i = 0; i<nBinsR9; ++i){
			h_ErecEgen_r9[j][i] = new TH1F(Form("h_ErecEgen_r9_%d_%d",j,i),Form("h_ErecEgen_r9_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string R9MeanTitle = "ErecEgenMean_vsR9"+sCorr;
		string R9SigmaTitle = "ErecEgenSigmaEff_vsR9"+sCorr;
		//ErecEgenMean_vsR9[j] = new TH1F(R9Title.c_str(),R9Title.c_str(),nBinsR9,R9Min,R9Max);
		//ErecEgenMean_vsR9[j]->SetBins(2*nBinsR9-1, BinsR9);
		ErecEgenMean_vsR9[j] = new TH1F(R9MeanTitle.c_str(),R9MeanTitle.c_str(),2*nBinsR9-1,BinsR9);
		ErecEgenSigmaEff_vsR9[j] = new TH1F(R9SigmaTitle.c_str(),R9SigmaTitle.c_str(),2*nBinsR9-1,BinsR9);
		
		//Energy
		for (Int_t i = 0; i<nBinsEnergy; ++i){
			h_ErecEgen_energy[j][i] = new TH1F(Form("h_ErecEgen_energy_%d_%d",j,i),Form("h_ErecEgen_energy_%d_%d",j,i),nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		}
		string EnergyMeanTitle = "ErecEgenMean_vsEnergy"+sCorr;
		string EnergySigmaTitle = "ErecEgenSigmaEff_vsEnergy"+sCorr;
		ErecEgenMean_vsEnergy[j] = new TH1F(EnergyMeanTitle.c_str(),EnergyMeanTitle.c_str(),nBinsEnergy,EnergyMin,EnergyMax);
		ErecEgenSigmaEff_vsEnergy[j] = new TH1F(EnergySigmaTitle.c_str(),EnergySigmaTitle.c_str(),nBinsEnergy,EnergyMin,EnergyMax);
		
	}
	
	
	
	cout << "initHistograms(): done" << endl;
	
	
	
	
//   In a ROOT session, you can do:
//      Root > .L compareSCcorrections.C
//      Root > compareSCcorrections t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
	
	
	
	initHistograms();
	
	// Loop over all entries
	if (fChain == 0) return;
	fChain->SetBranchStatus("*",0);
	fChain->SetBranchStatus("event_coll_size",1);
	/*
	fChain->SetBranchStatus("mcE"           ,1);
	fChain->SetBranchStatus("mcEta"         ,1);
	fChain->SetBranchStatus("mcPhi"         ,1);
	
	if (partType == "photon"){
		fChain->SetBranchStatus("phoSCEta"      ,1); 
		fChain->SetBranchStatus("phoSCPhi"      ,1); 
		fChain->SetBranchStatus("phoCetaCorrE"  ,1); 
		fChain->SetBranchStatus("phoCetaCorrEt" ,1); 
		fChain->SetBranchStatus("phoFullCorrE" ,1); 	
		fChain->SetBranchStatus("phoE" ,1); 	
		fChain->SetBranchStatus("phoSCRawE" ,1); 	
		fChain->SetBranchStatus("phoSCBrem"     ,1); 
		fChain->SetBranchStatus("phoR9"         ,1);  
	}
	else if (partType == "electron"){
		fChain->SetBranchStatus("eleSCEta"        ,1);        
		fChain->SetBranchStatus("eleSCPhi"        ,1);        
		fChain->SetBranchStatus("eleCetaCorrE"  ,1);  
		fChain->SetBranchStatus("eleCetaCorrEt" ,1); 
		fChain->SetBranchStatus("eleFullCorrE",1);
		fChain->SetBranchStatus("eleEn",1);
		fChain->SetBranchStatus("eleSCRawEn",1);
		fChain->SetBranchStatus("eleBrLinear"   ,1);   
		fChain->SetBranchStatus("eleE3x3"       ,1);
	}
	*/
	fChain->SetBranchStatus("phoSC_GeomEta"      ,1); 
	fChain->SetBranchStatus("phoSC_GeomPhi"      ,1); 
	fChain->SetBranchStatus("phoSC_correctedenergy"  ,1); 
	fChain->SetBranchStatus("phoSC_RawEnergyCetaCorr"  ,1); 
	fChain->SetBranchStatus("phoSC_RawEtCetaCorr" ,1); 
	fChain->SetBranchStatus("pho_Brem"     ,1); 
	fChain->SetBranchStatus("phoSC_r9"         ,1);       
	fChain->SetBranchStatus("GenEnergy"           ,1);
	fChain->SetBranchStatus("GenEta"         ,1);
	fChain->SetBranchStatus("GenPhi"         ,1);
	fChain->SetBranchStatus("pho_e3x3"       ,1);
	fChain->SetBranchStatus("phoSC_RawEnergy"    ,1);	
	

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
	   
	  if (jentry % 100000 == 0)  cout << jentry << endl;
	   
//	   // Loop over the reconstructed objects (electrons or photons)
//	   Int_t nobj = 0;
//	   if      (partType == "electron") nobj = nEle;
//	   else if (partType == "photon"  ) nobj = nPho;
//	   
//	   // skip pathological events
//	   if (nobj < 1 || nobj > 2) continue;
	  if (event_coll_size!=2) continue;
	  Int_t nobj=1;
	   
	   for (Int_t iobj = 0; iobj < nobj; ++iobj) {
		   
		   Double_t nt_em_eta        = 0;     
		   Double_t nt_em_phi        = 0;
		   Double_t nt_emCorrEta_e   = 0;
		   Double_t nt_emCorrEta_et  = 0;
		   Double_t nt_emFullCorr_e   = 0;		
		   Double_t nt_emDefault_e   = 0;	
		   Double_t nt_emRaw_e      = 0;
		   Double_t nt_em_br1        = 0;
		   Double_t nt_em_r9         = 0;
		   Double_t nt_mc_e	        = 0; 
		   
		   // Use the correct naming of your ntuple                                                                                                                                                                                                                
		   if (partType == "photon"){
		     nt_em_eta        = phoSC_GeomEta;
		     nt_em_phi        = phoSC_GeomPhi;
		     nt_emCorrEta_e   = phoSC_RawEnergyCetaCorr;
		     nt_emCorrEta_et  = phoSC_RawEtCetaCorr;
		     nt_em_br1        = pho_Brem;
		     nt_em_r9         = phoSC_r9;
		     nt_mc_e          = GenEnergy;
		   }
		   else if (partType == "electron"){
		     nt_em_eta        = phoSC_GeomEta;
		     nt_em_phi        = phoSC_GeomPhi;
		     nt_emCorrEta_e   = phoSC_RawEnergyCetaCorr;
		     nt_emCorrEta_et  = phoSC_RawEtCetaCorr;
		     nt_em_br1        = pho_Brem;
		     if ( phoSC_RawEnergyCetaCorr != 0) nt_em_r9 = pho_e3x3/phoSC_RawEnergy;
		     nt_mc_e          = GenEnergy;
		   }
		   nt_emDefault_e = phoSC_correctedenergy;

		   
		   Double_t fiducialPhiCut = 2.; // degrees around the crack
		   Double_t minETCut       = 5.; // pt>5 needed for electrons
		   
		   //Cinematique
		   Double_t theta = 2.*TMath::ATan(TMath::Exp(-nt_em_eta));
		   //cout << "Raw theta = " << theta << endl;
		   Double_t rawEt = nt_emRaw_e * TMath::Sin(theta);
		   //cout << "Raw energy = " << phoSCRawE[iobj] << endl;
		   //cout << "Raw et = " << rawEt << endl;
		   
		   //if (!(doEB && fabs(nt_em_eta) < etaCrackMin) || !(doEE && fabs(nt_em_eta) > etaCrackMax)) continue;
		   //cout << "Et="<<nt_emCorrEta_et<<" R9="<<nt_em_r9<<" eta="<<nt_em_eta <<endl;
		   
		   if ( // select showering objects
			   
			   // low ET at very high eta can have very large energy: apply the 5 GeV ET cut ?
			   //rawEt > minETCut    &&
			   nt_emCorrEta_et > minETCut    &&
			   nt_emCorrEta_et < PtMax       &&
			   
			   //fabs(nt_em_eta) > etaCrackMax &&
			   ((doEB && fabs(nt_em_eta) < etaCrackMin) 
				//|| (doEE && fabs(nt_em_eta) > etaCrackMax)) &&
				|| (doEE && fabs(nt_em_eta) > etaCrackMax && fabs(nt_em_eta) < 2.5)) &&
				//|| (doDeriveCorr && fabs(nt_em_eta) > 0 && fabs(nt_em_eta) < 2.5))  &&
			   
			   //R9 cut
			   ((partType == "photon" && ((doEB && nt_em_r9 < 0.94) || (doEE && nt_em_r9 < 0.95))) || partType == "electron" ) &&
			   //((doEB && nt_em_r9 < 0.94) || (doEE && nt_em_r9 < 0.94))           &&			   
			   
			   			   
			   // remove the phi gaps between the super modules: local corrections will take care of them
			   !isInPhiCracks(nt_em_phi, nt_em_eta, fiducialPhiCut)
			   && !isInEtaCracks(nt_em_eta)
			   ){ 
			   
			   //cout << "SC C(eta) corr energy = " << nt_emCorrEta_e << endl;
		   
			   
			   
			   //ETH diphoton
			   Double_t corrbremeta =  applyScCorrectionsBrEta_PHOTONS(nt_em_eta, nt_em_br1);
			   Double_t energyPhotonCorrETHbremeta = nt_emCorrEta_e / corrbremeta;
			   Double_t etPhotonCorrETHbremeta = energyPhotonCorrETHbremeta * TMath::Sin(theta);
			   Double_t corr = 1;// = applyScCorrections(nt_em_eta, nt_em_br1, nt_emCorrEta_et);
			   if (fabs(nt_em_eta) < etaCrackMin) corr = corrbremeta * applyScCorrectionsET_EB_PHOTONS(etPhotonCorrETHbremeta);
			   if (fabs(nt_em_eta) > etaCrackMax && fabs(nt_em_eta) < 2.5) corr = corrbremeta * applyScCorrectionsET_EE_PHOTONS(etPhotonCorrETHbremeta);
			   Double_t energyPhotonCorrETH = nt_emCorrEta_e / corr;
			   
			   //ETH diphoton energy
			   //Double_t corrbremeta_phot_EnergyScheme =  applyScCorrectionsBrEta_PHOTON_Energy(nt_em_eta, nt_em_br1);
			   Double_t corrbremeta_phot_EnergyScheme =  corrbremeta;
			   Double_t energyPhotonCorrETHbremeta_phot_EnergyScheme = nt_emCorrEta_e / corrbremeta;
			   Double_t etPhotonCorrETHbremeta_phot_EnergyScheme = energyPhotonCorrETHbremeta_phot_EnergyScheme * TMath::Sin(theta);
			   Double_t corr_phot_EnergyScheme = 1;// = applyScCorrections(nt_em_eta, nt_em_br1, nt_emCorrEta_et);
			   if (fabs(nt_em_eta) < etaCrackMin) corr_phot_EnergyScheme = corrbremeta_phot_EnergyScheme * applyScCorrectionsE_EB_PHOTONS(energyPhotonCorrETHbremeta_phot_EnergyScheme);
			   if (fabs(nt_em_eta) > etaCrackMax && fabs(nt_em_eta) < 2.5) corr_phot_EnergyScheme = corrbremeta_phot_EnergyScheme * applyScCorrectionsE_EE_PHOTONS(energyPhotonCorrETHbremeta_phot_EnergyScheme);
			   Double_t energyPhotonCorrETH_phot_EnergyScheme = nt_emCorrEta_e / corr_phot_EnergyScheme;
			   
//			   //ETH dielectron et, no R9
			   Double_t corrbremeta_elec =  applyScCorrectionsBrEta_ELECTRONS(nt_em_eta, nt_em_br1);
			   Double_t energyElectronCorrETHbremeta = nt_emCorrEta_e / corrbremeta_elec;
			   Double_t etElectronCorrETHbremeta = energyElectronCorrETHbremeta * TMath::Sin(theta);
			   Double_t corr_elec = 1;
			   if (fabs(nt_em_eta) < etaCrackMin) corr_elec = corrbremeta_elec * applyScCorrectionsET_EB_ELECTRONS(etElectronCorrETHbremeta);
			   if (fabs(nt_em_eta) > etaCrackMax && fabs(nt_em_eta) < 2.5) corr_elec = corrbremeta_elec * applyScCorrectionsET_EE_ELECTRONS(etElectronCorrETHbremeta);
			   //Double_t corr_elec = applyScCorrections_ELECTRONS(nt_em_eta, nt_em_br1, nt_emCorrEta_et);
			   Double_t energyElectronCorrETH = nt_emCorrEta_e / corr_elec;			   
			   
			   //ETH dielectron energy, no R9
			   //Double_t corrbremeta_elec_EnergyScheme =  applyScCorrectionsBrEta_ELECTRON_EnergyNoR9(nt_em_eta, nt_em_br1);
			   Double_t corrbremeta_elec_EnergyScheme =  corrbremeta_elec;
			   Double_t energyElectronCorrETHbremeta_EnergyScheme = nt_emCorrEta_e / corrbremeta_elec_EnergyScheme;
			   Double_t etElectronCorrETHbremeta_energy_EnergyScheme = energyElectronCorrETHbremeta_EnergyScheme * TMath::Sin(theta);
			   Double_t corr_elec_EnergyScheme = 1;
			   if (fabs(nt_em_eta) < etaCrackMin) corr_elec_EnergyScheme = corrbremeta_elec_EnergyScheme * applyScCorrectionsE_EB_ELECTRONS(energyElectronCorrETHbremeta_EnergyScheme);
			   if (fabs(nt_em_eta) > etaCrackMax && fabs(nt_em_eta) < 2.5) corr_elec_EnergyScheme = corrbremeta_elec_EnergyScheme * applyScCorrectionsE_EE_ELECTRONS(energyElectronCorrETHbremeta_EnergyScheme);
			   //Double_t corr_elec = applyScCorrections_ELECTRONS(nt_em_eta, nt_em_br1, nt_emCorrEta_et);
			   Double_t energyElectronCorrETH_EnergyScheme = nt_emCorrEta_e / corr_elec_EnergyScheme;			   
			   
			   
			   //Pt
			   //Int_t ipt = (Int_t)((rawEt-PtMin) / binwidth_pt );
			   Int_t ipt = (Int_t)((nt_emCorrEta_et-PtMin) / binwidth_pt );
			   //Int_t ipt = (Int_t)((etElectronCorrETHbremeta-PtMin) / binwidth_pt );
			   //if (fabs(nt_em_eta) < etaCrackMin) cout << "pt="<<nt_emCorrEta_et <<" ipt="<<ipt<< " r9="<<nt_em_r9<<" corr="<<applyScCorrectionsET_EB_ELECTRON_ETNoR9(etElectronCorrETHbremeta)<<endl;
			   if (nt_emCorrEta_et>PtMin && nt_emCorrEta_et<PtMax) {
			   //if (etElectronCorrETHbremeta>PtMin && etElectronCorrETHbremeta<PtMax) {
  
				    h_ErecEgen_pt[0][ipt]->Fill(nt_emRaw_e / nt_mc_e);
				    h_ErecEgen_pt[1][ipt]->Fill(nt_emCorrEta_e / nt_mc_e);
				    h_ErecEgen_pt[8][ipt]->Fill(nt_emDefault_e / nt_mc_e);				   
//				    h_ErecEgen_pt[3][ipt]->Fill(nt_emFullCorr_e / nt_mc_e);
//				    h_ErecEgen_pt[4][ipt]->Fill(AFEbrem / nt_mc_e);
//				    h_ErecEgen_pt[5][ipt]->Fill(AFEcomplete / nt_mc_e);
				    h_ErecEgen_pt[2][ipt]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
		 		    h_ErecEgen_pt[3][ipt]->Fill(energyPhotonCorrETH / nt_mc_e);
				    //h_ErecEgen_pt[8][ipt]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_pt[4][ipt]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_pt[5][ipt]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_pt[6][ipt]->Fill(energyElectronCorrETH / nt_mc_e);
				    //h_ErecEgen_pt[12][ipt]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				    h_ErecEgen_pt[7][ipt]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				    h_ErecEgen_pt[12][ipt]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				    h_ErecEgen_pt[13][ipt]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
				    h_ErecEgen_pt[10][ipt]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_pt[11][ipt]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				    h_ErecEgen_pt[12][ipt]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_pt[13][ipt]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
*/
				   //h_ErecEgen_pt[0][ipt]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
			   }
			   
			   //cout << "B"<<endl;
			   
			   //Eta
			   Int_t ieta = (Int_t)((nt_em_eta-EtaMin) / binwidth_eta );
			   //cout << "ieta="<<ieta<<endl;
			   if (nt_em_eta>EtaMin && nt_em_eta<EtaMax) {
					h_ErecEgen_eta[0][ieta]->Fill(nt_emRaw_e / nt_mc_e);
					h_ErecEgen_eta[1][ieta]->Fill(nt_emCorrEta_e / nt_mc_e);
					h_ErecEgen_eta[8][ieta]->Fill(nt_emDefault_e / nt_mc_e);	
//					h_ErecEgen_eta[3][ieta]->Fill(nt_emFullCorr_e / nt_mc_e);
//				    h_ErecEgen_eta[4][ieta]->Fill(AFEbrem / nt_mc_e);
//					h_ErecEgen_eta[5][ieta]->Fill(AFEcomplete / nt_mc_e);
					h_ErecEgen_eta[2][ieta]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_eta[3][ieta]->Fill(energyPhotonCorrETH / nt_mc_e);
				    //h_ErecEgen_eta[8][ieta]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_eta[4][ieta]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_eta[5][ieta]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_eta[6][ieta]->Fill(energyElectronCorrETH / nt_mc_e);
				    //h_ErecEgen_eta[12][ieta]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				    h_ErecEgen_eta[7][ieta]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				    h_ErecEgen_eta[12][ieta]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				    h_ErecEgen_eta[13][ieta]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
				    h_ErecEgen_eta[10][ieta]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_eta[11][ieta]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				    h_ErecEgen_eta[12][ieta]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_eta[13][ieta]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
					*/
			   }
			   
			   //cout << "C"<<endl;
			   
			   //Phi
			   Int_t iphi = (Int_t)((nt_em_phi-PhiMin) / binwidth_phi );
			   //cout << "ieta="<<ieta<<endl;
			   if (nt_em_phi>PhiMin && nt_em_phi<PhiMax){
				    h_ErecEgen_phi[0][iphi]->Fill(nt_emRaw_e / nt_mc_e);
					h_ErecEgen_phi[1][iphi]->Fill(nt_emCorrEta_e / nt_mc_e);
					h_ErecEgen_phi[8][iphi]->Fill(nt_emDefault_e / nt_mc_e);	
//					h_ErecEgen_phi[3][iphi]->Fill(nt_emFullCorr_e / nt_mc_e);
//				    h_ErecEgen_phi[4][iphi]->Fill(AFEbrem / nt_mc_e);
//					h_ErecEgen_phi[5][iphi]->Fill(AFEcomplete / nt_mc_e);
				    h_ErecEgen_phi[2][iphi]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_phi[3][iphi]->Fill(energyPhotonCorrETH / nt_mc_e);
				    //h_ErecEgen_phi[8][iphi]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_phi[4][iphi]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_phi[5][iphi]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_phi[6][iphi]->Fill(energyElectronCorrETH / nt_mc_e);
				    //h_ErecEgen_phi[12][iphi]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				    h_ErecEgen_phi[7][iphi]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				    h_ErecEgen_phi[12][iphi]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				    h_ErecEgen_phi[13][iphi]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
				    h_ErecEgen_phi[10][iphi]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_phi[11][iphi]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				    h_ErecEgen_phi[12][iphi]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_phi[13][iphi]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
					*/
				    
			   }
			   
			   //Brem
			   Int_t ibrem = (Int_t)((nt_em_br1-BremMin) / binwidth_brem );
			   //cout << "ieta="<<ieta<<endl;
			   if (nt_em_br1>BremMin && nt_em_br1<BremMax){
				    h_ErecEgen_brem[0][ibrem]->Fill(nt_emRaw_e / nt_mc_e);
					h_ErecEgen_brem[1][ibrem]->Fill(nt_emCorrEta_e / nt_mc_e);
				    h_ErecEgen_brem[8][ibrem]->Fill(nt_emDefault_e / nt_mc_e);
//				    h_ErecEgen_brem[3][ibrem]->Fill(nt_emFullCorr_e / nt_mc_e);
//			   	    h_ErecEgen_brem[4][ibrem]->Fill(AFEbrem / nt_mc_e);
//					h_ErecEgen_brem[5][ibrem]->Fill(AFEcomplete / nt_mc_e);
		 		    h_ErecEgen_brem[2][ibrem]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
				    h_ErecEgen_brem[3][ibrem]->Fill(energyPhotonCorrETH / nt_mc_e);
				    //h_ErecEgen_brem[8][ibrem]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_brem[4][ibrem]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				    h_ErecEgen_brem[5][ibrem]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
			 	    h_ErecEgen_brem[6][ibrem]->Fill(energyElectronCorrETH / nt_mc_e);
				    //h_ErecEgen_brem[12][ibrem]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				    h_ErecEgen_brem[7][ibrem]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				    h_ErecEgen_brem[12][ibrem]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				    h_ErecEgen_brem[13][ibrem]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
		 		    h_ErecEgen_brem[10][ibrem]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
	 			    h_ErecEgen_brem[11][ibrem]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				    h_ErecEgen_brem[12][ibrem]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				    h_ErecEgen_brem[13][ibrem]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
					*/
				
			   }
			   
			   //R9
			   Int_t ir9 = (Int_t)((ErecEgenMean_vsR9[0]->FindBin(nt_em_r9)-1)/2);
			   //cout << "ir9="<<ir9<<endl;
			   //Int_t ir9 = (Int_t)((nt_em_r9-R9Min) / binwidth_r9 );
			   //cout << "ieta="<<ieta<<endl;
			   if (nt_em_r9>R9Min && nt_em_r9<R9Max) {
				   h_ErecEgen_r9[0][ir9]->Fill(nt_emRaw_e / nt_mc_e);
				   h_ErecEgen_r9[1][ir9]->Fill(nt_emCorrEta_e / nt_mc_e);
				   h_ErecEgen_r9[8][ir9]->Fill(nt_emDefault_e / nt_mc_e);
//				   h_ErecEgen_r9[3][ir9]->Fill(nt_emFullCorr_e / nt_mc_e);
//				   h_ErecEgen_r9[4][ir9]->Fill(AFEbrem / nt_mc_e);
//				   h_ErecEgen_r9[5][ir9]->Fill(AFEcomplete / nt_mc_e);
				   h_ErecEgen_r9[2][ir9]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
				   h_ErecEgen_r9[3][ir9]->Fill(energyPhotonCorrETH / nt_mc_e);
				   //h_ErecEgen_r9[8][ir9]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				   h_ErecEgen_r9[4][ir9]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				   h_ErecEgen_r9[5][ir9]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
				   h_ErecEgen_r9[6][ir9]->Fill(energyElectronCorrETH / nt_mc_e);
				   //h_ErecEgen_r9[12][ir9]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				   h_ErecEgen_r9[7][ir9]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				   h_ErecEgen_r9[12][ir9]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				   h_ErecEgen_r9[13][ir9]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
				   h_ErecEgen_r9[10][ir9]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
				   h_ErecEgen_r9[11][ir9]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				   h_ErecEgen_r9[12][ir9]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				   h_ErecEgen_r9[13][ir9]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
					*/
			   }
			   
			   //Energy
			   Int_t ienergy = (Int_t)((nt_emCorrEta_e-EnergyMin) / binwidth_energy );
			   //cout << "ipt="<<ipt<<endl;
			   if (nt_emCorrEta_e>EnergyMin && nt_emCorrEta_e<EnergyMax) {
				   
				   h_ErecEgen_energy[0][ienergy]->Fill(nt_emRaw_e / nt_mc_e);
				   h_ErecEgen_energy[1][ienergy]->Fill(nt_emCorrEta_e / nt_mc_e);
				   h_ErecEgen_energy[8][ienergy]->Fill(nt_emDefault_e / nt_mc_e);				   
//				   h_ErecEgen_energy[3][ienergy]->Fill(nt_emFullCorr_e / nt_mc_e);
//				   h_ErecEgen_energy[4][ienergy]->Fill(AFEbrem / nt_mc_e);
//				   h_ErecEgen_energy[5][ienergy]->Fill(AFEcomplete / nt_mc_e);
				   h_ErecEgen_energy[2][ienergy]->Fill(energyPhotonCorrETHbremeta / nt_mc_e);
				   h_ErecEgen_energy[3][ienergy]->Fill(energyPhotonCorrETH / nt_mc_e);
				   //h_ErecEgen_energy[8][ienergy]->Fill(energyPhotonCorrETHbremeta_phot_EnergyScheme / nt_mc_e);
				   h_ErecEgen_energy[4][ienergy]->Fill(energyPhotonCorrETH_phot_EnergyScheme / nt_mc_e);
				   h_ErecEgen_energy[5][ienergy]->Fill(energyElectronCorrETHbremeta / nt_mc_e);
				   h_ErecEgen_energy[6][ienergy]->Fill(energyElectronCorrETH / nt_mc_e);
				   //h_ErecEgen_energy[12][ienergy]->Fill(energyElectronCorrETHbremeta_EnergyScheme / nt_mc_e);
				   h_ErecEgen_energy[7][ienergy]->Fill(energyElectronCorrETH_EnergyScheme / nt_mc_e);
//				   h_ErecEgen_energy[12][ienergy]->Fill(energyElectronCorrETH_2times2DScheme / nt_mc_e);
//				   h_ErecEgen_energy[13][ienergy]->Fill(energyPhotonCorrETH_2times2DScheme / nt_mc_e);
				   /*
				   h_ErecEgen_energy[10][ienergy]->Fill(energyPhotonCorrETHr9eta / nt_mc_e);
				   h_ErecEgen_energy[11][ienergy]->Fill(energyPhotonCorrETHr9scheme / nt_mc_e);
				   h_ErecEgen_energy[12][ienergy]->Fill(energyElectronCorrETHr9eta / nt_mc_e);
				   h_ErecEgen_energy[13][ienergy]->Fill(energyElectronCorrETHr9scheme / nt_mc_e);
					*/
			   }
			   
		   
		   }
		   
		   
	   }
   
   }
	
	Double_t mean    = 1;
	Double_t emean   = 0;
	Double_t chi2    = 0;      
	Double_t fracBad = 0;
	
	for (Int_t cor=0; cor<nCorr; cor++){
		
		for (Int_t ipt=0; ipt<nBinsPt; ipt++){
			mean    = 1;
			emean   = 0;
			chi2    = 0;      
			fracBad = 0;
			if (h_ErecEgen_pt[cor][ipt]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_pt[cor][ipt],  mean, emean, chi2, fracBad);
				ErecEgenMean_vsPt[cor]->Fill(PtMin+ipt*binwidth_pt+binwidth_pt/2, mean);
				ErecEgenMean_vsPt[cor]->SetBinError(1+ipt, emean);
				ErecEgenSigmaEff_vsPt[cor]->Fill(PtMin+ipt*binwidth_pt+binwidth_pt/2, effSigma(h_ErecEgen_pt[cor][ipt]));
			}
		}
	
		for (Int_t ieta=0; ieta<nBinsEtaEBEE; ieta++){
			mean    = 1;
			emean	= 0;
			chi2    = 0;      
			fracBad = 0;
			if (h_ErecEgen_eta[cor][ieta]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_eta[cor][ieta],  mean, emean, chi2, fracBad);
				ErecEgenMean_vsEta[cor]->Fill(EtaMin+ieta*binwidth_eta+binwidth_eta/2, mean);
				ErecEgenMean_vsEta[cor]->SetBinError(1+ieta, emean);
				ErecEgenSigmaEff_vsEta[cor]->Fill(EtaMin+ieta*binwidth_eta+binwidth_eta/2, effSigma(h_ErecEgen_eta[cor][ieta]));
			}
		}

		for (Int_t iphi=0; iphi<nBinsPhi; iphi++){
			mean    = 1;
			emean	= 0;
			chi2    = 0;      
			fracBad = 0;
			if (h_ErecEgen_phi[cor][iphi]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_phi[cor][iphi],  mean, emean, chi2, fracBad);
				ErecEgenMean_vsPhi[cor]->Fill(PhiMin+iphi*binwidth_phi+binwidth_phi/2, mean);
				ErecEgenMean_vsPhi[cor]->SetBinError(1+iphi, emean);
				ErecEgenSigmaEff_vsPhi[cor]->Fill(PhiMin+iphi*binwidth_phi+binwidth_phi/2, effSigma(h_ErecEgen_phi[cor][iphi]));

			}
		}

		for (Int_t ibrem=0; ibrem<nBinsBrem; ibrem++){
			mean    = 1;
			emean	= 0;
			chi2    = 0;      
			fracBad = 0;
			if (h_ErecEgen_brem[cor][ibrem]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_brem[cor][ibrem],  mean, emean, chi2, fracBad);
				ErecEgenMean_vsBrem[cor]->Fill(BremMin+ibrem*binwidth_brem+binwidth_brem/2, mean);
				ErecEgenMean_vsBrem[cor]->SetBinError(1+ibrem, emean);
				ErecEgenSigmaEff_vsBrem[cor]->Fill(BremMin+ibrem*binwidth_brem+binwidth_brem/2, effSigma(h_ErecEgen_brem[cor][ibrem]));
			}
		}
		
		for (Int_t ir9=0; ir9<nBinsR9; ir9++){
		//for (Int_t ir9=0; ir9<nBinsR9; ir9++){
			mean    = 1;
			emean	= 0;
			chi2    = 0;
			fracBad = 0;
			if (h_ErecEgen_r9[cor][ir9]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_r9[cor][ir9],  mean, emean, chi2, fracBad);
				//ErecEgenMean_vsR9[cor]->Fill(R9Min+ir9*binwidth_r9+binwidth_r9/2, mean);
				ErecEgenMean_vsR9[cor]->SetBinContent(2*ir9+1,mean);
				ErecEgenMean_vsR9[cor]->SetBinError(2*ir9+1,emean);
				ErecEgenSigmaEff_vsR9[cor]->SetBinContent(2*ir9+1,effSigma(h_ErecEgen_r9[cor][ir9]));

			}
		}
		
		for (Int_t ienergy=0; ienergy<nBinsEnergy; ienergy++){
			mean    = 1;
			emean   = 0;
			chi2    = 0;      
			fracBad = 0;
			if (h_ErecEgen_energy[cor][ienergy]->GetEntries() >minEntries) 
			{
				fitCB(h_ErecEgen_energy[cor][ienergy],  mean, emean, chi2, fracBad);
				ErecEgenMean_vsEnergy[cor]->Fill(EnergyMin+ienergy*binwidth_energy+binwidth_energy/2, mean);
				ErecEgenMean_vsEnergy[cor]->SetBinError(1+ienergy, emean);
				ErecEgenSigmaEff_vsEnergy[cor]->Fill(EnergyMin+ienergy*binwidth_energy+binwidth_energy/2, effSigma(h_ErecEgen_energy[cor][ienergy]));
			}
		}
		
		
	}
	 
	
	TFile fOuptut("histos_compareSCcorrections.root","recreate");
	for (Int_t cor=0; cor<nCorr; cor++){
		
		for (Int_t ipt=0; ipt<nBinsPt; ipt++){
			h_ErecEgen_pt[cor][ipt]->Write();
		}
		


		ErecEgenMean_vsPt[cor]->Print();
		ErecEgenMean_vsEta[cor]->Print();
		ErecEgenMean_vsPhi[cor]->Print();
		ErecEgenMean_vsBrem[cor]->Print();
		ErecEgenMean_vsR9[cor]->Print();
		ErecEgenMean_vsEnergy[cor]->Print();

		std::cout << cor << std::endl;
		ErecEgenMean_vsPt[cor]->Write();
		ErecEgenMean_vsEta[cor]->Write();
		ErecEgenMean_vsPhi[cor]->Write();
		ErecEgenMean_vsBrem[cor]->Write();
		ErecEgenMean_vsR9[cor]->Write();
		ErecEgenMean_vsEnergy[cor]->Write();
		
		ErecEgenSigmaEff_vsPt[cor]->Write();
		ErecEgenSigmaEff_vsEta[cor]->Write();
		ErecEgenSigmaEff_vsPhi[cor]->Write();
		ErecEgenSigmaEff_vsBrem[cor]->Write();
		ErecEgenSigmaEff_vsR9[cor]->Write();
		ErecEgenSigmaEff_vsEnergy[cor]->Write();
		 
	}	
	fOuptut.Close();
	
	/*
	TFile fOuptut2("histos_deriveSCcorrections.root","recreate");
	ErecEgenMean_vsBremEtaCorr->Write();
	fOuptut2.Close();
	*/
	//deriveCorrections_BrEta();
	
}


void compareSCcorrections::fitCB(TH1F *h, Double_t &mean, Double_t &emean, Double_t &chi2, Double_t& badReco  )
{
	// This is to quantify the fraction of events where the reconstructed energy is below EgenFrac
	badReco = h->Integral(1,h->FindBin(EgenFrac)) / (Double_t)h->GetEntries();
	
	// driving gaussian. Used to estimate the fit range
	TF1 *gtmp = 0;  
	if (plots){
		TCanvas *c1 = new TCanvas("c1","c1",600,600);
		c1->cd();
		h->Draw();
		
		// more solid peak position with a temporary histogram filled only with the bins above 50% of the peak max
		TH1F *htmp = new TH1F("htmp","htmp",nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		// protect the fits from small statistics rebinning
		if (h->GetMaximum()< 50.) { h->Rebin(2); htmp->Rebin(2); }
		if (h->GetMaximum()< 25.) { h->Rebin(2); htmp->Rebin(2); }
		for (Int_t i=0; i<h->GetNbinsX(); ++i) {if (h->GetBinContent(i) >h->GetMaximum()/2.) htmp->SetBinContent(i,h->GetBinContent(i));}
		htmp->Draw();
		c1->Update();
		getchar();
		
		// driving gaussian
		gtmp = new TF1("gtmp","gaus(0)",0,2.0);    
		// use the mean and RMS of the Erec/Egen as initial parameters for the driving gaussian
		// gtmp->SetParameters(10,1,0.05);
		cout << h->GetMaximum() << " " <<  h->GetMean() << " " <<  h->GetRMS() << " " <<  htmp->GetMean() << " " <<  htmp->GetRMS() << endl;
		gtmp->SetParameters(10, htmp->GetMean(), htmp->GetRMS());
		h->Fit("gtmp","","",htmp->GetMean()-5*htmp->GetRMS(),htmp->GetMean()+5*htmp->GetRMS()); // 0.8,1.1);
		h->Fit("gtmp","","",
			   gtmp->GetParameter(1)-2*TMath::Abs(gtmp->GetParameter(2)),
			   gtmp->GetParameter(1)+2*TMath::Abs(gtmp->GetParameter(2)));
		cout << "***** GTMP " 
		<< gtmp->GetParameter(0) << " " << gtmp->GetParameter(1) << " " << gtmp->GetParameter(2) 
		<< endl;
		c1->Update();
		getchar();
		delete htmp;
	}
	else{ 
		// more solid peak position with a temporary histogram filled only with the bins above 50% of the peak max
		TH1F *htmp = new TH1F("htmp","htmp",nBinsErecEgen,ErecEgenMin, ErecEgenMax);
		// protect the fits from small statistics rebinning
		if (h->GetMaximum()< 50.) { h->Rebin(2); htmp->Rebin(2); }
		if (h->GetMaximum()< 25.) { h->Rebin(2); htmp->Rebin(2); }
		for (Int_t i=0; i<h->GetNbinsX(); ++i) {if (h->GetBinContent(i) >h->GetMaximum()/2.) htmp->SetBinContent(i,h->GetBinContent(i));}
		htmp->Draw();
		
		
		
		// driving gaussian
		gtmp = new TF1("gtmp","gaus(0)",ErecEgenMin, ErecEgenMax);
		// use the mean and RMS of the Erec/Egen as initial parameters for the driving gaussian
		//    gtmp->SetParameters(10,1,0.01);
		cout << h->GetMaximum() << " " <<  h->GetMean() << " " <<  h->GetRMS() << " " <<  htmp->GetMean() << " " <<  htmp->GetRMS() << endl;
		gtmp->SetParameters(10, htmp->GetMean(), htmp->GetRMS());
		h->Fit("gtmp","","",htmp->GetMean()-5*htmp->GetRMS(),htmp->GetMean()+5*htmp->GetRMS()); // 0.8,1.1);
		h->Fit("gtmp","","",
			   gtmp->GetParameter(1)-2*TMath::Abs(gtmp->GetParameter(2)),
			   gtmp->GetParameter(1)+2*TMath::Abs(gtmp->GetParameter(2)));
		cout << "***** GTMP " 
		<< gtmp->GetParameter(0) << " " << gtmp->GetParameter(1) << " " << gtmp->GetParameter(2) 
		<< endl;
		delete htmp;
	}
	
	// RooDataHist from TH1F
	RooRealVar  x("x","x", ErecEgenMin, ErecEgenMax);  
	RooDataHist data("data","Ereco/Egen",x,h); 
	RooPlot*    xframe = x.frame(Name("xframe"),Title("E^{reco} / E^{gen}")) ;
	data.plotOn(xframe);
	
	// Initialize CB parameters
	Double_t  alphaStart =   0.5;
	Double_t  alphaMin   =   0.1;
	Double_t  alphaMax   =   2.0;
	Double_t  nStart     =  20.0;
	Double_t  nMin       =   0.0;
	Double_t  nMax       = 100.0;
	if ( gtmp->GetParameter(1) < 0.95 && gtmp->GetParameter(2) > 0.03 ) {
		alphaStart =   0.4;
		alphaMin   =   0.;
		alphaMax   =   1.0;
		nStart     =  20.;
		nMin       =   0.;
		nMax       = 100.;
	}
	
	// fit function
	RooRealVar alpha  ("alpha"  ,        "alpha" , alphaStart, alphaMin, alphaMax); 
	RooRealVar n      ("n"      ,            "n" , nStart, nMin, nMax); 
	RooRealVar cbmean ("cbmean" ,       "cbmean" , gtmp->GetParameter(1) ,0.5, 1.2); // ErecEgenMin, ErecEgenMax);
	RooRealVar cbsigma("cbsigma",      "cbsigma" , 0.01, 0.001,0.1) ;
	RooCBShape cball  ("cball"  , "crystal ball" , x, cbmean, cbsigma, alpha, n);
	
	// other functions
	// CB (x) Gaussian
	//   RooRealVar mg("mg","mg",1) ;
	//   RooRealVar sg("sg","sg",0.1,0.01,0.2) ;
	//   RooGaussian gauss("gauss","gauss",x,mg,sg) ; 
	//   RooFFTConvPdf CBgaus("CBgaus","CB (X) gauss",x,cball,gauss);
	//
	// CB + Gaussian
	//   RooRealVar ng("ng","ng",100,1,10000);
	//   RooRealVar nc("nc","nc",10, 1,10000);
	//   RooAddPdf CBgaus("CBgaus","CB + gauss",RooArgList(cball,gauss),RooArgList(nc,ng));
	
	// Fit Range using as units the sigma of the driving gaussian
	//
	Float_t nsigmaL = 10;
	Float_t nsigmaR = 2;
	//
	// Fit      
	RooFitResult* fitres =cball.fitTo(data,
									  Range(gtmp->GetParameter(1)-nsigmaL*TMath::Abs(gtmp->GetParameter(2)),
											gtmp->GetParameter(1)+nsigmaR*TMath::Abs(gtmp->GetParameter(2))),
									  Minos(kFALSE));    
	mean  = cbmean.getVal();
	emean = cbmean.getError();
	cball.plotOn (xframe,LineColor(kBlue));
	cball.paramOn(xframe,Layout(0.12,0.64,0.88));
	data. statOn (xframe,Layout(0.12,0.64,0.55));
	chi2 = xframe->chiSquare(4); // dof = 4 = number fof floating parametes
	//  cout << "***** CHI2 " << xframe->chiSquare(4) << endl; getchar();
	
	
	// plot
	//  gStyle->SetOptFit(1);
	if (plots){
		TCanvas *cpull = new TCanvas("cpull","cpull",600,700);
		TPad *cpull_1 = new TPad("cpull_1", "cpull_1",0,0.,1,1);
		cpull_1->Draw();
		cpull_1->cd();
		cpull_1->SetFillColor(0);
		cpull_1->SetBorderMode(0);
		cpull_1->SetBorderSize(2);
		cpull_1->SetFrameBorderMode(0);
		cpull_1->SetFrameBorderMode(0);
		cpull_1->SetBottomMargin(0.25);
		TString chi2txt = "#chi^{2}=" + floatToString(xframe->chiSquare(4)) ; // dof = 4 = number dof floating parametes
		TLatex* txt = new TLatex(0.72,10,chi2txt) ;
		txt->SetTextSize(0.04) ;
		txt->SetTextColor(kRed) ;
		xframe->addObject(txt) ;
		xframe->GetXaxis()->SetTitle("E^{reco}/E^{gen}");
		xframe->Draw();
		TPad *cpull_2 = new TPad("cpull_2", "cpull_2",0,0.,1.0,0.17);
		cpull_2->Draw();
		cpull_2->cd();
		cpull_2->SetFillColor(0);
		cpull_2->SetBorderMode(0);
		cpull_2->SetBorderSize(0);
		cpull_2->SetBottomMargin(0.45);
		cpull_2->SetFrameBorderMode(0);
		cpull_2->SetFrameBorderMode(0);
		// pulls    
		//     RooHist* hpull      = xframe->pullHist() ;
		//     RooPlot* xframePull = x.frame(Title("Pull Distribution")) ;
		//     xframePull->addPlotable(hpull,"P") ;
		//     xframePull->GetXaxis()->SetTitle("E^{reco}/E^{gen}");
		//     xframePull->GetXaxis()->SetTitleSize(0.2);
		//     xframePull->GetXaxis()->SetLabelSize(0.2);
		//     xframePull->GetYaxis()->SetRangeUser(-3,3);
		//     xframePull->GetYaxis()->SetTitle("Pull");
		//     xframePull->GetYaxis()->SetTitleSize(0.2);
		//     xframePull->GetYaxis()->SetLabelSize(0.1);
		//     xframePull->Draw();
		cpull->Update();  
		getchar();
	}      
	return;
}

