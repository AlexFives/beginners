#pragma once

#include <iostream>

class Animal {
public:
    void walk() {}
};

class Bird {
public:
    void fly() {}
};

class Fish {
public:
    void swim() {}
};

// multiple inheritance:
class Duck : public Bird, public Animal, public Fish {
public:
    Duck() = default;
};

void show_multiple_inheritance() {
    Duck duck;
    duck.fly();
    duck.swim();
    duck.walk();
}


struct Base {
    int base_value = 1;

    Base() = default;

    Base(int value) : base_value(value) {}
};

struct BaseChild1 : Base {
    BaseChild1(int value) : Base(value) {}
};

struct BaseChild2 : Base {
    BaseChild2(int value) : Base(value) {}
};

struct FinalClass : BaseChild1, BaseChild2 {
    FinalClass(int value1, int value2) : BaseChild1(value1), BaseChild2(value2) {}
};


struct BaseF {
    int base_value = 0;

    BaseF() = default;

    BaseF(int value) : base_value(value) {}
};

struct BaseChild1F : virtual BaseF {
    BaseChild1F() = default;

    BaseChild1F(int value) : BaseF(value) {}
};

struct BaseChild2F : virtual BaseF {
    BaseChild2F() = default;

    BaseChild2F(int value) : BaseF(value) {}
};

struct FinalClassF : BaseChild1F, BaseChild2F {

    FinalClassF() = default;

    FinalClassF(int value) : BaseChild1F(value), BaseChild2F(value) {}

    FinalClassF(int value1, int value2) : BaseChild1F(value1), BaseChild2F(value2) {}
};

void show_diamond_problem() {
    FinalClass diamond{5, 10};
//    diamond.base_value; // error, because compiler doesn't know which parent class value we want to get

    // how to solve it?
    // give working zone:
    std::cout << diamond.BaseChild1::base_value << std::endl;
    std::cout << diamond.BaseChild2::base_value << std::endl;
    // use "virtual":
    FinalClassF diamond_f;
    diamond_f.base_value = 15;
    std::cout << diamond_f.base_value << std::endl;
}