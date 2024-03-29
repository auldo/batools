#pragma once

#include "numerical_dataset.h"
#include <vector>
#include <string>
#include <fstream>
#include <utility>

namespace batools::examples {
    void run_example_mean_convergence(int population_size, int val_min, int val_max, int sample_size, int sample_count, const std::string& output);
}