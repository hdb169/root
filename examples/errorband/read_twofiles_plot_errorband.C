#include <sstream>
#include <string>
#include <fstream>

void read_twofiles_plot_errorband()
{
  std::ifstream infile("errorband_observed.txt"); //reads first txtfile
    
  std::string line;// read line by line
  vector <int> num; // define the following quantities which are actually the columns in the shms_eff.txt file, specify which is of int or float or double type
  vector <double> xval;
 vector <double> yval;
  vector <double> yval_err;
    
  while (std::getline(infile, line))//while loop to read all the lines , getline is to read all line of the txt file which is stored as infile, and reading all the lines
    {
      std::istringstream iss(line);// to read the whole strings in a line
      double a, b, c, d;// define eun by a, did by b, should by c, eff by d and eff_err by e
      if (!(iss >> a >> b >> c>>d)) // if it could not fine a, b, c, d, e, then not to proceed, so there must be 5 columns in this case.
        {
            
	  break; 
            
        } // error
      num.push_back(a);
      xval.push_back(b);//now run is stored in a
      yval.push_back(c);//did is stored in b
      yval_err.push_back(d);//should is stored as c
    
    }


std::ifstream infile1("errorband_expected.txt"); //reads first txtfile
    
  std::string line1;// read line by line
vector <int> num1;
  vector <double> xval1; // define the following quantities which are actually the columns in the shms_eff.txt file, specify which is of int or float or double type
  vector <double> yval1;
  vector <double> yval_err1;
    
  while (std::getline(infile1, line1))//while loop to read all the lines , getline is to read all line of the txt file which is stored as infile, and reading all the lines
    {
      std::istringstream iss(line1);// to read the whole strings in a line
      double a1, b1, c1, d1;// define eun by a, did by b, should by c, eff by d and eff_err by e
      if (!(iss >> a1 >> b1 >> c1 >> d1)) // if it could not fine a, b, c, d, e, then not to proceed, so there must be 5 columns in this case.
        {
            
	  break; 
            
        } // error
      num1.push_back(a1);
      xval1.push_back(b1);//now run is stored in a
      yval1.push_back(c1);//did is stored in b
      yval_err1.push_back(d1);//should is stored as c
    
    }

  //=========================================================//


  for (int i =0; i< xval1.size(); i++)// for cout you have to have elements equal to in one column or column with maximum elements 
    {
      // cout << xval[i]<<"\t"<<yval[i]<<"\t"<<yval_err[i]<<"\t"<<endl;

      
      cout<< num[i]<<"\t"<<xval1[i]<<"\t"<<yval1[i]<<"\t"<<yval_err1[i]<<"\t"<<num1[i]<<"\t"<< xval1[i]<<"\t"<<yval1[i]<<"\t"<<yval_err1[i]<<"\t"<<endl;//you have to cout each elements , so need i

    }
  TCanvas *c1 = new TCanvas("c1","ErrorBand",600,400);
  c1->cd();c1->SetGrid();
  TGraphErrors * gr = new TGraphErrors(num.size(), &xval[0], &yval[0],0, &yval_err[0]);//observed
  TGraphErrors * gr1 = new TGraphErrors(num1.size(), &xval1[0], &yval1[0],0, &yval_err1[0]);//expected


  gr1->GetXaxis()->SetTitle("XAxis Title [unit]");
  gr1->GetYaxis()->SetTitle("YAxis Title [unit]");
  gr1->GetXaxis()->CenterTitle();
  gr1->GetYaxis()->CenterTitle();
  gr1->GetYaxis()->SetRangeUser(-15,70);
  gr1->GetXaxis()->SetRangeUser(0,12);
  gr1->GetYaxis()->SetTitleOffset(1.2);
  gr1->SetTitle("Plot with Error Band");
  gr1->SetFillColor(kYellow);
   gr1->DrawClone("E3AL");
 
  gr->SetMarkerStyle(kFullCircle);
  gr->SetLineWidth(2);
  gr->DrawClone("PESame");
  // gr1->DrawClone("E3AL");

  c1->SaveAs("errorband.pdf");
  //Legend

  TLegend *leg = new TLegend(.1,.7,.3,.9,"First Error Band Plot Feb19 2020");
  leg->SetFillColor(0);
  leg->AddEntry(gr,"Observed Points");
  leg->AddEntry(gr1,"Expected Points");
  leg->DrawClone("Same");
  gr1->Print();
  gr->Print();
  return 0;


}

//Notes:
//(1) you are including Graph with Error, first one is to set points equal to size of first column, u can keep any columns, the x axis
// quantities, beginning from first number[0], y axis quantities[0], error along xaxis quantity = 0, if no error is defined, error in y axis quantities[0]


//2) When you draw two plots on the same Canvas, give the axis title etc to the first graph, and only then do gr->Draw("E3AL"), similarly write axis attributes for the second graph and write at the last gr->Draw()
