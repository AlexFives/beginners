#pragma once

#include <iostream>
#include <cmath>

using namespace std;

void solve_quadratic_equation(double a, double b, double c) {
    if (a == 0 and b == 0 and c == 0) {
        printf("x belongs to (-infinity, +infinity)\n");
        return;
    }
    if (a == 0 and b == 0) {
        printf("This equation has no solution\n");
        return;
    }
    if (a == 0) {
        printf("Linear equation: x = ");
        cout << -c / b << endl;
        return;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = ");
        cout << x1 << endl;
        printf("x2 = ");
        cout << x2 << endl;
        return;
    }
    if (d == 0) {
        double x = -b / (2 * a);
        printf("Two matching solutions: x1 = x2 = ");
        cout << x << endl;
        return;
    }
    printf("D < 0: this equation has complex solution. Not supported.");
}

//int main() {
//    double a, b, c;
//    cin >> a >> b >> c;
//    solve_quadratic_equation(a, b, c);
//    return 0;
//}