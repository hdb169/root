// Example drawing the interference pattern of light
// falling on a grid with n slits and ratio r of slit
// width over distance between slits.

auto pi = TMath::Pi();
// function code in C
double single(double *x, double *par) {
  return pow(sin(pi*par[1] * x[0])/(pi * par[0] * x[0]),2); //0 and 1 are set at the end of the code
}

double nslit0(double * x, double *par){
  return pow(sin(pi * par[1] * x[0]) / sin(pi * x[0]), 2);
}

double nslit(double *x, double *par){
  return single(x,par) * nslit0(x,par);
}
// This is the main program

void slits() {


  float r, ns;

  cout<<"slit width / g?";

  scanf("%f",&r);//r = width, %f for floats, %d for Double or int %s for string

  cout<<"# of slits?";

  scanf("%f", &ns); //numbe of slits 

  cout<<" interference pattern for  "<<ns
      <<" slits, width/distance: " <<r<<endl;

  // define function and set options
  TF1 * Fnslit = new TF1( "Fnslit",nslit,-5.001,5.,2.);// what is this 2>
  //TH1F *h1 = new TH1F(500,-5.001,5);
  Fnslit->SetNpx(5000);// x bins
  // set parameters, as read in above
  Fnslit->SetParameter(0,r);
  Fnslit->SetParameter(1,ns);
  // draw the interference pattern for a grid with n slits
  TCanvas *c1 = new TCanvas("c1","slits",600,400);
  c1->cd();
  Fnslit->Draw();

  c1->SaveAs(Form("pdf/slits_%f.pdf", ns));

}

//learn it
