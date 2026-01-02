{
	gROOT->ProcessLine( ".include ${AMPTOOLS}" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/report.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/Kinematics.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigurationInfo.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigFileParser.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/NormIntInterface.cc+" );
	gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/FitResults.cc+" );

	TString etaBasePath( "./unusedE/fit_fixedAlpha99_bin" );

	double x[10];
	double y[10];
	double yerr[10];
	double xerr[10];

	double pi[10];
	double eta[10];
	
	for( int i = 1; i <8; ++i ){


		TString etapath = etaBasePath;
		etapath += i;
		etapath += ".fit";

		FitResults freta( etapath.Data(), true );

		double a = freta.intensity("FastEta::S1::E",true).first;
	//	a += freta.intensity("FastEta::S2::ps",true).first;
		double a_err = freta.intensity("FastEta::S1::E", true).second;
		
		double b = freta.intensity("FastPi::S1P::E",true).first;
	//	b += freta.intensity("FastPi::S2P::ps",true).first;
		double b_err = freta.intensity("FastPi::S1P::E", true).second;


		pi[i] =a;
		eta[i] = b;



		x[i] = 2.0 + (0.1)*i;
		y[i] = (a-b)/(a+b);
		xerr[i] = 0.05;
		yerr[i] = (4 / pow((a+b),4)) * (b*b * a_err*a_err*a_err*a_err + a*a * b_err*b_err*b_err*b_err); 

	}

	TGraphErrors* g = new TGraphErrors(8,x,y,xerr,yerr );

	g->SetMinimum(-0.5);
	g->SetMaximum(0.5);
	g->GetXaxis()->SetTitle("Mass #eta#pi");
	g->SetTitle("Asymmetry: #frac{#pi - #eta}{#pi + #eta}");
	g->SetMarkerStyle(104);
	g->SetMarkerSize(2);
	g->Draw("AP");
	auto legend = new TLegend(0.1,0.7,0.48,0.9);

	legend->AddEntry(g, "Nominal");
	legend->Draw();


	double sum=0;	
	cout <<"Asymmetry: " << endl;
	for(int i=0; i<9;i++){
		sum+=y[i];	
		cout << y[i] << ", ";
	}
	cout << endl;

	cout <<"Intensity of Pi: " << endl;
	for(int i=1; i<9;i++){
		cout << pi[i] << ", ";
	}
	cout << endl;

	cout <<"Intensity of eta: " << endl;
	for(int i=1; i<9;i++){
		cout << eta[i] << ", ";
	}

}
