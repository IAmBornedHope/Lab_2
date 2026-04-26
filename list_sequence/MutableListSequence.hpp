#pragma once
#include "ListSequence.hpp"

template<class T>
class MutableListSequence : public ListSequence<T> {
public:
    using ListSequence<T>::ListSequence;

    ListSequence<T>* instance() override {
        return this;
    }
    ListSequence<T>* clone() const override {
        return new MutableListSequence<T>(*this);
    }
    ListSequence<T>* construct_empty() const override {
        return new MutableListSequence<T>();
    }
    
    T& operator[](size_t index) {
        return this->items_->get_reference(index);
    }
};
