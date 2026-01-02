{
	TString file = "/Users/rebecca/workspace/run/NeueSystematic/mid/alphaCombos/eta_bin1.root";
	TString savetitle = "~/Desktop/mid_eta_bin1.pdf";
	TFile *filePtr = new TFile(file);

	TCanvas* c = new TCanvas("c", "c", 1100, 1100);
	c->Divide(3,3);


	TH1F* phiacc = new TH1F("phiacc", "#phi", 40, -3.2, 3.2);
	TH1F* phibkgnd = new TH1F("phibkgnd", "#phi", 40, -3.2, 3.2);
	TH1F* phidat = new TH1F("phidat", "#phi", 40, -3.2, 3.2);

	TH1F* s12acc = new TH1F("s12acc", "s12", 100, 2., 12.);
	TH1F* s12bkgnd = new TH1F("s12bkgnd", "s12", 100, 2., 12.);
	TH1F* s12dat = new TH1F("s12dat", "s12", 100, 2., 12.);

	TH1F* s23acc = new TH1F("s23acc", "s23", 100, 2., 10.);
	TH1F* s23bkgnd = new TH1F("s23bkgnd", "s23", 100, 2, 10.);
	TH1F* s23dat = new TH1F("s23dat", "s23", 100, 2., 10.);

	TH1F* u3acc = new TH1F("u3acc", "u_{p}", 60, -4,0);
	TH1F* u3bkgnd = new TH1F("u3bkgnd", "u_{p}", 60, -4,0);
	TH1F* u3dat = new TH1F("u3dat", "u_{p}", 60, -4,0);

	TH1F* t1acc = new TH1F("t1acc", "t_{#eta}", 60, -10, 0);
	TH1F* t1bkgnd = new TH1F("t1bkgnd", "t_{#eta}", 60, -10,0);
	TH1F* t1dat = new TH1F("t1dat", "t_{#eta}", 60, -10, 0);

	TH1F* t2acc = new TH1F("t2acc", "t_{#pi}", 60, -10, 0);
	TH1F* t2bkgnd = new TH1F("t2bkgnd", "t_{#pi}", 60, -10, 0);
	TH1F* t2dat = new TH1F("t2dat", "t_{#pi}", 60, -10, 0);

	TH1F* cosacc = new TH1F("cosacc", "cos(#theta)", 60, -1.1, 1.1);
	TH1F* cosbkgnd = new TH1F("cosbkgnd", "cos(#theta)", 60, -1.1, 1.1);
	TH1F* cosdat = new TH1F("cosdat", "cos(#theta)", 60, -1.1, 1.1);


	TH1F* s13acc = new TH1F("s13acc", "s13", 100, 2, 12.);
	TH1F* s13bkgnd = new TH1F("s13bkgnd", "s13", 100, 2, 12.);
	TH1F* s13dat = new TH1F("s13dat", "s13", 100, 2, 12.);

   TH1F* s23gen = new TH1F("s23gen", "s23", 100, 0, 14.);
 s23gen = (TH1F*)filePtr->Get("s23_gen");

	THStack * hs1 = new THStack("hs1"," #phi_{GJ}");
	THStack * hs2 = new THStack("hs2"," cos(#theta_{GJ})");
	THStack * hs3 = new THStack("hs3"," s12");
	THStack * hs4 = new THStack("hs4"," s13");
	THStack * hs5= new THStack("hs5","s23");
	THStack * hs6 = new THStack("hs6"," t1");
	THStack * hs7 = new THStack("hs7","t2");
	THStack * hs8 = new THStack("hs8"," u3");
	THStack * hs9 = new THStack("hs9"," s");


	s12acc = (TH1F*)filePtr->Get("s12_acc");
	s13acc = (TH1F*)filePtr->Get("s13_acc");
	s13dat = (TH1F*)filePtr->Get("s13_dat");
	s13bkgnd = (TH1F*)filePtr->Get("s13_bkg");
	s12dat = (TH1F*)filePtr->Get("s12_dat");
	s12bkgnd = (TH1F*)filePtr->Get("s12_bkg");
	s23acc = (TH1F*)filePtr->Get("s23_acc");
	s23dat = (TH1F*)filePtr->Get("s23_dat");
	s23bkgnd = (TH1F*)filePtr->Get("s23_bkg");
	cosacc = (TH1F*)filePtr->Get("cosT_acc");
	cosdat = (TH1F*)filePtr->Get("cosT_dat");
	cosbkgnd = (TH1F*)filePtr->Get("cosT_bkg");
	phiacc = (TH1F*)filePtr->Get("phiAng_acc");
	phidat = (TH1F*)filePtr->Get("phiAng_dat");
	phibkgnd = (TH1F*)filePtr->Get("phiAng_bkg");
	u3acc = (TH1F*)filePtr->Get("u3_acc");
	u3dat = (TH1F*)filePtr->Get("u3_dat");
	u3bkgnd = (TH1F*)filePtr->Get("u3_bkg");
	t1acc = (TH1F*)filePtr->Get("t_eta_acc");
	t1dat = (TH1F*)filePtr->Get("t_eta_dat");
	t1bkgnd = (TH1F*)filePtr->Get("t_eta_bkg");
	t2acc = (TH1F*)filePtr->Get("t_pi_acc");
	t2dat = (TH1F*)filePtr->Get("t_pi_dat");
	t2bkgnd = (TH1F*)filePtr->Get("t_pi_bkg");

	sacc = (TH1F*)filePtr->Get("s_acc");
	sdat = (TH1F*)filePtr->Get("s_dat");
	sbkgnd = (TH1F*)filePtr->Get("s_bkg");

	double events=0.;
	double genevents = 0.;
	for(int i=0; i<100; i++){
		events += s23acc->GetBinContent(i); 
		genevents += s23gen->GetBinContent(i);
	}
	cout << events / genevents<< endl;

	hs1->Add(phibkgnd);
	phiacc->SetFillColor(kGreen-8);
	hs1->Add(phiacc);

	hs2->Add(cosbkgnd);
	cosacc->SetFillColor(kGreen-8);
	hs2->Add(cosacc);

	hs3->Add(s12bkgnd);
	s12acc->SetFillColor(kGreen-8);
	hs3->Add(s12acc);

	hs4->Add(s13bkgnd);
	s13acc->SetFillColor(kGreen-8);
	hs4->Add(s13acc);

	hs5->Add(s23bkgnd);
	s23acc->SetFillColor(kGreen-8);
	hs5->Add(s23acc);

	hs6->Add(t1bkgnd);
	t1acc->SetFillColor(kGreen-8);
	hs6->Add(t1acc);

	hs7->Add(t2bkgnd);
	t2acc->SetFillColor(kGreen-8);
	hs7->Add(t2acc);

	hs8->Add(u3bkgnd);
	u3acc->SetFillColor(kGreen-8);
	hs8->Add(u3acc);

	hs9->Add(sbkgnd);
	sacc->SetFillColor(kGreen-8);
	hs9->Add(sacc);

	c->GetPad(1)->SetTopMargin(.01); 
	c->GetPad(2)->SetTopMargin(.01); 
	c->GetPad(3)->SetTopMargin(.01); 
	c->GetPad(4)->SetTopMargin(.01); 
	c->GetPad(5)->SetTopMargin(.01); 
	c->GetPad(6)->SetTopMargin(.01); 
	c->GetPad(7)->SetTopMargin(.01); 
	c->GetPad(8)->SetTopMargin(.01); 
	c->GetPad(9)->SetTopMargin(.01); 


	c->GetPad(1)->SetBottomMargin(.15); 
	c->GetPad(2)->SetBottomMargin(.15); 
	c->GetPad(3)->SetBottomMargin(.15); 
	c->GetPad(4)->SetBottomMargin(.15); 
	c->GetPad(5)->SetBottomMargin(.15); 
	c->GetPad(6)->SetBottomMargin(.15); 
	c->GetPad(7)->SetBottomMargin(.15); 
	c->GetPad(8)->SetBottomMargin(.15); 
	c->GetPad(9)->SetBottomMargin(.15);


	c->GetPad(1)->SetLeftMargin(.15); 
	c->GetPad(2)->SetLeftMargin(.15); 
	c->GetPad(3)->SetLeftMargin(.15); 
	c->GetPad(4)->SetLeftMargin(.15); 
	c->GetPad(5)->SetLeftMargin(.15); 
	c->GetPad(6)->SetLeftMargin(.15); 
	c->GetPad(7)->SetLeftMargin(.15); 
	c->GetPad(8)->SetLeftMargin(.15); 
	c->GetPad(9)->SetLeftMargin(.15); 

	c->GetPad(1)->SetRightMargin(.01); 
	c->GetPad(2)->SetRightMargin(.01); 
	c->GetPad(3)->SetRightMargin(.01); 
	c->GetPad(4)->SetRightMargin(.01); 
	c->GetPad(5)->SetRightMargin(.01); 
	c->GetPad(6)->SetRightMargin(.01); 
	c->GetPad(7)->SetRightMargin(.01); 
	c->GetPad(8)->SetRightMargin(.01); 
	c->GetPad(9)->SetRightMargin(.01); 

	c->cd(1);
	phidat->SetStats(0);
	phidat->SetLineColor(kBlack);
	phidat->GetXaxis()->SetTitleOffset(0.75);
	phidat->SetTitle("");
	phidat->GetXaxis()->SetTitle("#phi_{GJ} [rad]");
	phidat->GetXaxis()->SetTitleSize(0.07);
	phidat->GetXaxis()->SetLabelSize(0.055);
	phidat->GetYaxis()->SetTitleSize(0.055);
	phidat->GetYaxis()->SetLabelSize(0.055);

	phidat->Draw("e,same");
	hs1->Draw("HIST,same");
	phidat->Draw("e,same");

	c->cd(2);

	cosdat->SetStats(0);
	cosdat->GetXaxis()->SetTitleOffset(0.75);
	cosdat->SetTitle("");
	cosdat->SetLineColor(kBlack);
	cosdat->GetXaxis()->SetTitle("cos(#theta_{GJ})");
	cosdat->GetXaxis()->SetTitleSize(0.07);
	cosdat->GetXaxis()->SetLabelSize(0.055);
	cosdat->GetYaxis()->SetTitleSize(0.055);
	cosdat->GetYaxis()->SetLabelSize(0.055);
	cosdat->Draw("e,same");
	hs2->Draw("HIST,same");
	cosdat->Draw("e,same");

	c->cd(6);

	s12dat->SetStats(0);
	s12dat->SetLineColor(kBlack);
	s12dat->GetXaxis()->SetTitleOffset(0.75);
	s12dat->SetTitle("");
	s12dat->GetXaxis()->SetTitle("s_{#eta p} [GeV^{2}]");
	s12dat->GetXaxis()->SetTitleSize(0.075);
	s12dat->GetYaxis()->SetTitleSize(0.055);
	s12dat->Draw("e,same");
	s12dat->GetYaxis()->SetLabelSize(0.055);
	hs3->Draw("HIST,same");
	s12dat->GetXaxis()->SetLabelSize(0.055);
	s12dat->Draw("e,same");

	c->cd(4);

	s13dat->SetStats(0);
	s13dat->GetXaxis()->SetTitleOffset(0.75);
	s13dat->SetTitle("");
	s13dat->GetXaxis()->SetTitle("s_{#pi p} [GeV^{2}]");
	s13dat->GetXaxis()->SetTitleSize(0.075);
	s13dat->GetYaxis()->SetTitleSize(0.055);
	s13dat->SetLineColor(kBlack);
	s13dat->GetXaxis()->SetLabelSize(0.055);
	s13dat->GetYaxis()->SetLabelSize(0.055);
	s13dat->Draw("e,same");
	hs4->Draw("HIST,same");
	s13dat->Draw("e,same");

	c->cd(5);
	s23dat->Draw("e,same");
	s23dat->SetStats(0);
	s23dat->GetXaxis()->SetTitleOffset(0.75);
	s23dat->SetTitle("");
	s23dat->GetXaxis()->SetLabelSize(0.055);
	s23dat->GetXaxis()->SetTitle("s_{#eta#pi} [GeV^{2}]");
	s23dat->SetLineColor(kBlack);
	s23dat->GetXaxis()->SetTitleSize(0.075);
	s23dat->GetYaxis()->SetLabelSize(0.055);
	s23dat->GetYaxis()->SetTitleSize(0.055);
	hs5->Draw("HIST,same");
	s23dat->Draw("e,same");

	c->cd(9);
	t1dat->Draw("e,same");
	hs6->Draw("HIST,same");
	t1dat->SetTitle("");
	t1dat->SetStats(0);
	t1dat->GetXaxis()->SetTitleOffset(0.75);
	t1dat->GetXaxis()->SetTitle("t_{#eta} [GeV^{2}]");
	t1dat->GetXaxis()->SetTitleSize(0.075);
	t1dat->GetXaxis()->SetLabelSize(0.055);
	t1dat->SetLineColor(kBlack);
	t1dat->GetYaxis()->SetLabelSize(0.055);
	t1dat->GetYaxis()->SetTitleSize(0.055);
	t1dat->Draw("e,same");

	c->cd(7);
	t2dat->Draw("e,same");
	hs7->Draw("HIST,same");
	t2dat->SetStats(0);
	t2dat->GetXaxis()->SetTitleOffset(0.75);
	t2dat->GetXaxis()->SetTitle("t_{#pi} [GeV^{2}]");
	t2dat->GetXaxis()->SetTitleSize(0.075);
	t2dat->SetTitle("");	
	t2dat->GetXaxis()->SetLabelSize(0.055);
	t2dat->SetLineColor(kBlack);
	t2dat->GetYaxis()->SetLabelSize(0.055);
	t2dat->GetYaxis()->SetTitleSize(0.055);
	t2dat->Draw("e,same");

	c->cd(8);
	u3dat->SetStats(0);
	u3dat->Draw("e,same");
	hs8->Draw("HIST,same");
	u3dat->GetXaxis()->SetTitle("t_{2} [GeV^{2}]");
	u3dat->SetTitle("");
	u3dat->SetLineColor(kBlack);
	u3dat->GetXaxis()->SetTitleOffset(0.75);
	u3dat->GetXaxis()->SetTitleSize(0.075);
	u3dat->GetXaxis()->SetLabelSize(0.055);
	u3dat->GetYaxis()->SetLabelSize(0.055);
	u3dat->GetYaxis()->SetTitleSize(0.055);
	u3dat->Draw("e,same");

	c->cd(3);

	sdat->SetStats(0);
	sdat->Draw("e,same");
	hs9->Draw("HIST,same");
	sdat->GetXaxis()->SetTitle("s [GeV^{2}]");
	sdat->SetTitle("");
	sdat->SetLineColor(kBlack);
	sdat->GetXaxis()->SetTitleOffset(0.75);
	sdat->GetXaxis()->SetLabelSize(0.055);
	sdat->GetXaxis()->SetTitleSize(0.075);
	sdat->GetYaxis()->SetTitleSize(0.055);
	sdat->GetYaxis()->SetLabelSize(0.055);
	sdat->Draw("e,same");

	c->SaveAs(savetitle);

}
