#include <type_traits>
#include <memory>
#include "batools_exception.h"

namespace batools {
#define numerical_dataset_template template <typename T>

numerical_dataset_template
class numerical_dataset {
private:
    size_t _size{0};
    std::unique_ptr<T[]> _data{std::make_unique<T[]>(0)};
public:
    //Constructors
    numerical_dataset() noexcept;
    explicit numerical_dataset(size_t size) noexcept;
    numerical_dataset(std::initializer_list<T> data) noexcept;

    //Operator overloads
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
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

//Operator overlods
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
}//End of batools namespace