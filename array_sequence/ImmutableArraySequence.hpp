#pragma once
#include "ArraySequence.hpp"

template<class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    using ArraySequence<T>::ArraySequence;

    ArraySequence<T>* instance() override {
        return this->clone();
    }
    ArraySequence<T>* clone() const override {
        return new ImmutableArraySequence<T>(*this);
    }
    ArraySequence<T>* construct_empty() const override {
        return new ImmutableArraySequence<T>();
    }
    
    T operator[](size_t index) const {
        return this->items_->get(index);
    }
};
