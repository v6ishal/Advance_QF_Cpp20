#include "IR.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Plain Vanilla IRS, pays fixed, receives floating
    // freq payments every 3M, maturity 1 year
    // STEP 1: INPUT PARAMETERS
    double notional = 1000000; // notional
    double K = 0.04; // fixed rate IRS
    double alpha = 0.25; // daycount factor
    double sigma = 0.15; // fwd rates volatility
    double dT = 0.25;
    int N = 3; // number forward rates
    int M = 1000; // number of simulations

    // Construct a IR object from the input parameters:
    IR ir1(notional, K, alpha, sigma, dT, N, M);

    auto results = ir1.get_simulation_data();

    auto sz = results.datapoints.size();
    for (decltype(sz) nsim = 0; nsim < sz; ++nsim)
    {
        cout << "simIRS[" << nsim << "] = " << results.datapoints[nsim] << endl;
    }
    cout << "\n *** IRS PV = " << results.Value << endl;

    return 0;
}
