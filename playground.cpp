#include "batools.h"
#include <iostream>

int main() {
    std::cout << "Running batools playground on version " << batools::get_version() << "." << std::endl;
    const auto tmp_file{"/Users/dominikaulinger/Projects/batools/tmp/test.data"};
    batools::examples::run_example_mean_convergence(1000, 1, 100, 2, 200, tmp_file);
    //batools::examples::run_example_draw_normal_distribution(0, 10, 0.1, 5, 0.000000000001, tmp_file);
    //batools::examples::run_example_draw_standard_normal_distribution(-10, 10, 0.01, tmp_file);
}