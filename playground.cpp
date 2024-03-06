#include "batools.h"
#include <iostream>

void test_mean_estimation_convergence() {
    auto dataset{batools::random_numerical_dataset(2000, 1, 10000)};
    dataset.printMean();

    batools::numerical_dataset<float> sampleMeans{};
    for(auto i{0}; i < 1000; ++i) {
        auto sample{dataset.draw_sample(10)};
        sampleMeans += sample.mean();
        sampleMeans.printMean();
    }
}

int main() {
    std::cout << "Running batools playground on version " << batools::get_version() << "." << std::endl;
    test_mean_estimation_convergence();
}