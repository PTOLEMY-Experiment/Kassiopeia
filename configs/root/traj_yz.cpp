//g++ demo2.cxx $(root-config --glibs --cflags --libs) -o demo2

#include "TF1.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include <TStyle.h>

int main(int argc, char **argv)
{
    TApplication app("app", &argc, argv);
    TFile f("sim/output/Kassiopeia/test_1T_y0.078439816.root");

//    TFile f("sim/output/Kassiopeia/analytic_1T_ysingle0.0261799388_kescan18600_E0-37200.root");
//    TFile f("sim/output/Kassiopeia/analytic_10T_0.0050550_0.0050600_scan.root");
//    TFile f("sim/output/Kassiopeia/analytic_0.005_0.006_10T_scan_0.005_0.00505.root");

    TCanvas *c = new TCanvas("c_traj_E", "c_traj_E", 1);
    c->Divide(1, 2);

    TTree *steps, *track;
    f.GetObject("component_step_world_DATA",steps);
    f.GetObject("component_track_world_DATA",track);

    gStyle->SetPalette(kRainBow);

    c->cd(1);
    steps->Draw("kinetic_energy:position_z");
    c->SetLogy();

    c->cd(2);
    steps->Draw("position_y:position_z:kinetic_energy","","col RY");

    TH2F *h1;

    h1 = (TH2F*)c->GetPrimitive("htemp");
//    h1->GetXaxis()->SetTitle("Position Z (m)");
//    h1->GetYaxis()->SetTitle("Position Y (m)");
//    h1->SetTitle("");
//    h1->GetYaxis()->SetTitleOffset(1.2);

    c->Modified(); c->Update();

    TRootCanvas *rc = (TRootCanvas *)c->GetCanvasImp();
    rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    app.Run();
    return 0;
}


/*

TCanvas *cTrajE = new TCanvas("c_traj_E", "c_traj_E", 1);
cTrajE->Divide(1, 2);

std::vector<double> kmins;
std::vector<double> kmaxs;
std::vector<double> ymins;
std::vector<double> ymaxs;
std::vector<double> zmins;
std::vector<double> zmaxs;

TMultiGraph *KEs = new TMultiGraph();
TMultiGraph *YZs = new TMultiGraph();

for (int i = 0; i < num_tracks; i++) {
    LTrack *tr = tracks[i];

    vector<double> t = tr->GetTime();
    for (size_t i = 0; i < t.size(); i++) t[i] = 1e9 * t[i]; // display as ns

    vector<double> e = tr->GetEnergy();
    vector<double> u = tr->GetPotential();
    vector<double> k = tr->GetKinetic();

    TGraph *gK = new TGraph(t.size(), &t[0], &k[0]);
    gK->SetLineWidth(2);
    gK->SetLineColor(i + 1);

    KEs->Add(gK);

    vector<double> x = tr->GetX();
    vector<double> y = tr->GetY();
    vector<double> z = tr->GetZ();

    TGraph *gTrajYZ = new TGraph(y.size(), &z[0], &y[0]);
    gTrajYZ->SetLineWidth(2);
    gTrajYZ->SetLineColor(i + 1);

    YZs->Add(gTrajYZ);

}
*/
/*
    double kmin = TMath::MinElement(gK->GetN(), gK->GetY()); // optimize range
    double kmax = TMath::MaxElement(gK->GetN(), gK->GetY());
    kmins.push_back(kmin);
    kmaxs.push_back(kmax);
    double kgmin = *std::min_element(kmins.begin(),kmins.end());
    double kgmax = *std::max_element(kmaxs.begin(),kmaxs.end());

    gK->GetYaxis()->SetRangeUser(0.8*kgmin, 1.2*kgmax);

    double zmin = TMath::MinElement(gTrajYZ->GetN(), gTrajYZ->GetX()); // optimize range
    double zmax = TMath::MaxElement(gTrajYZ->GetN(), gTrajYZ->GetX());
    double ymin = TMath::MinElement(gTrajYZ->GetN(), gTrajYZ->GetY());
    double ymax = TMath::MaxElement(gTrajYZ->GetN(), gTrajYZ->GetY());
    ymins.push_back(ymin);
    ymaxs.push_back(ymax);
    zmins.push_back(zmin);
    zmaxs.push_back(zmax);
    double ygmin = *std::min_element(ymins.begin(),ymins.end());
    double ygmax = *std::max_element(ymaxs.begin(),ymaxs.end());
    double zgmin = *std::min_element(zmins.begin(),zmins.end());
    double zgmax = *std::max_element(zmaxs.begin(),zmaxs.end());


    gTrajYZ->GetXaxis()->SetRangeUser(zgmin>0? 0.8*zgmin:1.2*zgmin, zgmax>0? 1.2*zgmax:0.8*zgmax);
    gTrajYZ->GetYaxis()->SetRangeUser(ygmin>0? 0.8*ygmin:1.2*ygmin, ygmax>0? 1.2*ygmax:0.8*ygmax);*//*


cTrajE->cd(1);
KEs->SetTitle("Kinetic Energy; t[ns] ; Energy [eV]");
KEs->Draw("AL");
gPad->SetLogy();
//    KEs->GetHistogram()->GetXaxis()->SetRangeUser(0.,2.5);

cTrajE->cd(2);
YZs->SetTitle("YZ Track; z[m]; y[m]");
YZs->Draw("AL RY");

*/




/*


steps->Draw("sqrt(momentum_y*momentum_y+momentum_z*momentum_z):position_z:magnetic_field_x","","col");
c1->SetLogy();
TH2F *h = (TH2F*) c1->GetPrimitive("htemp");
h->GetYaxis()->SetLimits(1e-26,2e-22);
h->GetXaxis()->SetLimits(-1,0);
c1->Modified();
c1->Update()

    h = (TH2F*) c1->GetPrimitive("htemp");

steps->Draw("sqrt(momentum_y*momentum_y+momentum_z*momentum_z):position_z:time","","col");
c1->SetLogy();
h->GetYaxis()->SetLimits(1e-26,2e-22);
c1->Modified();
c1->Update()

    steps->Draw("sqrt(momentum_y*momentum_y+momentum_z*momentum_z):position_z:time","","col");
c1->Modified();
c1->Update()

    TFile f("sim/output/Kassiopeia/flat_world_single_point.root");
TTree *steps, *track;
f.GetObject("component_step_world_DATA",steps);
f.GetObject("component_track_world_DATA",track);
steps->Draw("position_y:position_z:time","","col")

    steps->Draw("position_x:position_y:position_z:time")


        steps->Draw("position_y:position_z:time","","col")
            c1->Modified();
c1->Update()
    h = (TH2F*) c1->GetPrimitive("htemp");
h->GetXaxis()->SetLimits(-0.1,0.1);
h->GetYaxis()->SetLimits(-0.1,0.1);
h->GetZaxis()->SetLimits(-0.1,1);
c1->Modified();
c1->Update()

    steps->Draw("magnetic_field_x:position_z")
        steps->Draw("position_x:position_y:position_z:time")
            steps->Draw("position_y:position_x:position_z:sqrt(momentum_y*momentum_y+momentum_z*momentum_z)")
                steps->Draw("sqrt(momentum_y*momentum_y+momentum_z*momentum_z):position_z:electric_field_y","","col")

                    steps->Draw("sqrt(momentum_y*momentum_y+momentum_z*momentum_z)/(magnetic_field_x*1.6e-19):position_z")


                        h->GetYaxis()->SetLimits(1e-26,2e-22);
c1->Modified();
c1->Update()
    h->GetXaxis()->SetLimits(-1,0);c1->Modified();c1->Update()

    */