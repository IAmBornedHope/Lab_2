#pragma once
#include <cstddef>

template<class T>
class Option {
private:
    union  {
        std::byte data_[sizeof(T)];
        T value_;
    } storage_;

    bool has_value_;

public:
    Option() : has_value_{false} {}

    Option(const T& value) : has_value_(true) {
        new (storage_.data_) T(value);
    }

    ~Option() {
        if (has_value_) {
            storage_.value_.~T();
        }
    }

    bool has_value() const {
        return has_value_;
    }

    T& get_value() {
        if (!has_value_) {
            throw EmptyOptionException("Option пустое");
        }
        return storage_.value_;
    }

    const T& get_value() const {
        if (!has_value_) {
            throw EmptyOptionException("Option пустое");
        }
        return storage_.value_;
    }
};