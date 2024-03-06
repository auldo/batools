#include "example_mean_convergence.h"

namespace batools::examples {
    void run_example_mean_convergence(int population_size, int val_min, int val_max, int sample_size, int sample_count, const std::string& output) {
        auto dataset{::batools::random_numerical_dataset(population_size, val_min, val_max)};
        dataset.printMean();

        std::vector<std::pair<int, float>> sampleCountToMeanMapping;
        batools::numerical_dataset<float> sampleMeans{};
        for(auto i{0}; i < sample_count; ++i) {
            auto sample{dataset.draw_sample(sample_size)};
            auto sampleMean{sample.mean()};
            sampleMeans += sampleMean;
            sampleCountToMeanMapping.push_back(std::move(std::make_pair(i, sampleMeans.mean())));
        }

        std::ofstream stream{};
        stream.open(output, std::ios_base::trunc);
        if(stream.is_open()) {
            for(auto& [sampleCount, mean] : sampleCountToMeanMapping) {
                stream << sampleCount << "\t" << mean << "\n";
            }
            stream.close();
        }

        sampleMeans.printMean();
        std::string command{"gnuplot -p -e \"plot '" + output + "' with linespoints linestyle 1\""};
        system(command.c_str());
    }
}