#include "example_mean_convergence.h"

namespace batools::examples {
    void run_example_mean_convergence(int population_size, int val_min, int val_max, int sample_size, int sample_count, std::string_view output) {
        auto dataset{::batools::random_numerical_dataset(population_size, val_min, val_max)};
        dataset.printMean();

        std::vector<std::pair<int, float>> sampleCountToMeanMapping;
        batools::numerical_dataset<float> sampleMeans{};
        for(auto i{0}; i < sample_count; ++i) {
            auto sample{dataset.draw_sample(sample_size)};
            sampleMeans += sample.mean();
            auto mean{sampleMeans.printMean()};
            sampleCountToMeanMapping.push_back(std::move(std::make_pair(i, mean)));
        }

        std::ofstream stream{};
        stream.open(output, std::ios_base::trunc);
        if(stream.is_open()) {
            for(auto& [sampleCount, mean] : sampleCountToMeanMapping) {
                stream << sampleCount << "\t" << mean << "\n";
            }
            stream.close();
        }

        system("gnuplot -p -e \"plot '/Users/dominikaulinger/Projects/batools/tmp/test.data' with linespoints linestyle 1\"");
    }
}