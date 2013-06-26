#include "TFile.h"                                                      
#include "TH1F.h"				                       
#include <iostream>  			                                
  			                                                

  	                                                                
                                                                         
Double_t applyScCorrectionsE_EB_PHOTONS(Double_t E){  							   
  Int_t iE      = -1;                                                                   
  for (Int_t iiE  = 0; iiE  < nBinsE;  ++iiE ){ 				      
    if ( leftE [iiE]  <= (E)      &&       (E) < rightE[iiE] ) {		      
      iE  = iiE;  								      
    }										      
  }										      
  if (E < leftE  [0] )         { iE = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: E < leftE  [0] )       " << std::endl;}   
  if (E > rightE [nBinsE-1] ) { iE = nBinsE-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: E > rightE [nBinsE-1] " << std::endl;}   
  if (iE == -1) { return 1;}					      
											      
  Int_t binE =  2*iE+1 ; // h_CBE_EB_PHOTONS->FindBin(E);                                    
  Double_t tmp = h_CBE_EB_PHOTONS->GetBinContent(binE);                                        
  if ( 0< binE && binE < 2*nBinsE+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  
                                                                         
Double_t applyScCorrectionsE_EE_PHOTONS(Double_t E){  							   
  Int_t iE      = -1;                                                                   
  for (Int_t iiE  = 0; iiE  < nBinsE;  ++iiE ){ 				      
    if ( leftE [iiE]  <= (E)      &&       (E) < rightE[iiE] ) {		      
      iE  = iiE;  								      
    }										      
  }										      
  if (E < leftE  [0] )         { iE = 0;              if (DBG) std::cout << " WARNING [applyScCorrections]: E < leftE  [0] )       " << std::endl;}   
  if (E > rightE [nBinsE-1] ) { iE = nBinsE-1;      if (DBG) std::cout << " WARNING [applyScCorrections]: E > rightE [nBinsE-1] " << std::endl;}   
  if (iE == -1) { return 1;}					      
											      
  Int_t binE =  2*iE+1 ; // h_CBE_EE_PHOTONS->FindBin(E);                                    
  Double_t tmp = h_CBE_EE_PHOTONS->GetBinContent(binE);                                        
  if ( 0< binE && binE < 2*nBinsE+1) return tmp;                          	      
  else return 1.;                                                               	      
                                                                                         
}                                                                               
                                                                                  

