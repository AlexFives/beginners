#pragma once

#include <iostream>

using namespace std;

// nested structures
// 1st implementation
struct Node {
    int value;
    Node *next, *prev;

    Node() = default;

    Node(int var) : value(var) {}
};

class List {
    Node *root;
public:
    List() {
        this->root = new Node;
    }

    ~List() {
        delete this->root;
        this->root = nullptr;
    }
};

// 2nd implementation
class List2 {
public:
    struct Node2 {
        int value;
        Node *next, *prev;

        Node2() = default;

        Node2(int var) : value(var) {}
    };

    List2() {
        this->root = new Node;
    }

    ~List2() {
        delete this->root;
        this->root = nullptr;
    }

private:
    Node *root;
};

// static
int some_generator() {
    static int static_var = 0;
    return static_var++;
}

// static in oop
// 1) as static method
class ObjectWithStaticMethod {
    // code...
public:
    static void say_hello(const char *name) {
        printf("Hello, %s!\n", name);
    }
};

// 2) static attribute
class ObjectWithStaticAttribute {
    // code...
    static int base;
public:
    int id;

    ObjectWithStaticAttribute() {
        this->id = base++;
    };
};

int ObjectWithStaticAttribute::base = 1;

void show_static() {
    // static var
    int a = some_generator();
    int b = some_generator();
    int c = some_generator();
    printf("%d %d %d\n", a, b, c);
    // static method
    ObjectWithStaticMethod::say_hello("world");
    ObjectWithStaticMethod object;
    object.say_hello("object");
    // static attribute
    ObjectWithStaticAttribute inst1{};
    ObjectWithStaticAttribute inst2{};
    ObjectWithStaticAttribute inst3{};
    printf("%d %d %d\n", inst1.id, inst2.id, inst3.id);
    printf("\n");
}

// friend
// friendly functions
class FriendlyClass {
    int a, b, c;
public:
    FriendlyClass(int a, int b, int c) : a(a), b(b), c(c) {}

    friend int class_sum(FriendlyClass &obj);
};

int class_sum(FriendlyClass &obj) {
    return obj.a + obj.b + obj.c;
}

// friendly classes
class FriendP;

class P {
    int a, b;
public:
    P(int _a, int _b) : a(_a), b(_b) {}

    int getA() { return a; }

    int getB() { return b; }

    friend class FriendP;
};

class FriendP {
    int a;
public:
    FriendP(int _a) : a(_a) {}

    FriendP(int _a, P &p) : a(_a) {
        p.a = _a;
    }

    int sum_a(P &p) { return this->a + p.a; }

    void set_b(P &p) { p.b = p.a + a; }
};

// friendly methods

class BaseClass;

class Friend_BaseClass {
    int some_attr = 10;
public:
    Friend_BaseClass() = default;

    int sum_vars(BaseClass &obj);
};

class BaseClass {
    int hidden_var = 1000;
public:
    BaseClass(int var) : hidden_var(var) {}

    friend int Friend_BaseClass::sum_vars(BaseClass &obj);
};

int Friend_BaseClass::sum_vars(BaseClass &obj) {
    return this->some_attr + obj.hidden_var;
}

void show_friendly() {
    // friendly functions
    FriendlyClass f_class{1, 2, 3};
    int sum_of_class = class_sum(f_class);
    printf("%d\n", sum_of_class);
    // friendly classes
    P p(1, 2);
    FriendP friend_p(10);
    int sum_a = friend_p.sum_a(p);
    friend_p.set_b(p);
    printf("%d %d\n", sum_a, p.getB());
    // friendly methods
    BaseClass base_class{100};
    Friend_BaseClass f_base_class;
    int sum_vars = f_base_class.sum_vars(base_class);
    printf("%d\n", sum_vars);
    printf("\n");
}

// explicit
class Vec2d {
public:
    int x, y;

    Vec2d(int var1 = 0, int var2 = 0) : x(var1), y(var2) {}

    Vec2d add(Vec2d other) { return {x + other.x, y + other.y}; }

};

class ExplicitVec2d {
public:
    int x, y;

    explicit ExplicitVec2d(int var1 = 0, int var2 = 0) : x(var1), y(var2) {}

    ExplicitVec2d add(ExplicitVec2d other) {
//        return {x + other.x, y + other.y}; // doesn't work,
        // because explicit constructor prohibits casting {...} to ExplicitVec2d class
        return (ExplicitVec2d) {x + other.x, y + other.y};
    }
};

void show_explicit() {
    Vec2d vec{0, 8};
    Vec2d res_add1 = vec.add({});
    Vec2d res_add2 = vec.add((Vec2d) {});
    Vec2d res_add3 = vec.add(13);
    Vec2d res_add4 = vec.add({1, 3});
    Vec2d res_add5 = vec.add((Vec2d) {1, 3});
    Vec2d res_add6 = vec.add(Vec2d());
    Vec2d res_add7 = vec.add(Vec2d(-1, -3));
    Vec2d res_add8 = vec.add(vec);

    ExplicitVec2d exp_vec{0, 8};
    ExplicitVec2d res_exp_add1 = exp_vec.add(ExplicitVec2d());
    ExplicitVec2d res_exp_add2 = exp_vec.add((ExplicitVec2d) {});
    ExplicitVec2d res_exp_add3 = exp_vec.add((ExplicitVec2d) {1, 3});
    ExplicitVec2d res_exp_add4 = exp_vec.add(ExplicitVec2d(-1, 3));
    ExplicitVec2d res_exp_add5 = exp_vec.add((ExplicitVec2d) {13});
}

// delete
class Something {
public:
    int field;

//    Something(double var) : field((int) var) {} // old constructor, which is depricated
    Something(double var) = delete;

    Something(int var) : field(var) {}

};


// const after method
class CCC {
    int attr = 10;
public:
    int getAttr() const { return attr; } // const means, that I don't change class fields
};

#include <cmath>

// operator overloading
// inside the class
struct Vector2D {
    double x = 0, y = 0;

    Vector2D() = default;

    Vector2D(double a, double b) : x(a), y(b) {}

    double length() { return sqrt(x * x + y * y); }

    // java implementation
    Vector2D add(Vector2D &vec) { return {x + vec.x, y + vec.y}; }

    Vector2D mult(double t) { return {x * t, y * t}; }

    double dot(Vector2D &vec) { return x * vec.x + y * vec.y; }

    // operator overloading implementation
    Vector2D operator+(Vector2D &vec) { return {x + vec.x, y + vec.y}; }

    Vector2D operator*(double t) { return {x * t, y * t}; }

    double operator*(Vector2D &vec) { return x * vec.x + y * vec.y; }

    // other
    Vector2D operator+=(Vector2D &vec) {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }

    Vector2D operator*=(double t) {
        this->x *= t;
        this->y *= t;
        return *this;
    }

    Vector2D operator=(Vector2D &vec) {
        this->x = vec.x;
        this->y = vec.y;
        return *this;
    }
};

// operator overloading using friendly functions
struct Point2D {
    double x = 0, y = 0;

    Point2D() = default;

    Point2D(double a, double b) : x(a), y(b) {}

    friend Point2D operator+(Point2D &p1, Point2D &p2);

    friend Point2D operator*(Point2D &p, double t);
};

Point2D operator+(Point2D &p1, Point2D &p2) {
    return {p1.x + p2.x, p1.y + p2.y};
}

Point2D operator*(Point2D &p, double t) {
    return {p.x * t, p.y * t};
}

void show_overloading() {
    Vector2D vec1{10, 20};
    Vector2D vec2{300, 400};
    double T = 10;
    Vector2D res_sum1 = vec1 + vec2;
    Vector2D res_sum2 = vec2 + vec1;
    Vector2D res_mult1 = vec1 * T;
    Vector2D res_mult2 = T * vec1; // doesn't work, because operator*(Vector2D) for double type wasn't overloaded
    vec1 += vec2;
}

// templates
template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair(T1 var1, T2 var2) : first(var1), second(var2) {}
};

void show_templates() {
    Pair p{1.0, "string"};
    auto first = p.first;
    auto second = p.second;
    printf("%f %s\n", first, second);
    printf("\n");
}