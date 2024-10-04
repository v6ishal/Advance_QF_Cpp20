#include"random.hpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Monte Carlo European Call"<<endl;
    //Input paramters
    auto T = 1; //maturity
    auto K = 100; //strike price
    auto S0 = 100; //spot price
    auto sigma = 0.10; //volatility
    auto r = 0.05; //IR
    int N = 500; //GBM
    int M = 10000; //MC

    double S[N+1];
    auto premium = 0.0;
    auto payoff = 0.0;
    auto dt = T/N;
    
    //Simulations
    for(int i=0;i<M;i++)
    {
        S[0] = S0;
        for(int j=0;j<N;j++)
        {
            double epsilon = boxMuller();
            S[j+1] = S[j]*(1+r*dt+sigma*sqrt(dt)*epsilon);
        }
        //payoff
        payoff += max(S[N]-K, 0.0);
    }

    //discount the payoff
    premium = exp(-r*T)*(payoff/M);
    cout<<"Premium for XYZ stock after GBM and Monte Carlo Simulations-> ";
    cout<<premium<<endl;

}
