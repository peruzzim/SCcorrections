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
  h_corr[0]->SetBinContent(1,1.00312 );
  h_corr[0]->SetBinContent(3,1.0038 );
  h_corr[0]->SetBinContent(5,1.00565 );
  h_corr[0]->SetBinContent(7,1.00524 );
  h_corr[0]->SetBinContent(9,1.00418 );
  h_corr[0]->SetBinContent(11,1.00339 );
  h_corr[0]->SetBinContent(13,1.00447 );
  h_corr[0]->SetBinContent(15,1.00304 );
  h_corr[0]->SetBinContent(17,1.00266 );
  h_corr[0]->SetBinContent(19,1.00268 );
  h_corr[0]->SetBinContent(21,1.00285 );
  h_corr[0]->SetBinContent(23,1.00216 );
  h_corr[0]->SetBinContent(25,1.00122 );
  h_corr[0]->SetBinContent(27,1.00171 );
  h_corr[0]->SetBinContent(29,1.00275 );
  h_corr[0]->SetBinContent(31,1.00253 );
  h_corr[0]->SetBinContent(33,1.00141 );
  h_corr[0]->SetBinContent(35,0.998228 );

  h_corr[1]->SetBinContent(1,1.00353 );
  h_corr[1]->SetBinContent(3,1.00375 );
  h_corr[1]->SetBinContent(5,1.00482 );
  h_corr[1]->SetBinContent(7,1.0045 );
  h_corr[1]->SetBinContent(9,1.00388 );
  h_corr[1]->SetBinContent(11,1.00288 );
  h_corr[1]->SetBinContent(13,1.00331 );
  h_corr[1]->SetBinContent(15,1.00219 );
  h_corr[1]->SetBinContent(17,1.00134 );
  h_corr[1]->SetBinContent(19,1.00165 );
  h_corr[1]->SetBinContent(21,1.00135 );
  h_corr[1]->SetBinContent(23,1.00004 );
  h_corr[1]->SetBinContent(25,1.00049 );
  h_corr[1]->SetBinContent(27,1.00135 );
  h_corr[1]->SetBinContent(29,0.998285 );
  h_corr[1]->SetBinContent(31,0.999249 );
  h_corr[1]->SetBinContent(33,0.997015 );
  h_corr[1]->SetBinContent(35,0.991827 );

  h_corr[2]->SetBinContent(1,1.00268 );
  h_corr[2]->SetBinContent(3,1.00317 );
  h_corr[2]->SetBinContent(5,1.00427 );
  h_corr[2]->SetBinContent(7,1.00353 );
  h_corr[2]->SetBinContent(9,1.0031 );
  h_corr[2]->SetBinContent(11,1.00198 );
  h_corr[2]->SetBinContent(13,1.00109 );
  h_corr[2]->SetBinContent(15,1.00099 );
  h_corr[2]->SetBinContent(17,1.00044 );
  h_corr[2]->SetBinContent(19,0.999942 );
  h_corr[2]->SetBinContent(21,1.00025 );
  h_corr[2]->SetBinContent(23,0.999839 );
  h_corr[2]->SetBinContent(25,0.999343 );
  h_corr[2]->SetBinContent(27,0.997805 );
  h_corr[2]->SetBinContent(29,0.9976 );
  h_corr[2]->SetBinContent(31,0.99801 );
  h_corr[2]->SetBinContent(33,0.997174 );
  h_corr[2]->SetBinContent(35,0.990273 );

  h_corr[3]->SetBinContent(1,1.00239 );
  h_corr[3]->SetBinContent(3,1.0025 );
  h_corr[3]->SetBinContent(5,1.00277 );
  h_corr[3]->SetBinContent(7,1.0021 );
  h_corr[3]->SetBinContent(9,1.00082 );
  h_corr[3]->SetBinContent(11,1.00044 );
  h_corr[3]->SetBinContent(13,0.999265 );
  h_corr[3]->SetBinContent(15,0.99849 );
  h_corr[3]->SetBinContent(17,0.998506 );
  h_corr[3]->SetBinContent(19,0.99663 );
  h_corr[3]->SetBinContent(21,0.998309 );
  h_corr[3]->SetBinContent(23,0.996356 );
  h_corr[3]->SetBinContent(25,0.994358 );
  h_corr[3]->SetBinContent(27,0.992014 );
  h_corr[3]->SetBinContent(29,0.994974 );
  h_corr[3]->SetBinContent(31,0.995158 );
  h_corr[3]->SetBinContent(33,0.990216 );
  h_corr[3]->SetBinContent(35,0.981146 );

  h_corr[4]->SetBinContent(1,1.00042 );
  h_corr[4]->SetBinContent(3,1.00066 );
  h_corr[4]->SetBinContent(5,1.00071 );
  h_corr[4]->SetBinContent(7,0.999997 );
  h_corr[4]->SetBinContent(9,0.999141 );
  h_corr[4]->SetBinContent(11,0.997244 );
  h_corr[4]->SetBinContent(13,0.996322 );
  h_corr[4]->SetBinContent(15,0.995331 );
  h_corr[4]->SetBinContent(17,0.994275 );
  h_corr[4]->SetBinContent(19,0.994044 );
  h_corr[4]->SetBinContent(21,0.994801 );
  h_corr[4]->SetBinContent(23,0.991458 );
  h_corr[4]->SetBinContent(25,0.990905 );
  h_corr[4]->SetBinContent(27,0.99098 );
  h_corr[4]->SetBinContent(29,0.98939 );
  h_corr[4]->SetBinContent(31,0.986875 );
  h_corr[4]->SetBinContent(33,0.986076 );
  h_corr[4]->SetBinContent(35,0.974445 );

  h_corr[5]->SetBinContent(1,0.999443 );
  h_corr[5]->SetBinContent(3,0.998372 );
  h_corr[5]->SetBinContent(5,0.997611 );
  h_corr[5]->SetBinContent(7,0.997083 );
  h_corr[5]->SetBinContent(9,0.994134 );
  h_corr[5]->SetBinContent(11,0.993345 );
  h_corr[5]->SetBinContent(13,0.991468 );
  h_corr[5]->SetBinContent(15,0.990873 );
  h_corr[5]->SetBinContent(17,0.987817 );
  h_corr[5]->SetBinContent(19,0.987057 );
  h_corr[5]->SetBinContent(21,0.985594 );
  h_corr[5]->SetBinContent(23,0.98525 );
  h_corr[5]->SetBinContent(25,0.982653 );
  h_corr[5]->SetBinContent(27,0.980509 );
  h_corr[5]->SetBinContent(29,0.977234 );
  h_corr[5]->SetBinContent(31,0.976602 );
  h_corr[5]->SetBinContent(33,0.971231 );
  h_corr[5]->SetBinContent(35,0.974445 );

  h_corr[6]->SetBinContent(1,0.997196 );
  h_corr[6]->SetBinContent(3,0.994881 );
  h_corr[6]->SetBinContent(5,0.994344 );
  h_corr[6]->SetBinContent(7,0.993436 );
  h_corr[6]->SetBinContent(9,0.991051 );
  h_corr[6]->SetBinContent(11,0.990067 );
  h_corr[6]->SetBinContent(13,0.988207 );
  h_corr[6]->SetBinContent(15,0.990873 );
  h_corr[6]->SetBinContent(17,0.984409 );
  h_corr[6]->SetBinContent(19,0.982966 );
  h_corr[6]->SetBinContent(21,0.981727 );
  h_corr[6]->SetBinContent(23,0.980146 );
  h_corr[6]->SetBinContent(25,0.977137 );
  h_corr[6]->SetBinContent(27,0.975534 );
  h_corr[6]->SetBinContent(29,0.974315 );
  h_corr[6]->SetBinContent(31,0.972407 );
  h_corr[6]->SetBinContent(33,0.965858 );
  h_corr[6]->SetBinContent(35,0.974445 );

  h_corr[7]->SetBinContent(1,0.976982 );
  h_corr[7]->SetBinContent(3,0.974051 );
  h_corr[7]->SetBinContent(5,0.970804 );
  h_corr[7]->SetBinContent(7,0.969995 );
  h_corr[7]->SetBinContent(9,0.969812 );
  h_corr[7]->SetBinContent(11,0.968786 );
  h_corr[7]->SetBinContent(13,0.965999 );
  h_corr[7]->SetBinContent(15,0.963978 );
  h_corr[7]->SetBinContent(17,0.961398 );
  h_corr[7]->SetBinContent(19,0.961739 );
  h_corr[7]->SetBinContent(21,0.958883 );
  h_corr[7]->SetBinContent(23,0.957226 );
  h_corr[7]->SetBinContent(25,0.951642 );
  h_corr[7]->SetBinContent(27,0.949062 );
  h_corr[7]->SetBinContent(29,0.942751 );
  h_corr[7]->SetBinContent(31,0.943376 );
  h_corr[7]->SetBinContent(33,0.965858 );
  h_corr[7]->SetBinContent(35,0.886708 );

  h_corr[8]->SetBinContent(1,0.981664 );
  h_corr[8]->SetBinContent(3,0.980179 );
  h_corr[8]->SetBinContent(5,0.977598 );
  h_corr[8]->SetBinContent(7,0.975469 );
  h_corr[8]->SetBinContent(9,0.974405 );
  h_corr[8]->SetBinContent(11,0.972435 );
  h_corr[8]->SetBinContent(13,0.971144 );
  h_corr[8]->SetBinContent(15,0.96725 );
  h_corr[8]->SetBinContent(17,0.965171 );
  h_corr[8]->SetBinContent(19,0.960089 );
  h_corr[8]->SetBinContent(21,0.956982 );
  h_corr[8]->SetBinContent(23,0.955285 );
  h_corr[8]->SetBinContent(25,0.951823 );
  h_corr[8]->SetBinContent(27,0.941622 );
  h_corr[8]->SetBinContent(29,0.933324 );
  h_corr[8]->SetBinContent(31,0.928404 );
  h_corr[8]->SetBinContent(33,0.916041 );
  h_corr[8]->SetBinContent(35,0.864879 );

  h_corr[9]->SetBinContent(1,0.984746 );
  h_corr[9]->SetBinContent(3,0.982545 );
  h_corr[9]->SetBinContent(5,0.980126 );
  h_corr[9]->SetBinContent(7,0.979537 );
  h_corr[9]->SetBinContent(9,0.976052 );
  h_corr[9]->SetBinContent(11,0.97363 );
  h_corr[9]->SetBinContent(13,0.971982 );
  h_corr[9]->SetBinContent(15,0.96612 );
  h_corr[9]->SetBinContent(17,0.962722 );
  h_corr[9]->SetBinContent(19,0.956838 );
  h_corr[9]->SetBinContent(21,0.954617 );
  h_corr[9]->SetBinContent(23,0.946593 );
  h_corr[9]->SetBinContent(25,0.930908 );
  h_corr[9]->SetBinContent(27,0.915928 );
  h_corr[9]->SetBinContent(29,0.920631 );
  h_corr[9]->SetBinContent(31,0.897547 );
  h_corr[9]->SetBinContent(33,0.876156 );
  h_corr[9]->SetBinContent(35,0.818965 );

  h_corr[10]->SetBinContent(1,0.988036 );
  h_corr[10]->SetBinContent(3,0.987029 );
  h_corr[10]->SetBinContent(5,0.983871 );
  h_corr[10]->SetBinContent(7,0.983178 );
  h_corr[10]->SetBinContent(9,0.980495 );
  h_corr[10]->SetBinContent(11,0.977938 );
  h_corr[10]->SetBinContent(13,0.975138 );
  h_corr[10]->SetBinContent(15,0.971418 );
  h_corr[10]->SetBinContent(17,0.962834 );
  h_corr[10]->SetBinContent(19,0.958912 );
  h_corr[10]->SetBinContent(21,0.948436 );
  h_corr[10]->SetBinContent(23,0.943919 );
  h_corr[10]->SetBinContent(25,0.92384 );
  h_corr[10]->SetBinContent(27,0.95076 );
  h_corr[10]->SetBinContent(29,0.904529 );
  h_corr[10]->SetBinContent(31,0.897547 );
  h_corr[10]->SetBinContent(33,0.868972 );
  h_corr[10]->SetBinContent(35,0.818965 );

  h_corr[11]->SetBinContent(1,0.990345 );
  h_corr[11]->SetBinContent(3,0.989017 );
  h_corr[11]->SetBinContent(5,0.986475 );
  h_corr[11]->SetBinContent(7,0.983991 );
  h_corr[11]->SetBinContent(9,0.981781 );
  h_corr[11]->SetBinContent(11,0.976278 );
  h_corr[11]->SetBinContent(13,0.97069 );
  h_corr[11]->SetBinContent(15,0.96604 );
  h_corr[11]->SetBinContent(17,0.94535 );
  h_corr[11]->SetBinContent(19,0.940475 );
  h_corr[11]->SetBinContent(21,0.9201 );
  h_corr[11]->SetBinContent(23,0.943919 );
  h_corr[11]->SetBinContent(25,0.92384 );
  h_corr[11]->SetBinContent(27,0.95076 );
  h_corr[11]->SetBinContent(29,0.904529 );
  h_corr[11]->SetBinContent(31,0.897547 );
  h_corr[11]->SetBinContent(33,0.868972 );
  h_corr[11]->SetBinContent(35,0.818965 );

  h_corr[12]->SetBinContent(1,0.990751 );
  h_corr[12]->SetBinContent(3,0.991295 );
  h_corr[12]->SetBinContent(5,0.988907 );
  h_corr[12]->SetBinContent(7,0.985201 );
  h_corr[12]->SetBinContent(9,0.982325 );
  h_corr[12]->SetBinContent(11,0.979082 );
  h_corr[12]->SetBinContent(13,0.970264 );
  h_corr[12]->SetBinContent(15,0.966628 );
  h_corr[12]->SetBinContent(17,0.952817 );
  h_corr[12]->SetBinContent(19,0.9342 );
  h_corr[12]->SetBinContent(21,0.9201 );
  h_corr[12]->SetBinContent(23,0.943919 );
  h_corr[12]->SetBinContent(25,0.92384 );
  h_corr[12]->SetBinContent(27,0.95076 );
  h_corr[12]->SetBinContent(29,0.904529 );
  h_corr[12]->SetBinContent(31,0.897547 );
  h_corr[12]->SetBinContent(33,0.868972 );
  h_corr[12]->SetBinContent(35,0.818965 );

  h_corr[13]->SetBinContent(1,0.991375 );
  h_corr[13]->SetBinContent(3,0.990764 );
  h_corr[13]->SetBinContent(5,0.98988 );
  h_corr[13]->SetBinContent(7,0.986238 );
  h_corr[13]->SetBinContent(9,0.98494 );
  h_corr[13]->SetBinContent(11,0.979488 );
  h_corr[13]->SetBinContent(13,0.974038 );
  h_corr[13]->SetBinContent(15,0.975949 );
  h_corr[13]->SetBinContent(17,0.927693 );
  h_corr[13]->SetBinContent(19,0.9342 );
  h_corr[13]->SetBinContent(21,0.9201 );
  h_corr[13]->SetBinContent(23,0.943919 );
  h_corr[13]->SetBinContent(25,0.92384 );
  h_corr[13]->SetBinContent(27,0.95076 );
  h_corr[13]->SetBinContent(29,0.904529 );
  h_corr[13]->SetBinContent(31,0.897547 );
  h_corr[13]->SetBinContent(33,0.868972 );
  h_corr[13]->SetBinContent(35,0.818965 );

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
  h_CBE_EB->SetBinContent(1, 0.992169); 
  h_CBE_EB->SetBinContent(3, 0.998226); 
  h_CBE_EB->SetBinContent(5, 0.999316); 
  h_CBE_EB->SetBinContent(7, 0.999764); 
  h_CBE_EB->SetBinContent(9, 1.00022); 
  h_CBE_EB->SetBinContent(11, 1.00028); 
  h_CBE_EB->SetBinContent(13, 0.999973); 
  h_CBE_EB->SetBinContent(15, 1.00006); 
  h_CBE_EB->SetBinContent(17, 1.00012); 
  h_CBE_EB->SetBinContent(19, 1.00035); 
  h_CBE_EB->SetBinContent(21, 1.00069); 
  h_CBE_EB->SetBinContent(23, 1.00106); 
  h_CBE_EB->SetBinContent(25, 1.00154); 
  h_CBE_EB->SetBinContent(27, 1.00139); 
  h_CBE_EB->SetBinContent(29, 1.00177); 
  h_CBE_EB->SetBinContent(31, 1.00158); 
  h_CBE_EB->SetBinContent(33, 1.00132); 
  h_CBE_EB->SetBinContent(35, 1.00079); 
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
  h_CBE_EE->SetBinContent(1, 0.882783); 
  h_CBE_EE->SetBinContent(3, 0.942349); 
  h_CBE_EE->SetBinContent(5, 0.968664); 
  h_CBE_EE->SetBinContent(7, 0.979249); 
  h_CBE_EE->SetBinContent(9, 0.98328); 
  h_CBE_EE->SetBinContent(11, 0.988222); 
  h_CBE_EE->SetBinContent(13, 0.990444); 
  h_CBE_EE->SetBinContent(15, 0.992744); 
  h_CBE_EE->SetBinContent(17, 0.994365); 
  h_CBE_EE->SetBinContent(19, 0.995717); 
  h_CBE_EE->SetBinContent(21, 0.996661); 
  h_CBE_EE->SetBinContent(23, 0.997681); 
  h_CBE_EE->SetBinContent(25, 0.999025); 
  h_CBE_EE->SetBinContent(27, 0.999434); 
  h_CBE_EE->SetBinContent(29, 0.999831); 
  h_CBE_EE->SetBinContent(31, 1.00012); 
  h_CBE_EE->SetBinContent(33, 1.00123); 
  h_CBE_EE->SetBinContent(35, 1.00111); 
  h_CBE_EE->SetBinContent(37, 1.00166); 
  h_CBE_EE->SetBinContent(39, 1.00189); 
  h_CBE_EE->SetBinContent(41, 1.00232); 
  h_CBE_EE->SetBinContent(43, 1.00238); 
  h_CBE_EE->SetBinContent(45, 1.00222); 
  h_CBE_EE->SetBinContent(47, 1.00245); 
  h_CBE_EE->SetBinContent(49, 1.00167); 
  h_CBE_EE->SetBinContent(51, 1.00091); 
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
