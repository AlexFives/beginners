#pragma once

#include <iostream>

/*
 struct SomeStruct {};
 SomeStruct var; // - instance
 */

struct MyStruct {
    // these fields are public
    int a = 10;

    void b() {}

// access modifiers
public:
    /*
     1) available inside the class
     2) passed on inheritance
     3) can be obtained from the instance of this class
     */

    // public fields
    float public_attr = 10.0;

    void public_method() { std::printf("MyStruct::public_method!"); }

protected:
    /*
     1) available inside the class
     2) passed on inheritance
     */

    // protected fields
    int protected_attr = 1;

    void protected_method() { std::printf("MyStruct::protected_method!"); }

private:
    /*
     1) available inside the class
     */
    // private fields
    char private_attr = 'a';

    void private_method() { std::printf("MyStruct::private_method!"); }
};

class MyClass {
    // these fields are private
    int a = 10;

    void b() {}

    // access modifiers
public:
    /*
     1) available inside the class
     2) passed on inheritance
     3) can be obtained from the instance of this class
     */

    // public fields
    float public_attr = 10.0;

    void public_method() { std::printf("MyClass::public_method!"); }

protected:
    /*
     1) available inside the class
     2) passed on inheritance
     */

    // protected fields
    int protected_attr = 1;

    void protected_method() { std::printf("MyClass::protected_method!"); }

private:
    /*
     1) available inside the class
     */
    // private fields
    char private_attr = 'a';

    void private_method() { std::printf("MyClass::private_method!"); }
};

void show_intro() {
    MyClass my_class;
    auto class_public_attr = my_class.public_attr;
    my_class.public_method();

    MyStruct my_struct;
    auto struct_a = my_struct.a;
    my_struct.b();
    auto struct_public_attr = my_struct.public_attr;
    my_struct.public_method();
}