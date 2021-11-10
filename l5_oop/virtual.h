#pragma once

#include <iostream>

// virtual method says to compiler to call the latest method in
class A {
public:
    virtual void virtual_method() {
        std::printf("virtual method of A\n");
    }

    void common_method() {
        std::printf("common method of A\n");
    }
};

class B : public A {
public:
    virtual void virtual_method() {
        std::printf("virtual method of B\n");
    }

    void common_method() {
        std::printf("common method of B\n");
    }
};

class C : public B {
public:
    virtual void virtual_method() {
        std::printf("virtual method of C\n");
    }

    void common_method() {
        std::printf("common method of C\n");
    }
};

void show_virtual() {
    C c_object;
    A &a_ref = c_object;

    c_object.virtual_method(); // C
    c_object.common_method(); // C

    a_ref.virtual_method(); // C
    a_ref.common_method(); // A
}

class SomeInterface {
protected:
    int attr;

public:

    SomeInterface(int attr) : attr(attr) {}

    virtual void some_method() = 0; // "= 0" means, that this method must be overrided in the child class

    int getAttr() { return this->attr; }
};

class SomeInterfaceChild : virtual public SomeInterface {
public:
    SomeInterfaceChild(int value) : SomeInterface(value) {}

    // it's good to use "override" after func, if this method is overrided
    void some_method() override {
        // we must override SomeInterface::some_method(), because it's "= 0"
        std::printf("Overrided some method!\n");
    }
};

void show_interface_usage() {
    SomeInterfaceChild child{10}; // {} - uniform initialization
    child.some_method();
    int attr = child.getAttr(); // 10
}