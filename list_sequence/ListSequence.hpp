#pragma once
#include <cstddef>
#include <stdexcept>
#include "../sequence/Sequence.hpp"
#include "../linked_list/LinkedList.hpp"
#include "../sequence/IEnumerator.hpp"

template<class T>
class ListSequence: public Sequence<T> {
protected:
    LinkedList<T>* items_;
    ListSequence<T>* append_internal(T temp);
    ListSequence<T>* prepend_internal(T temp);
    ListSequence<T>* insert_at_internal(T temp, size_t index);

public:
    ListSequence();
    ListSequence(T* items, size_t count);
    ListSequence(const ListSequence<T>& list);

    virtual ~ListSequence();

    virtual ListSequence<T>* clone() const = 0;
    virtual ListSequence<T>* instance() = 0;
    virtual ListSequence<T>* construct_empty() const = 0;

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

    ListIterator<T> begin();
    ListIterator<T> end();
    IEnumerator<T>* get_enumerator() const override;

    Sequence<T>* map(T (*func)(T)) override;
    Sequence<T>* where(bool (*predicate)(T)) override;
    T reduce(T (*func)(T, T), T accumulator) override;
};

#include "ListSequence.tpp"