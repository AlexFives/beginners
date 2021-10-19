#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> VEC; // <int> - template

// list vs vector:
// list: insertion - O(1)
// vector: push_back/pop_back -  amortized O(1), insert - O(n)
// list: [] - O(n)
// vector: [] - O(1)

// stack, queue, deque


void vectorMETHODS(VEC &);
void vectorOPERATORS(VEC &);
void vectorDemo();

#include "containers.cpp"