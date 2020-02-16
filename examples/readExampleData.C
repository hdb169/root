
/*# fake data to demonstrate the use of TGraphErrors

# x    y    ex    ey
  1.   0.4  0.1   0.05
  1.3  0.3  0.05  0.1
  1.7  0.5  0.15  0.1
  1.9  0.7  0.05  0.1
  2.3  1.3  0.07  0.1
  2.9  1.5  0.2   0.1



  */




void readExampleData(){

  TFile *f = new TFile("ROOTfiles/graph1.root","RECREATE");
  TGraphErrors *gr = new TGraphErrors("ExampleData.txt");
  gr->Draw("AP");
  gr->Write();

}
