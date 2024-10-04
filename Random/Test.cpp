#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>

double option_price_gbm(bool is_call, double S, double K, double T, double r, double sigma) {
    // Using boost for the cumulative normal distribution
    boost::math::normal_distribution<> norm_dist(0.0, 1.0);

    // Calculate d1 and d2
    double d1 = (std::log(S / K) + (r + sigma * sigma / 2.0) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (is_call) {
        // Call option price
        return S * boost::math::cdf(norm_dist, d1) - K * std::exp(-r * T) * boost::math::cdf(norm_dist, d2);
    } else {
        // Put option price
        return K * std::exp(-r * T) * boost::math::cdf(norm_dist, -d2) - S * boost::math::cdf(norm_dist, -d1);
    }
}

int main() {
    // Option parameters
    double S = 100.0;    // Spot price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity in years
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility

    // Call option price
    double call_price = option_price_gbm(true, S, K, T, r, sigma);
    std::cout << "Call Option Price: " << call_price << std::endl;

    // Put option price
    double put_price = option_price_gbm(false, S, K, T, r, sigma);
    std::cout << "Put Option Price: " << put_price << std::endl;

    return 0;
}
