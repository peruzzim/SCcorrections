#include "TF1.h"
#include "TMath.h"



Double_t applyScCorrectionsBrEta_ELECTRONS(Double_t eta, Double_t sigmaPhiSigmaEta){ 


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
 	        if (sigmaPhiSigmaEta >= 1)  tmpInter = ( fcorr_ELECTRONS[iEta]  .Eval(sigmaPhiSigmaEta) + 															          
 		         	    		         fcorr_ELECTRONS[iEta+1].Eval(sigmaPhiSigmaEta) ) / 2. ;														          
 	        else tmpInter = (xcorr_ELECTRONS[iEta] + xcorr_ELECTRONS[iEta+1])/2.; 
        }																						         
      }																						         
      return tmpInter;																					         
    }  																							         
    if (sigmaPhiSigmaEta >= 1) return fcorr_ELECTRONS[tmpEta].Eval(sigmaPhiSigmaEta);						       						       
    else return xcorr_ELECTRONS[tmpEta]; 
 } 


