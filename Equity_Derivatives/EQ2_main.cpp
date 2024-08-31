#include "random.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    cout << "\n *** START EQ2: Monte Carlo equity basket *** \n";
    // STEP 1: INPUT PARAMETERS
    double T=1; // maturity
    double r=0.05; // interest rate
    double S10=120; // spot equity 1
    double S20=100; // spot equity 2
    double sigma1=0.10; // volatility
    double sigma2=0.15; // volatility
    double rho=0.5; // correlation
    int N=300; // number of steps
    int M=10000; // number of simulations
    double S1[N+1];
    double S2[N+1];
    double sumpayoff=0;
    double premium=0;
    double dt = T / N;
    // STEP 2: MAIN SIMULATION LOOP
    for (int j=0; j < M; j++)
    {
        S1[0]=S10;
        S2[0]=S20;
        // STEP 3: TIME INTEGRATION LOOP
        for (int i=0; i < N; i++)
        {
            double epsilon1 = SampleBoxMuller();
            double epsilon2 = SampleBoxMuller();
            S1[i+1] = S1[i]*(1+r*dt+sigma1*sqrt(dt)*epsilon1);
            epsilon2 = epsilon1*rho+sqrt(1-rho*rho)*epsilon2;
            S2[i+1]=S2[i]*(1+r*dt+sigma2*sqrt(dt)*epsilon2);
        }
        // STEP 4: TIME INTEGRATION LOOP
        sumpayoff += max(S1[N],S2[N]);
    }
    // STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF
    premium = exp(-r*T)*(sumpayoff / M);
    // STEP 6: OUTPUT RESULTS
    cout <<"premium = " << premium << "\n";
    cout << "\n *** END EQ2: Monte Carlo equity basket *** \n";
    return 0;
}