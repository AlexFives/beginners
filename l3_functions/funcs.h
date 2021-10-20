#pragma once

#include <iostream>
#include <string>

using namespace std;

// [returns type] [func_name]([type] [arg_name], ...) {
//  code...
// }

void printHelloWorld(); // function declaration

// function realisation
void printHelloWorld() {
    cout << "Hello, world!" << endl;
}

/*
 local and global variables:
    file.cpp:
        double PI = 3.14; // global variable

        double square(double r) {
            // r - local variable
            return PI * r * r;
        }
        cout << r; // error!
        double r = 1.0; // this var and r in square - different variables!
 */



// declaration examples:
//  void printName1(string);
//  void printName1(string name);

//  void printName2(string&);
//  void printName2(string &name);

//  void printName3(const string&);
//  void printName3(const string &name);

//  void printName4(const string&&);
//  void printName4(const string &&name);

void printName1(string name) {
    // name was copied!
    name += '!'; // global name wasn't changed!
    cout << "Hello, " << name << endl;
}

void printName2(string &name) {
    // name wasn't copied
    name += '!'; // global name was changed!
    cout << "Hello, " << name << endl;
}

void printName3(const string &name) {
    // name wasn't copied, can't edit name
    cout << "Hello, " << name << endl;
}

// useless!
//void printName(const string name) {
//    cout << "Hello, " << name << endl;
//}

void printName4(string &&name) {
    // name isn't variable

    // used like printName4("Name");
    // string name = "Name"; printName5(name); error!
    name += '!';
    cout << "Hello, " << name << endl;
}

void printName5(const string &&name) {
    // name isn't variable
    // can't edit name

    // used like printName4("Name"); or printName4(pointer_to_string);
    // string name = "Name"; printName5(name); error!
    cout << "Hello, " << name << endl;
}


// func with multiple parameters example
// int int_sum(const int &, const int &);
int int_sum(const int &a, const int &b) {
    return a + b;
}

// default values for parameters
//void printRange(const int&, const int&, const int&);
void printRange(const int &begin, const int &end, const int &step = 1) {
    if (begin >= end) return;
    for (int i = begin; i < end; i += step) cout << i << ' ';
    cout << endl;
}
//void printRange(int begin = 0, const int &end, const int &step = 1) {...} - error!

// magic words:
// return and recursion
void input() {
    int temp;
    cin >> temp;
    if (temp == 0) {
        cout << "Write another value!\n";
        return;
    }
    int password;
    password = 10 * temp / 5 * 3 * temp;
    cout << "Password: " << password << endl;
}
// same as this function:
/*
void input() {
    int temp;
    cin >> temp;
    if (temp == 0) {
        cout << "Write another value!\n";
        return;
    }
    else {
        int password;
        password = 10 * temp / 5 * 3 * temp;
        cout << "Password: " << password << endl;
    }
}
*/

// recursions
uint64_t factorial(int n) {
    if (n < 2) return 1; // base part
    return factorial(n - 1); // recursion part
}

void someRecursiveFunc(const int &&i = 0) {
    if (i > 5) {
        cout << endl;
        return;
    }
    cout << i << ' ';
    someRecursiveFunc(i + 1);
}


// inline int inlineIntSum(const int&, const int &b);
// inline word says to the compiler to paste this func in code! (speed, optimization)
inline int inlineIntSum(const int &a, const int &b) {
    return a + b;
}


// extern
// global variables and functions are declared in globals.h
// extern allows to use extern-objects from globals.h in the whole project
extern double EXTERN_VAR = 13.0;
extern const double PI;

extern inline float ExternInlineFloatSum(const float &a, const float &b) {
    return a + b;
}


// templates
template<typename T>
auto sum(const T &, const T &);

template<typename T>
auto sum(const T &a, const T &b) {
    return a + b;
}

template<typename T>
T sumT(const T &a, const T &b) {
    return a + b;
}

template<typename T, typename A, typename B>
T sumNotAuto(const A &a, const B &b) {
    return a + b;
}

int some_var = 0;

int &ampersand_func() {
    return some_var;
}

int *star_func() {
    return &some_var;
}