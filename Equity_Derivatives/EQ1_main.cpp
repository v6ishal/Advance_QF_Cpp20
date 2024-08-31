#include "random.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    cout << "\n *** START EQ1: Monte Carlo European Call *** \n";
    // STEP 1: INPUT PARAMETERS
    double T=1; // maturity
    double K=100; // strike
    double S0=100; // spot
    double sigma=0.10; // volatility
    double r=0.05; // interest rate
    int N=500; // number of steps
    int M=10000; // number of simulations
    double S[N+1];
    double sumpayoff=0;
    double premium=0;
    double dt = T / N;
    // STEP 2: MAIN SIMULATION LOOP
    for (int j=0; j < M; j++)
    {
        S[0]=S0; // initialize each path for simulation
        // STEP 3: TIME INTEGRATION LOOP
        for (int i=0; i < N; i++)
        {
            double epsilon = SampleBoxMuller(); // get Gaussian draw
            S[i+1] = S[i]*(1+r*dt+sigma*sqrt(dt)*epsilon);
        }
        // STEP 4: COMPUTE PAYOFF
        sumpayoff += max(S[N]-K,0.0); // compute and ad payoff
    }
    // STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF
    premium = exp(-r*T)*(sumpayoff / M);
    // STEP 6: OUTPUT RESULTS
    cout <<"premium = " << premium << "\n";
    cout << "\n *** END EQ1: Monte Carlo single asset *** \n";
    return 0;
}