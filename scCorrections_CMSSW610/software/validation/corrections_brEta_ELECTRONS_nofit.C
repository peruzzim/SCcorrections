#include "TFile.h"                                                     
#include "TH1F.h"				                        
#include <iostream>  			                                
  			                                                

  	                                                                
Double_t applyScCorrectionsBrEta_ELECTRONS(Double_t eta, Double_t sigmaPhiSigmaEta){  
  	                                                                
  const Int_t    nBinsEta = 14;                          
  Double_t       leftEta  [14];                         
  Double_t       rightEta [14];                         
  const Int_t    nBinsBr  = 18;                           
  Double_t       leftBr  [18];                            
  Double_t       rightBr [18];                            
  Double_t brbins  [36];                                
  TH1F **h_corr = h_corr_ELECTRONS;
  	                                                                
  leftEta[0] =  0.02 ; 
  leftEta[1] =  0.25 ; 
  leftEta[2] =  0.46 ; 
  leftEta[3] =  0.81 ; 
  leftEta[4] =  0.91 ; 
  leftEta[5] =  1.01 ; 
  leftEta[6] =  1.16 ; 
  leftEta[7] =  1.56 ; 
  leftEta[8] =  1.653 ; 
  leftEta[9] =  1.8 ; 
  leftEta[10] =  2 ; 
  leftEta[11] =  2.2 ; 
  leftEta[12] =  2.3 ; 
  leftEta[13] =  2.4 ; 
  rightEta[0] =  0.25 ; 
  rightEta[1] =  0.42 ; 
  rightEta[2] =  0.77 ; 
  rightEta[3] =  0.91 ; 
  rightEta[4] =  1.01 ; 
  rightEta[5] =  1.13 ; 
  rightEta[6] =  1.44 ; 
  rightEta[7] =  1.653 ; 
  rightEta[8] =  1.8 ; 
  rightEta[9] =  2 ; 
  rightEta[10] =  2.2 ; 
  rightEta[11] =  2.3 ; 
  rightEta[12] =  2.4 ; 
  rightEta[13] =  2.5 ; 
  leftBr[0] =  0.8 ; 
  leftBr[1] =  1 ; 
  leftBr[2] =  1.2 ; 
  leftBr[3] =  1.4 ; 
  leftBr[4] =  1.6 ; 
  leftBr[5] =  1.8 ; 
  leftBr[6] =  2 ; 
  leftBr[7] =  2.2 ; 
  leftBr[8] =  2.4 ; 
  leftBr[9] =  2.6 ; 
  leftBr[10] =  2.8 ; 
  leftBr[11] =  3 ; 
  leftBr[12] =  3.2 ; 
  leftBr[13] =  3.4 ; 
  leftBr[14] =  3.6 ; 
  leftBr[15] =  3.8 ; 
  leftBr[16] =  4 ; 
  leftBr[17] =  5 ; 
  rightBr[0] =  1 ; 
  rightBr[1] =  1.2 ; 
  rightBr[2] =  1.4 ; 
  rightBr[3] =  1.6 ; 
  rightBr[4] =  1.8 ; 
  rightBr[5] =  2 ; 
  rightBr[6] =  2.2 ; 
  rightBr[7] =  2.4 ; 
  rightBr[8] =  2.6 ; 
  rightBr[9] =  2.8 ; 
  rightBr[10] =  3 ; 
  rightBr[11] =  3.2 ; 
  rightBr[12] =  3.4 ; 
  rightBr[13] =  3.6 ; 
  rightBr[14] =  3.8 ; 
  rightBr[15] =  4 ; 
  rightBr[16] =  5 ; 
  rightBr[17] =  10 ; 
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

  
     Int_t tmpEta = -1;                                                                                                                                                                        
     Int_t tmpBr  = -1;																					      
   																							      
     // Extra protections										       										      
      																							      
     if (TMath::Abs(eta)  <   leftEta[0]           ) { tmpEta = 0;          if (DBG) std::cout << " WARNING [applyScCorrections]: (TMath::Abs(eta)  <   leftEta[0]          " << std::endl;}   
     if (TMath::Abs(eta)  >=  rightEta[nBinsEta-1] ) { tmpEta = nBinsEta-1; if (DBG) std::cout << " WARNING [applyScCorrections]: TMath::Abs(eta)  >=  rightEta[nBinsEta-1] " << std::endl;}   
   																							      
     if (sigmaPhiSigmaEta <  leftBr [0]            ) {tmpBr = 0;            if (DBG) std::cout << " WARNING [applyScCorrections]: sigmaPhiSigmaEta <  leftBr [0]            " << std::endl;}   
     if (sigmaPhiSigmaEta >= rightBr[nBinsBr]      ) {tmpBr = nBinsBr  -1;  if (DBG) std::cout << " WARNING [applyScCorrections]: sigmaPhiSigmaEta >= rightBr[nBinsBr]      " << std::endl;}   
                                                                                                                                                                                               
     for (Int_t iEta = 0; iEta < nBinsEta; ++iEta){								              								      
       if ( leftEta[iEta] <= TMath::Abs(eta) && TMath::Abs(eta) <rightEta[iEta] ){				       									      
         tmpEta = iEta;											       										      
       }													       										      
     }													         									      
   																							      
     for (Int_t iSigmaPhiSigmaEta = 0; iSigmaPhiSigmaEta < nBinsBr; ++iSigmaPhiSigmaEta){			       									      
       if (leftBr [iSigmaPhiSigmaEta]  <= sigmaPhiSigmaEta && sigmaPhiSigmaEta <rightBr [iSigmaPhiSigmaEta] ){      									      
         tmpBr = iSigmaPhiSigmaEta;										       									      
       }													       										      
     }													       										      
     																							      
     // Interpolation																					      
     Double_t tmpInter = 1;																				      
     // In eta cracks/gaps 																				      
     if (tmpEta == -1 && tmpBr != -1 ) { // need to interpolate only eta, if br is out of range skip this										      
       																							      
       if (TMath::Abs(eta) >=rightEta[nBinsEta-1] ) { // out of ECAL boundary														      
	 //         for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];    															      
         return 1; // don't correct																			      
       }																							      
       																							      
       // central bin at eta = 0																				      
       if (0 <= TMath::Abs(eta) && TMath::Abs(eta) <leftEta[0] ) {															      
         																						      
         tmpInter = h_corr[0]->GetBinContent(2*tmpBr+1);																	      
         																						      
       }																							      
       else { // all other crack-bins																			      
         																						      
         for (Int_t iEta = 0; iEta < nBinsEta-1; ++iEta){								       								      
   	if (rightEta[iEta] <= TMath::Abs(eta) && TMath::Abs(eta) <leftEta[iEta+1] ){													      
   	  tmpInter = ( h_corr[iEta]  ->GetBinContent(2*tmpBr+1) + 															      
   		       h_corr[iEta+1]->GetBinContent(2*tmpBr+1) ) / 2. ;														      
   	}																						      
         }																						      
       }																							      
       //       for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];    															      
       return tmpInter;																					      
     }  																							      
     // end interpolation                                                                                                                                                                      
   if (tmpEta == -1 || tmpBr == -1){									       
     //     for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];                                  		       
     return  1;	// don't correct												       
   }													       
   													       
   Double_t tmp = h_corr[tmpEta]->GetBinContent(2*tmpBr+1);				   		       
   //   for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];                                  		       
   return  tmp;                                                                                                   
}													   
                                                                         
