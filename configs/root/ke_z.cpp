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
    TCanvas* c = new TCanvas("c", "traj_yz", 0, 0, 800, 600);
    TFile f("sim/output/Kassiopeia/test_1T_y0.078439816.root");
//    TFile f("sim/output/Kassiopeia/analytic_1T_ysingle0.0261799388_kescan18600_E0-37200.root");
//    TFile f("sim/output/Kassiopeia/analytic_0.005_0.006_10T_scan_0.005_0.00505.root");
//    TFile f("sim/output/Kassiopeia/flat_world_single_point_0.07205_0.07215.root");

    TTree *steps, *track;
    f.GetObject("component_step_world_DATA",steps);
    f.GetObject("component_track_world_DATA",track);

    gStyle->SetPalette(kRainBow);


    steps->Draw("position_y:position_z:kinetic_energy","","col");
//    steps->Draw("kinetic_energy:position_z");
//    steps->Draw("col");
//    c->SetLogy();

//    TF1 *f1 = new TF1("f1","sin(x)", -5, 5);
//    f1->SetLineColor(kBlue+1);
//    f1->SetTitle("My graph;x; sin(x)");
//    f1->Draw();

    TH2F *h1;

    h1 = (TH2F*)c->GetPrimitive("htemp");
//    h1->GetZaxis()->SetLimits(-0.01,0.002);
//    h1->GetYaxis()->SetLimits(1,20000);
//    h1->GetXaxis()->SetLimits(-0.1,0.8);

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