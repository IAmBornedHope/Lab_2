#pragma once
#include "ListSequence.hpp"

template<class T>
class ImmutableListSequence : public ListSequence<T> {
public:
    using ListSequence<T>::ListSequence;

    ListSequence<T>* instance() override {
        return this->clone();
    }
    ListSequence<T>* clone() const override {
        return new ImmutableListSequence<T>(*this);
    }
    ListSequence<T>* construct_empty() const override {
        return new ImmutableListSequence<T>();
    }
    
    T operator[](size_t index) const {
        return this->items_->get(index);
    }
};
