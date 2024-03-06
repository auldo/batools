#include "batools.h"
#include <iostream>

int main() {
    std::cout << "Running batools playground on version " << batools::get_version() << "." << std::endl;
    auto dataset{batools::numerical_dataset<int>{1, 2, 3}};
    std::cout << dataset[4] << std::endl;
}