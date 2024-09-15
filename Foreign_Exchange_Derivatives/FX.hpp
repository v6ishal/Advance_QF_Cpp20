// FX.h
#ifndef FX_H
#define FX_H

#include "matrix.hpp"
#include <bits/stdc++.h>
using namespace std;

// A struct to hold the result data
struct result_data {
    double alpha;
    double dtau;
    double k;
    std::vector<double> x, S, t, tau;
    matrix<double> u, v;

    result_data(double a, double d, double k_, std::vector<double> x_,
                std::vector<double> S_, std::vector<double> t_,
                std::vector<double> tau_, matrix<double> u_,
                matrix<double> v_)
        : alpha(a), dtau(d), k(k_), x(x_), S(S_), t(t_), tau(tau_), u(u_), v(v_) {}
};

// Declare the operator << function for result_data
std::ostream& operator<<(std::ostream& os, const result_data& result);

class FX {
private:
    double T, K, S0, sigma, r, dt, dx;
    int N, M;

public:
    FX(double T_, double K_, double S0_, double sigma_, double r_, double dt_, double dx_, int N_, int M_){
        T = T_;
        K = K_;
        S0 = S0_;
        sigma = sigma_;
        r = r_;
        dt = dt_;
        dx = dx_;
        N = N_;
        M = M_;
    }

    result_data get_data_and_premium() const;
    result_data evaluate_data_and_premium() const;
};

#endif
