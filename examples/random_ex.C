
//1)It will take random numbers to fill histogram h1.
//(0,5) means put 5 for [0] i.e first param
//(1,10) means put 10 for 2nd param i.e.for [1]


using std::string;  

// root classes
#include "TH1F.h"
#include "TFile.h"
#include "TRandom.h"
void random_ex(){

  TFile *file = new TFile("ROOTfiles/function_as_a_hist.root","RECREATE");
  TF1 * f1 = new TF1( "f1"," [0]*x*x + [1] *x + 5", 3, 14.);
  f1->SetParameter(0,5);
  f1->SetParameter(1,10);
  TH1F *h1 = new TH1F ("h1","draw any function as a hist",100, 3,14);
  for (int i = 0;i<100;++i){
    h1->Fill(f1->GetRandom());
  }

  TCanvas *c1=new TCanvas("c1","c1",600,400);
  c1->Divide(2,1);

  c1->cd(1);
  h1->Draw();
  c1->cd(2);

  TH1F *h2 =new TH1F("h2","h2",100,-3,3);
  for (int i = 0; i<100; i++){
    h2->Fill((sin(i) * sin(i) + cos(i) * cos(i)), 1);
  } 

  h2->Draw();
  h1->Write();
  h2->Write();
  //file->Write();
}
