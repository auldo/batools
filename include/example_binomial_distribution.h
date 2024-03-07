#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "binomial_distribution.h"

namespace batools::examples {
    void run_example_draw_binomial_distribution(const int& n, const double& p, const std::string& output);
    void run_example_draw_binomial_distribution_cumulative(const int& n, const double& p, const std::string& output);
}