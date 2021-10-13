#include "containers.h"

void vectorDemo() {
    VEC vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vectorOPERATORS(vec);
    vectorMETHODS(vec);
}

void vectorOPERATORS(VEC &vec) {
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
    cout << endl;
    for (auto item : vec) cout << item << ' ';
    cout << endl;
    for (auto iter = vec.begin(); iter < vec.end(); iter++) cout << *iter << ' ';
    cout << endl;
}

void vectorMETHODS(VEC &vec) {
    VEC _vec = vec;
    int len = _vec.size();
    sort(_vec.begin(), _vec.end());
    auto iter_begin = _vec.begin(); // pointer to _vec[0];
    auto iter_end = _vec.end(); // pointer to node after the last node
    auto riter_begin = _vec.rbegin(); // pointer to last element in vector, reversed order
    auto riter_end = _vec.rend(); // pointer to node before the first node, reversed order
    reverse(_vec.begin() + 3, _vec.end());
    bool is_empty = _vec.empty();
    int capacity = _vec.capacity();
    // ------------
    vec.push_back(10);
    vec.pop_back();
    vec.insert(vec.begin(), -1);
    vec.erase(vec.begin(), vec.begin() + 1);
    // element access
    auto elem_at = vec.at(0);
    auto elem_first = vec.front();
    auto elem_last = vec.back();
    auto iter = vec.emplace(vec.begin(), 100);
    // inserts 100 at position vec.begin() and returns iter with this position
    vec.emplace(iter, 200); // only inserts 200 at position iter
    vec.emplace_back(1000); // push_back
    // something about list!
}