//This macro reads a txt or dat file with one column only

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_expodat(){
  TFile *file1 = new TFile("ROOTfiles/read_datfile.root","RECREATE");
  TH1F *h1 = new TH1F("h1","read_expodat", 100, 0., 5.);
   TH1F *h2 = new TH1F("h2","read_expodat", 100, 0., 5.);


  ifstream inputfile;
  double x;
  inputfile.open("expo.dat");

  while(inputfile >>x){// remember you need to use while
    // if(x>1.0){ you can set this
    h1->Fill(x);

    // } you can set this
  }

  h1->Draw("e p1");
  h2->Draw("same");
  h1->SetMarkerStyle(21);
  h1->SetMarkerSize(2);

  inputfile.close();
  h1->Write();// problem is its not writing in a error form
  h2->Write();
  //alternative way of reading file
  string line;
   ifstream myfile("expo.dat");
  if (myfile.is_open())
    {
      while(getline(myfile,line))
	{
	  cout<< line << "\n"<<endl;
	}
      myfile.close();
    }
  else cout<<"Unable to open file"<<endl;

}
