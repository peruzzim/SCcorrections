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
  xcorr[0]=1.00346;
  xcorr[1]=1.00364;
  xcorr[2]=1.00292;
  xcorr[3]=1.00245;
  xcorr[4]=1.00054;
  xcorr[5]=0.998907;
  xcorr[6]=0.996038;
  xcorr[7]=0.975516;
  xcorr[8]=0.980921;
  xcorr[9]=0.983646;
  xcorr[10]=0.987532;
  xcorr[11]=0.989681;
  xcorr[12]=0.991023;
  xcorr[13]=0.991069;

  Double_t par0[nBinsEta]; 
  Double_t par1[nBinsEta]; 
  Double_t par2[nBinsEta]; 

  par0[0] = 1.00813;
  par1[0] = -0.00199557;
  par2[0] = 0 ;

  par0[1] = 1.00808;
  par1[1] = -0.00248394;
  par2[1] = 0 ;

  par0[2] = 1.00768;
  par1[2] = -0.00277756;
  par2[2] = 0 ;

  par0[3] = 1.00772;
  par1[3] = -0.00385004;
  par2[3] = 0 ;

  par0[4] = 1.00722;
  par1[4] = -0.0049654;
  par2[4] = 0 ;

  par0[5] = 1.00813;
  par1[5] = -0.0078904;
  par2[5] = 0 ;

  par0[6] = 1.00637;
  par1[6] = -0.00863514;
  par2[6] = 0 ;

  par0[7] = 0.978049;
  par1[7] = -0.00198433;
  par2[7] = -0.00176545;

  par0[8] = 0.983403;
  par1[8] = 0.000303515;
  par2[8] = -0.00322049;

  par0[9] = 0.982195;
  par1[9] = 0.00766543;
  par2[9] = -0.00647221;

  par0[10] = 0.98559;
  par1[10] = 0.0090261;
  par2[10] = -0.0072685;

  par0[11] = 0.989543;
  par1[11] = 0.00840811;
  par2[11] = -0.00820998;

  par0[12] = 0.98707;
  par1[12] = 0.0133784;
  par2[12] = -0.00933559;

  par0[13] = 0.986042;
  par1[13] = 0.0149044;
  par2[13] = -0.00960159;


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
	if (sigmaPhiSigmaEta >= 1.2)  tmpInter = ( par0[iEta] + sigmaPhiSigmaEta*par1[iEta] + sigmaPhiSigmaEta*sigmaPhiSigmaEta*par2[iEta] +  
						   par0[iEta+1] + sigmaPhiSigmaEta*par1[iEta+1] + sigmaPhiSigmaEta*sigmaPhiSigmaEta*par2[iEta+1]) / 2. ; 
	else tmpInter = (xcorr[iEta] + xcorr[iEta+1])/2.; 
      }																						         
    }																						         
    return tmpInter;																					         
  }  																							         
  if (sigmaPhiSigmaEta >= 1.2) return par0[tmpEta] + sigmaPhiSigmaEta*par1[tmpEta] + sigmaPhiSigmaEta*sigmaPhiSigmaEta*par2[tmpEta]; 
  else return xcorr[tmpEta]; 
} 


Double_t F_applyScCorrectionsBrEta(Double_t *xx, Double_t *pp){  
 
  Double_t eta  = xx[0] ;                      
  Double_t brem = xx[1] ;                      
  return applyScCorrectionsBrEta(eta, brem);    		     
} 
