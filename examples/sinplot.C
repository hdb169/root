void sinplot(){
  Int_t N=6;
  Double_t x = 1.5;
  Double_t geom_series = 0;
  for (int i=0; i<N;++i){// when N = 10, i will go fro 0 to 9 only
    geom_series+=TMath::Power(x,i);//when N =10=>[0.5^0 =1, 1+ 0.5^1 = 1.5, 1.5+0.5^2 = 1.75, 1.75+0.5^3 = 1.875, 
    //1.875+0.5^4 = 1.9375,...., 1.99609+0.5^9 = 1.99804 
    cout<<geom_series<<endl;
    cout <<"=========================="<<endl;
    cout << TMath::Abs(geom_series - (1-TMath::Power(x,N-1))/(1-x)) <<endl;

  }
  //NO LOOOP
  
  cout<<"hi"<<endl;
  cout<<geom_series<<endl;
  cout << TMath::Abs(geom_series - (1-TMath::Power(x,N-1))/(1-x)) <<endl;

  //////DONE

  TCanvas *c1= new TCanvas ("c1","c1",600,400);
  c1->Divide(2,2);
  c1->cd(1);
  TF1 *f1 = new TF1("f1","sin(x)/x",0,100);
  f1->Draw();
  c1->cd(2);
  TF1 *f2 = new TF1("f2","sin(x) * sin(x) + cos(x) * cos(x)",0,100);
  f2->Draw();

  c1->cd(3);

  TF3*f3 = new TF3("f3","[0]*sin([1]*x)/x",0.,10.);
  f3->SetParameter(0,5);//SetParameter(a,b)=>where a is for paramtere number 0,1,2...or which, where as b os for providing
  // exact value of that parameter.Here for parameter [0], give value of 1, and for parameter [1], give the value of 1
  f3->SetParameter(1,3);
  f3->Draw();




}
