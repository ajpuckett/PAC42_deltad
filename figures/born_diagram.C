{
  gROOT->ProcessLine(".x ~/rootlogon.C");
  TCanvas* c1 = new TCanvas("c1","c1",600,600);
  TCanvas *c2 = new TCanvas("c2","c2",600,600);
  
  c1->cd();

  TArrow A;
  TLine L; 
  //TCurlyLine G;

  L.SetLineWidth(3);
  A.SetLineWidth(3);
  //G.SetLineWidth(3);

  A.DrawArrow(0,1,0.25,0.875,.05,">");
  L.DrawLine(0.25,.875,0.5,.75);
  A.DrawArrow(.5,.75,.75,.875,.05,">");
  L.DrawLine(.75,.875,1,1);

  TCurlyLine G(.5,.75,.5,.5,.02,.02);
  G.SetLineWidth(3);
  G.SetWavy();
  G.Draw();

  TEllipse E;
  E.SetLineWidth(3);
  E.SetFillStyle(0);
  E.DrawEllipse(0.5,0.3,0.2,0.2,0,360,0);

  // R^2 = (x-x0)^2 + (y-y0)^2
  //y - y0 is known
  // x - x0 = +/- sqrt(R^2 - (y-y0)^2)

  double x1 = 0.5 - sqrt(pow(0.2,2.)-pow(0.15-0.3,2.));
  double x2 = 0.5 - sqrt(pow(0.2,2.)-pow(0.3-0.3,2.));
  double x3 = 0.5 - sqrt(pow(0.2,2.)-pow(0.3-0.45,2.));

  A.DrawArrow(0.0,0.15,0.1,0.15,.05,">");
  A.DrawArrow(0.0,0.3,0.1,0.3,.05,">");
  A.DrawArrow(0.0,0.45,0.1,0.45,.05,">");

  L.DrawLine(0.1,0.15,x1,0.15);
  L.DrawLine(0.1,0.3,x2,0.3);
  L.DrawLine(0.1,0.45,x3,0.45);

  L.DrawLine(1.-x1,0.15,1.0,0.0);
  L.DrawLine(1.-x3,0.45,1.0,0.6);

  c2->cd();
  
  A.DrawArrow(0,1,0.25,0.875,.05,">");
  L.DrawLine(0.25,.875,0.5,.75);
  A.DrawArrow(.5,.75,.75,.875,.05,">");
  L.DrawLine(.75,.875,1,1);
  
  G.SetLineWidth(3);
  G.SetWavy();
  G.Draw();

  E.SetLineWidth(3);
  E.SetFillStyle(0);
  E.DrawEllipse(0.5,0.3,0.2,0.2,0,360,0);

  A.DrawArrow(0.0,0.15,0.1,0.15,.05,">");
  A.DrawArrow(0.0,0.3,0.1,0.3,.05,">");
  A.DrawArrow(0.0,0.45,0.1,0.45,.05,">");

  L.DrawLine(0.1,0.15,x1,0.15);
  L.DrawLine(0.1,0.3,x2,0.3);
  L.DrawLine(0.1,0.45,x3,0.45);

  x1 = 0.5 + sqrt(pow(0.2,2.)-pow(0.15-0.3,2.));
  x2 = 0.5 + sqrt(pow(0.2,2.)-pow(0.3-0.3,2.));
  x3 = 0.5 + sqrt(pow(0.2,2.)-pow(0.3-0.45,2.));
  
  A.DrawArrow(x1,0.15,0.9,0.15,.05,">");
  A.DrawArrow(x2,0.3,0.9,0.3,.05,">");
  A.DrawArrow(x3,0.45,0.9,0.45,.05,">");

  L.DrawLine(0.9,0.15,1,0.15);
  L.DrawLine(0.9,0.3,1,0.3);
  L.DrawLine(0.9,0.45,1,0.45);

  TCanvas *c3 = new TCanvas("c3","c3",600,600);

  A.DrawArrow( 0.0, 0.7, 0.3, 0.7 , .05, "->-");
  A.DrawArrow( 0.3, 0.7, 0.6, 1.0 , .05, "->-");

  

  TCurlyLine gamma2( 0.3, 0.7, 0.5, 0.35, 0.02, 0.02 );

  gamma2.SetLineWidth(3);
  gamma2.SetWavy();
  gamma2.Draw();

  E.DrawEllipse( 0.2, 0.35, 0.03, 0.15, 0, 360, 0 );
  E.DrawEllipse( 0.8, 0.35, 0.03, 0.15, 0, 360, 0 );

  A.DrawArrow( 0.0, 0.45, 0.2 - 0.03*sqrt( 1 - pow(.1/.15,2)), 0.45, 0.05, "->-");
  A.DrawArrow( 0.0, 0.35, 0.2 - 0.03*sqrt( 1 - pow(0.0/.15,2)), 0.35, 0.05, "->-");
  A.DrawArrow( 0.0, 0.25, 0.2 - 0.03*sqrt( 1 - pow(0.1/.15,2)), 0.25, 0.05, "->-");

  A.DrawArrow( 0.8 + 0.03*sqrt( 1 - pow(.15/.15,2)), 0.5, 1, 0.6, 0.05, "->-");
  A.DrawArrow( 0.8 + 0.03*sqrt( 1 - pow(0.0/.15,2)), 0.35, 1, 0.35, 0.05, "->-");
  A.DrawArrow( 0.8 + 0.03*sqrt( 1 - pow(0.15/.15,2)), 0.2, 1, 0.1, 0.05, "->-");

  A.DrawArrow( 0.23, 0.35, 0.5, 0.35, 0.05, "->-");
  
  double slope_gamma = -0.35/0.2;
  
  A.DrawArrow( 0.5, 0.35, 0.5 - 0.15 /slope_gamma,0.2, .05, "->-" );

  double xtemp, ytemp;
  xtemp = 0.5 + 0.2 /fabs( slope_gamma );
  ytemp = 0.15;

  double alpha_angle = atan( fabs( slope_gamma ) );

  double xcent = xtemp + 0.04/fabs(slope_gamma);
  double ycent = ytemp - 0.04;

  double radius = 0.04 / sin( alpha_angle );
  //E.DrawEllipse( xcent, ycent, radius, radius, 0, 360, 0 );
  
  TVector3 recoiling_quark( 1.0/fabs(slope_gamma), -1, 0 );
  recoiling_quark = recoiling_quark.Unit();
  
  double a2 = 0.1;
  double b2 = 0.03; 
  
  TVector3 ellipse3_pos( 0.5 + 0.15/fabs(slope_gamma), 0.2, 0);
  ellipse3_pos += b2 * recoiling_quark;
  E.DrawEllipse( ellipse3_pos.X(), ellipse3_pos.Y(), a2, b2, 0, 360, 90.0 -  alpha_angle*180.0/TMath::Pi());
  
  TVector3 zaxis( 0, 0, 1 );
  TVector3 nperp = (zaxis.Cross( recoiling_quark )).Unit();

  TVector3 rayout1_pos = ellipse3_pos + a2 * nperp;
  TVector3 rayout2_pos = ellipse3_pos - a2 * nperp;
  //find the intersection with the plane y = 0;
  TVector3 yaxis(0,1,0);
  
  TVector3 ypoint(0.5,0,0);
  //nhat.(r-r0) = 0 
  //nhat = yaxis
  // r0 = ypoint
  // r = rayout_pos + s * rayout
  //nhat dot ( raypos + s * ray - r0) = 0
  // s * nhat.ray = nhat.(r0 - raypos)
  double s1 = yaxis.Dot( ypoint - rayout1_pos )/yaxis.Dot( recoiling_quark );
  double s2 = yaxis.Dot( ypoint - rayout2_pos )/yaxis.Dot( recoiling_quark );
  TVector3 rayout1_exit = rayout1_pos + s2 * recoiling_quark;
  TVector3 rayout2_exit = rayout2_pos + s2 * recoiling_quark;
  
  L.DrawLine( rayout1_pos.X(), rayout1_pos.Y(), rayout1_exit.X(), rayout1_exit.Y());

  L.DrawLine( rayout2_pos.X(), rayout2_pos.Y(), rayout2_exit.X(), rayout2_exit.Y());

  TVector3 gluepos1 = rayout1_pos + 0.8*s2 * recoiling_quark;
  TVector3 gluepos2 = rayout2_pos + 0.8*s2 * recoiling_quark;
  

  TCurlyLine gluon1( gluepos1.X(), gluepos1.Y(), 
		     gluepos2.X(), gluepos2.Y(), 
		     0.02, 0.02 );
  gluon1.SetLineWidth(3);
  gluon1.Draw();

  //TCurlyLine gluon2


    
}
