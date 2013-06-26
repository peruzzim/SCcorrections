



int Plotter(){

  //	gROOT->ProcessLine(".x setTDRStyle.C");
	
	TFile* f;
	
	double ErecEgenMin = 0.92;
	double ErecEgenMax = 1.08;
	
	bool doEB=false;
	bool doEE=true;
	
	if (doEB) f= new TFile("histos_compareSCcorrections_PHOTON_EB.root","read");
	if (doEE) f= new TFile("histos_compareSCcorrections_PHOTON_EE.root","read");
	
	string legendeEB = "Correction scheme, EB R9<0.94";
	string legendeEE = "Correction scheme, EE R9<0.95";
	
	string slegende, sceta, picturesuffix;
	if (doEB) {
		slegende = legendeEB;
		sceta = "C(#eta)";
		picturesuffix = "Photon_EB";
	}
	if (doEE) {
		slegende = legendeEE;
		sceta = "Raw";
		picturesuffix = "Photon_EE";
	}
	
	string extension = "pdf"; //pdf
	
	 
	//Pt
	TCanvas* CanvasPt = new TCanvas("CanvasPt","CanvasPt");
	
	ErecEgenMean_vsPtCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPtCeta->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenMean_vsPtCeta->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsPtCeta->SetAxisRange(0.98,1.06,"Y");
	if (doEE) ErecEgenMean_vsPtCeta->SetAxisRange(0.95,1.06,"Y");
	ErecEgenMean_vsPtCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsPtCeta->SetMarkerSize(1);
	ErecEgenMean_vsPtCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtCeta->Draw("P");
	
//
//	//ErecEgenMean_vsPtPhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsPtPhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsPtPhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsPtPhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsPtPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPtPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETH->Draw("Psame");

	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->Draw("Psame");
	
	
	
	TLine* line = new TLine(10,1,250,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsPtPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasPt->Update();
	CanvasPt->Draw();
	string pic = "ErecEgenMean_vsPt_" + picturesuffix + "." + extension;
	CanvasPt->Print(pic.c_str());
	
	//return;
	
	//Eta
	TCanvas* CanvasEta = new TCanvas("CanvasEta","CanvasEta");
	
	ErecEgenMean_vsEtaCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEtaCeta->SetXTitle("#eta");
	ErecEgenMean_vsEtaCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsEtaCeta->SetAxisRange(0.95,1.05,"Y");
	ErecEgenMean_vsEtaCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsEtaCeta->SetMarkerSize(1);
	ErecEgenMean_vsEtaCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaCeta->Draw("P");
	
//	
//	//ErecEgenMean_vsEtaPhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsEtaPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEtaPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line2;
	if (doEB) line2 = new TLine(-1.44,1,1.44,1);
	if (doEE) line2 = new TLine(-2.5,1,2.5,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEtaCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsEtaPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEtaPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasEta->Update();
	CanvasEta->Draw();
	string pic = "ErecEgenMean_vsEta_" + picturesuffix + "." + extension;
	CanvasEta->Print(pic.c_str());
	
	//return;
	
	//Phi
	TCanvas* CanvasPhi = new TCanvas("CanvasPhi","CanvasPhi");
	
	ErecEgenMean_vsPhiCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPhiCeta->SetXTitle("#phi");
	ErecEgenMean_vsPhiCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPhiCeta->SetAxisRange(0.95,1.05,"Y");
	ErecEgenMean_vsPhiCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsPhiCeta->SetMarkerSize(1);
	ErecEgenMean_vsPhiCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiCeta->Draw("P");
	
//	
//	//ErecEgenMean_vsPhiPhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsPhiPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPhiPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsPhiPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasPhi->Update();
	CanvasPhi->Draw();	
	string pic =  "ErecEgenMean_vsPhi_" + picturesuffix + "." + extension;
	CanvasPhi->Print(pic.c_str());

	//Brem
	TCanvas* CanvasBrem = new TCanvas("CanvasBrem","CanvasBrem");
	
	ErecEgenMean_vsBremCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsBremCeta->SetXTitle("#sigma_{#phi}/#sigma_{#eta}");
	ErecEgenMean_vsBremCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsBremCeta->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsBremCeta->SetMarkerSize(1);
	ErecEgenMean_vsBremCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremCeta->Draw("P");
	
//	
//	//ErecEgenMean_vsBremPhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsBremPhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsBremPhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsBremPhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsBremPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsBremPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETH->Draw("Psame");

	//ErecEgenMean_vsBremPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsBremPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasBrem->Update();
	CanvasBrem->Draw();	
	string pic =  "ErecEgenMean_vsBrem_" + picturesuffix + "." + extension;
	CanvasBrem->Print(pic.c_str());

	
	//R9
	TCanvas* CanvasR9 = new TCanvas("CanvasR9","CanvasR9");
	
	ErecEgenMean_vsR9Ceta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsR9Ceta->SetXTitle("R9");
	ErecEgenMean_vsR9Ceta->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsR9Ceta->SetAxisRange(0.92,1.08,"Y");
	if (doEE)ErecEgenMean_vsR9Ceta->SetAxisRange(0.8,1.2,"Y");
	ErecEgenMean_vsR9Ceta->SetMarkerColor(kBlack);
	ErecEgenMean_vsR9Ceta->SetMarkerSize(1);
	ErecEgenMean_vsR9Ceta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9Ceta->Draw("P");
	
//	
//	//ErecEgenMean_vsR9PhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsR9PhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsR9PhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsR9PhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsR9PhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsR9PhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETH->Draw("Psame");

	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9Ceta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsR9PhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasR9->Update();
	CanvasR9->Draw();	
	string pic =  "ErecEgenMean_vsR9_" + picturesuffix + "." + extension;
	CanvasR9->Print(pic.c_str());

	
	//return;
	
	
	//Energy
	TCanvas* CanvasEnergy = new TCanvas("CanvasEnergy","CanvasEnergy");
	
	ErecEgenMean_vsEnergyCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEnergyCeta->SetXTitle("Energy (GeV)");
	ErecEgenMean_vsEnergyCeta->GetYaxis()->SetTitleOffset(1.5);
	
	if (doEB) {
		ErecEgenMean_vsEnergyCeta->SetAxisRange(0.98,1.06,"Y");
		ErecEgenMean_vsEnergyCeta->SetAxisRange(0,450,"X");
	}
	if (doEE) {
		ErecEgenMean_vsEnergyCeta->SetAxisRange(0.9,1.1,"Y");
		ErecEgenMean_vsEnergyCeta->SetAxisRange(0,850,"X");
	}
	ErecEgenMean_vsEnergyCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsEnergyCeta->SetMarkerSize(1);
	ErecEgenMean_vsEnergyCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyCeta->Draw("P");
	
//	
//	//ErecEgenMean_vsEnergyPhotonOldAF->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
//	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerColor(kBlue);
//	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerSize(1);
//	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerStyle(kFullDotLarge);
//	ErecEgenMean_vsEnergyPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEnergyPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line;
	if (doEB) line = new TLine(0,1,450,1);
	if (doEE) line = new TLine(0,1,850,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEnergyCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsEnergyPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->Draw();
	CanvasEnergy->Update();
	CanvasEnergy->Draw();
	string pic =  "ErecEgenMean_vsEnergy_" + picturesuffix + "." + extension;
	CanvasEnergy->Print(pic.c_str());
	//CanvasEnergy->Print("ErecEgenMean_vsEnergy.gif");
	
	
	
	return;
	
	
	/*
	//SIGMA EFF
	
	double SigmaMin = 0;
	double SigmaMax = 0.1;
	
	//Pt
	TCanvas* CanvasSigmaPt = new TCanvas("CanvasSigmaPt","CanvasSigmaPt");
	
	ErecEgenSigmaEff_vsPtCeta->SetYTitle("#sigma_{eff} E_{rec}/E_{gen}");
	ErecEgenSigmaEff_vsPtCeta->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenSigmaEff_vsPtCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenSigmaEff_vsPtCeta->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPtCeta->SetMarkerColor(kBlack);
	ErecEgenSigmaEff_vsPtCeta->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPtCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPtCeta->Draw("P");
	
	
	//ErecEgenSigmaEff_vsPtPhotonOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPtPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsPtPhotonOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPtPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPtPhotonOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsPtPhotonNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPtPhotonNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsPtPhotonNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPtPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPtPhotonNewETH->Draw("Psame");
	
	TLine* line = new TLine(10,1,250,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsPtCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPtPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPtPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasSigmaPt->Update();
	CanvasSigmaPt->Draw();
	CanvasSigmaPt->Print("ErecEgenSigma_vsPt.gif");
	
	//Eta
	TCanvas* CanvasSigmaEta = new TCanvas("CanvasSigmaEta","CanvasSigmaEta");
	
	ErecEgenSigmaEff_vsEtaCeta->SetYTitle("#sigma_{eff} E_{rec}/E_{gen}");
	ErecEgenSigmaEff_vsEtaCeta->SetXTitle("#eta");
	ErecEgenSigmaEff_vsEtaCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenSigmaEff_vsEtaCeta->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsEtaCeta->SetMarkerColor(kBlack);
	ErecEgenSigmaEff_vsEtaCeta->SetMarkerSize(1);
	ErecEgenSigmaEff_vsEtaCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsEtaCeta->Draw("P");
	
	
	//ErecEgenSigmaEff_vsEtaPhotonOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsEtaPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsEtaPhotonOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsEtaPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsEtaPhotonOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsEtaPhotonNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsEtaPhotonNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsEtaPhotonNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsEtaPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsEtaPhotonNewETH->Draw("Psame");
	
	TLine* line2 = new TLine(-1.44,1,1.44,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsEtaCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsEtaPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsEtaPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasSigmaEta->Update();
	CanvasSigmaEta->Draw();
	CanvasSigmaEta->Print("ErecEgenSigma_vsEta.gif");
	
	//Phi
	TCanvas* CanvasSigmaPhi = new TCanvas("CanvasSigmaPhi","CanvasSigmaPhi");
	
	ErecEgenSigmaEff_vsPhiCeta->SetYTitle("#sigma_{eff} E_{rec}/E_{gen}");
	ErecEgenSigmaEff_vsPhiCeta->SetXTitle("#phi");
	ErecEgenSigmaEff_vsPhiCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenSigmaEff_vsPhiCeta->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPhiCeta->SetMarkerColor(kBlack);
	ErecEgenSigmaEff_vsPhiCeta->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPhiCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPhiCeta->Draw("P");
	
	
	//ErecEgenSigmaEff_vsPhiPhotonOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPhiPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsPhiPhotonOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPhiPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPhiPhotonOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsPhiPhotonNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPhiPhotonNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsPhiPhotonNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPhiPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPhiPhotonNewETH->Draw("Psame");
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsPhiCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPhiPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPhiPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasSigmaPhi->Update();
	CanvasSigmaPhi->Draw();	
	CanvasSigmaPhi->Print("ErecEgenSigma_vsPhi.gif");
	
	//Brem
	TCanvas* CanvasSigmaBrem = new TCanvas("CanvasSigmaBrem","CanvasSigmaBrem");
	
	ErecEgenSigmaEff_vsBremCeta->SetYTitle("#sigma_{eff} E_{rec}/E_{gen}");
	ErecEgenSigmaEff_vsBremCeta->SetXTitle("#sigma_{#phi}/#sigma_{#eta}");
	ErecEgenSigmaEff_vsBremCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenSigmaEff_vsBremCeta->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsBremCeta->SetMarkerColor(kBlack);
	ErecEgenSigmaEff_vsBremCeta->SetMarkerSize(1);
	ErecEgenSigmaEff_vsBremCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsBremCeta->Draw("P");
	
	
	//ErecEgenSigmaEff_vsBremPhotonOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsBremPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsBremPhotonOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsBremPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsBremPhotonOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsBremPhotonNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsBremPhotonNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsBremPhotonNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsBremPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsBremPhotonNewETH->Draw("Psame");
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsBremCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsBremPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsBremPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasSigmaBrem->Update();
	CanvasSigmaBrem->Draw();	
	CanvasSigmaBrem->Print("ErecEgenSigma_vsBrem.gif");
	
	//R9
	TCanvas* CanvasSigmaR9 = new TCanvas("CanvasSigmaR9","CanvasSigmaR9");
	
	ErecEgenSigmaEff_vsR9Ceta->SetYTitle("#sigma_{eff} E_{rec}/E_{gen}");
	ErecEgenSigmaEff_vsR9Ceta->SetXTitle("R9");
	ErecEgenSigmaEff_vsR9Ceta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenSigmaEff_vsR9Ceta->SetAxisRange(0,0.15,"Y");
	ErecEgenSigmaEff_vsR9Ceta->SetMarkerColor(kBlack);
	ErecEgenSigmaEff_vsR9Ceta->SetMarkerSize(1);
	ErecEgenSigmaEff_vsR9Ceta->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsR9Ceta->Draw("P");
	
	
	//ErecEgenSigmaEff_vsR9PhotonOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsR9PhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsR9PhotonOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsR9PhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsR9PhotonOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsR9PhotonNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsR9PhotonNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsR9PhotonNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsR9PhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsR9PhotonNewETH->Draw("Psame");
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsR9Ceta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsR9PhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsR9PhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasSigmaR9->Update();
	CanvasSigmaR9->Draw();	
	CanvasSigmaR9->Print("ErecEgenSigma_vsR9.gif");
	*/
	
	
	//return;
	
	//Comparaison detaillee brem, eta, et
	
	//Pt
	TCanvas* CanvasDetailPt = new TCanvas("CanvasDetailPt","CanvasDetailPt");
	
	ErecEgenMean_vsPtPhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPtPhotonOldAFbremOnly->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenMean_vsPtPhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsPtPhotonOldAFbremOnly->SetAxisRange(0.99,1.02,"Y");
	if (doEE) ErecEgenMean_vsPtPhotonOldAFbremOnly->SetAxisRange(0.98,1.02,"Y");
	ErecEgenMean_vsPtPhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsPtPhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsPtPhotonOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsPtPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsPtPhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPtPhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtPhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPtPhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsPtPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETH->Draw("Psame");
	
	TLine* line = new TLine(10,1,200,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtPhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailPt->Update();
	CanvasDetailPt->Draw();
	string pic =  "ErecEgenMean_vsPt_" + picturesuffix + "_detail.gif";
	CanvasDetailPt->Print(pic.c_str());
	//CanvasDetailPt->Print("ErecEgenMean_vsPt_detail.gif");

	//return;
	
	//Eta
	TCanvas* CanvasDetailEta = new TCanvas("CanvasDetailEta","CanvasDetailEta");
	
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetXTitle("#eta");
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetAxisRange(0.97,1.03,"Y");
	if (doEE) ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetAxisRange(0.97,1.03,"Y");
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsEtaPhotonOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsEtaPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETH->Draw("Psame");
	
	TLine* line2;
	if (doEB) line2 = new TLine(-1.44,1,1.44,1);
	if (doEE) line2 = new TLine(-2.5,1,2.5,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEtaPhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEtaPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEtaPhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEtaPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailEta->Update();
	CanvasDetailEta->Draw();
	string pic =  "ErecEgenMean_vsEta_" + picturesuffix + "_detail.gif";
	CanvasDetailEta->Print(pic.c_str());
	//CanvasDetailEta->Print("ErecEgenMean_vsEta_detail.gif");
	
	//return;
	
	//Phi
	TCanvas* CanvasDetailPhi = new TCanvas("CanvasDetailPhi","CanvasDetailPhi");
	
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetXTitle("#phi");
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetAxisRange(0.98,1.03,"Y");
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsPhiPhotonOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsPhiPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETH->Draw("Psame");
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiPhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailPhi->Update();
	CanvasDetailPhi->Draw();
	string pic =  "ErecEgenMean_vsPhi_" + picturesuffix + "_detail.gif";
	CanvasDetailPhi->Print(pic.c_str());
	//CanvasDetailPhi->Print("ErecEgenMean_vsPhi_detail.gif");
	
	//return;
	
	//Brem
	TCanvas* CanvasDetailBrem = new TCanvas("CanvasDetailBrem","CanvasDetailBrem");
	
	ErecEgenMean_vsBremPhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsBremPhotonOldAFbremOnly->SetXTitle("#sigma_{#phi}/#sigma_{#eta}");
	ErecEgenMean_vsBremPhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsBremPhotonOldAFbremOnly->SetAxisRange(0.98,1.03,"Y");
	if (doEE) ErecEgenMean_vsBremPhotonOldAFbremOnly->SetAxisRange(0.95,1.08,"Y");
	ErecEgenMean_vsBremPhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsBremPhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsBremPhotonOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsBremPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsBremPhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsBremPhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsBremPhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsBremPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETH->Draw("Psame");
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremPhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailBrem->Update();
	CanvasDetailBrem->Draw();
	string pic =  "ErecEgenMean_vsBrem_" + picturesuffix + "_detail.gif";
	CanvasDetailBrem->Print(pic.c_str());
	//CanvasDetailBrem->Print("ErecEgenMean_vsBrem_detail.gif");
	
	//return;
	
	//R9
	TCanvas* CanvasDetailR9 = new TCanvas("CanvasDetailR9","CanvasDetailR9");
	
	ErecEgenMean_vsR9PhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsR9PhotonOldAFbremOnly->SetXTitle("R9");
	ErecEgenMean_vsR9PhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsR9PhotonOldAFbremOnly->SetAxisRange(0.96,1.04,"Y");
	if (doEE) ErecEgenMean_vsR9PhotonOldAFbremOnly->SetAxisRange(0.8,1.2,"Y");
	ErecEgenMean_vsR9PhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsR9PhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsR9PhotonOldAF->SetAxisRange(0.96,1.04,"Y");
	ErecEgenMean_vsR9PhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsR9PhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsR9PhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9PhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsR9PhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsR9PhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETH->Draw("Psame");
	
	TLine* line5;
	if (doEB) line5 = new TLine(0,1,0.94,1);
	if (doEE) line5 = new TLine(0,1,0.95,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9PhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailR9->Update();
	CanvasDetailR9->Draw();
	string pic =  "ErecEgenMean_vsR9_" + picturesuffix + "_detail.gif";
	CanvasDetailR9->Print(pic.c_str());
	//CanvasDetailR9->Print("ErecEgenMean_vsR9_detail.gif");

	
	
	//Energy
	TCanvas* CanvasDetailEnergy = new TCanvas("CanvasDetailEnergy","CanvasDetailEnergy");
	
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetXTitle("Energy (GeV)");
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetAxisRange(0.99,1.02,"Y");
	if (doEE) ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetAxisRange(0.9,1.1,"Y");
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsEnergyPhotonOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsEnergyPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETH->Draw("Psame");
	
	TLine* line6 = new TLine(0,1,500,1);
	line6->SetLineWidth(2);
	line6->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonOldAFbremOnly->GetName(), "f(Brem) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonNewETHbremetaOnly->GetName(), "f(Brem,#eta) photon", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->Draw();
	CanvasDetailEnergy->Update();
	CanvasDetailEnergy->Draw();
	string pic =  "ErecEgenMean_vsEnergy_" + picturesuffix + "_detail.gif";
	CanvasDetailEnergy->Print(pic.c_str());
	//CanvasDetailEnergy->Print("ErecEgenMean_vsEnergy_detail.gif");
	
		return 0;
}














