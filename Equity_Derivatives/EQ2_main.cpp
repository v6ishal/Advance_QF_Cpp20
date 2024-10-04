#include"random.hpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // For 2 assets
    cout<<"Monte Carlo European Call"<<endl;
    //Input paramters
    auto T = 1; //maturity
    auto K = 100; //strike price
    auto S10 = 100; //spot price for asset 1
    auto S20 = 100; //spot price for asset 2
    auto sigma1 = 0.10; //volatility
    auto sigma2 = 0.15;
    auto rho = 0.5; //correlation
    auto r = 0.05; //IR
    int N = 500; //GBM
    int M = 10000; //MC

    double S1[N+1];
    double S2[N+1];
    auto premium = 0.0;
    auto payoff = 0.0;
    auto dt = T/N;
    
    //Simulations
    for(int i=0;i<M;i++)
    {
        S1[0] = S10;
        S2[0] = S20;
        for(int j=0;j<N;j++)
        {
            double epsilon1 = boxMuller();
            S1[j+1] = S1[j]*(1+r*dt+sigma1*sqrt(dt)*epsilon1);
            double epsilon2 = boxMuller();
            epsilon2 = epsilon1*rho+sqrt(1-rho*rho)*epsilon2;
            S2[j+1] = S2[j]*(1+r*dt+sigma2*sqrt(dt)*epsilon2);
        }
        //payoff
        payoff += max(S1[N], S2[N]);
    }

    //discount the payoff
    premium = exp(-r*T)*(payoff/M);
    cout<<"Premium for XYZ stock after GBM and Monte Carlo Simulations-> ";
    cout<<premium<<endl;

}
