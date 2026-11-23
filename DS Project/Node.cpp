#pragma once
#include "Node.h"

template <typename T>
Node<T>::Node(const T& d) {
    data = d;
    next = nullptr;
}