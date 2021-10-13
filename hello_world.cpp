#include <iostream>

using namespace std;

void print(int num) {
    if (num == 1) return;
    cout << num << endl;
}

int fact(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

int main() {
//    cout << "Hello, world!" << endl;
//    cout << "Hello" << ',' << ' ' << "world" << '!' << endl;
//    printf("Hello, world!");
    print(1);
    return 0;
}