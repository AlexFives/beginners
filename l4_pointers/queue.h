#pragma once

#include <iostream>

using namespace std;

namespace Queue {
    struct Node {
        void *value = nullptr;
        Node *next = nullptr;
    };

    template<typename T>
    void print(Node*&);

    template<typename T>
    void add(T, Node*&);

    template<typename T>
    void pop(Node*&);

    int size(Node*&);
}

#include "queue.tpp"