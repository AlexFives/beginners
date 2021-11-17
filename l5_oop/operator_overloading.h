#pragma once

#include <iostream>

using namespace std;

class Int {
    int i = 0;
public:
    Int() = default;

    Int(Int &other) = default;

    Int(int var) : i(var) {}

    // arithmetic operators
    Int operator+(Int &other) { return {i + other.i}; } // a + b

    Int operator-(Int &other) { return {i - other.i}; } // a - b

    Int operator*(Int &other) { return {i * other.i}; } // a * b

    Int operator/(Int &other) { return {i / other.i}; } // a / b

    // prefix inc
    Int &operator++() {
        this->i++;
        return *this;
    } // ++a

    // postfix inc
    Int operator++(int) {
        Int old(*this);
        this->i++;
        return old;
    } // a++

    // prefix dec
    Int &operator--() {
        this->i--;
        return *this;
    } // --a

    // postfix dec
    Int operator--(int) {
        Int old(*this);
        this->i--;
        return old;
    } // a--

    // module division
    Int operator%(Int &other) { return {i % other.i}; } // a % b

    // unary +
    Int &operator+() { return *this; } // +a

    // unary -
    Int &operator-() {
        this->i = -i;
        return *this;
    } // -a

    // assignments
    Int &operator=(Int &other) = default; // default copying
    // a = b

    Int &operator+=(Int &other) {
        i += other.i;
        return *this;
    } // a += b

    Int &operator-=(Int &other) {
        i -= other.i;
        return *this;
    } // a -= b

    Int &operator*=(Int &other) {
        i *= other.i;
        return *this;
    } // a *= b

    Int &operator/=(Int &other) {
        i /= other.i;
        return *this;
    } // a /= b

    Int &operator%=(Int &other) {
        i %= other.i;
        return *this;
    } // a %= b

    Int &operator&=(Int &other) {
        i &= other.i;
        return *this;
    } // a &= b

    Int &operator|=(Int &other) {
        i |= other.i;
        return *this;
    } // a |= b

    Int &operator^=(Int &other) {
        i ^= other.i;
        return *this;
    } // a ^= b

    Int &operator<<=(Int &other) {
        i <<= other.i;
        return *this;
    } // a <<= b

    Int &operator>>=(Int &other) {
        i >>= other.i;
        return *this;
    } // a >>= b

    // comparison
    bool operator==(Int &other) { return i == other.i; } // a == b

    bool operator!=(Int &other) { return i != other.i; } // a != b

    bool operator<(Int &other) { return i < other.i; } // a < b

    bool operator>(Int &other) { return i > other.i; } // a > b

    bool operator<=(Int &other) { return i <= other.i; } // a <= b

    bool operator>=(Int &other) { return i >= other.i; } // a >= b

    // logic
    bool operator!() { return i == 0; } // !a (not a)

    template<typename T>
    bool operator&&(T other) { return i != 0 and (bool) other; } // a && b (a and b)

    template<typename T>
    bool operator||(T other) { return i != 0 or (bool) other; } // a || b (a or b)

    // bitwise
    Int operator~() { return ~i; } // ~a

    Int operator&(Int &other) { return i & other.i; } // a & b (a bitand b)

    Int operator|(Int &other) { return i | other.i; } // a | b (a bitor b)

    Int operator^(Int &other) { return i ^ other.i; } // a ^ b (a xor b)

    Int operator<<(Int &other) { return i << other.i; } // a << b

    Int operator>>(Int &other) { return i >> other.i; } // a >> b

    // type casting
    operator int() { return int(i); } // (int) a, int(a), static_cast<int>(a)...

    template<typename T>
    operator T() { return T(i); } // T - any type, which supports casting from int

    // cin and cout
    friend ostream &operator<<(ostream &out, const Int &integer) {
        out << integer.i;
        return out;
    }

    friend istream &operator>>(istream &input, Int &integer) {
        input >> integer.i;
        return input;
    }
};

void show_Int_overloading() {
    Int i = 10.2;
    double d_i = i;
    cin >> i;
    cout << i << endl;
    i++;
    i--;
}