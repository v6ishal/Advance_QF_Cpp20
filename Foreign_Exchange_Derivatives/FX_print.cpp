// FX_print.cpp
#include "FX.hpp"
#include <bits/stdc++.h>
using namespace std;

// A function to format and print the results
ostream& operator<<(ostream& os, const result_data& result) {
    os << "Alpha: " << result.alpha << "\n";
    os << "Dtau: " << result.dtau << "\n";
    os << "k: " << result.k << "\n";

    os << "\nVector x:\n";
    for (const auto& val : result.x) {
        os << val << " ";
    }

    os << "\n\nVector S:\n";
    for (const auto& val : result.S) {
        os << val << " ";
    }

    os << "\n\nVector t:\n";
    for (const auto& val : result.t) {
        os << val << " ";
    }

    os << "\n\nVector tau:\n";
    for (const auto& val : result.tau) {
        os << val << " ";
    }

    os << "\n\nMatrix u:\n";
    for (int i = 0; i < result.u.num_rows(); ++i) {
        for (int j = 0; j < result.u.num_cols(); ++j) {
            os << result.u[i][j] << " ";
        }
        os << "\n";
    }

    os << "\n\nMatrix v:\n";
    for (int i = 0; i < result.v.num_rows(); ++i) {
        for (int j = 0; j < result.v.num_cols(); ++j) {
            os << result.v[i][j] << " ";
        }
        os << "\n";
    }

    os << "\n\nPremium:\n";
    int row = result.v.num_rows();
    int col = result.v.num_cols();
    os << result.v[row/2][col-1];
    os << "\n";

    return os;
}