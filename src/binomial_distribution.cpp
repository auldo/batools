#include "binomial_distribution.h"

namespace batools::distributions::binomial {

    int binomial_coefficient(const int& n, const int& k) {
        const auto n_fac{tgamma(n + 1)};
        const auto k_fac{tgamma(k + 1)};
        const auto nk_fac{tgamma((n - k) + 1)};
        return static_cast<int>(n_fac / (k_fac * nk_fac));
    }

    double probability_mass_function(const int& k, const int& n, const double& p) {
        return binomial_coefficient(n, k) * std::pow(p, k) * std::pow((1-p), (n-k));
    }

    double cumulative_distribution_function(const int& k, const int& n, const double& p) {
        double sum{0};
        for(auto i{0}; i <= k; ++i)
            sum += probability_mass_function(i, n, p);
        return sum;
    }

}