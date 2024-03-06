#pragma once

#include "normal_distribution.h"
#include <string>
#include <iostream>
#include <fstream>

namespace batools::examples {
    void run_example_draw_normal_distribution(double min, double max, double steps, double mean, double std, const std::string& output);
    void run_example_draw_standard_normal_distribution(double min, double max, double steps, const std::string& output);
}