Double_t applyScCorrectionsET_EB(Double_t ET){      
   				 	  
  Double_t par0 = 0.974329; 
  Double_t par1 = 0.999405; 
  Double_t par2 = 5.59569e-06; 
  Double_t par3 = 0.0533371; 
  Double_t par4 = -8.23504; 

  if (ET > 200) ET =200;   		  
  if (             ET <    5 ) return         1.;  
  if (  5 <= ET && ET <   10 ) return         par0 ;  
  if ( 10 <= ET && ET <= 200 ) return         (par1  + ET*par2)*(1- par3*exp(ET/ par4));
 						  
}                                           
                					        
Double_t F_applyScCorrectionsET_EB(Double_t *xx, Double_t *pp){  
  Double_t x = xx[0] ;                     
  return applyScCorrectionsET_EB(x);    		  
}		                          
  		                          
//Double_t applyScCorrectionsET_EE(Double_t ET){      
//   				 	  
//  Double_t par0 = 0.94162; 
//  Double_t par1 = 0.996168; 
//  Double_t par2 = 3.78712e-05; 
//  Double_t par3 = 0.0482788; 
//  Double_t par4 = -19.1232; 
//
//  if (ET > 200) ET =200;   		  
//  if (             ET <    5 ) return         1.;  
//  if (  5 <= ET && ET <   10 ) return         par0;  
//  if ( 10 <= ET && ET <= 200 ) return         ( par1  + ET*par2)*(1-par3*exp(ET/par4));
// 						  
//}                                           
//                					        
//Double_t F_applyScCorrectionsET_EE(Double_t *xx, Double_t *pp){  
//  Double_t x = xx[0] ;                     
//  return applyScCorrectionsET_EE(x);    		  
//}		                          
