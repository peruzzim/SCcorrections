{
  TChain data("Tree");

  Int_t n = 0;
  TString path = "../../nobackup/";
  //  n+=data.Add(path+"DiElectrons_600pre2_AF_minitree.root",0);
  n+=data.Add(path+"singleelectron_600pre4_minitree_2GAMMA.root",0);
  
  cout << "#files = " << n << endl;
}
