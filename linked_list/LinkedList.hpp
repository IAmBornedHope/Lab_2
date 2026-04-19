#pragma once
#include <cstddef>
#include <stdexcept>
#include <initializer_list>

template <typename T> class ListIterator;

template<class T>
class LinkedList {
    friend class ListIterator<T>;
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}

    };
    size_t length_;
    Node* head_;
    Node* tail_;

public:
    
    LinkedList();
    LinkedList(T* items, size_t count);
    LinkedList(const LinkedList <T>& list);
    LinkedList(const std::initializer_list<T>& linked_list);
    ~LinkedList();

    size_t get_length() const;
    T get_first() const;
    T get_last() const;
    Node* get_node(size_t index) const;
    Node* get_head() const;
    T& get_reference(size_t index) const;
    T get(size_t index) const;

    void append(T item);
    void prepend(T item);
    void insert_at(T item, size_t index);
    
    LinkedList<T>* get_sublist(size_t start_index, size_t end_index) const;
    LinkedList<T>* concat(LinkedList<T>* list);

    ListIterator<T> begin();
    ListIterator<T> end();
    ListIterator<T> begin() const;
    ListIterator<T> end() const;

};
#include "ListIterator.hpp"
#include "LinkedList.tpp"