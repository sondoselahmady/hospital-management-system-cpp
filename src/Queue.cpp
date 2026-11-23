#pragma once
#include "../include/Queue.h"

template <typename T>
Queue<T>::Queue() {
    frontPtr = nullptr;
    rearPtr = nullptr;
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    if (rearPtr == nullptr) {
        frontPtr = rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if (frontPtr != nullptr) {
        Node<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) rearPtr = nullptr;
        delete temp;
    }
}

template <typename T>
T Queue<T>::front() const {
    if (frontPtr != nullptr) return frontPtr->data;
    throw std::runtime_error("Queue is empty!");
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return frontPtr == nullptr;
}

template <typename T>
void Queue<T>::print() const {
    Node<T>* curr = frontPtr;
    while (curr) {
        curr->data.printPatient();  // Assumes T has printPatient()
        curr = curr->next;
    }
}