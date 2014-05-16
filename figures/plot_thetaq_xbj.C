double thetaq(double *x, double *par){
  double xbj = x[0];
  double Q2 = par[0];
  double Ebeam = par[1];

  double Mp = 0.938272;
  double nu = Q2/(2.*Mp*xbj);
  double y = nu/Ebeam;
  
  //  return acos( (1.0+Mp*xbj*y/nu)/sqrt( 1.0+2.*Mp*xbj/nu ) );
  //cout << "nu, Q2, x, y = " << nu << ", " << Q2 << ", "
  //     << xbj << ", " << y << endl;

  //cout << "x, argument of acos = " << xbj << ", " << (nu + Mp*xbj*y)/sqrt(pow(nu,2)+Q2) << endl;

  //double W2 = pow(Mp,2) + Q2*(1.-xbj)/xbj;

  if( nu + Mp*xbj*y >= sqrt(pow(nu,2)+Q2) ) return 0.0;

  if( nu >= Ebeam ) return 0.0;
  else return 180.0/TMath::Pi() * acos( (nu + Mp*xbj*y)/sqrt(pow(nu,2)+Q2) );
}

void plot_thetaq_xbj(){
  TF1 *thetaq_x_Q2 = new TF1("thetaq_x_Q2", thetaq, 1.e-4, 1.0 ,2 );
 
  double Mp = 0.938272;
  //W^2 = M^2 + Q^2(1-x)/x
  // x (W^2 + Q^2) = M^2 + Q^2
  double W2min = 4.0;
  double Q2 = 1.0;
  double xmax = (pow(Mp,2) + Q2)/(W2min + Q2 );
  //double ymax = 0.99;
  double Ebeam = 11.0;
  double pmin = 0.01; //GeV
  double numax = Ebeam - pmin;
  double xmin = Q2/(2.*Mp*numax);

  TH2D *frame = new TH2D("frame","",1,0.0,1.0,1,0.0,45.0);

  frame->Draw();

  thetaq_x_Q2->FixParameter(1, Ebeam);

  for(int i=1; i<=14; i++){
    
    thetaq_x_Q2->SetParameter(0, Q2);
    
    cout << "Q2 = " << Q2 << endl;

    xmax = (pow(Mp,2) + Q2)/(W2min + Q2 );
    xmin = Q2/(2.*Mp*numax);

    cout << "xmin, xmax = " << xmin << ", " << xmax << endl;
    
    thetaq_x_Q2->SetRange( xmin, xmax );
    
    thetaq_x_Q2->SetLineColor(i);
    
    thetaq_x_Q2->DrawCopy("same");
    
    Q2 += 1.0;
    
  }
  

}
