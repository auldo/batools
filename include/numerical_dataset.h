#pragma once

#include <type_traits>
#include <memory>
#include <ranges>
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include "batools_exception.h"

namespace batools {
#define numerical_dataset_template template <typename T> requires std::is_arithmetic_v<T>

numerical_dataset_template
class numerical_dataset {
private:
    size_t _size{0};
    std::unique_ptr<T[]> _data{std::make_unique<T[]>(0)};
    std::vector<size_t> draw_random_indices(size_t size);
public:
    //Constructors
    numerical_dataset() noexcept;
    explicit numerical_dataset(size_t size) noexcept;
    numerical_dataset(std::initializer_list<T> data) noexcept;

    //Operator overloads
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    numerical_dataset& operator+=(T elem);

    //Other
    numerical_dataset draw_sample(size_t size);
    double sample_standard_deviation(double& mean, bool corrected = true) const;
    double standard_deviation(double& mean) const;
    double mean() const;

    //Printers
    void print() const;
    void printMean() const;
};

//Constructors
numerical_dataset_template
numerical_dataset<T>::numerical_dataset() noexcept = default;

numerical_dataset_template
numerical_dataset<T>::numerical_dataset(size_t size) noexcept : _size(size), _data{std::make_unique<T[]>(size)} {};

numerical_dataset_template
numerical_dataset<T>::numerical_dataset(std::initializer_list<T> data) noexcept : _size(data.size()), _data{std::make_unique<T[]>(data.size())} {
    for(auto i{0}; i < _size; ++i)
        _data.get()[i] = *(data.begin() + i);
};

//Operator overloads
numerical_dataset_template
T& numerical_dataset<T>::operator[](size_t idx) {
    if(idx < _size)
        return _data[idx];
    throw batools::exceptions::out_of_range();
}

numerical_dataset_template
const T& numerical_dataset<T>::operator[](size_t idx) const {
    if(idx < _size)
        return _data[idx];
    throw batools::exceptions::out_of_range();
}

numerical_dataset_template
numerical_dataset<T>& numerical_dataset<T>::operator+=(T elem) {
    auto released{_data.release()};
    _data = std::make_unique<T[]>(_size + 1);
    for(auto i{0}; i < _size; ++i)
        _data.get()[i] = released[i];
    _data[_size] = elem;
    _size += 1;
    return *this;
}

//Private
numerical_dataset_template
std::vector<size_t> numerical_dataset<T>::draw_random_indices(size_t size) {
    std::random_device seed;
    if(size > _size)
        throw exceptions::out_of_range();
    std::vector<size_t> indices(_size);
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), std::default_random_engine{seed()});
    std::vector<size_t> takenIndices(size);
    for(auto i{0}; i < size; ++i)
        takenIndices[i] = indices[i];
    return takenIndices;
}

//Other
numerical_dataset_template
numerical_dataset<T> numerical_dataset<T>::draw_sample(size_t size) {
    std::vector<size_t> indices{draw_random_indices(size)};
    numerical_dataset<T> dataset(size);
    for(auto i{0}; i < size; ++i)
        dataset[i] = operator[](indices[i]);
    return dataset;
}

numerical_dataset_template
double numerical_dataset<T>::mean() const {
    double sum{0};
    for(auto i{0}; i < _size; ++i) sum += static_cast<double>(operator[](i));
    return sum / _size;
}

numerical_dataset_template
double numerical_dataset<T>::sample_standard_deviation(double& mean, bool corrected) const {
    double sum{0};
    for(auto i{0}; i < _size; ++i) sum += (std::pow((static_cast<double>(operator[](i)) - mean), 2));
    return corrected ? sum / (_size - 1) : sum / _size;
}

numerical_dataset_template
double numerical_dataset<T>::standard_deviation(double &mean) const {
    return sample_standard_deviation(mean, false);
}

//Printers
numerical_dataset_template
void numerical_dataset<T>::print() const {
    for(auto i{0}; i < _size; ++i)
        std::cout << operator[](i) << " ";
    std::cout << std::endl;
}

numerical_dataset_template
void numerical_dataset<T>::printMean() const {
    std::cout << "Mean is: " << mean() << std::endl;
}

//Out of class
numerical_dataset<int> random_numerical_dataset(int size, int min, int max);

}//End of batools namespace