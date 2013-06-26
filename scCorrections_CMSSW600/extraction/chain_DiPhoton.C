{
  TChain data("Tree");

  Int_t n = 0;
  TString path = "../../nobackup/";
  n+=data.Add(path+"singlephoton_600pre4_minitree_2GAMMA.root",0);
    
  cout << "#files = " << n << endl;
}
