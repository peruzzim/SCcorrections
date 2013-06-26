Double_t applyScCorrectionsE_EE(Double_t E){      
  				 	  
 Double_t par0 = 500;               
 Double_t par1 = 0.99489 ;	  
 Double_t par2 = 1.29648e-05 ;     
  				 	  
  if (E  > par0 ) E = par0 ;   		  
  if (            E <   0     ) return      1.;  
  if (  0 <= E && E <=  par0  ) return      par1 + E*par2; 
						   
}                                           
               					        
Double_t F_applyScCorrectionsE_EE(Double_t *xx, Double_t *pp){  
  Double_t x = xx[0] ;                     
  return applyScCorrectionsE_EE(x);    		  
}		                          
