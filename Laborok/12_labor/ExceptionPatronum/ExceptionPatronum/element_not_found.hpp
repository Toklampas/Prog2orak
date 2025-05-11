#pragma once
#include <stdexcept>

template <typename T>
class element_not_found : public std::logic_error {
    T element;
public:
    explicit element_not_found(const T& elem) : std::logic_error("element not found"), element(elem) {}

    const T& get_element() const { return element; }

    const char* what() const noexcept override { return std::logic_error::what(); }
};