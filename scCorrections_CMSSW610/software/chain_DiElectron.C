{
  TChain data("Tree");

  Int_t n = 0;
  TString path = "./TREES";
  n+=data.Add(path+"/RelValSingleElectronPt5to250_CMSSW_6_1_0_pre6_TS126203_TS126341_patch1_START61_V6.root",0);
    
  cout << "#files = " << n << endl;
}
