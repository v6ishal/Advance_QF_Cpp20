// FX2_main.cpp
#include "FX.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // STEP 1: INPUT PARAMETERS
    auto T = 0.5; // maturity
    auto K = 75.0; // strike
    auto S0 = 75.0; // spot
    auto sigma = 0.30; // volatility
    auto r = 0.05; // interest rate
    auto dx = 0.5; // space step
    auto dt = 0.1; // time step
    auto N = 5; // number of space steps
    auto M = 6; // number of time steps
    // Construct a FX object from the input parameters:
    FX fx_eq2(T, K, S0, sigma, r, dt, dx, N, M);
    // Ask the object to evaluate the FX data
    // for European Up-and_Out Barrier Call:
    auto result = fx_eq2.evaluate_data_and_premium();
    // STEP 7: OUTPUT RESULTS
    cout << result;

    return 0;
}