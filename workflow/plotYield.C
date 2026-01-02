{
	gROOT->ProcessLine( ".include ${AMPTOOLS}" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/report.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/Kinematics.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigurationInfo.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigFileParser.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/NormIntInterface.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/FitResults.cc+" );

	TString etaBasePath( "./alphaCombos/fit_fixedAlpha9_9_bin" );

	double x[10];
	double y[10];
	double yerr[10];
	double xerr[10];
	double z[10];
	double pi[10];
	double eta[10];
  double z2[10];


	for( int i = 0; i <7; ++i ){


		TString etapath = etaBasePath;
		etapath += (i+1);
		etapath += ".fit";

		FitResults fr( etapath.Data(), true );

		double a = fr.intensity("FastEta::S1::E",true).first;

		double b = fr.intensity("FastPi::S1P::E",true).first;
		z[i] = fr.intensity("FastEta::S2::ps", true).first;

  		z2[i] = fr.intensity("FastPi::S2P::ps", true).first;

		pi[i] =b;
		eta[i] = a;



		x[i] = 2.0 + (0.1)*(i+1);
		xerr[i] = 0;

	}

	double Upi_std[7] = { 6.91557e+02,
		4.72052e+02,
		4.84942e+02 ,
		3.82660e+02,
		2.73307e+02 ,
		1.94323e+02,
		1.61441e+02
	};

	double Ueta_std[7] = {5.82155e+02,
		4.52562e+02,
		4.57693e+02,
		3.50579e+02 ,
		2.74590e+02 ,
		1.89251e+02, 
		1.74349e+02
	};


	double pi_std[7] = { 6.55029e+02,
		4.93333e+02 ,
		4.71777e+02,
		3.51715e+02,
		2.51203e+02,
		1.85961e+02,
		1.51249e+02

	};
	double eta_std[7] = {6.07822e+02,
		5.01899e+02,
		4.25519e+02,
		3.82561e+02 ,
		2.59235e+02,
		1.83632e+02,
		1.69061e+02 
	};

	double zerr[7] = { 6.91557e+02,
		4.72052e+02,
		4.84942e+02,
		3.82660e+02,
		2.73307e+02 ,
		1.94323e+02,
		1.61441e+02
	};

	double zerr2[7] = {5.82155e+02,
4.52562e+02,
4.57693e+02,
3.50579e+02 ,
2.74590e+02 ,
1.89251e+02, 
1.74349e+02
};


	double nU_pi, nU_eta;
	double ntrue_uni; double nobs_uni, nU_eta_obs;;
	double ntrue_eta; double ntrue_pi; double nobs_eta; double nobs_pi;
	for(int i=0; i<7;i++){
		TString etapath = etaBasePath;
		etapath += (i+1);
		etapath += ".fit";

		FitResults fr( etapath.Data(), true );


		 ntrue_eta = fr.intensity("FastEta::S1::E",true).first;

                nobs_eta = fr.intensity("FastEta::S1::E",false).first;
                ntrue_pi = fr.intensity("FastPi::S1P::E",true).first;
                nobs_pi = fr.intensity("FastPi::S1P::E", false).first;
                nU_eta = fr.intensity("FastEta::S2::ps",true).first;
                nU_eta_obs = fr.intensity("FastEta::S2::ps",false).first;
                nU_pi = fr.intensity("FastPi::S2P::ps",true).first;
                ntrue_uni = fr.intensity("FastPi::S2P::ps",true).first;
                nobs_uni = fr.intensity("FastPi::S2P::ps",false).first;

zerr2[i] = sqrt(zerr2[i]*zerr2[i] + (nU_eta*nU_eta / nU_eta_obs));
                zerr[i] = sqrt(zerr[i]*zerr[i] + (ntrue_uni*ntrue_uni / nobs_uni));
                pi_std[i] = sqrt(pi_std[i]*pi_std[i] + (ntrue_pi*ntrue_pi / nobs_pi));
                eta_std[i] = sqrt(eta_std[i]*eta_std[i] + (ntrue_eta*ntrue_eta / nobs_eta));
                //N_true div sqrt (N_obs)

                double ratio = ntrue_eta/ (ntrue_eta + nU_eta);
                double sigmaR = ratio *  sqrt((eta_std[i]*eta_std[i] / (ntrue_eta*ntrue_eta)) + (Ueta_std[i]*Ueta_std[i] + eta_std[i]*eta_std[i]) / ((nU_eta+ntrue_eta)*(nU_eta+ntrue_eta)));

                cout << ratio << " \pm "  << sigmaR << endl;

	}
	TGraphErrors* g2 = new TGraphErrors(7,x,pi,xerr,pi_std );
	TGraphErrors* g = new TGraphErrors(7,x,eta,xerr,eta_std );
 TGraphErrors* g3 = new TGraphErrors(7, x, z, xerr, zerr);
        TGraphErrors* g4 = new TGraphErrors(7, x, z2, xerr, zerr);
	g->SetMinimum(0);
	g->GetXaxis()->SetTitle("Mass #eta#pi [GeV]");
	g->GetYaxis()->SetTitle("Yield (\# of Events)");
	g->SetMarkerStyle(20);
	g->SetMarkerSize(1);
	g->SetMarkerColor(kBlue);
	g->Draw("AP");
	auto legend = new TLegend(0.1,0.7,0.48,0.9);

	g2->GetXaxis()->SetTitle("Mass #eta#pi");
	g2->SetMarkerStyle(20);
	g2->SetMarkerSize(1);
	g2->SetMarkerColor(kRed);
	g2->Draw("P");
   g3->GetXaxis()->SetTitle("Mass #eta#pi");
        g3->SetMarkerStyle(20);
        g3->SetMarkerSize(1);
        g3->SetMarkerColor(kBlack);
        g3->Draw("P");


legend->AddEntry(g3, "Uniform");
	legend->AddEntry(g, "Fast #eta");
	legend->AddEntry(g2, "Fast #pi");
	legend->Draw();

        g4->GetXaxis()->SetTitle("Mass #eta#pi");
        g4->SetMarkerStyle(20);
        g4->SetMarkerSize(1);
        g4->SetMarkerColor(kGreen);
        g4->Draw("P");

        legend->AddEntry(g4, "Uniform #eta");

	legend->Draw();

}
