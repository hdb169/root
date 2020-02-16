// Builds a graph with errors, displays it and saves it as image
#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void TGraphErr(){
  const int n_points=10;
  double x_vals[n_points]={1,2,3,4,5,6,7,8,9,10};
  double y_vals[n_points]={6,12,14,20,22,24,35,45,44,53};
  double y_errs[n_points]={5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};




  TGraphErrors *gr = new TGraphErrors(n_points,x_vals,y_vals,nullptr,y_errs);
  gr->SetTitle("Main Title; x label [unit]; y label [unit]");
  gr->SetMarkerStyle(kOpenCircle);
  gr->SetMarkerColor(kBlue);
  gr->SetLineColor(kBlue);
  gr->SetLineWidth(4);

  TCanvas *c1 = new TCanvas();
  gr->DrawClone("APE");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->CenterTitle();
  // Define a linear function
  TF1 *f1 = new TF1("Linear Law", "[0]+x*[1]",0.5,10.5);
  f1->SetLineColor(kRed);
  f1->SetLineStyle(2);
  f1->SetLineWidth(5);
  // Fit it to the graph and draw it
  gr->Fit(f1);// f1, where f1 is [0]+x[1] is y = mx +c type
  f1->DrawClone("Sames");//IMPORTANT we are fitting graph
  // i.e gr into this linear function, so use gr
  //Rem. DrawClone not the Draw
 
  // Build and Draw a legend

  TLegend * leg = new TLegend(0.1,0.7,0.48,0.9,"Lab. Lesson 1"); //don't have ("leg",0.1....)//x1,y1 =lower left,x2,y2 = upper right, whole canvas with title of size 1,1,1,1

  leg->SetFillColor(0);
  gr->SetFillColor(0);
  leg->AddEntry(gr,"Exp. Points");// we have two graphs, one from fit (Th) and one from data
  leg->AddEntry(f1, "Th. Law");
  leg->DrawClone("same");//DrawClone


  TArrow * arrow = new TArrow(8,8,6.2,23,0.02,"|>");//x1,y1 to x2, y2; |> = arrow
  arrow->SetLineWidth(2);
  arrow->SetLineColor(kGreen);
  arrow->DrawClone();

  TLatex *text = new TLatex(8.2,7.5,"#splitline{Maximum}{Deviation}");//x=8,y=7
 text->DrawClone();
  c1->Print("pdf/graph_with_law.pdf");
  // c1->Print("pdf/graph_with_law.eps");
  //c1->Print("pdf/graph_with_law.gif");

}
int main(){
  TGraphErr();
}
