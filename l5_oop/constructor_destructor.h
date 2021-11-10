#pragma once


class SomeClass {
    int a = 5, b, c;

public:
    // constructors:
    SomeClass(int b, int c): b(b), c(c) {}
    /*
     SomeClass(int b, int c) // - constructor
     : b(b), c(c) // - setting attributes
     {} // because it is function, we should write them, also we can write some algorithm here
     */

    // another constructor
    SomeClass(int a, int b, int c_value) {
        // constructor implementation, it's not necessary to set attributes with ":"
        // "this" - pointer to this class (pointer to itself)
        this->a = a; // because "a" is the parameter of constructor and "a" is attribute use this->a
        this->b = b;
        c = c_value; // it's not necessary to use "this"
    }

    // destructor
    ~SomeClass() = default; // "default" means, that we don't need to correctly delete something inside the class
    // also "default" can be used with the constructor, if all attributes have values:
    // SomeClass() = default;

    /*
     if we need to implement destructor:
     ~SomeClass() {
        ...
     }
     */

};