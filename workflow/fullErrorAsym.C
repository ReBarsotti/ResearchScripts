{

	double x[10], xerr[10];
	for(int i=0;i<9;i++){
		x[i] = 2. + (0.1)*i;
		xerr[i] = 0.0;

	}



	double staterr[9] = {0.009237, 0.0101127, 0.0111764, 0.0120451, 0.0134226, 0.015445, 0.0183964, 0.0240482, 0.0292252}; //statistical errors
	double yerr[9] = {0.0089305, 0.018427, 0.029925, 0.02851, 0.013769, 0.016196, 0.026825, 0.042218, 0.033905};	//Systematic errors
	double y[9] = {-0.0363833, -0.0496567, -0.0758623, -0.133759, -0.195493, -0.2454, -0.280068, -0.345551, -0.3829}; //asymmetry


	for(int i=0;i<9;i++){
		yerr[i] = sqrt(yerr[i]*yerr[i] + staterr[i]*staterr[i]);
	}

	TGraphErrors* g = new TGraphErrors(8,x,y,xerr,yerr );
	TGraphErrors* g2 = new TGraphErrors(8,x,y,xerr,staterr );

	g->SetMinimum(-0.5);
	g->SetMaximum(0.);
	g->GetXaxis()->SetTitle("Mass #eta#pi");
	g->GetYaxis()->SetTitle(" #frac{Y_{#pi} - Y_{#eta}}{Y_{#pi} + Y_{#eta}}");
	//g->SetTitle("Asymmetry: #frac{#pi - #eta}{#pi + #eta}");
	g->SetMarkerStyle(20);
	g->SetMarkerSize(1);

	gStyle->SetEndErrorSize(10);
	//g->SetFillColor(4);
	//g->SetFillStyle(3010);
	//g->Draw("a3");
	g->Draw("AP");

	g2->SetMinimum(-0.5);
	g2->SetMaximum(0.);
	g2->GetXaxis()->SetTitle("Mass #eta#pi");
	g2->GetYaxis()->SetTitle(" #frac{Y_{#pi} - Y_{#eta}}{Y_{#pi} + Y_{#eta}}");
	//g->SetTitle("Asymmetry: #frac{#pi - #eta}{#pi + #eta}");
	g2->SetMarkerStyle(20);
	gStyle->SetEndErrorSize(5);
	g2->SetMarkerSize(1);
	g2->Draw("P");
}
