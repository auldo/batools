#include "example_central_limit_theorem.h"

namespace batools::examples {
    void run_example_central_limit_theorem(const std::string& output, const int& sample_count, const int& sample_size, bool standardized) {
        std::ofstream out{};
        out.open(output, std::ios_base::trunc);
        if(out.is_open()) {
            auto dataset{batools::random_numerical_dataset(100, 0, 10)};
            auto pop_mean{dataset.mean()};
            auto pop_std{dataset.standard_deviation()};
            dataset.printMean();
            std::vector<double> means;
            for(auto i{0}; i < sample_count; ++i) {
                auto sample{dataset.draw_sample(sample_size)};
                means.push_back(static_cast<float>(static_cast<int>(sample.mean() * 10.)) / 10.);
            }
            std::unordered_map<double, int> counts;
            for(auto& mean : means) {
                if(standardized) {
                    mean = ::batools::distributions::standard_normal::standardize(mean, pop_mean, pop_std);
                }
                if(counts.contains(mean)) {
                    counts.at(mean) += 1;
                } else {
                    counts.insert(std::make_pair(mean, 1));
                }
            }
            counts.insert({0, 1});
            for(const auto& [mean, count] : counts)
                out << mean << "\t" << count << std::endl;
            out.close();

            std::string command{"gnuplot -p -e \"plot '" + output + "'\""};
            system(command.c_str());
        }
    }
}