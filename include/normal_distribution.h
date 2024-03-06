#pragma once
#include <cmath>

namespace batools::distributions::normal {

    double probability_density_function(const double& value, const double& mean, const double& std);

}

namespace batools::distributions::standard_normal {

    double probability_density_function(const double& value);

}