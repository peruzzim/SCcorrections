#include "TFile.h"                                                     
#include "TH1F.h"				                        
#include <iostream>  			                                
  			                                                


Double_t applyScCorrectionsET_EB_PHOTONS(Double_t ET){  							   

  return 1;
  Int_t iET      = -1;                                                                   
  for (Int_t iiET  = 0; iiET  < nBinsET;  ++iiET ){ 				      
    if ( leftET [iiET]  <= (ET)      &&       (ET) < rightET[iiET] ) {		      
      iET  = iiET;  								      
    }										      
  }										      
  if (ET < leftET  [0] )         { iET = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: ET < leftET  [0] )       " << std::endl;}   
  if (ET > rightET [nBinsET-1] ) { iET = nBinsET-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: ET > rightET [nBinsET-1] " << std::endl;}   
  if (iET == -1) { return 1;}					      
											      
  Int_t binET =  2*iET+1 ; // h_CBET_EB_PHOTONS->FindBin(ET);                                    
  Double_t tmp = h_CBET_EB_PHOTONS->GetBinContent(binET);                                        
  if ( 0< binET && binET < 2*nBinsET+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
                                                                         
Double_t applyScCorrectionsET_EE_PHOTONS(Double_t ET){  							   
  return 1;
  Int_t iET      = -1;                                                                   
  for (Int_t iiET  = 0; iiET  < nBinsET;  ++iiET ){ 				      
    if ( leftET [iiET]  <= (ET)      &&       (ET) < rightET[iiET] ) {		      
      iET  = iiET;  								      
    }										      
  }										      
  if (ET < leftET  [0] )         { iET = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: ET < leftET  [0] )       " << std::endl;}   
  if (ET > rightET [nBinsET-1] ) { iET = nBinsET-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: ET > rightET [nBinsET-1] " << std::endl;}   
  if (iET == -1) { return 1;}					      
											      
  Int_t binET =  2*iET+1 ; // h_CBET_EE_PHOTONS->FindBin(ET);                                    
  Double_t tmp = h_CBET_EE_PHOTONS->GetBinContent(binET);                                        
  if ( 0< binET && binET < 2*nBinsET+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  

