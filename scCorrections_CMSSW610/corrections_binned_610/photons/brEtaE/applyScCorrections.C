#ifndef scCorrectionsBrETAE_h                                              
#define scCorrectionsBrETAE_h                                              
#include "TFile.h"                                                      
#include "TH1F.h"				                       
#include <iostream>  			                                
  			                                                
bool DBG = false;			                                
  	                                                                
Double_t applyScCorrectionsBrEta(Double_t eta, Double_t sigmaPhiSigmaEta){  
  	                                                               
  const Int_t    nBinsEta = 14;                    
  Double_t       leftEta  [14];                   
  Double_t       rightEta [14];                   
  const Int_t    nBinsBr  = 18;                     
  Double_t       leftBr  [18];                      
  Double_t       rightBr [18];                      
  Double_t brbins  [36];                    
  TH1F *h_corr[14];                                 
  	                                                               
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
  for (Int_t i = 0; i<nBinsEta; ++i){                                                   
    h_corr[i] = new TH1F(Form("h_corr_%d",i),Form("h_corr_%d",i),nBinsBr*2-1, brbins);  
  }                                                                                     
  h_corr[0]->SetBinContent(1,1.00911 );
  h_corr[0]->SetBinContent(3,1.00195 );
  h_corr[0]->SetBinContent(5,1.00448 );
  h_corr[0]->SetBinContent(7,1.00537 );
  h_corr[0]->SetBinContent(9,1.00515 );
  h_corr[0]->SetBinContent(11,1.00532 );
  h_corr[0]->SetBinContent(13,1.00522 );
  h_corr[0]->SetBinContent(15,1.00522 );
  h_corr[0]->SetBinContent(17,1.00508 );
  h_corr[0]->SetBinContent(19,1.0043 );
  h_corr[0]->SetBinContent(21,1.0031 );
  h_corr[0]->SetBinContent(23,1.00451 );
  h_corr[0]->SetBinContent(25,1.00369 );
  h_corr[0]->SetBinContent(27,1.00341 );
  h_corr[0]->SetBinContent(29,1.00161 );
  h_corr[0]->SetBinContent(31,1.0014 );
  h_corr[0]->SetBinContent(33,1.0029 );
  h_corr[0]->SetBinContent(35,0.997805 );

  h_corr[1]->SetBinContent(1,1.01103 );
  h_corr[1]->SetBinContent(3,1.0044 );
  h_corr[1]->SetBinContent(5,1.00518 );
  h_corr[1]->SetBinContent(7,1.00564 );
  h_corr[1]->SetBinContent(9,1.00478 );
  h_corr[1]->SetBinContent(11,1.0045 );
  h_corr[1]->SetBinContent(13,1.00464 );
  h_corr[1]->SetBinContent(15,1.00406 );
  h_corr[1]->SetBinContent(17,1.00452 );
  h_corr[1]->SetBinContent(19,1.00281 );
  h_corr[1]->SetBinContent(21,1.00181 );
  h_corr[1]->SetBinContent(23,1.00301 );
  h_corr[1]->SetBinContent(25,1.00153 );
  h_corr[1]->SetBinContent(27,1.00105 );
  h_corr[1]->SetBinContent(29,1.0036 );
  h_corr[1]->SetBinContent(31,1.00087 );
  h_corr[1]->SetBinContent(33,0.999447 );
  h_corr[1]->SetBinContent(35,0.996071 );

  h_corr[2]->SetBinContent(1,1.00755 );
  h_corr[2]->SetBinContent(3,1.00203 );
  h_corr[2]->SetBinContent(5,1.00518 );
  h_corr[2]->SetBinContent(7,1.00399 );
  h_corr[2]->SetBinContent(9,1.00382 );
  h_corr[2]->SetBinContent(11,1.00366 );
  h_corr[2]->SetBinContent(13,1.00316 );
  h_corr[2]->SetBinContent(15,1.00278 );
  h_corr[2]->SetBinContent(17,1.00278 );
  h_corr[2]->SetBinContent(19,1.00218 );
  h_corr[2]->SetBinContent(21,1.00115 );
  h_corr[2]->SetBinContent(23,1.00156 );
  h_corr[2]->SetBinContent(25,1.00125 );
  h_corr[2]->SetBinContent(27,0.999759 );
  h_corr[2]->SetBinContent(29,0.999675 );
  h_corr[2]->SetBinContent(31,0.998803 );
  h_corr[2]->SetBinContent(33,0.997966 );
  h_corr[2]->SetBinContent(35,0.99159 );

  h_corr[3]->SetBinContent(1,1.00755 );
  h_corr[3]->SetBinContent(3,1.00198 );
  h_corr[3]->SetBinContent(5,1.00234 );
  h_corr[3]->SetBinContent(7,1.00237 );
  h_corr[3]->SetBinContent(9,1.00422 );
  h_corr[3]->SetBinContent(11,1.00203 );
  h_corr[3]->SetBinContent(13,1.00025 );
  h_corr[3]->SetBinContent(15,0.999455 );
  h_corr[3]->SetBinContent(17,0.999964 );
  h_corr[3]->SetBinContent(19,0.998423 );
  h_corr[3]->SetBinContent(21,0.999232 );
  h_corr[3]->SetBinContent(23,0.998635 );
  h_corr[3]->SetBinContent(25,0.996475 );
  h_corr[3]->SetBinContent(27,0.997508 );
  h_corr[3]->SetBinContent(29,0.995793 );
  h_corr[3]->SetBinContent(31,0.997236 );
  h_corr[3]->SetBinContent(33,0.993536 );
  h_corr[3]->SetBinContent(35,0.986535 );

  h_corr[4]->SetBinContent(1,1.00755 );
  h_corr[4]->SetBinContent(3,0.999715 );
  h_corr[4]->SetBinContent(5,1.00087 );
  h_corr[4]->SetBinContent(7,1.00135 );
  h_corr[4]->SetBinContent(9,1.00022 );
  h_corr[4]->SetBinContent(11,0.998876 );
  h_corr[4]->SetBinContent(13,0.999437 );
  h_corr[4]->SetBinContent(15,0.996879 );
  h_corr[4]->SetBinContent(17,0.995211 );
  h_corr[4]->SetBinContent(19,0.995829 );
  h_corr[4]->SetBinContent(21,0.994191 );
  h_corr[4]->SetBinContent(23,0.992941 );
  h_corr[4]->SetBinContent(25,0.992971 );
  h_corr[4]->SetBinContent(27,0.992722 );
  h_corr[4]->SetBinContent(29,0.989664 );
  h_corr[4]->SetBinContent(31,0.989544 );
  h_corr[4]->SetBinContent(33,0.984077 );
  h_corr[4]->SetBinContent(35,0.975884 );

  h_corr[5]->SetBinContent(1,1.00755 );
  h_corr[5]->SetBinContent(3,0.999649 );
  h_corr[5]->SetBinContent(5,0.997419 );
  h_corr[5]->SetBinContent(7,0.997699 );
  h_corr[5]->SetBinContent(9,0.996926 );
  h_corr[5]->SetBinContent(11,0.996159 );
  h_corr[5]->SetBinContent(13,0.994407 );
  h_corr[5]->SetBinContent(15,0.991623 );
  h_corr[5]->SetBinContent(17,0.990541 );
  h_corr[5]->SetBinContent(19,0.987653 );
  h_corr[5]->SetBinContent(21,0.985283 );
  h_corr[5]->SetBinContent(23,0.986988 );
  h_corr[5]->SetBinContent(25,0.985919 );
  h_corr[5]->SetBinContent(27,0.97931 );
  h_corr[5]->SetBinContent(29,0.980458 );
  h_corr[5]->SetBinContent(31,0.976297 );
  h_corr[5]->SetBinContent(33,0.973508 );
  h_corr[5]->SetBinContent(35,0.961739 );

  h_corr[6]->SetBinContent(1,1.00755 );
  h_corr[6]->SetBinContent(3,0.998084 );
  h_corr[6]->SetBinContent(5,0.996585 );
  h_corr[6]->SetBinContent(7,0.996382 );
  h_corr[6]->SetBinContent(9,0.995253 );
  h_corr[6]->SetBinContent(11,0.993395 );
  h_corr[6]->SetBinContent(13,0.992929 );
  h_corr[6]->SetBinContent(15,0.990296 );
  h_corr[6]->SetBinContent(17,0.988461 );
  h_corr[6]->SetBinContent(19,0.986458 );
  h_corr[6]->SetBinContent(21,0.984312 );
  h_corr[6]->SetBinContent(23,0.982401 );
  h_corr[6]->SetBinContent(25,0.98005 );
  h_corr[6]->SetBinContent(27,0.978624 );
  h_corr[6]->SetBinContent(29,0.974662 );
  h_corr[6]->SetBinContent(31,0.973472 );
  h_corr[6]->SetBinContent(33,0.9666 );
  h_corr[6]->SetBinContent(35,0.961739 );

  h_corr[7]->SetBinContent(1,0.973756 );
  h_corr[7]->SetBinContent(3,0.974773 );
  h_corr[7]->SetBinContent(5,0.974204 );
  h_corr[7]->SetBinContent(7,0.974139 );
  h_corr[7]->SetBinContent(9,0.974032 );
  h_corr[7]->SetBinContent(11,0.972481 );
  h_corr[7]->SetBinContent(13,0.97031 );
  h_corr[7]->SetBinContent(15,0.967816 );
  h_corr[7]->SetBinContent(17,0.965199 );
  h_corr[7]->SetBinContent(19,0.962478 );
  h_corr[7]->SetBinContent(21,0.961222 );
  h_corr[7]->SetBinContent(23,0.957902 );
  h_corr[7]->SetBinContent(25,0.956655 );
  h_corr[7]->SetBinContent(27,0.94847 );
  h_corr[7]->SetBinContent(29,0.946364 );
  h_corr[7]->SetBinContent(31,0.943846 );
  h_corr[7]->SetBinContent(33,0.93199 );
  h_corr[7]->SetBinContent(35,0.903582 );

  h_corr[8]->SetBinContent(1,0.979872 );
  h_corr[8]->SetBinContent(3,0.978604 );
  h_corr[8]->SetBinContent(5,0.978455 );
  h_corr[8]->SetBinContent(7,0.97707 );
  h_corr[8]->SetBinContent(9,0.976315 );
  h_corr[8]->SetBinContent(11,0.973663 );
  h_corr[8]->SetBinContent(13,0.970326 );
  h_corr[8]->SetBinContent(15,0.968126 );
  h_corr[8]->SetBinContent(17,0.965351 );
  h_corr[8]->SetBinContent(19,0.962038 );
  h_corr[8]->SetBinContent(21,0.960899 );
  h_corr[8]->SetBinContent(23,0.950201 );
  h_corr[8]->SetBinContent(25,0.943317 );
  h_corr[8]->SetBinContent(27,0.942918 );
  h_corr[8]->SetBinContent(29,0.936381 );
  h_corr[8]->SetBinContent(31,0.932375 );
  h_corr[8]->SetBinContent(33,0.919942 );
  h_corr[8]->SetBinContent(35,0.87488 );

  h_corr[9]->SetBinContent(1,0.981161 );
  h_corr[9]->SetBinContent(3,0.978441 );
  h_corr[9]->SetBinContent(5,0.97769 );
  h_corr[9]->SetBinContent(7,0.977881 );
  h_corr[9]->SetBinContent(9,0.976922 );
  h_corr[9]->SetBinContent(11,0.973494 );
  h_corr[9]->SetBinContent(13,0.970774 );
  h_corr[9]->SetBinContent(15,0.966917 );
  h_corr[9]->SetBinContent(17,0.959063 );
  h_corr[9]->SetBinContent(19,0.962411 );
  h_corr[9]->SetBinContent(21,0.951703 );
  h_corr[9]->SetBinContent(23,0.941883 );
  h_corr[9]->SetBinContent(25,0.936695 );
  h_corr[9]->SetBinContent(27,0.93186 );
  h_corr[9]->SetBinContent(29,0.93208 );
  h_corr[9]->SetBinContent(31,0.930355 );
  h_corr[9]->SetBinContent(33,0.893809 );
  h_corr[9]->SetBinContent(35,0.87488 );

  h_corr[10]->SetBinContent(1,0.981023 );
  h_corr[10]->SetBinContent(3,0.980024 );
  h_corr[10]->SetBinContent(5,0.97949 );
  h_corr[10]->SetBinContent(7,0.979971 );
  h_corr[10]->SetBinContent(9,0.978824 );
  h_corr[10]->SetBinContent(11,0.976202 );
  h_corr[10]->SetBinContent(13,0.973203 );
  h_corr[10]->SetBinContent(15,0.969889 );
  h_corr[10]->SetBinContent(17,0.963938 );
  h_corr[10]->SetBinContent(19,0.960585 );
  h_corr[10]->SetBinContent(21,0.954658 );
  h_corr[10]->SetBinContent(23,0.948633 );
  h_corr[10]->SetBinContent(25,0.933944 );
  h_corr[10]->SetBinContent(27,0.948763 );
  h_corr[10]->SetBinContent(29,0.93208 );
  h_corr[10]->SetBinContent(31,0.930355 );
  h_corr[10]->SetBinContent(33,0.893809 );
  h_corr[10]->SetBinContent(35,0.87488 );

  h_corr[11]->SetBinContent(1,0.981028 );
  h_corr[11]->SetBinContent(3,0.980314 );
  h_corr[11]->SetBinContent(5,0.979225 );
  h_corr[11]->SetBinContent(7,0.97997 );
  h_corr[11]->SetBinContent(9,0.979587 );
  h_corr[11]->SetBinContent(11,0.978107 );
  h_corr[11]->SetBinContent(13,0.971492 );
  h_corr[11]->SetBinContent(15,0.971792 );
  h_corr[11]->SetBinContent(17,0.963637 );
  h_corr[11]->SetBinContent(19,0.956738 );
  h_corr[11]->SetBinContent(21,0.954658 );
  h_corr[11]->SetBinContent(23,0.948633 );
  h_corr[11]->SetBinContent(25,0.933944 );
  h_corr[11]->SetBinContent(27,0.948763 );
  h_corr[11]->SetBinContent(29,0.93208 );
  h_corr[11]->SetBinContent(31,0.930355 );
  h_corr[11]->SetBinContent(33,0.893809 );
  h_corr[11]->SetBinContent(35,0.87488 );

  h_corr[12]->SetBinContent(1,0.979634 );
  h_corr[12]->SetBinContent(3,0.98311 );
  h_corr[12]->SetBinContent(5,0.983679 );
  h_corr[12]->SetBinContent(7,0.980413 );
  h_corr[12]->SetBinContent(9,0.977107 );
  h_corr[12]->SetBinContent(11,0.976334 );
  h_corr[12]->SetBinContent(13,0.969681 );
  h_corr[12]->SetBinContent(15,0.964521 );
  h_corr[12]->SetBinContent(17,0.964822 );
  h_corr[12]->SetBinContent(19,0.956738 );
  h_corr[12]->SetBinContent(21,0.954658 );
  h_corr[12]->SetBinContent(23,0.948633 );
  h_corr[12]->SetBinContent(25,0.933944 );
  h_corr[12]->SetBinContent(27,0.948763 );
  h_corr[12]->SetBinContent(29,0.93208 );
  h_corr[12]->SetBinContent(31,0.930355 );
  h_corr[12]->SetBinContent(33,0.893809 );
  h_corr[12]->SetBinContent(35,0.87488 );

  h_corr[13]->SetBinContent(1,0.979634 );
  h_corr[13]->SetBinContent(3,0.976508 );
  h_corr[13]->SetBinContent(5,0.981052 );
  h_corr[13]->SetBinContent(7,0.978603 );
  h_corr[13]->SetBinContent(9,0.977332 );
  h_corr[13]->SetBinContent(11,0.981104 );
  h_corr[13]->SetBinContent(13,0.965046 );
  h_corr[13]->SetBinContent(15,0.964521 );
  h_corr[13]->SetBinContent(17,0.964822 );
  h_corr[13]->SetBinContent(19,0.956738 );
  h_corr[13]->SetBinContent(21,0.954658 );
  h_corr[13]->SetBinContent(23,0.948633 );
  h_corr[13]->SetBinContent(25,0.933944 );
  h_corr[13]->SetBinContent(27,0.948763 );
  h_corr[13]->SetBinContent(29,0.93208 );
  h_corr[13]->SetBinContent(31,0.930355 );
  h_corr[13]->SetBinContent(33,0.893809 );
  h_corr[13]->SetBinContent(35,0.87488 );

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
         for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];    															      
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
       for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];    															      
       return tmpInter;																					      
     }  																							      
     // end interpolation                                                                                                                                                                      
   if (tmpEta == -1 || tmpBr == -1){									       
     for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];                                  		       
     return  1; // don't correct											       
   }													       
   													       
   Double_t tmp = h_corr[tmpEta]->GetBinContent(2*tmpBr+1);				   		       
   for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];                                  		       
   return  tmp;                                                                                                   
}													   
                                                                         
Double_t applyScCorrectionsE_EB(Double_t E){  							   
  const Int_t    nBinsE             = 26;             
  Double_t       leftE  [nBinsE];                    
  Double_t       rightE [nBinsE];                    
  Double_t       EBins  [nBinsE*2];                  
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
  TH1F *h_CBE_EB    = new TH1F("h_CBE_EB"    ,"h_CBE_EB"    ,nBinsE*2-1, EBins); 
  h_CBE_EB->SetBinContent(1, 1.00232); 
  h_CBE_EB->SetBinContent(3, 1.00052); 
  h_CBE_EB->SetBinContent(5, 1.00057); 
  h_CBE_EB->SetBinContent(7, 1.00033); 
  h_CBE_EB->SetBinContent(9, 0.999998); 
  h_CBE_EB->SetBinContent(11, 0.999642); 
  h_CBE_EB->SetBinContent(13, 1.00013); 
  h_CBE_EB->SetBinContent(15, 0.999744); 
  h_CBE_EB->SetBinContent(17, 0.999726); 
  h_CBE_EB->SetBinContent(19, 0.999707); 
  h_CBE_EB->SetBinContent(21, 1.00008); 
  h_CBE_EB->SetBinContent(23, 1.00028); 
  h_CBE_EB->SetBinContent(25, 1.00046); 
  h_CBE_EB->SetBinContent(27, 0.999905); 
  h_CBE_EB->SetBinContent(29, 1.00014); 
  h_CBE_EB->SetBinContent(31, 1.00029); 
  h_CBE_EB->SetBinContent(33, 0.999585); 
  h_CBE_EB->SetBinContent(35, 1.00085); 
  h_CBE_EB->SetBinContent(37, 1); 
  h_CBE_EB->SetBinContent(39, 1); 
  h_CBE_EB->SetBinContent(41, 1); 
  h_CBE_EB->SetBinContent(43, 1); 
  h_CBE_EB->SetBinContent(45, 1); 
  h_CBE_EB->SetBinContent(47, 1); 
  h_CBE_EB->SetBinContent(49, 1); 
  h_CBE_EB->SetBinContent(51, 1); 
  Int_t iE      = -1;                                                                   
  for (Int_t iiE  = 0; iiE  < nBinsE;  ++iiE ){ 				      
    if ( leftE [iiE]  <= (E)      &&       (E) < rightE[iiE] ) {		      
      iE  = iiE;  								      
    }										      
  }										      
  if (E < leftE  [0] )         { iE = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: E < leftE  [0] )       " << std::endl;}   
  if (E > rightE [nBinsE-1] ) { iE = nBinsE-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: E > rightE [nBinsE-1] " << std::endl;}   
  if (iE == -1) {delete  h_CBE_EB; return 1;}					      
											      
  Int_t binE =  2*iE+1 ; // h_CBE_EB->FindBin(E);                                    
  Double_t tmp = h_CBE_EB->GetBinContent(binE);                                        
  delete h_CBE_EB;                                                             	      
  if ( 0< binE && binE < 2*nBinsE+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
                                                                         
Double_t applyScCorrectionsE_EE(Double_t E){  							   
  const Int_t    nBinsE             = 26;             
  Double_t       leftE  [nBinsE];                    
  Double_t       rightE [nBinsE];                    
  Double_t       EBins  [nBinsE*2];                  
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
  TH1F *h_CBE_EE    = new TH1F("h_CBE_EE"    ,"h_CBE_EE"    ,nBinsE*2-1, EBins); 
  h_CBE_EE->SetBinContent(1, 1); 
  h_CBE_EE->SetBinContent(3, 0.992836); 
  h_CBE_EE->SetBinContent(5, 0.996175); 
  h_CBE_EE->SetBinContent(7, 0.994136); 
  h_CBE_EE->SetBinContent(9, 0.996067); 
  h_CBE_EE->SetBinContent(11, 0.995012); 
  h_CBE_EE->SetBinContent(13, 0.996377); 
  h_CBE_EE->SetBinContent(15, 0.997417); 
  h_CBE_EE->SetBinContent(17, 0.997449); 
  h_CBE_EE->SetBinContent(19, 0.998589); 
  h_CBE_EE->SetBinContent(21, 0.998367); 
  h_CBE_EE->SetBinContent(23, 0.99895); 
  h_CBE_EE->SetBinContent(25, 0.998895); 
  h_CBE_EE->SetBinContent(27, 1.00053); 
  h_CBE_EE->SetBinContent(29, 0.999709); 
  h_CBE_EE->SetBinContent(31, 1.00063); 
  h_CBE_EE->SetBinContent(33, 1.00045); 
  h_CBE_EE->SetBinContent(35, 1.00059); 
  h_CBE_EE->SetBinContent(37, 1.00071); 
  h_CBE_EE->SetBinContent(39, 1.00192); 
  h_CBE_EE->SetBinContent(41, 1.0019); 
  h_CBE_EE->SetBinContent(43, 1.00332); 
  h_CBE_EE->SetBinContent(45, 1.00263); 
  h_CBE_EE->SetBinContent(47, 1.00316); 
  h_CBE_EE->SetBinContent(49, 0.999199); 
  h_CBE_EE->SetBinContent(51, 1.00046); 
  Int_t iE      = -1;                                                                   
  for (Int_t iiE  = 0; iiE  < nBinsE;  ++iiE ){ 				      
    if ( leftE [iiE]  <= (E)      &&       (E) < rightE[iiE] ) {		      
      iE  = iiE;  								      
    }										      
  }										      
  if (E < leftE  [0] )         { iE = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: E < leftE  [0] )       " << std::endl;}   
  if (E > rightE [nBinsE-1] ) { iE = nBinsE-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: E > rightE [nBinsE-1] " << std::endl;}   
  if (iE == -1) {delete  h_CBE_EE; return 1;}					      
											      
  Int_t binE =  2*iE+1 ; // h_CBE_EE->FindBin(E);                                    
  Double_t tmp = h_CBE_EE->GetBinContent(binE);                                        
  delete h_CBE_EE;                                                             	      
  if ( 0< binE && binE < 2*nBinsE+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
#endif                                                 
