#pragma once

#include "funcs.h"

void launch3() {
    // default
    printHelloWorld();
    string name;
    cin >> name;
    printName1(name);
    printName2(name);
    printName3(name);
    const string const_name = "CONST_NAME";
    printName1(const_name);
//    printName2(const_name); error!
    printName3(const_name);
    // &&
    // doesn't work with variables
    printName4("Name");
    printName5("Name");
    char *p_name = "P_NAME"; // pointer
    printName1(p_name);
    //    printName2(p_name); error!
    printName3(p_name);
    printName4(p_name);
    printName5(p_name);
    cout << endl;
    // extern
    cout << EXTERN_VAR << ' ' << PI << endl;
    int a = 10, b = 20;
    int result = inlineIntSum(a, b);
    float c = 10., d = 20.;
    float f_result = ExternInlineFloatSum(c, d);
    printf("%d %f\n", result, f_result);
    cout << endl;
    // templates
    string s1 = "Hello, ";
    string s2 = "world!";
    string string_result = sum(s1, s2);
    int int_result = sum(a, b);
    float float_result = sum(c, d);
    cout << int_result << ' ' << float_result << ' ' << string_result << endl;
    auto not_auto_result = sumNotAuto<float>(a, d);
    printf("%f\n", not_auto_result);
    cout << endl;
    // pointers magic
    cout << ampersand_func() << endl;
    ampersand_func() = 223;
    cout << ampersand_func() << endl;
    cout << *star_func() << endl;
    *star_func() = 1000;
    cout << *star_func() << endl;
}