#pragma once
#include "../include/Node.h"

template <typename T>
Node<T>::Node(const T& d) {
    data = d;
    next = nullptr;
}