{
	/*
	   gROOT->ProcessLine( ".include ${AMPTOOLS}" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/report.cc+" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/Kinematics.cc+" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigurationInfo.cc+" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/ConfigFileParser.cc+" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/NormIntInterface.cc+" );
	   gROOT->LoadMacro( "/usr/local/AmpTools/AmpTools/IUAmpTools/FitResults.cc+" );
	 */


	TString pibasePath( "./alphaCombos/fit_fixedAlpha9_9_bin" );

	double Ypi, Ypi_obs,Yeta,Yeta_obs,pi_var,eta_var;

	double asym_std[8] = {0,3.90009e-03,
5.01260e-03 ,
6.67110e-03 ,
1.08485e-02,
1.47472e-02,
1.96787e-02,
 2.64215e-02
 };

	double total_variance[9];
	double total_stddev[9];

	for(int i=1; i<8; i++){
		TString pipath = pibasePath;
		pipath += i;
		pipath += ".fit";
		FitResults fr( pipath.Data(), true );


		Yeta = fr.intensity("FastEta::S1::E",true).first; // + fr.intensity("FastEta::S2::ps",true).first;
		Yeta_obs = fr.intensity("FastEta::S1::E",false).first; // + fr.intensity("FastEta::S2::ps",false).first;

		Ypi = fr.intensity("FastPi::S1P::E",true).first; // + fr.intensity("FastPi::S2P::ps",true).first;
		Ypi_obs = fr.intensity("FastPi::S1P::E",false).first; // + fr.intensity("FastPi::S2P::ps",false).first;


		pi_var= (Ypi*Ypi) / Ypi_obs; // + pi_std[i]*pi_std[i];
		eta_var = (Yeta*Yeta) / Yeta_obs; // + eta_std[i]*eta_std[i];;


		double denom =  pow((Ypi + Yeta),4);
		double num = 4*eta_var*Ypi*Ypi + 4*pi_var*Yeta*Yeta;

	
		total_stddev[i] = sqrt((num / denom)+ asym_std[i]*asym_std[i]);

		cout << total_stddev[i] <<", " ;
	}


}
