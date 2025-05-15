{

	TString data = "./data_045/tree_pi0eta__B4_M17_M7_FLAT_03*.root";
	TString mc = "tree_pi0eta__B4_M17_M7_BGGEN_03*.root";
	TString bkg = "bkg_1D.root";

	TString ntName = "ntFSGlueX_101_1";

	double scale = 1.0; bool reverseOrder = false;
	TString axisLabel = ""; TString variable = ""; TString bounds = ""; TString cuts =""; TString category = ""; TString sbcuts =""; TString binLabel = ""; TString tag = "";


	TBox *sig;TBox *sig_outline; TBox* sb; TBox* sb_outline; TBox* sb2; TBox* sb2_outline;
	////////
	int var = 6; 
	////////

	for(int var =0; var<=8; var++){

		if(var ==0){
			variable = "RFDeltaT";
			tag = "rfdeltaT";
			bounds = "(100,-18,18)";
			cuts = "CUT(unusedE,mass23, unusedTracks,zProton,protMom,beamE,eta,pi0,chi2)";
			sbcuts = "CUT(unusedE,mass23, unusedTracks,zProton,protMom,beamE,pi0,chi2)";
			axisLabel = "RF #Delta t (ns)";
			binLabel = "Entries / 0.36 ns";
		}
		if(var ==1){
			variable = "NumUnusedTracks";
			tag = "unusedTrack";
			bounds = "(5,-1.5, 3.5 )"; 
			cuts = "CUT(unusedE,mass23,zProton,protMom,beamE,eta,pi0,chiRank,chi2)";
			sbcuts = "CUT(unusedE,mass23,zProton,chiRank,protMom,beamE,pi0,chi2)";
			axisLabel = "# of Unused Tracks";
			binLabel = "Entries / Track";
		}
		if(var ==2){
			variable = "EnUnusedSh";
			tag="unusedE";
			bounds = "(20,-0.5, 2.0)";
			cuts = "CUT(unusedTracks,mass23,zProton,protMom,beamE,eta,pi0,chiRank,chi2)";
			sbcuts = "CUT(mass23, unusedTracks,zProton,chiRank,protMom,beamE,pi0,chi2)";
			axisLabel = "Unused Energy [GeV]";
			binLabel = "Entries / 0.125 GeV";
		}
		if(var ==3){
			variable = "Chi2DOF";
			tag = "chi2";
			bounds = "(100, 0, 15)";
			cuts = "CUT(unusedE,mass23, unusedTracks,zProton,protMom,beamE,eta,pi0,chiRank)";	
			axisLabel = "#chi^{2} / DOF";
			binLabel = "Entries / 0.15";
			sbcuts = "CUT(unusedE,mass23, chiRank, unusedTracks,zProton,protMom,beamE,pi0)";
		}
		if(var ==4){
			variable = "ProdVz";
			tag = "protZ";
			bounds = "(100, 0, 140)";
			cuts = "CUT(unusedE,mass23, unusedTracks,protMom,beamE,eta,pi0,chiRank,chi2)";	
			axisLabel = "Proton z-position [cm]";
			binLabel = "Entries / 1.4 cm";
			sbcuts = "CUT(unusedE,mass23,chiRank, unusedTracks,protMom,beamE,pi0,chi2)";
		}
		if(var ==5){
			variable = "MOMENTUM([p+])";
			tag = "protMom";
			bounds = "(70, 0, 4.0)";
			cuts = "CUT(unusedE, mass23,unusedTracks,zProton,beamE,eta,pi0,chiRank,chi2)";
			axisLabel = "Proton Momentum [GeV/c]";
			binLabel = "Entries / 0.057 GeV";
			sbcuts = "CUT(unusedE,mass23, unusedTracks,chiRank,zProton,beamE,pi0,chi2)";
		}
		if(var==6){
			variable = "EnPB";
			tag = "beamE";
			bounds = "(80, 3.2, 12.0)";
			cuts = "CUT(unusedE,mass23, unusedTracks,protMom,zProton,eta,pi0,chiRank,chi2)";
			sbcuts = "CUT(unusedE,mass23, unusedTracks,zProton,chiRank,protMom,pi0,chi2)";
			axisLabel = "Beam Energy [GeV]";
			binLabel = "Entries / 0.8 GeV";
		}
		if(var ==7){	
			variable = "MASS(2)";
			tag="etamass";
			bounds = "(70, 0.4, 0.7)";
			cuts = "CUT(unusedE, mass23,unusedTracks,protMom,zProton,beamE,pi0,chiRank,chi2)";	
			axisLabel = "Mass(#eta_{#gamma#gamma}) [GeV/c^2]";
			sbcuts = "CUT(unusedE,mass23,chiRank, unusedTracks,zProton,protMom,beamE,pi0,chi2)";
			binLabel = "Entries / 0.0043 GeV";
		}
		if(var ==8){
			variable = "MASS(3)";
			tag = "pimass";
			bounds = "(70, 0.07, 0.2)";
			cuts = "CUT(unusedE, mass23,unusedTracks,protMom,zProton,beamE,eta,chiRank,chi2)";
			axisLabel = "Mass(#pi^{0}_{#gamma#gamma}) [GeV/c^2]";
			sbcuts = "CUT(unusedE,mass23, unusedTracks,zProton,protMom,chiRank,beamE,chi2)";
			binLabel = "Entries / 0.0019 GeV";
		}

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
		c1->SetTitle(variable);
		TH1F* htot = FSModeHistogram::getTH1F(mc,ntName,category,variable,bounds,cuts,scale);
		TH1F* hbkg = FSModeHistogram::getTH1F(bkg,ntName,category,variable,bounds,sbcuts,scale);
		htot->SetFillColor(29);
		htot->SetLineColor(29);
		vector< pair<TString,float> > components = 
			FSModeHistogram::getMCComponentsAndSizes(mc,ntName,category,variable,bounds,cuts,scale);

		vector<TH1F*> histograms =
			FSModeHistogram::getMCComponentsTH1F(mc,ntName,category,variable,bounds,cuts,scale);

		TH1F* hdata = FSModeHistogram::getTH1F(data,ntName,category,variable,bounds,cuts,scale);
		Double_t factor = hdata->Integral();

		double scaling = factor / htot->Integral();
		htot->Scale(scaling);
		hbkg->Scale(scaling);



		if(hdata->GetMaximum()< htot->GetMaximum()){
			htot->Draw("hist");

			htot->SetTitle(" ");
			htot->GetXaxis()->SetTitle(axisLabel);
			htot->GetYaxis()->SetTitle(binLabel);
		}
		else{
			hdata->Draw();
			htot->Draw("hist,same");

			hdata->SetTitle(" ");
			hdata->GetXaxis()->SetTitle(axisLabel);
			hdata->GetYaxis()->SetTitle(binLabel);
		}

		THStack* stack = new THStack("sDrawMCComponents","sDrawMCComponents");
		TLegend* legend = new TLegend(0.7,0.5,1.0,1.0);
		for (unsigned int ihist = 0; ihist < histograms.size(); ihist++){
			int i = ihist;  if (reverseOrder) i = histograms.size() - ihist - 1;
			TH1F* hcomp = histograms[i];
			hcomp->Scale(scaling);
			if (i != 0) hcomp->SetFillColor(i+1);
			hcomp->SetLineColor(i+1);
			stack->Add(hcomp,"hist");
			TString legendString(FSModeHistogram::formatMCComponent(components[i].first,components[i].second));
			legendString = FSModeString::rootSymbols(legendString);
			legend->AddEntry(hcomp,legendString,"F");
			if(i>=4)
				break;
		}
		legend->AddEntry(htot,"Other processes", "F");
		legend->AddEntry(hbkg, "Sideband", "F");
		if (histograms.size() != 0){
			stack->Draw("same");	
			legend->Draw("same");
		}

		hbkg->SetLineColor(kGray+2);
		hbkg->SetFillColor(kGray+2);
		hbkg->SetFillStyle(3244);
		hdata->Draw("same");
		hbkg->Draw("same,HIST");
		c1->RedrawAxis();



		TString fig = tag+".png";
		c1->Print();
		//	}


		if(var ==0){
			sig_outline = new TBox(-2.0,0,2.0,gPad->GetUymax());
			sig = new TBox(-2.0,0, 2.0,gPad->GetUymax());
			sig->SetFillStyle(3003);
			sig->SetFillColor(kGreen);
			sig_outline->SetLineColor(kGreen);
			sig_outline->SetFillStyle(0);
			sig_outline->SetLineWidth(2);
			sig->Draw();
			sig_outline->Draw();
		}
		else if(var ==1){
			sb = new TBox(0.5, 0,3.5, gPad->GetUymax() );
			sb_outline = new TBox(0.5, 0,3.5, gPad->GetUymax() );

			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb_outline->SetLineColor(kRed);
			sb_outline->SetFillStyle(0);
			sb_outline->SetLineWidth(2);
			sb->Draw();
			//sb_outline->Draw();

		}
		else if(var==2){
			sb = new TBox(0.15, 0,2, gPad->GetUymax() );
			sb_outline = new TBox(0.15, 0,2, gPad->GetUymax() );

			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb_outline->SetLineColor(kRed);
			sb_outline->SetFillStyle(0);
			//sb_outline->SetLineWidth(2);
			sb->Draw();
			//sb_outline->Draw();

		}
		else if(var==3){
			sb = new TBox(5, 0,15, gPad->GetUymax() );
			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb->Draw();
		}
		else if(var==4){
			sb = new TBox(0, 0,52, gPad->GetUymax() );
			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb->Draw();
			sb2 = new TBox(78, 0,140, gPad->GetUymax() );
			sb2->SetFillStyle(3003);
			sb2->SetFillColor(kRed);
			sb2->Draw();
		}
		else if(var==6){
			sb = new TBox(3.2, 0,8.1, gPad->GetUymax() );
			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb->Draw();
		}
		else if(var==7){
			sig = new TBox(0.498, 0, 0.598, gPad->GetUymax());
			sig_outline = new TBox(0.498, 0, 0.598, gPad->GetUymax());
			sig->SetFillStyle(3003);
			sig->SetFillColor(kGreen);
			sig_outline->SetLineColor(kGreen);
			sig_outline->SetFillStyle(0);
			sig_outline->SetLineWidth(2);

			sb = new TBox(0.498 -.07, 0,0.498-0.02, gPad->GetUymax() );
			sb_outline = new TBox(0.498-0.07, 0,0.498-0.02, gPad->GetUymax() );

			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb_outline->SetLineColor(kRed);
			sb_outline->SetFillStyle(0);
			sb_outline->SetLineWidth(2);

			sb2 = new TBox(0.598 +.02, 0,0.598+0.07, gPad->GetUymax() );
			sb2_outline = new TBox(0.598+0.02, 0,0.598+.07, gPad->GetUymax() );

			sb2->SetFillStyle(3003);
			sb2->SetFillColor(kRed);
			sb2_outline->SetLineColor(kRed);
			sb2_outline->SetFillStyle(0);
			sb2_outline->SetLineWidth(2);


			sb->Draw();
			sb2->Draw();
			sb_outline->Draw();
			sb2_outline->Draw();
			sig->Draw();
			sig_outline->Draw();
		}
		else if(var==8){

			sig = new TBox(0.11, 0, 0.16, gPad->GetUymax());
			sig_outline = new TBox(0.11, 0, 0.16, gPad->GetUymax());
			sig->SetFillStyle(3003);
			sig->SetFillColor(kGreen);
			sig_outline->SetLineColor(kGreen);
			sig_outline->SetFillStyle(0);
			sig_outline->SetLineWidth(2);	

			sb = new TBox(0.11 -.01, 0,0.11-0.024, gPad->GetUymax() );
			sb_outline = new TBox(0.11-0.01, 0,0.11-0.024, gPad->GetUymax() );

			sb->SetFillStyle(3003);
			sb->SetFillColor(kRed);
			sb_outline->SetLineColor(kRed);
			sb_outline->SetFillStyle(0);
			sb_outline->SetLineWidth(2);

			sb2 = new TBox(0.16 +.01, 0,0.16+.024, gPad->GetUymax() );
			sb2_outline = new TBox(0.16+0.01, 0,0.16+.024, gPad->GetUymax() );

			sb2->SetFillStyle(3003);
			sb2->SetFillColor(kRed);
			sb2_outline->SetLineColor(kRed);
			sb2_outline->SetFillStyle(0);
			sb2_outline->SetLineWidth(2);


			sb->Draw();
			sb2->Draw();
			sb_outline->Draw();
			sb2_outline->Draw();
			sig->Draw();
			sig_outline->Draw();
		}
		legend->Draw();


		c1->SaveAs(fig);
}
}
