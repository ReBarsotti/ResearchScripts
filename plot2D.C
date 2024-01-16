{
	TString data = "./data_045/tree_pi0eta__B4_M17_M7_FLAT_03*.root";
	TString ntName = "ntFSGlueX_101_1";

	FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");
	FSCut::defineCut("mass23", "MASS(2,3)>1.8");
	FSCut::defineCut("unusedE","EnUnusedSh<0.1");
	FSCut::defineCut("unusedTracks","NumUnusedTracks<1");
	FSCut::defineCut("zProton","ProdVz>=52&&ProdVz<=78");
	FSCut::defineCut("protMom","MOMENTUM([p+])>=0.3");
	FSCut::defineCut("beamE","(EnPB>8.1)");
	FSCut::defineCut("chiRank", "(Chi2RankVar==Chi2RankVarBest)");
	FSCut::defineCut("eta","abs(MASS([eta])-0.548)<0.05","(abs(MASS([eta])-0.548+0.107)<0.025 || abs(MASS([eta])-0.548-0.103)<0.025)", 1.0);
	FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<0.025","(abs(MASS([pi0])-0.135+0.0425)<0.0125 || abs(MASS([pi0])-0.135-0.0425)<0.0125)", 1.0);
	FSCut::defineCut("chi2", "Chi2DOF<5.0");
	FSCut::defineCut("rf", "OR(abs(RFDeltaT)<2.0)");

	FSTree::addFriendTree("Chi2Rank");




	TCanvas* c1 = new TCanvas("cDrawMCComponents","cDrawMCComponents",600,600);

	TH2F* mass_cos = FSModeHistogram::getTH2F(data,ntName,"m101_1","GJCOSTHETA(2;3;B):MASS(2,3)","(150,0.5, 4.0, 150, -1.0, 1.0)","CUT(unusedTracks,unusedE,zProton,chiRank,beamE,eta,pi0)");

	mass_cos->SetTitle("");
	mass_cos->GetXaxis()->SetTitle("Mass(#eta #pi^{0}) [GeV / c^{2}]");
	mass_cos->GetYaxis()->SetTitle("cos(#theta_{GJ})");
	mass_cos->Draw("colz");
	TBox* sb = new TBox(0.5,-1.0,1.8,1.0);
	sb->SetFillStyle(3002);
	sb->SetFillColor(kRed);
	sb->Draw();

	c1->SaveAs("mass_cos.png");

	TH2F* mass = 	FSModeHistogram::getTH2F(data,ntName,"m101_1", "MASS(3):MASS(2)", "(100, 0.4,0.7, 100, .07,.20)", "CUT(unusedTracks,unusedE,zProton,chiRank,beamE, mass23)");



	mass->SetTitle("");
	mass->GetXaxis()->SetTitle("Mass(#eta_{#gamma#gamma}) [GeV/c^{2}]");
	mass->GetYaxis()->SetTitle("Mass(#pi^{0}_{#gamma#gamma}) [GeV/c^{2}]");
	mass->Draw("colz");
	
	TBox* sb1 = new TBox(0.4,.11 -.01,0.7,.11-.024);
	sb1->SetLineColor(kRed);
	sb1->SetLineWidth(2);
	sb1->SetFillStyle(0);
	sb1->Draw();

	TBox* sb2 = new TBox(0.4,.16+.01,0.7,.16+.024);
	sb2->SetLineColor(kRed);
	sb2->SetLineWidth(2);
	sb2->SetFillStyle(0);
	sb2->Draw();

	TBox* sb3 = new TBox(0.598+.02,.07,0.598+.07,.2);
	sb3->SetLineColor(kRed);
	sb3->SetLineWidth(2);
	sb3->SetFillStyle(0);
	sb3->Draw();


	TBox* sb4 = new TBox(0.498-.02,.07,0.498-.07,.2);
	sb4->SetLineColor(kRed);
	sb4->SetLineWidth(2);
	sb4->SetFillStyle(0);
	sb4->Draw();

	

	TBox* sig1 = new TBox(0.4,.11,0.7,.16);
	sig1->SetLineColor(kBlack);
	sig1->SetLineWidth(3);
	sig1->SetFillStyle(0);
	sig1->Draw();


	TBox* sig2 = new TBox(0.498,.07,0.598,.2);
	sig2->SetLineColor(kBlack);
	sig2->SetLineWidth(3);
	sig2->SetFillStyle(0);
	sig2->Draw();


	TBox* outline = new TBox(0.4,.07,0.7,0.2);
	outline->SetLineColor(kBlack);
	outline->SetLineWidth(2);
	outline->SetFillStyle(0);
	outline->Draw();


	c1->SaveAs("mass2_mass3.png");
}
