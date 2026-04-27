#pragma once
#include <cstddef>
#include <stdexcept>
#include "../sequence/Sequence.hpp"
#include "../dynamic_array/DynamicArray.hpp"
#include "../sequence/IEnumerator.hpp"

template<class T>
class ArraySequence: public Sequence<T> {
protected:
    DynamicArray<T>* items_;
    ArraySequence<T>* append_internal(T temp);
    ArraySequence<T>* prepend_internal(T temp);
    ArraySequence<T>* insert_at_internal(T temp, size_t index);
public:
    ArraySequence();
    ArraySequence(T* array, size_t count);
    ArraySequence(const ArraySequence<T>& source_sequence);

    virtual ~ArraySequence();

    virtual ArraySequence<T>* clone() const = 0;
    virtual ArraySequence<T>* instance() = 0;
    virtual ArraySequence<T>* construct_empty() const = 0;

    T get_first() const override;
    T get_last() const override;
    T get(size_t index) const override;
    size_t get_length() const override;
    void clear() override;

    Sequence<T>* append(T temp) override;
    Sequence<T>* prepend(T temp) override;
    Sequence<T>* insert_at(T temp, size_t index) override;

    Sequence<T>* concat(Sequence<T>* sequence) const override;
    Sequence<T>* get_subsequence(size_t start_index, size_t end_index) const override;

    ArrayIterator<T> begin();
    ArrayIterator<T> end();
    IEnumerator<T>* get_enumerator() const override;
    
    Sequence<T>* map(T (*func)(T)) override;
    Sequence<T>* where(bool (*predicate)(T)) override;
    T reduce(T (*func)(T, T), T accumulator) override;
};

#include "ArraySequence.tpp"