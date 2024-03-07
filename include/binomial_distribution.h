#pragma once
#include <cmath>

namespace batools::distributions::binomial {

    int binomial_coefficient(const int& n, const int& k);
    double probability_mass_function(const int& k, const int& n, const double& p);
    double cumulative_distribution_function(const int& k, const int& n, const double& p);

}