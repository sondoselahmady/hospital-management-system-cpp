#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& d);
};

#include "Node.cpp"  // Required for template class definitions