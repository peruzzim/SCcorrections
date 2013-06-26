



int Plotter(){

  //	gROOT->ProcessLine(".x setTDRStyle.C");
	
	TFile* f;
	
	double ErecEgenMin = 0.92;
	double ErecEgenMax = 1.08;
	
	bool doEB=0;
	bool doEE=!doEB;
	
	if (doEB) f= new TFile("histos_compareSCcorrections_PHOTON_EB.root","read");
	if (doEE) f= new TFile("histos_compareSCcorrections_PHOTON_EE.root","read");
	
	string legendeEB = "Correction scheme, EB R9<0.94";
	string legendeEE = "Correction scheme, EE R9<0.95";
	
	string slegende, sceta, picturesuffix;
	if (doEB) {
		slegende = legendeEB;
		sceta = "C(#eta) (610), 610 corrs (fitted)";
		picturesuffix = "Photon_EB";
	}
	if (doEE) {
		slegende = legendeEE;
		sceta = "Raw (610), 610 corrs (fitted)";
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
	
	
	//ErecEgenMean_vsPtPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETH->Draw("Psame");

	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsPtDefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPtDefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtDefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtPhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsPtDefaultCorrEnergy->Draw("Psame");

	
	TLine* line = new TLine(10,1,250,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsPtPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPtDefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
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
	
	
	//ErecEgenMean_vsEtaPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsEtaDefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEtaDefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaDefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaPhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsEtaDefaultCorrEnergy->Draw("Psame");
	
	
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
	legende->AddEntry(ErecEgenMean_vsEtaDefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
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
	
	//ErecEgenMean_vsPhiPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsPhiDefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPhiDefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiDefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsPhiDefaultCorrEnergy->Draw("Psame");
	
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsPhiPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->AddEntry(ErecEgenMean_vsPhiDefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
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
	
	
	//ErecEgenMean_vsBremPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETH->Draw("Psame");

	//ErecEgenMean_vsBremPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsBremDefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsBremDefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremDefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremPhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsBremDefaultCorrEnergy->Draw("Psame");
	
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremCeta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsBremPhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremPhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->AddEntry(ErecEgenMean_vsBremDefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
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
	
	
	//ErecEgenMean_vsR9PhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETH->Draw("Psame");

	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsR9DefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsR9DefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9DefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9PhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsR9DefaultCorrEnergy->Draw("Psame");
	
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9Ceta->GetName(), sceta.c_str(), "p");
//	legende->AddEntry(ErecEgenMean_vsR9PhotonOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9PhotonNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) photon", "p");
	legende->AddEntry(ErecEgenMean_vsR9DefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
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
	
	
	//ErecEgenMean_vsEnergyPhotonNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETH->Draw("Psame");
	
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerColor(kMagenta);
	ErecEgenMean_vsEnergyDefaultCorrEnergy->SetMarkerColor(kYellow);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEnergyDefaultCorrEnergy->SetMarkerSize(1);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyDefaultCorrEnergy->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyPhotonNewETHEnergyScheme->Draw("Psame");
	ErecEgenMean_vsEnergyDefaultCorrEnergy->Draw("Psame");
	
	
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
	legende->AddEntry(ErecEgenMean_vsEnergyDefaultCorrEnergy->GetName(), "default SC corrected energy (53X corrs)", "p");
	legende->Draw();
	CanvasEnergy->Update();
	CanvasEnergy->Draw();
	string pic =  "ErecEgenMean_vsEnergy_" + picturesuffix + "." + extension;
	CanvasEnergy->Print(pic.c_str());
	//CanvasEnergy->Print("ErecEgenMean_vsEnergy.gif");
	
	
	
	return;
	
	
}














