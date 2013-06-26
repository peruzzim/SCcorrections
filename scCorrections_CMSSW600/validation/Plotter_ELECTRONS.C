


int Plotter_ELECTRONS(){

  //	gROOT->ProcessLine(".x setTDRStyle.C");
	
	TFile* f;
	
	double ErecEgenMin = 0.92;
	double ErecEgenMax = 1.08;
	
	bool doEB=false;
	bool doEE=true;
	
	
	if (doEB) f= new TFile("histos_compareSCcorrections_ELECTRON_EB.root","read");
	if (doEE) f= new TFile("histos_compareSCcorrections_ELECTRON_EE.root","read");
	
	string legendeEB = "Electron EB";
	string legendeEE = "Electron EE";
	
	string slegende, sceta, picturesuffix;
	if (doEB) {
		slegende = legendeEB;
		sceta = "C(#eta)";
		picturesuffix = "Electron_EB";
	}
	if (doEE) {
		slegende = legendeEE;
		sceta = "Raw";
		picturesuffix = "Electron_EE";
	}
	
	string extension = "pdf";//pdf

	 
	//Pt
	TCanvas* CanvasPt = new TCanvas("CanvasPt","CanvasPt");
	
	ErecEgenMean_vsPtCeta->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPtCeta->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenMean_vsPtCeta->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPtCeta->SetAxisRange(0,200,"X");
	if (doEB) ErecEgenMean_vsPtCeta->SetAxisRange(0.96,1.05,"Y");
	if (doEE) ErecEgenMean_vsPtCeta->SetAxisRange(0.95,1.06,"Y");
	ErecEgenMean_vsPtCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsPtCeta->SetMarkerSize(1);
	ErecEgenMean_vsPtCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtCeta->Draw("P");
	
//	
	//ErecEgenMean_vsPtElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->Draw("Psame");

	
	TLine* line = new TLine(5,1,200,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtCeta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsPtElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	
	legende->Draw();
	CanvasPt->Update();
	CanvasPt->Draw();
	string pic = "ErecEgenMean_vsPt_" + picturesuffix + "." + extension;
	CanvasPt->Print(pic.c_str());
	//CanvasPt->Print("ErecEgenMean_vsPt.gif");
	
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
//	//ErecEgenMean_vsEtaElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->Draw("Psame");
		
	
	TLine* line2;
	if (doEB) line2 = new TLine(-1.44,1,1.44,1);
	if (doEE) line2 = new TLine(-2.5,1,2.5,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEtaCeta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsEtaElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasEta->Update();
	CanvasEta->Draw();
	string pic = "ErecEgenMean_vsEta_" + picturesuffix + "." + extension;
	CanvasEta->Print(pic.c_str());
	//CanvasEta->Print("ErecEgenMean_vsEta.gif");
	
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
//	//ErecEgenMean_vsPhiElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->Draw("Psame");
	
	
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiCeta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsPhiElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasPhi->Update();
	CanvasPhi->Draw();	
	string pic =  "ErecEgenMean_vsPhi_" + picturesuffix + "." + extension;
	CanvasPhi->Print(pic.c_str());
	//CanvasPhi->Print("ErecEgenMean_vsPhi.gif");

	//return;
	
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
//	//ErecEgenMean_vsBremElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremCeta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsBremElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasBrem->Update();
	CanvasBrem->Draw();	
	string pic =  "ErecEgenMean_vsBrem_" + picturesuffix + "." + extension;
	CanvasBrem->Print(pic.c_str());
	//CanvasBrem->Print("ErecEgenMean_vsBrem.gif");
	
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
//	//ErecEgenMean_vsR9ElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9Ceta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsR9ElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasR9->Update();
	CanvasR9->Draw();	
	//CanvasR9->Print("ErecEgenMean_vsR9.gif");
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
		ErecEgenMean_vsEnergyCeta->SetAxisRange(0,1000,"X");
	}
	ErecEgenMean_vsEnergyCeta->SetMarkerColor(kBlack);
	ErecEgenMean_vsEnergyCeta->SetMarkerSize(1);
	ErecEgenMean_vsEnergyCeta->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyCeta->Draw("P");
	
//	
//	//ErecEgenMean_vsEnergyElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->Draw("Psame");
	
	
	TLine* line;
	if (doEB) line = new TLine(0,1,450,1);
	if (doEE) line = new TLine(0,1,1000,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEnergyCeta->GetName(), sceta.c_str(), "p");
	//legende->AddEntry(ErecEgenMean_vsEnergyElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasEnergy->Update();
	CanvasEnergy->Draw();
	//CanvasEnergy->Print("ErecEgenMean_vsEnergy.gif");
	string pic =  "ErecEgenMean_vsEnergy_" + picturesuffix + "." + extension;
	CanvasEnergy->Print(pic.c_str());
	
	
	return;
	
	
	
	
	//Pt
	TCanvas* CanvasPt_detail = new TCanvas("CanvasPt_detail","CanvasPt_detail");
	
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetAxisRange(0.96,1.05,"Y");
	if (doEE) ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetAxisRange(0.95,1.06,"Y");
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsPtElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line = new TLine(5,1,200,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsPtElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	
	legende->Draw();
	CanvasPt_detail->Update();
	CanvasPt_detail->Draw();
	string pic = "ErecEgenMean_vsPt_" + picturesuffix + "_detail.gif";
	CanvasPt_detail->Print(pic.c_str());
	//CanvasPt->Print("ErecEgenMean_vsPt.gif");
	
	//return;
	
	//Eta
	TCanvas* CanvasEta_detail = new TCanvas("CanvasEta_detail","CanvasEta_detail");
	
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetXTitle("#eta");
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetAxisRange(0.95,1.05,"Y");
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsEtaElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line2;
	if (doEB) line2 = new TLine(-1.44,1,1.44,1);
	if (doEE) line2 = new TLine(-2.5,1,2.5,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsEtaElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasEta_detail->Update();
	CanvasEta_detail->Draw();
	string pic = "ErecEgenMean_vsEta_" + picturesuffix + "_detail.gif";
	CanvasEta_detail->Print(pic.c_str());
	//CanvasEta->Print("ErecEgenMean_vsEta.gif");
	
	//return;
	
	//Phi
	TCanvas* CanvasPhi_detail = new TCanvas("CanvasPhi_detail","CanvasPhi_detail");
	
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetXTitle("#phi");
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetAxisRange(0.95,1.05,"Y");
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsPhiElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsPhiElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasPhi_detail->Update();
	CanvasPhi_detail->Draw();	
	string pic =  "ErecEgenMean_vsPhi_" + picturesuffix + "_detail.gif";
	CanvasPhi_detail->Print(pic.c_str());
	//CanvasPhi->Print("ErecEgenMean_vsPhi.gif");
	
	//Brem
	TCanvas* CanvasBrem_detail = new TCanvas("CanvasBrem_detail","CanvasBrem_detail");
	
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetXTitle("#sigma_{#phi}/#sigma_{#eta}");
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsBremElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsBremElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasBrem_detail->Update();
	CanvasBrem_detail->Draw();	
	string pic =  "ErecEgenMean_vsBrem_" + picturesuffix + "_detail.gif";
	CanvasBrem_detail->Print(pic.c_str());
	//CanvasBrem->Print("ErecEgenMean_vsBrem.gif");
	
	//R9
	TCanvas* CanvasR9_detail = new TCanvas("CanvasR9_detail","CanvasR9_detail");
	
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetXTitle("R9");
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetAxisRange(0.92,1.08,"Y");
	if (doEE)ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetAxisRange(0.8,1.2,"Y");
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsR9ElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsR9ElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasR9_detail->Update();
	CanvasR9_detail->Draw();	
	//CanvasR9->Print("ErecEgenMean_vsR9.gif");
	string pic =  "ErecEgenMean_vsR9_" + picturesuffix + "_detail.gif";
	CanvasR9_detail->Print(pic.c_str());
	
	//return;
	
	
	//Energy
	TCanvas* CanvasEnergy_detail = new TCanvas("CanvasEnergy_detail","CanvasEnergy_detail");
	
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetXTitle("Energy (GeV)");
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetAxisRange(0.98,1.06,"Y");
	if (doEE) ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetAxisRange(0.9,1.1,"Y");
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->Draw("P");
	
	//ErecEgenMean_vsEnergyElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETH->Draw("Psame");
	
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerColor(kBlue);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->Draw("Psame");
	
	TLine* line = new TLine(0,1,500,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	//legende->AddEntry(ErecEgenMean_vsEnergyElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETHEnergyScheme->GetName(), "f(Brem,#eta) #times F(Energy) Electron", "p");
	legende->Draw();
	CanvasEnergy_detail->Update();
	CanvasEnergy_detail->Draw();
	//CanvasEnergy->Print("ErecEgenMean_vsEnergy.gif");
	string pic =  "ErecEgenMean_vsEnergy_" + picturesuffix + "_detail.gif";
	CanvasEnergy_detail->Print(pic.c_str());
	
	
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
	
	
	//ErecEgenSigmaEff_vsPtElectronOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPtElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsPtElectronOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPtElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPtElectronOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsPtElectronNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPtElectronNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsPtElectronNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPtElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPtElectronNewETH->Draw("Psame");
	
	TLine* line = new TLine(10,1,250,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsPtCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPtElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPtElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
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
	
	
	//ErecEgenSigmaEff_vsEtaElectronOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsEtaElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsEtaElectronOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsEtaElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsEtaElectronOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsEtaElectronNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsEtaElectronNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsEtaElectronNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsEtaElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsEtaElectronNewETH->Draw("Psame");
	
	TLine* line2 = new TLine(-1.44,1,1.44,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsEtaCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsEtaElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsEtaElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
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
	
	
	//ErecEgenSigmaEff_vsPhiElectronOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPhiElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsPhiElectronOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPhiElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPhiElectronOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsPhiElectronNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsPhiElectronNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsPhiElectronNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsPhiElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsPhiElectronNewETH->Draw("Psame");
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsPhiCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPhiElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsPhiElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
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
	
	
	//ErecEgenSigmaEff_vsBremElectronOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsBremElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsBremElectronOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsBremElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsBremElectronOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsBremElectronNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsBremElectronNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsBremElectronNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsBremElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsBremElectronNewETH->Draw("Psame");
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsBremCeta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsBremElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsBremElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
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
	
	
	//ErecEgenSigmaEff_vsR9ElectronOldAF->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsR9ElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenSigmaEff_vsR9ElectronOldAF->SetMarkerSize(1);
	ErecEgenSigmaEff_vsR9ElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsR9ElectronOldAF->Draw("Psame");
	
	//ErecEgenSigmaEff_vsR9ElectronNewETH->SetAxisRange(SigmaMin,SigmaMax,"Y");
	ErecEgenSigmaEff_vsR9ElectronNewETH->SetMarkerColor(8);
	ErecEgenSigmaEff_vsR9ElectronNewETH->SetMarkerSize(1);
	ErecEgenSigmaEff_vsR9ElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenSigmaEff_vsR9ElectronNewETH->Draw("Psame");
	
	TLine* line5 = new TLine(0.,1,0.94,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, "Correction scheme, EB R9<0.94");
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenSigmaEff_vsR9Ceta->GetName(), "C(#eta)", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsR9ElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenSigmaEff_vsR9ElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasSigmaR9->Update();
	CanvasSigmaR9->Draw();	
	CanvasSigmaR9->Print("ErecEgenSigma_vsR9.gif");
	*/
	
	
	return;
	
	//Comparaison detaillee brem, eta, et
	
	//Pt
	TCanvas* CanvasDetailPt = new TCanvas("CanvasDetailPt","CanvasDetailPt");
	
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetXTitle("E_{T,raw} (GeV)");
	ErecEgenMean_vsPtElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetAxisRange(0,200,"X");
	if (doEB) ErecEgenMean_vsPtElectronOldAFbremOnly->SetAxisRange(0.99,1.02,"Y");
	if (doEE) ErecEgenMean_vsPtElectronOldAFbremOnly->SetAxisRange(0.98,1.02,"Y");
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsPtElectronOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsPtElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsPtElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsPtElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPtElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPtElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPtElectronNewETH->Draw("Psame");
	
	TLine* line = new TLine(10,1,200,1);
	line->SetLineWidth(2);
	line->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPtElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPtElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailPt->Update();
	CanvasDetailPt->Draw();
	CanvasDetailPt->Print("ErecEgenMean_vsPt_detail.gif");

	//return;
	
	//Eta
	TCanvas* CanvasDetailEta = new TCanvas("CanvasDetailEta","CanvasDetailEta");
	
	ErecEgenMean_vsEtaElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEtaElectronOldAFbremOnly->SetXTitle("#eta");
	ErecEgenMean_vsEtaElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsEtaElectronOldAFbremOnly->SetAxisRange(0.97,1.03,"Y");
	if (doEE) ErecEgenMean_vsEtaElectronOldAFbremOnly->SetAxisRange(0.97,1.03,"Y");
	ErecEgenMean_vsEtaElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsEtaElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsEtaElectronOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsEtaElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsEtaElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsEtaElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEtaElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEtaElectronNewETH->Draw("Psame");
	
	TLine* line2;
	if (doEB) line2 = new TLine(-1.44,1,1.44,1);
	if (doEE) line2 = new TLine(-2.5,1,2.5,1);
	line2->SetLineWidth(2);
	line2->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEtaElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEtaElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailEta->Update();
	CanvasDetailEta->Draw();
	CanvasDetailEta->Print("ErecEgenMean_vsEta_detail.gif");
	
	//return;
	
	//Phi
	TCanvas* CanvasDetailPhi = new TCanvas("CanvasDetailPhi","CanvasDetailPhi");
	
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetXTitle("#phi");
	ErecEgenMean_vsPhiElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetAxisRange(0.98,1.03,"Y");
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsPhiElectronOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsPhiElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsPhiElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsPhiElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsPhiElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsPhiElectronNewETH->Draw("Psame");
	
	TLine* line3 = new TLine(-3.1415,1,3.1415,1);
	line3->SetLineWidth(2);
	line3->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsPhiElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsPhiElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailPhi->Update();
	CanvasDetailPhi->Draw();
	CanvasDetailPhi->Print("ErecEgenMean_vsPhi_detail.gif");
	
	//return;
	
	//Brem
	TCanvas* CanvasDetailBrem = new TCanvas("CanvasDetailBrem","CanvasDetailBrem");
	
	ErecEgenMean_vsBremElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsBremElectronOldAFbremOnly->SetXTitle("#sigma_{#phi}/#sigma_{#eta}");
	ErecEgenMean_vsBremElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsBremElectronOldAFbremOnly->SetAxisRange(0.98,1.03,"Y");
	if (doEE) ErecEgenMean_vsBremElectronOldAFbremOnly->SetAxisRange(0.95,1.08,"Y");
	ErecEgenMean_vsBremElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsBremElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsBremElectronOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsBremElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsBremElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsBremElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsBremElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsBremElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsBremElectronNewETH->Draw("Psame");
	
	TLine* line4 = new TLine(0.88,1,5,1);
	line4->SetLineWidth(2);
	line4->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsBremElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsBremElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailBrem->Update();
	CanvasDetailBrem->Draw();
	CanvasDetailBrem->Print("ErecEgenMean_vsBrem_detail.gif");
	
	//return;
	
	//R9
	TCanvas* CanvasDetailR9 = new TCanvas("CanvasDetailR9","CanvasDetailR9");
	
	ErecEgenMean_vsR9ElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsR9ElectronOldAFbremOnly->SetXTitle("R9");
	ErecEgenMean_vsR9ElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsR9ElectronOldAFbremOnly->SetAxisRange(0.96,1.04,"Y");
	if (doEE) ErecEgenMean_vsR9ElectronOldAFbremOnly->SetAxisRange(0.8,1.2,"Y");
	ErecEgenMean_vsR9ElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsR9ElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsR9ElectronOldAF->SetAxisRange(0.96,1.04,"Y");
	ErecEgenMean_vsR9ElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsR9ElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsR9ElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsR9ElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsR9ElectronNewETH->Draw("Psame");
	
	TLine* line5;
	if (doEB) line5 = new TLine(0,1,0.94,1);
	if (doEE) line5 = new TLine(0,1,0.95,1);
	line5->SetLineWidth(2);
	line5->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsR9ElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsR9ElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailR9->Update();
	CanvasDetailR9->Draw();
	CanvasDetailR9->Print("ErecEgenMean_vsR9_detail.gif");

	
	
	//Energy
	TCanvas* CanvasDetailEnergy = new TCanvas("CanvasDetailEnergy","CanvasDetailEnergy");
	
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetYTitle("E_{rec}/E_{gen}");
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetXTitle("Energy (GeV)");
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->GetYaxis()->SetTitleOffset(1.5);
	if (doEB) ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetAxisRange(0.99,1.02,"Y");
	if (doEE) ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetAxisRange(0.9,1.1,"Y");
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetMarkerColor(kBlack);
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronOldAFbremOnly->Draw("P");
	
	//ErecEgenMean_vsEnergyElectronOldAF->SetAxisRange(0.98,1.04,"Y");
	ErecEgenMean_vsEnergyElectronOldAF->SetMarkerColor(kBlue);
	ErecEgenMean_vsEnergyElectronOldAF->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronOldAF->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronOldAF->Draw("Psame");
	
	//ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerColor(kRed);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->Draw("Psame");
	
	//ErecEgenMean_vsEnergyElectronNewETH->SetAxisRange(ErecEgenMin,ErecEgenMax,"Y");
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerColor(8);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerSize(1);
	ErecEgenMean_vsEnergyElectronNewETH->SetMarkerStyle(kFullDotLarge);
	ErecEgenMean_vsEnergyElectronNewETH->Draw("Psame");
	
	TLine* line6 = new TLine(0,1,500,1);
	line6->SetLineWidth(2);
	line6->Draw("same");
	
	legende = new TLegend(0.3, 0.7, 0.95, 0.95, slegende.c_str());
	legende->SetFillColor(kWhite);
	legende->AddEntry(ErecEgenMean_vsEnergyElectronOldAFbremOnly->GetName(), "f(Brem) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronOldAF->GetName(), "f(Brem) #times F(#eta,E_{T}) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETHbremetaOnly->GetName(), "f(Brem,#eta) Electron", "p");
	legende->AddEntry(ErecEgenMean_vsEnergyElectronNewETH->GetName(), "f(Brem,#eta) #times F(E_{T}) Electron", "p");
	legende->Draw();
	CanvasDetailEnergy->Update();
	CanvasDetailEnergy->Draw();
	CanvasDetailEnergy->Print("ErecEgenMean_vsEnergy_detail.gif");
	
		return 0;
}














