#pragma once
#include <iostream>
#include <format>
#include <cmath>
#include <concepts>
#include "../exceptions/Exceptions.hpp"

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<Arithmetic T>
class Complex {
private:
    T re_;
    T im_;

public:
    Complex() : re_{}, im_{} {}

    Complex(T re) : re_{re}, im_{} {};
    Complex(T re, T im) : re_{re}, im_{im} {}

    T get_re() const { return re_; }
    T get_im() const { return im_; }

    void set_re(T re) { re_ = re; }
    void set_im(T im) { im_ = im; }

    Complex operator-() const {
        return Complex(-re_, -im_);
    }

    Complex operator+(const Complex& other) const {
        return Complex(re_ + other.re_, im_ + other.im_);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re_ - other.re_, im_ - other.im_);
    }

    Complex operator*(const Complex& other) const {
        T re = (re_ * other.re_) - (im_ * other.im_);
        T im = (re_ * other.im_) + (im_ * other.re_);
        return Complex(re, im);
    }

    Complex operator/(const Complex& other) const {
        T denominator = (other.re_ * other.re_) + (other.im_ * other.im_);
        if (denominator == 0) {
            throw DivisionByZeroException("Complex. Деление на ноль.");
        }
        T re = ((re_ * other.re_) + (im_ * other.im_)) / denominator;
        T im = ((im_ * other.re_) - (re_ * other.im_)) / denominator;
        
        return Complex(re, im);
    }

    bool operator==(const Complex& other) const {
        if constexpr(std::is_integral_v<T>) {
            return (re_ == other.re_) && (im_ == other.im_);
        }
        T epsilon = 1000 * std::max({std::abs(re_), std::abs(im_), std::abs(other.re_), std::abs(other.im_)}) * std::numeric_limits<T>::epsilon();

        return (std::abs((re_ - other.re_)) < epsilon) && (std::abs((im_ - other.im_)) < epsilon);
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    double absolute_squared() const {
        return static_cast<double>(re_) * re_ + static_cast<double>(im_) * im_;
    }

    double absolute() const {
        return std::sqrt(absolute_squared());
    }


    std::string complex_to_string() const {

        double new_re = static_cast<double>(re_);
        double new_im = static_cast<double>(im_);
        std::string zero = "0";
        std::string re_string = "";
        std::string im_string = "";

        if (new_re != 0.0) {
            re_string = std::format("{:.2f}", new_re);
            zero = "";
        }

        if (new_im != 0.0) {
            im_string = std::format("{:+.2f}i", new_im);
            zero = "";
        }

        return std::format("{}{}{}", zero, re_string, im_string);

    }
};

template<Arithmetic T>
std::ostream& operator<<(std::ostream& stream, const Complex<T>& complex) {
    stream << complex.complex_to_string();
    return stream;
}

template <Arithmetic T>
double abs(const Complex<T>& complex) {
    return complex.absolute();
}