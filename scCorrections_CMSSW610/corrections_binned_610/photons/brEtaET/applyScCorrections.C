#ifndef scCorrectionsBrETAET_h                                           
#define scCorrectionsBrETAET_h                                           
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
     return  1;	// don't correct												       
   }													       
   													       
   Double_t tmp = h_corr[tmpEta]->GetBinContent(2*tmpBr+1);				   		       
   for (Int_t i = 0; i < nBinsEta; ++i) delete h_corr[i];                                  		       
   return  tmp;                                                                                                   
}													   
                                                                         
Double_t applyScCorrectionsET_EB(Double_t ET){  							   
  const Int_t    nBinsET             = 13;             
  Double_t       leftET  [nBinsET];                    
  Double_t       rightET [nBinsET];                    
  Double_t       ETBins  [nBinsET*2];                  
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
  TH1F *h_CBET_EB    = new TH1F("h_CBET_EB"    ,"h_CBET_EB"    ,nBinsET*2-1, ETBins); 
  h_CBET_EB->SetBinContent(1, 1); 
  h_CBET_EB->SetBinContent(3, 1.00303); 
  h_CBET_EB->SetBinContent(5, 1.00119); 
  h_CBET_EB->SetBinContent(7, 1.00117); 
  h_CBET_EB->SetBinContent(9, 1.00021); 
  h_CBET_EB->SetBinContent(11, 1.00035); 
  h_CBET_EB->SetBinContent(13, 1.00014); 
  h_CBET_EB->SetBinContent(15, 20.5594); 
  h_CBET_EB->SetBinContent(17, 0.99996); 
  h_CBET_EB->SetBinContent(19, 0.999874); 
  h_CBET_EB->SetBinContent(21, 0.999847); 
  h_CBET_EB->SetBinContent(23, 0.999819); 
  h_CBET_EB->SetBinContent(25, 0.999608); 
  Int_t iET      = -1;                                                                   
  for (Int_t iiET  = 0; iiET  < nBinsET;  ++iiET ){ 				      
    if ( leftET [iiET]  <= (ET)      &&       (ET) < rightET[iiET] ) {		      
      iET  = iiET;  								      
    }										      
  }										      
  if (ET < leftET  [0] )         { iET = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: ET < leftET  [0] )       " << std::endl;}   
  if (ET > rightET [nBinsET-1] ) { iET = nBinsET-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: ET > rightET [nBinsET-1] " << std::endl;}   
  if (iET == -1) {delete  h_CBET_EB; return 1;}					      
											      
  Int_t binET =  2*iET+1 ; // h_CBET_EB->FindBin(ET);                                    
  Double_t tmp = h_CBET_EB->GetBinContent(binET);                                        
  delete h_CBET_EB;                                                             	      
  if ( 0< binET && binET < 2*nBinsET+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
                                                                         
Double_t applyScCorrectionsET_EE(Double_t ET){  							   
  const Int_t    nBinsET             = 13;             
  Double_t       leftET  [nBinsET];                    
  Double_t       rightET [nBinsET];                    
  Double_t       ETBins  [nBinsET*2];                  
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
  TH1F *h_CBET_EE    = new TH1F("h_CBET_EE"    ,"h_CBET_EE"    ,nBinsET*2-1, ETBins); 
  h_CBET_EE->SetBinContent(1, 1); 
  h_CBET_EE->SetBinContent(3, 0.996547); 
  h_CBET_EE->SetBinContent(5, 0.995308); 
  h_CBET_EE->SetBinContent(7, 0.99712); 
  h_CBET_EE->SetBinContent(9, 0.99693); 
  h_CBET_EE->SetBinContent(11, 0.997823); 
  h_CBET_EE->SetBinContent(13, 0.998411); 
  h_CBET_EE->SetBinContent(15, 0.998947); 
  h_CBET_EE->SetBinContent(17, 0.999935); 
  h_CBET_EE->SetBinContent(19, 1.00044); 
  h_CBET_EE->SetBinContent(21, 1.00131); 
  h_CBET_EE->SetBinContent(23, 1.00186); 
  h_CBET_EE->SetBinContent(25, 1.0027); 
  Int_t iET      = -1;                                                                   
  for (Int_t iiET  = 0; iiET  < nBinsET;  ++iiET ){ 				      
    if ( leftET [iiET]  <= (ET)      &&       (ET) < rightET[iiET] ) {		      
      iET  = iiET;  								      
    }										      
  }										      
  if (ET < leftET  [0] )         { iET = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: ET < leftET  [0] )       " << std::endl;}   
  if (ET > rightET [nBinsET-1] ) { iET = nBinsET-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: ET > rightET [nBinsET-1] " << std::endl;}   
  if (iET == -1) {delete  h_CBET_EE; return 1;}					      
											      
  Int_t binET =  2*iET+1 ; // h_CBET_EE->FindBin(ET);                                    
  Double_t tmp = h_CBET_EE->GetBinContent(binET);                                        
  delete h_CBET_EE;                                                             	      
  if ( 0< binET && binET < 2*nBinsET+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
#endif                                                 
