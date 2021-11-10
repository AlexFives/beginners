#pragma once

#include <iostream>
#include <cmath>

class Polygon {
public:
    virtual double area() = 0;

    virtual double perimeter() = 0;
};

class Triangle : virtual Polygon {
public:
    double a, b, c;

    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() override {
        double p = this->perimeter() / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double perimeter() override {
        return a + b + c;
    }
};

class Parallelogram : virtual Polygon {
    double a, b, alpha;

    Parallelogram(double a, double b, double alpha) : a(a), b(b), alpha(alpha) {}

    double area() override {
        return a * b * std::sin(alpha);
    }

    double perimeter() override {
        return a + a + b + b;
    }
};

class Circle : virtual Polygon {
    double r;

    Circle(double r) : r(r) {}

    double area() override {
        return PI * r * r;
    }

    double perimeter() override {
        return PI * (r + r);
    }
};