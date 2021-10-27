#pragma once

#include <bits/stdc++.h>
#include "stack.h"
#include "queue.h"

using namespace std;

int getNumber(int number) { return number; }

int num = 322;
int *p_num, **p_p_num, ***p_p_p_num;

void variables() {
    // variables
    printf("###VARIABLES\n");
    // num - variable
    printf("num: %d\n", num); // 322
    // &num returns address (memory cell), where num is located
    printf("num address (&num): 0x%x\n", &num); // 0x...
    // *&num returns data, that is stored in num address (equals num)
    printf("data in num address (*&num): %d\n", *&num); // num or 322
    // this also works (as *&num)
    printf("something strange: %d\n", *&*&*&*&*&*&num); // num or 322
    // or this too (as &num)
    printf("a bit more strange: 0x%x\n", &*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&num); // &num
    printf("\n");
}

void references() {
    // references
    printf("\n###REFERENCES\n");
    int &ref_num = num; // reference to int type
    // int &ref; ERROR! reference can't be declared
    int num2 = 123;
    // assigning will change num
    ref_num = num2; // equals num = num2
    ref_num = num; // equals num = num
    ref_num = 322; // equals num = 322
    // const reference, it can't be reassigned
    const int &const_ref = num;
    // const references can refer to function result
    const int &function_ref = getNumber(10); // refer to 10
    // reference has the same value with the variable
    printf("ref_num: %d\n", ref_num); // num or 322
    // and the same address
    printf("ref_num address (&ref_num): 0x%x\n", &ref_num); // &num
    printf("\n");
}

void void_pointer();
void pointer2pointer2pointer();
void pointer2pointer();

void pointers() {
    // pointers
    printf("\n###POINTERS\n");
    // type *pointer_name = &variable
    p_num = &num; // int type pointer, which points to memory cell, containing int type
    printf("p_num: 0x%x\n", p_num); // &num
    // pointer has own address
    printf("p_num address (&p_num): 0x%x\n", &p_num); // 0x...
    // *&p_num returns data, that is stored in p_num address (returns &num)
    printf("data in p_num address (*&p_num): 0x%x\n", *&p_num); // p_num or &num
    // *p_num returns data, that is stored in p_num (returns *&num or num)
    printf("dereferencing of p_num (*p_num): %d\n", *p_num); // num or 322
    // &*p_num returns address to data, that is stored in p_num (returns &num)
    printf("address to dereferenced p_num (&*p_num): 0x%x\n", &*p_num); // p_num or &num
    printf("\n");

    pointer2pointer();
    void_pointer();

    // test your knowledge
    /*
     int num = 322; (num address = 0x1)
     int *p_num = &num; (p_num address = 0x10)
     int *pointer = p_num; (pointer address = 0x100)
     pointer - ?
     *pointer - ?
     &pointer - ?
     &*pointer - ?
     */
}

void pointer2pointer() {
    // pointer to pointer
    p_p_num = &p_num;
    printf("p_p_num: 0x%x\n", p_p_num); // &p_num
    printf("p_p_num address (&p_p_num): 0x%x\n", &p_p_num); // 0x...
    printf("data in p_p_num address (*&p_p_num): 0x%x\n", *&p_p_num); // p_p_num or &p_num
    printf("address to data in p_p_num address (&*&p_p_num): 0x%x\n", &*&p_p_num); // &p_p_num
    printf("dereferencing of p_p_num (*p_p_num): 0x%x\n", *p_p_num); // p_num or &num
    printf("address to dereferenced p_p_num (&*p_p_num): 0x%x\n", &*p_p_num); // p-p_num or &p_num
    printf("double dereferencing of p_p_num (**p_p_num): %d\n", **p_p_num); // *p_num or num or 322
    printf("address to double dereferenced p_p_num (&**p_p_num): 0x%x\n", &**p_p_num); // &*p_num or p_num or &num
    printf("\n");

    pointer2pointer2pointer();
}

void pointer2pointer2pointer() {
    // pointer to pointer to pointer
    p_p_p_num = &p_p_num;
    printf("p_p_p_num: 0x%x\n", p_p_p_num); // &p_p_num
    printf("p_p_p_num address (&p_p_p_num): 0x%x\n", &p_p_p_num); // 0x...
    printf("data in p_p_p_num address (*&p_p_p_num): 0x%x\n", *&p_p_p_num); // p_p_p_num or &p_p_num
    printf("address to data in p_p_p_num address (&*&p_p_p_num): 0x%x\n", &*&p_p_p_num); // &p_p_p_num
    printf("dereferencing of p_p_p_num (*p_p_p_num): 0x%x\n", *p_p_p_num); // p_p_num or &p_num
    printf("address to dereferenced p_p_p_num (&*p_p_p_num): 0x%x\n", &*p_p_p_num); // p_p_p_num or &p_p_num
    printf("double dereferencing of p_p_p_num (**p_p_p_num): 0x%x\n", **p_p_p_num); // *p_p_num or p_num or &num
    printf("address to double dereferenced p_p_p_num (&**p_p_p_num): 0x%x\n", &**p_p_p_num); // &*p_p_num or p_p_num or &p_num
    printf("triple dereferencing of p_p_p_num (***p_p_p_num): %d\n", ***p_p_p_num); // **p_p_num or *p_num or num or 322
    printf("address to triple dereferenced p_p_p_num (&***p_p_p_num): 0x%x\n", &***p_p_p_num);
    // &**p_p_num or *p_p_num or &*p_num or p_num or &num
    printf("\n");
}

void void_pointer() {

    void *p_void = &p_num;
    p_void = p_p_num;
    p_void = &num;
    printf("p_void: 0x%x\n", p_void); // &num
    printf("p_void address (&p_void): 0x%x\n", &p_void); // 0x...
    printf("dereferencing of p_void (*(TYPE*)p_void): %d\n", *(int*)p_void); // num
    printf("\n");
}

void custom_cstyle_stack();
void custom_cstyle_queue();

void dynamic_memory_allocation() {
    // dynamic memory allocation
    printf("\n###DYNAMIC MEMORY ALLOCATION\n");
    int *pointer = nullptr; // nullptr (null pointer) is a pointer, which doesn't point anywhere
    printf("pointer: 0x%x\n", pointer); // 0x0
    // printf("dereferenced pointer (*pointer): %d\n", *pointer); ERROR!
    printf("address of the pointer (&pointer): 0x%x\n", &pointer); // 0x...

    pointer = new int(322); // free memory allocated for new int type
    printf("pointer: 0x%x\n", pointer); // 0x... (allocated memory cell, not 0x0)
    printf("dereferenced pointer (*pointer): %d\n", *pointer); // 322
    printf("address of the pointer (&pointer): 0x%x\n", &pointer); // 0x...

    delete pointer; // new int deletes from memory, &pointer - same, *pointer == 0!
    pointer = nullptr; // set null pointer (&pointer = 0x0, *pointer - error)

    // mistakes
    /*
     int *pointer = new int(10);

     Memory leaks (use Valgrind Memcheck to detect it):
     1) pointer = new int(20); previous value wasn't deleted
     2) pointer = nullptr; previous value wasn't deleted
     3) void doSomething() { int *p = new int(222); }
        allocated memory wasn't cleared
     */

    custom_cstyle_stack();
    custom_cstyle_queue();
    printf("\n");
}

void custom_cstyle_stack() {
    printf("\n#STACK\n");
    using namespace Stack;
    Node *node = new Node;
    typedef int T;
    printf("Stack size: %d\n", size(node)); // 0
    printf("Sizes: ");
    for (int i = 0; i < 10; i++) {
        add(i, node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Stack contains: ");
    print<T>(node);
    printf("Size: %d\n", size(node));
    printf("Sizes: ");
    for (int i = 0; i < 5; i++) {
        pop<T>(node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Stack contains: ");
    print<T>(node);
    printf("Size: %d\n", size(node));
    printf("Sizes: ");
    for (int i = 0; i < 5; i++) {
        pop<T>(node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Stack contains: ");
    print<T>(node);
    delete node;
}

void custom_cstyle_queue() {
    printf("\n#QUEUE\n");
    using namespace Queue;
    Node *node = new Node;
    typedef int T;
    printf("Queue size: %d\n", size(node)); // 0
    printf("Sizes: ");
    for (int i = 0; i < 10; i++) {
        add(i, node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Queue contains: ");
    print<T>(node);
    printf("Size: %d\n", size(node));
    printf("Sizes: ");
    for (int i = 0; i < 5; i++) {
        pop<T>(node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Queue contains: ");
    print<T>(node);
    printf("Size: %d\n", size(node));
    printf("Sizes: ");
    for (int i = 0; i < 5; i++) {
        pop<T>(node);
        printf("%d ", size(node));
    }
    printf("\n");
    printf("Queue contains: ");
    print<T>(node);
    delete node;
}

void show() {
    variables();
    references();
    pointers();
    dynamic_memory_allocation();
}