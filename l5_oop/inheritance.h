#pragma once

#include <string>
#include <utility>
#include <iostream>

/*
 struct and class differences in inheritance:
 struct SomeStruct : Parent {};
 it makes "Parent" public;

 class SomeClass : Parent {};
 it makes "Parent" private;
 */

class Vehicle {
public:
    std::string name;
    int color;

    // "std::move" makes parameter name rvalue and prepairs it to correct coping
    Vehicle(std::string name, int color) : name(std::move(name)), color(color) {}

    Vehicle(const Vehicle &other) = default; // default copying constructor

    // destructor is not necessary, if we don't need specially delete something

    void go() {
        std::printf("Whrum, whrum, uuuuuuuuuuuuuuuu...\n");
    }

    void getInfo() {
        std::cout << "Name: " << name << "\nColor: " << color << std::endl;
    }

protected:
    void protected_method() {
        std::cout << "Vehicle::protected_method!" << std::endl;
    }

private:
    void private_method() {
        std::cout << "Vehicle::private_method!" << std::endl;
    }

};

// inheritance, "public" makes public all public fields of Vehicle
class Car : public Vehicle {
public:
    int max_speed;

    Car(std::string name, int color, int max_speed) : Vehicle(std::move(name), color), max_speed(max_speed) {}
    // we should call parent class constructor
    // also we can do it in implementation part (in {})

    Car(int max_speed, const Vehicle &vehicle): max_speed(max_speed), Vehicle(vehicle) {}

    void call_protected_method() {
        // only inside the class I can call protected_method(), because it's protected
        this->protected_method();
    }

    void call_private_method() {
//        this->private_method(); // doesn't work!
        std::cout << "I can't call it :( Car::call_private_method!" << std::endl;
    }
};

void show_inheritance() {
    Car car_instance("Name", 1, 200);
    car_instance.go();
    car_instance.getInfo();
    auto c_name = car_instance.name;
    auto c_color = car_instance.color;
    auto c_speed = car_instance.max_speed;
//    car_instance.ppp(); // it is protected
    // but I can use:
    car_instance.call_protected_method();
    // trying to call Vehicle private method
    car_instance.call_private_method();
}