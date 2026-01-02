{
//	TString file = "/Users/rebecca/workspace/run/jpac_tests/bin_4/lesspoly/s0_unbounded/aug9/tests/test_noexp/second_term_bin5.root";
	TString file = "/Users/rebecca/workspace/run/NeueSystematic/mid/alphaCombos/eta_bin1.root ";	
	TString savetitle = "~/Desktop/gen_eta_mid_bin1.pdf";
	//TString file = "/Users/rebecca/workspace/run/jpac_tests/bin_4/lesspoly/narrow_fasteta.root";
	TFile *filePtr = new TFile(file);


	TCanvas* c = new TCanvas("c", "c", 1100, 1100);
	c->Divide(3,3);


	TH1F* phigen = new TH1F("phigen", "#phi", 60, -3.2, 3.2);

	TH1F* s12gen = new TH1F("s12gen", "s12", 60, 0, 14.);

	TH1F* s23gen = new TH1F("s23gen", "s23", 60, 0, 14.);

	TH1F* u3gen = new TH1F("u3gen", "t_{2}", 60, -6,1);

	TH1F* t1gen = new TH1F("t1gen", "t_{#eta}", 60, -10, 1);

	TH1F* t2gen = new TH1F("t2gen", "t_{#pi}", 60, -10, 1);

	TH1F* cosgen = new TH1F("cosgen", "cos(#theta)", 100, -1.1, 1.1); 

	TH1F* s13gen = new TH1F("s13gen", "s13", 60, 0, 14.);




	s12gen = (TH1F*)filePtr->Get("s12_gen");
	s13gen = (TH1F*)filePtr->Get("s13_gen");
	s23gen = (TH1F*)filePtr->Get("s23_gen");
	cosgen = (TH1F*)filePtr->Get("cosT_gen");
	phigen = (TH1F*)filePtr->Get("phiAng_gen");
	u3gen = (TH1F*)filePtr->Get("u3_gen");
	t1gen = (TH1F*)filePtr->Get("t_eta_gen");
	t2gen = (TH1F*)filePtr->Get("t_pi_gen");
	TH1F* sgen = (TH1F*)filePtr->Get("s_gen");


/*
	for(int i=0; i<100; i++){
		cout << s12gen->GetBinCenter(i) << "\t" << s12gen->GetBinContent(i) << endl;;
	}
*/


	phigen->SetFillColor(kYellow);
	cosgen->SetFillColor(kYellow);

	s12gen->SetFillColor(kYellow);
	cosgen->SetStats(0);	
	phigen->SetStats(0);	
	s12gen->SetStats(0);	
	s13gen->SetStats(0);	
	s13gen->SetFillColor(kYellow);
	s23gen->SetStats(0);
	s23gen->SetFillColor(kYellow);
	t1gen->SetStats(0);
	t1gen->SetFillColor(kYellow);
	t2gen->SetStats(0);
	t2gen->SetFillColor(kYellow);
	u3gen->SetStats(0);
	u3gen->SetFillColor(kYellow);	
	sgen->SetStats(0);
	sgen->SetFillColor(kYellow);



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
	phigen->GetXaxis()->SetTitleOffset(0.75);
	phigen->SetTitle("");
	phigen->GetXaxis()->SetTitle("#phi_{GJ} [rad]");
	phigen->GetXaxis()->SetTitleSize(0.07);
	phigen->GetXaxis()->SetLabelSize(0.055);
	phigen->GetYaxis()->SetTitleSize(0.06);
	phigen->GetYaxis()->SetLabelSize(0.055);
	phigen->Draw("HIST");

	c->cd(2);
	cosgen->GetXaxis()->SetTitleOffset(0.75);
	cosgen->SetTitle("");
	cosgen->SetLineColor(kBlack);
	cosgen->GetXaxis()->SetTitle("cos(#theta_{GJ})");
	cosgen->GetXaxis()->SetTitleSize(0.07);
	cosgen->GetXaxis()->SetLabelSize(0.055);
	cosgen->GetYaxis()->SetTitleSize(0.06);
	cosgen->GetYaxis()->SetLabelSize(0.055);
	cosgen->Draw("HIST");

	c->cd(6);
	s12gen->SetLineColor(kBlack);
	s12gen->GetXaxis()->SetTitleOffset(0.75);
	s12gen->SetTitle("");
	s12gen->GetXaxis()->SetLabelSize(0.055);
	s12gen->GetXaxis()->SetTitle("s_{#eta p} [GeV^{2}]");
	s12gen->GetXaxis()->SetTitleSize(0.075);
	s12gen->GetYaxis()->SetTitleSize(0.06);
	s12gen->Draw("HIST");

	c->cd(4);
	s13gen->SetLineColor(kBlack);
	s13gen->GetXaxis()->SetTitleOffset(0.75);
	s13gen->SetTitle("");
	s13gen->GetXaxis()->SetLabelSize(0.055);
	s13gen->GetXaxis()->SetTitle("s_{#pi p} [GeV^{2}]");
	s13gen->GetXaxis()->SetTitleSize(0.075);
	s13gen->GetYaxis()->SetTitleSize(0.06);
	s13gen->GetYaxis()->SetLabelSize(0.055);
	s13gen->Draw("HIST");

	c->cd(5);
	s23gen->GetXaxis()->SetTitleOffset(0.75);
	s23gen->SetTitle("");
	s23gen->GetXaxis()->SetLabelSize(0.055);
	s23gen->GetXaxis()->SetTitle("s_{#eta#pi} [GeV^{2}]");
	s23gen->SetLineColor(kBlack);
	s23gen->GetXaxis()->SetTitleSize(0.075);
	s23gen->GetYaxis()->SetTitleSize(0.06);
	s23gen->GetYaxis()->SetLabelSize(0.055);
	s23gen->Draw("HIST");

	c->cd(9);
	t1gen->GetXaxis()->SetTitleOffset(0.75);
	t1gen->SetTitle("");
	t1gen->GetXaxis()->SetTitle("t_{#eta} [GeV^{2}]");
	t1gen->GetXaxis()->SetTitleSize(0.075);
	t1gen->GetXaxis()->SetLabelSize(0.055);
	t1gen->SetLineColor(kBlack);
	t1gen->GetYaxis()->SetLabelSize(0.055);
	t1gen->GetYaxis()->SetTitleSize(0.06);
	t1gen->Draw("HIST");

	c->cd(7);
	t2gen->SetTitle("");
	t2gen->GetXaxis()->SetTitleOffset(0.75);
	t2gen->GetXaxis()->SetTitle("t_{#pi} [GeV^{2}]");
	t2gen->GetXaxis()->SetTitleSize(0.075);
	t2gen->GetXaxis()->SetLabelSize(0.055);
	t2gen->SetLineColor(kBlack);
	t2gen->GetYaxis()->SetTitleSize(0.06);
	t2gen->GetYaxis()->SetLabelSize(0.055);
	t2gen->Draw("HIST");

	c->cd(8);
	u3gen->GetXaxis()->SetTitle("t_{2} [GeV^{2}]");
	u3gen->SetTitle("");
	u3gen->SetLineColor(kBlack);
	u3gen->GetXaxis()->SetTitleOffset(0.75);
	u3gen->GetXaxis()->SetTitleSize(0.075);
	u3gen->GetXaxis()->SetLabelSize(0.055);
	u3gen->GetYaxis()->SetTitleSize(0.06);
	u3gen->GetYaxis()->SetLabelSize(0.055);
	u3gen->Draw("HIST");

	c->cd(3);
	sgen->GetXaxis()->SetTitle("s [GeV^{2}]");
	sgen->SetTitle("");
	sgen->SetLineColor(kBlack);
	sgen->GetXaxis()->SetTitleOffset(0.75);
	sgen->GetXaxis()->SetLabelSize(0.055);
	sgen->GetXaxis()->SetTitleSize(0.075);
	sgen->GetYaxis()->SetTitleSize(0.06);
	sgen->GetYaxis()->SetLabelSize(0.055);
	sgen->Draw("HIST");

	c->SaveAs(savetitle);
}
