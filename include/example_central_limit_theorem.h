#pragma once

#include "numerical_dataset.h"
#include "normal_distribution.h"
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

namespace batools::examples {
    void run_example_central_limit_theorem(const std::string& output, const int& sample_count, const int& sample_size, bool standardized = false);
}