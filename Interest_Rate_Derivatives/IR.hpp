

#ifndef IR_HPP
#define IR_HPP

#include <bits/stdc++.h>
#include "matrix.hpp"
#include "random.hpp"
using namespace std;

struct IR_results
{
    std::vector<double> datapoints;
    double Value;

    IR_results(const std::vector<double>& data, double val)
        : datapoints(data), Value(val) {}
};

class IR
{
private:
    double notional;
    double K;        // Fixed rate
    double alpha;    // Daycount factor
    double sigma;    // Forward rates volatility
    double dT;       // Time increment
    int N;           // Number of forward rates
    int M;           // Number of simulations

public:
    IR(double notional, double K, double alpha, double sigma, double dT, int N, int M)
        : notional(notional), K(K), alpha(alpha), sigma(sigma), dT(dT), N(N), M(M) {}

    // Function to run the LIBOR rate Monte Carlo simulations
    IR_results run_LIBOR_simulations() const;

    // Wrapper to call run_LIBOR_simulations()
    IR_results get_simulation_data() const
    {
        return run_LIBOR_simulations();
    }
};

#endif // IR_HPP
