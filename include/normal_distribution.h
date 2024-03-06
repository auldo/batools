#pragma once
#include <cmath>

namespace batools::distributions::normal {

    double probability_density_function(const double& value, const double& mean, const double& std);
    double cumulative_distribution_function(const double& value, const double& mean, const double& std);

}

namespace batools::distributions::standard_normal {

    inline double standardize(const double& value, const double& mean, const double& std) { return (value - mean) / std; }
    double probability_density_function(const double& value);
    double cumulative_distribution_function(const double& value);

}