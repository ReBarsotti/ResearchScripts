{
	FSModeCollection::addModeInfo("101_1")->addCategory("m101_1");
	FSTree::addFriendTree("Chi2Rank");
	FSTree::addFriendTree("EventNum");


	FSCut::defineCut("unusedTrack", "NumUnusedTracks ==0");
	FSCut::defineCut("prodV", "VzP1>=52&&VzP1<=78&& (VxP1*VxP1 + VyP1*VyP1)<=1");
	FSCut::defineCut("unusedE", "EnUnusedSh<0.1");

	FSCut::defineCut("chiRank","Chi2RankVar==Chi2RankVarBest");
	FSCut::defineCut("chi2","Chi2DOF<5.");
	FSCut::defineCut("pi0","abs(MASS([pi0])-0.135)<0.025","(abs(MASS([pi0])-0.135+0.04)<0.006 || abs(MASS([pi0])-0.135-0.04)<0.006)", -0.24);
	FSCut::defineCut("eta","abs(MASS([eta])-0.548)<0.05","(abs(MASS([eta])-0.548+0.105)<0.025 || abs(MASS([eta])-0.548-0.105)<0.025)", -0.5);
	FSCut::defineCut("rf", "abs(RFDeltaT)<2.0");

	FSCut::defineCut("eventNum2", "Chi2Rank==1");

	TString file2017 = "./flattenedAccMC_2017p.root";
	TString file2018_01 = "./flattenedAccMC_2018_01p.root";
	TString file2018_08 = "./flattenedAccMC_2018_08p.root";


	double eventtot = 20771203 + 24089057 + 59438603;
	double weightedtot = 20771203*0.174 + 24089057*.504 + 59438603*.321;

	double weightedcombo;
	double weightedReconCombos;



	///THIS NUMBER IS INCORRECT ... IT INCLUDES LOW BEAM ENERGY PHOTONS
	/// GENERATED NUMS:

	/// 2017 = 53,100,0000 
	/// 2018_01 =  98,100,000
	/// 2018_08 = 152,700,000

	/// 2018_01 and 2018_08 should have had their numbers switched but I'm dummmmm


	/// PERCENTAGES:

	/// 2017 = 17.4
	/// 2018_01 = 50.4
	/// 2018_08 = 32.1 

	hist = FSModeHistogram::getTH1F(file2017,"ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	weightedReconCombos = hist->GetEntries()* 0.174;

	hist = FSModeHistogram::getTH1F(file2018_01,"ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	weightedReconCombos += hist->GetEntries()* 0.504;

	hist = FSModeHistogram::getTH1F(file2018_08,"ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	weightedReconCombos += hist->GetEntries()* 0.321;
	

	/*

	   FSModeTree::skimTree("flattenedAccMC_2017p.root","ntFSGlueX_101_1","","accMC_2017_unusedEnergy.root","CUT(unusedE)");
	   FSModeTree::skimTree("flattenedAccMC_2018_01p.root","ntFSGlueX_101_1","","accMC_2018_01_unusedEnergy.root","CUT(unusedE)");
	   FSModeTree::skimTree("flattenedAccMC_2018_08p.root","ntFSGlueX_101_1","","accMC_2018_08_unusedEnergy.root","CUT(unusedE)");
	
	   FSModeTree::createChi2RankingTree("accMC_2017_unusedEnergy.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_unusedEnergy.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_unusedEnergy.root","ntFSGlueX_101_1","m101_1","", "");



	   FSModeTree::skimTree("flattenedAccMC_2017p.root","ntFSGlueX_101_1","","accMC_2017_unusedTrack.root","CUT(unusedTrack)");
	   FSModeTree::skimTree("flattenedAccMC_2018_01p.root","ntFSGlueX_101_1","","accMC_2018_01_unusedTrack.root","CUT(unusedTrack)");
	   FSModeTree::skimTree("flattenedAccMC_2018_08p.root","ntFSGlueX_101_1","","accMC_2018_08_unusedTrack.root","CUT(unusedTrack)");

	   FSModeTree::createChi2RankingTree("accMC_2017_unusedTrack.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_unusedTrack.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_unusedTrack.root","ntFSGlueX_101_1","m101_1","", "");



	   FSModeTree::skimTree("flattenedAccMC_2017p.root","ntFSGlueX_101_1","","accMC_2017_eventLevelCut.root","CUT(unusedTrack,unusedE)");
	   FSModeTree::skimTree("flattenedAccMC_2018_01p.root","ntFSGlueX_101_1","","accMC_2018_01_eventLevelCut.root","CUT(unusedTrack,unusedE)");
	   FSModeTree::skimTree("flattenedAccMC_2018_08p.root","ntFSGlueX_101_1","","accMC_2018_08_eventLevelCut.root","CUT(unusedTrack,unusedE)");

	   FSModeTree::createChi2RankingTree("accMC_2017_eventLevelCut.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_eventLevelCut.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_eventLevelCut.root","ntFSGlueX_101_1","m101_1","", "");
	   



	   FSModeTree::skimTree("accMC_2017_eventLevelCut.root","ntFSGlueX_101_1","","accMC_2017_postRF.root","CUT(rf)");
	   FSModeTree::skimTree("accMC_2018_01_eventLevelCut.root","ntFSGlueX_101_1","","accMC_2018_01_postRF.root","CUT(rf)");
	   FSModeTree::skimTree("accMC_2018_08_eventLevelCut.root","ntFSGlueX_101_1","","accMC_2018_08_postRF.root","CUT(rf)");

	   FSModeTree::createChi2RankingTree("accMC_2017_postRF.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_postRF.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_postRF.root","ntFSGlueX_101_1","m101_1","", "");
	   


	   FSModeTree::skimTree("accMC_2017_postRF.root","ntFSGlueX_101_1","","accMC_2017_postRank.root","CUT(chiRank)");
	   FSModeTree::skimTree("accMC_2018_01_postRF.root","ntFSGlueX_101_1","","accMC_2018_01_postRank.root","CUT(chiRank)");
	   FSModeTree::skimTree("accMC_2018_08_postRF.root","ntFSGlueX_101_1","","accMC_2018_08_postRank.root","CUT(chiRank)");

	   FSModeTree::createChi2RankingTree("accMC_2017_postRank.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_postRank.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_postRank.root","ntFSGlueX_101_1","m101_1","", "");
	   



	   FSModeTree::skimTree("accMC_2017_postRank.root","ntFSGlueX_101_1","","accMC_2017_sansChi2.root","CUT(prodV,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_01_postRank.root","ntFSGlueX_101_1","","accMC_2018_01_sansChi2.root","CUT(prodV,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_08_postRank.root","ntFSGlueX_101_1","","accMC_2018_08_sansChi2.root","CUT(prodV,eta,pi0)");

	   FSModeTree::createChi2RankingTree("accMC_2017_sansChi2.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_sansChi2.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_sansChi2.root","ntFSGlueX_101_1","m101_1","", "");
	   



	   FSModeTree::skimTree("accMC_2017_postRank.root","ntFSGlueX_101_1","","accMC_2017_sansVertex.root","CUT(chi2,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_01_postRank.root","ntFSGlueX_101_1","","accMC_2018_01_sansVertex.root","CUT(chi2,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_08_postRank.root","ntFSGlueX_101_1","","accMC_2018_08_sansVertex.root","CUT(chi2,eta,pi0)");

	   FSModeTree::createChi2RankingTree("accMC_2017_sansVertex.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_sansVertex.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_sansVertex.root","ntFSGlueX_101_1","m101_1","", "");
	   



	   FSModeTree::skimTree("accMC_2017_postRank.root","ntFSGlueX_101_1","","accMC_2017_sansMass.root","CUT(prodV,chi2)");
	   FSModeTree::skimTree("accMC_2018_01_postRank.root","ntFSGlueX_101_1","","accMC_2018_01_sansMass.root","CUT(prodV,chi2)");
	   FSModeTree::skimTree("accMC_2018_08_postRank.root","ntFSGlueX_101_1","","accMC_2018_08_sansMass.root","CUT(prodV,chi2)");

	   FSModeTree::createChi2RankingTree("accMC_2017_sansMass.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01_sansMass.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08_sansMass.root","ntFSGlueX_101_1","m101_1","", "");




	   FSModeTree::skimTree("accMC_2017_sansChi2.root","ntFSGlueX_101_1","","accMC_2017.root","CUT(prodV,chi2,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_01_sansChi2.root","ntFSGlueX_101_1","","accMC_2018_01.root","CUT(prodV,chi2,eta,pi0)");
	   FSModeTree::skimTree("accMC_2018_08_sansChi2.root","ntFSGlueX_101_1","","accMC_2018_08.root","CUT(prodV,chi2,eta,pi0)");

	   FSModeTree::createChi2RankingTree("accMC_2017.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_01.root","ntFSGlueX_101_1","m101_1","", "");
	   FSModeTree::createChi2RankingTree("accMC_2018_08.root","ntFSGlueX_101_1","m101_1","", "");


	 */



	/*	hist = FSModeHistogram::getTH1F("accMC_2017_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents += hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_eventLevelCut.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents += hist->GetEntries() * 0.321;

		cout << "Weighted event-level combos frac: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted event-level events frac: " << (wtevents / weightedtot) << endl;
	 

	hist = FSModeHistogram::getTH1F("accMC_2017_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	combos = hist->GetEntries();
	weightedcombos = hist->GetEntries()* 0.174;
	hist = FSModeHistogram::getTH1F("accMC_2017_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
	events = hist->GetEntries();
	wtevents= hist->GetEntries() * 0.174;

	hist = FSModeHistogram::getTH1F("accMC_2018_01_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	combos += hist->GetEntries();
	weightedcombos += hist->GetEntries()* 0.504;
	hist = FSModeHistogram::getTH1F("accMC_2018_01_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
	events += hist->GetEntries();
	wtevents += hist->GetEntries() * 0.504;

	hist = FSModeHistogram::getTH1F("accMC_2018_08_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
	combos += hist->GetEntries();
	weightedcombos += hist->GetEntries()* 0.321;
	hist = FSModeHistogram::getTH1F("accMC_2018_08_unusedEnergy.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
	events += hist->GetEntries();
	wtevents += hist->GetEntries() * 0.321;

	cout << "Weighted unusedEnergy combos frac: " << (weightedcombos / weightedReconCombos) << endl;
	cout << "Weighted unusedEnergy events frac: " << (wtevents / weightedtot) << endl;


*/


		
		hist = FSModeHistogram::getTH1F("accMC_2017_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		combos = hist->GetEntries();
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		events = hist->GetEntries();
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		combos += hist->GetEntries();
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		events += hist->GetEntries();
		wtevents += hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		combos += hist->GetEntries();
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_unusedTrack.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		events += hist->GetEntries();
		wtevents += hist->GetEntries() * 0.321;

		cout << "Weighted unusedTrack combos frac: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted unusedTrack events frac: " << (wtevents / weightedtot) << endl;




/*
		hist = FSModeHistogram::getTH1F("accMC_2017_sansRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_sansRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;


		hist = FSModeHistogram::getTH1F("accMC_2018_01_postRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_postRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents += hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_postRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_postRF.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents += hist->GetEntries() * 0.321;


		cout << "Weighted fraction - combos post RF: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events post RF: " << (wtevents / weightedtot) << endl;



		hist = FSModeHistogram::getTH1F("accMC_2017_postRank.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F(accMC_2018_01_postRank.root,"ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_postRank.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_postRank.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_postRank.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_postRank.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.321;

		cout << "Weighted fraction - combos post chi Rank: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events post chi Rank: " << (wtevents / weightedtot) << endl;



		hist = FSModeHistogram::getTH1F("accMC_2017_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansChi2.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.321;

		cout << "Weighted fraction - combos w/o chi2: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events w/o chi2: " << (wtevents / weightedtot) << endl;


		hist = FSModeHistogram::getTH1F("accMC_2017_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansMass.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.321;
		cout << "Weighted fraction - combos w/o mass windows: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events w/o mass windows: " << (wtevents / weightedtot) << endl;


		hist = FSModeHistogram::getTH1F("accMC_2017_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.504;

		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08_sansVertex.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.321;

		cout << "Weighted fraction - combos w/o vertex: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events w/o vertex: " << (wtevents / weightedtot) << endl;






		hist = FSModeHistogram::getTH1F("accMC_2017.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT()");
		weightedcombos = hist->GetEntries()* 0.174;
		hist = FSModeHistogram::getTH1F("accMC_2017.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents= hist->GetEntries() * 0.174;

		hist = FSModeHistogram::getTH1F("accMC_2018_01.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT()");
		weightedcombos += hist->GetEntries()* 0.504;
		hist = FSModeHistogram::getTH1F("accMC_2018_01.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.504;
	
		hist = FSModeHistogram::getTH1F("accMC_2018_08.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT()");
		weightedcombos += hist->GetEntries()* 0.321;
		hist = FSModeHistogram::getTH1F("accMC_2018_08.root","ntFSGlueX_101_1","","EnPB","(100,0,12.)","CUT(eventNum2)");
		wtevents+= hist->GetEntries() * 0.321;

		cout << "Weighted fraction - combos left: " << (weightedcombos / weightedReconCombos) << endl;
		cout << "Weighted fraction - events left: " << (wtevents / weightedtot) << endl;




	*/


}
