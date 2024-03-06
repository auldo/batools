#include "example_normal_distribution.h"

namespace batools::examples {

void run_example_draw_normal_distribution(double min, double max, double steps, double mean, double std, const std::string& output) {
    std::ofstream out{};
    out.open(output, std::ios_base::trunc);
    if(!out.is_open())
        return;

    while(min < max) {
        auto value{::batools::distributions::normal::probability_density_function(min, mean, std)};
        out << min << "\t" << value << "\n";
        min += steps;
    }
    out.close();
    std::string command{"gnuplot -p -e \"plot '" + output + "' with linespoints linestyle 1\""};
    system(command.c_str());
}

void run_example_draw_standard_normal_distribution(double min, double max, double steps, const std::string& output) {
    std::ofstream out{};
    out.open(output, std::ios_base::trunc);
    if(!out.is_open())
        return;

    while(min < max) {
        auto value{::batools::distributions::standard_normal::probability_density_function(min)};
        out << min << "\t" << value << "\n";
        min += steps;
    }
    out.close();
    std::string command{"gnuplot -p -e \"plot '" + output + "' with linespoints linestyle 1\""};
    system(command.c_str());
}

}