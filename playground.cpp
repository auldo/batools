#include "batools.h"
#include <iostream>

int main() {
    std::cout << "Running batools playground on version " << batools::get_version() << "." << std::endl;
    batools::examples::run_example_mean_convergence(2000, 1, 100, 10, 20000, "/Users/dominikaulinger/Projects/batools/tmp/test.data");
}