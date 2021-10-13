#include "utility.h"

void pairDemo() {
    pair<int, float> pair1;
    pair1.first = 10;
    pair1.second = 12.34;
    pair<float, int> pair2 = {43.21, 10};
    float p2_first = pair2.first;
    int p2_second = pair2.second;
    pair2.first = pair1.second;
}