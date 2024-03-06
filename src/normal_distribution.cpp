#include "normal_distribution.h"

namespace batools::distributions::normal {

#define SQRT_2 std::sqrt(2)

    double probability_density_function(const double& value, const double& mean, const double& std) {
        return (1 / (std * std::sqrt(2 * M_PI))) * (std::exp(-1 * std::pow((value - mean), 2) / (2 * std::pow(std, 2))));
    }

    double cumulative_distribution_function(const double& value, const double& mean, const double& std) {
        return ::batools::distributions::standard_normal::cumulative_distribution_function(::batools::distributions::standard_normal::standardize(value, mean, std));
    }

}

namespace batools::distributions::standard_normal {

    double probability_density_function(const double& value) {
        return ::batools::distributions::normal::probability_density_function(value, 0, 1);
    }

    double cumulative_distribution_function(const double& value) {
        return 0.5 * (1 + std::erf(value / SQRT_2));
    }

}