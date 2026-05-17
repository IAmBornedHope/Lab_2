#pragma once
#include <format>
#include <string>
#include <exception>

class Exception: public std::exception {
private:
    std::string message_;

public:
    explicit Exception(const std::string& message) : message_(message) {}
    ~Exception() noexcept override = default;
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

class IndexOutOfRangeException: public Exception {
public:

    IndexOutOfRangeException(size_t index_1, size_t index_2, size_t size) 
    : Exception(std::format("Индексы за границами: {}-{} (Размер - {})", index_1, index_2, size)) {}

    explicit IndexOutOfRangeException(size_t index, size_t size) 
        : Exception(std::format("Индекс за границами: {} (Размер - {})", index, size)) {}

    explicit IndexOutOfRangeException(size_t index) 
        : Exception(std::format("Индекс за границами: {})", index)) {}

    explicit IndexOutOfRangeException(const std::string& message) 
        : Exception(message) {}
};

class InvalidArgumentException: public Exception {
public:
    InvalidArgumentException(const std::string& name, const std::string& reason)
        : Exception(std::format("Некорректный аргумент: {}. Причина: {}", name, reason)) {}
    
    explicit InvalidArgumentException(const std::string& message)
        : Exception(message) {}
};

class NullPointerException: public Exception {
public:
    NullPointerException(const std::string& name = "pointer")
        : Exception(std::format("Передан нулевой указатель: {}", name)) {}
};

class EmptyListException: public Exception {
public:
    EmptyListException(const std::string& function = "function")
    : Exception(std::format("Нельзя выполнить {} для пустого контейнера", function)) {}
};

class IteratorPointerException: public Exception {
public:
    IteratorPointerException(const std::string& message) : Exception(message) {}
};

class BitIndexException: public Exception {
public:
    BitIndexException(const char* message) : Exception(message) {}
};

class SequenceLengthMismatchException: public Exception {
public:
    SequenceLengthMismatchException(const std::string& name = "function", size_t length_1 = 0, size_t length_2 = 0)
        : Exception(std::format("Длины не совпадают в функции {}! Длина 1: {}, Длина 2: {}", name, length_1, length_2)) {}
};

class DivisionByZeroException: public Exception {
public:
    DivisionByZeroException(const std::string& function = "")
        : Exception(std::format("Деление на ноль в функции {}", function)) {}
};

class MatrixSizeMismatchException: public Exception {
public:
    MatrixSizeMismatchException(const std::string& name = "function", size_t size_1 = 0, size_t size_2 = 0)
        : Exception(std::format("Матрицы разного размера в функции {}! Первая: {}х{}. Вторая: {}х{}", name, size_1, size_1, size_2, size_2)) {}
};