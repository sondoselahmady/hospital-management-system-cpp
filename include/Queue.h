#pragma once
#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    Node<T>* frontPtr;
    Node<T>* rearPtr;

public:
    Queue();
    void enqueue(const T& item);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    void print() const;
};

#include "Queue.cpp"  // Include implementation for template class