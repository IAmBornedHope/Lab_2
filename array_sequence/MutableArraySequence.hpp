#pragma once
#include "ArraySequence.hpp"

template<class T>
class MutableArraySequence : public ArraySequence<T> {
public:
    using ArraySequence<T>::ArraySequence;

    ArraySequence<T>* instance() override {
        return this;
    }
    ArraySequence<T>* clone() const override {
        return new MutableArraySequence<T>(*this);
    }
    ArraySequence<T>* construct_empty() const override {
        return new MutableArraySequence<T>();
    }
    
    T& operator[](size_t index) {
        return this->items_->get_reference(index);
    }
};
