void comp(TString f1n, TString f2n, TString mode, bool sepplots=true){

  int nplots=0;

  TFile *f[2];
  f[0] = new TFile(f1n.Data(),"read");
  f[1] = new TFile(f2n.Data(),"read");

  TH1F *h[3][14];


  if (mode=="brEta"){
    nplots=14;
    TString hname="h_corr";
    for (int j=0; j<2; j++) for (int i=0; i<nplots; i++) f[j]->GetObject(Form("%s_%d",hname.Data(),i),h[j][i]);
  }
  else if (mode=="ET"){
    nplots=2;
    for (int j=0; j<2; j++) {
      f[j]->GetObject("h_CBET_EB",h[j][0]);
      f[j]->GetObject("h_CBET_EE",h[j][1]);
      assert (h[j][0]!=NULL);
    }
  }
  else if (mode=="E"){
    nplots=2;
    for (int j=0; j<2; j++) {
      f[j]->GetObject("h_CBE_EB",h[j][0]);
      f[j]->GetObject("h_CBE_EE",h[j][1]);
    }
  }

  for (int i=0; i<nplots; i++) {
    h[0][i]->SetMarkerColor(kBlue);
    h[1][i]->SetMarkerColor(kRed);
  }


  TCanvas *canv[14];
  TLegend *leg[14];

  if (sepplots){
    for (int i=0; i<nplots; i++) {
      canv[i]=new TCanvas();
      canv[i]->cd();
      h[0][i]->SetAxisRange(0.8,1.05,"Y");
      h[0][i]->Draw();
      h[1][i]->Draw("same");
      h[2][i]=(TH1F*)(h[0][i]->Clone());
      h[2][i]->Divide(h[1][i]);
      h[2][i]->SetMarkerColor(1);
      h[2][i]->Draw("same");
      leg[i]=new TLegend(0.7,0.3,0.9,0.5);
      leg[i]->AddEntry(h[0][i],"600pre4","p");
      leg[i]->AddEntry(h[1][i],"52","p");
      leg[i]->AddEntry(h[2][i],"ratio","p");
      leg[i]->Draw();
      canv[i]->Print(Form("comparison_%s_%d.png",mode.Data(),i));
    }
  }
  else{
    canv[0]=new TCanvas();
    canv[0]->GetPad(0)->DivideSquare(nplots);
    for (int i=0; i<nplots; i++) {
      canv[0]->cd(i+1);
      h[0][i]->SetAxisRange(0.8,1.05,"Y");
      h[0][i]->Draw();
      h[1][i]->Draw("same");
    }
  }



}
