#include "example_binomial_distribution.h"

namespace batools::examples {
    void run_example_draw_binomial_distribution(const int& n, const double& p, const std::string& output) {
        std::ofstream out{};
        out.open(output, std::ios_base::trunc);
        if(out.is_open()) {
            for(auto i{0}; i <= n; ++i) {
                auto value{::batools::distributions::binomial::probability_mass_function(i, n, p)};
                out << i << "\t" << value << std::endl;
            }
            out.close();
            std::string command{"gnuplot -p -e \"plot '" + output + "' with linespoints linestyle 1\""};
            system(command.c_str());
        }
    }

    void run_example_draw_binomial_distribution_cumulative(const int& n, const double& p, const std::string& output) {
        std::ofstream out{};
        out.open(output, std::ios_base::trunc);
        if(out.is_open()) {
            for(auto i{0}; i <= n; ++i) {
                auto value{::batools::distributions::binomial::cumulative_distribution_function(i, n, p)};
                out << i << "\t" << value << std::endl;
            }
            out.close();
            std::string command{"gnuplot -p -e \"plot '" + output + "' with linespoints linestyle 1\""};
            system(command.c_str());
        }
    }
}