#include "TMath.h"

Double_t applyScCorrectionsBrEta(Double_t eta, Double_t sigmaPhiSigmaEta){ 

  bool DBG = false;

  // eta binning ------------------------------------------------------------------------------- 
  // 
  const Double_t etaCrackMin = 1.44; 
  const Double_t etaCrackMax = 1.56; 
   
  //STD 
  const Int_t    nBinsEta              = 14; 
  Double_t       leftEta  [nBinsEta]   = { 0.02, 0.25, 0.46, 0.81, 0.91, 1.01, 1.16,           etaCrackMax,  1.653,  1.8, 2.0, 2.2, 2.3, 2.4 };  
  Double_t       rightEta [nBinsEta]   = { 0.25, 0.42, 0.77, 0.91, 1.01, 1.13, etaCrackMin,    1.653,        1.8  ,  2.0, 2.2, 2.3, 2.4, 2.5 };  

  Double_t xcorr[nBinsEta];
  xcorr[0]=1.00911;
  xcorr[1]=1.01103;
  xcorr[2]=1.00755;
  xcorr[3]=1.00755;
  xcorr[4]=1.00755;
  xcorr[5]=1.00755;
  xcorr[6]=1.00755;
  xcorr[7]=0.973756;
  xcorr[8]=0.979872;
  xcorr[9]=0.981161;
  xcorr[10]=0.981023;
  xcorr[11]=0.981028;
  xcorr[12]=0.979634;
  xcorr[13]=0.979634;

  Double_t par0[nBinsEta];
  Double_t par1[nBinsEta];
  Double_t par2[nBinsEta];
  Double_t par3[nBinsEta];
  Double_t par4[nBinsEta];

  par0[0] = 0.000768052 ;
  par1[0] = 2.04651 ;
  par2[0] = -0.00532509 ;
  par3[0] = 0.987668 ;
  par4[0] = 17.7301 ;

  par0[1] = 0.00331551 ;
  par1[1] = 1.42944 ;
  par2[1] = -0.00132638 ;
  par3[1] = 0.99663 ;
  par4[1] = 11.7288 ;

  par0[2] = 0.00299318 ;
  par1[2] = 1.58006 ;
  par2[2] = -0.00119715 ;
  par3[2] = 0.992485 ;
  par4[2] = 13.6014 ;

  par0[3] = 0.00167598 ;
  par1[3] = 1.32833 ;
  par2[3] = -0.000670924 ;
  par3[3] = 0.989889 ;
  par4[3] = 13.3696 ;

  par0[4] = 0.000790722 ;
  par1[4] = 1.35829 ;
  par2[4] = -0.0138033 ;
  par3[4] = 0.980184 ;
  par4[4] = 11.1678 ;

  par0[5] = 0.13577 ;
  par1[5] = 0.00373831 ;
  par2[5] = -0.0543079 ;
  par3[5] = 1.00842 ;
  par4[5] = 0.911564 ;

  par0[6] = 0.144223 ;
  par1[6] = 2.06662 ;
  par2[6] = -0.0563825 ;
  par3[6] = 0.990502 ;
  par4[6] = 2.29549 ;

  par0[7] = 0.187812 ;
  par1[7] = 2.79467 ;
  par2[7] = -0.0751247 ;
  par3[7] = 0.960841 ;
  par4[7] = 2.87279 ;

  par0[8] = 0.887431 ;
  par1[8] = 2.64958 ;
  par2[8] = -0.0225306 ;
  par3[8] = 0.960174 ;
  par4[8] = 2.70598 ;

  par0[9] = 0.294117 ;
  par1[9] = 3.44856 ;
  par2[9] = -0.117637 ;
  par3[9] = 0.953106 ;
  par4[9] = 2.83931 ;

  par0[10] = 0.276291 ;
  par1[10] = 3.08719 ;
  par2[10] = -0.110498 ;
  par3[10] = 0.949254 ;
  par4[10] = 3.07739 ;

  par0[11] = 0.219354 ;
  par1[11] = 2.12927 ;
  par2[11] = -0.0877415 ;
  par3[11] = 0.937027 ;
  par4[11] = 3.43749 ;

  par0[12] = 0.226169 ;
  par1[12] = 2.13503 ;
  par2[12] = -0.0904675 ;
  par3[12] = 0.969127 ;
  par4[12] = 2.17677 ;

  par0[13] = 0.0767101 ;
  par1[13] = 1.45445 ;
  par2[13] = -0.030684 ;
  par3[13] = 0.887661 ;
  par4[13] = 6.30074 ;

  // extra protections																					   
  // fix sigmaPhiSigmaEta boundaries 
  if (sigmaPhiSigmaEta < 0.8)  sigmaPhiSigmaEta = 0.8; 
  if (sigmaPhiSigmaEta > 5  )  sigmaPhiSigmaEta = 5; 

  // eta = 0																						   
  if (TMath::Abs(eta)  <  leftEta[0]            ) { eta = 0.02 ; }																   
  // outside acceptance																					   
  if (TMath::Abs(eta)  >=  rightEta[nBinsEta-1] ) { eta = 2.49; if (DBG) std::cout << " WARNING [applyScCorrections]: TMath::Abs(eta)  >=  rightEta[nBinsEta-1] " << std::endl;}  
  																								   
  Int_t tmpEta = -1;                                                                                                                                                                         
  for (Int_t iEta = 0; iEta < nBinsEta; ++iEta){								              								      	   
    if ( leftEta[iEta] <= TMath::Abs(eta) && TMath::Abs(eta) <rightEta[iEta] ){				       									      	   
      tmpEta = iEta;											       										   
    }													       										   
  }													       										           

  // Interpolation													         
  Double_t tmpInter = 1;													         
  // In eta cracks/gaps 													         
  if (tmpEta == -1 ) { // need to interpolate    
    for (Int_t iEta = 0; iEta < nBinsEta-1; ++iEta){									         
      if (rightEta[iEta] <= TMath::Abs(eta) && TMath::Abs(eta) <leftEta[iEta+1] ){					         
	if (sigmaPhiSigmaEta >= 1)  tmpInter =   (par0[iEta  ]*(1.-exp(-(sigmaPhiSigmaEta-par4[iEta  ])/par1[iEta  ]))*par2[iEta  ]*sigmaPhiSigmaEta + par3[iEta  ]+
						  par0[iEta+1]*(1.-exp(-(sigmaPhiSigmaEta-par4[iEta+1])/par1[iEta+1]))*par2[iEta+1]*sigmaPhiSigmaEta + par3[iEta+1] ) /2.;
				      // ( fcorr[iEta].Eval(sigmaPhiSigmaEta) +fcorr[iEta+1].Eval(sigmaPhiSigmaEta) ) / 2. ;
	  else tmpInter = (xcorr[iEta] + xcorr[iEta+1])/2.; 
      }															         
    }															         
    return tmpInter;													         
  }  															         
  if (sigmaPhiSigmaEta >= 1) return par0[tmpEta  ]*(1.-exp(-(sigmaPhiSigmaEta-par4[tmpEta  ])/par1[tmpEta  ]))*par2[tmpEta  ]*sigmaPhiSigmaEta + par3[tmpEta  ]; // fcorr[tmpEta].Eval(sigmaPhiSigmaEta);  
  else return xcorr[tmpEta]; 
} 


Double_t F_applyScCorrectionsBrEta(Double_t *xx, Double_t *pp){  
 
  Double_t eta  = xx[0] ;                      
  Double_t brem = xx[1] ;                      
  return applyScCorrectionsBrEta(eta, brem);    		     
} 
