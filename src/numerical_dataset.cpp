#include "numerical_dataset.h"

namespace batools {
    int random_int(int& min, int& max) {
        std::random_device seeder;
        std::mt19937 rng(seeder());
        std::uniform_int_distribution<int> gen(min, max); // uniform, unbiased
        return gen(rng);
    }

    numerical_dataset<int> random_numerical_dataset(int size, int min, int max) {
        numerical_dataset<int> dataset(size);
        for(auto i{0}; i < size; ++i)
            dataset[i] = random_int(min, max);
        return dataset;
    }
}