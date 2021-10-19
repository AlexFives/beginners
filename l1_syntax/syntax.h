#pragma once

#include <iostream>

using namespace std;

const double PI = 3.14;

void variableBytes() {
    // 1 byte:
    bool bool_true = true;
    bool bool_false = false;
    char _char = 'a'; // also "int8_t", ASCII chars, [-2^7, 2^7 - 1]
    char _int_char = -64;
    unsigned char u_char = 255; // also "uint8_t", ASCII chars, [0, 2^8 - 1]

    // 2 bytes:
    short short_int = 32000; // also "short int", "signed short int", "int16_t". [-2^15, 2^15 - 1]
    unsigned short u_short = 64000; // also "unsigned short int", "uint16_t". [0, 2^16 - 1]
    wchar_t wchar = 'a'; // UTF-16 chars, [0, 2^16 - 1]

    // 4 bytes:
    int _int = -2000000000; // also "signed", "int32_t", "long". [-2^31, 2^31 - 1]
    unsigned int _uint = 4000000000; // also "unsigned", "uint32_t", "unsigned long". [0, 2^32 - 1]
    float _float = 123.456; // [-3.4E38, -3.4E-38] and [3.4E-38, 3.4E38]
    // if number doesn't in these ranges, then rounds it to 0 or to +-inf:
    // 3.5E38 == inf, -3.5E38 == -inf, +-3.5E-38 == 0
    float _float_exp = 1E10; // exponential notation of float number

    // 8 bytes:
    long long _long_long = -9000000000; // also "signed long long", "int64_t". [-2^63, 2^63 - 1]
    unsigned long long _ull = 18000000000; // also "unsigned long long", "uint64_t". [0, 2^64 - 1]
    double _double = 123123.1239182398; // also "long double", [-1.7E308, -1.7E-308] and [1.7E-308, 1.7E308]
    // rounding works like in float, also supports exponential notation

    int int_array[10]; // static array of int, length = 10.

    auto auto_var = 5;
    auto_var = 'a'; // 97 (index in ASCII)
    auto_var = 12.34; // 12, (floors float object)

    const int const_value = 10; // can't reassign this value: const_value = 11 will cause error
}

void operators();

void ifelse(const int &, const int &);

void cycles(int n) {
    if (n < 2) return;

    int array[n];
    for (int i = 0; i < n; i++) array[i] = i;

    for (int item : array) {
        int tmp = 10 - item;
        cout << item * tmp << ' ';
    }
    cout << endl;

    int i = 0;
    while (i++ < n) array[i] = i * i;

    for (int iter = 0; iter != n; ++iter) cout << array[iter] << ' ';
    cout << endl;
    for (int iter = 0; iter != n; iter++) cout << array[iter] << ' ';
    cout << endl;

    i = 0;
    while (i++ != n) cout << array[i] << ' ';
    cout << endl;
    i = 0;
    while (++i < n) cout << array[i] << ' ';
    cout << endl;

    i = 0;
    do {
        cout << i << ' ';
        i++;
    } while (i < 10);


    for (int item : array) {
        if (item == array[n - 1]) continue;
        cout << item << ' ';
    }
    cout << endl;

    for (int iter = 0; iter < n; iter++) {
        cout << array[iter] << ' ';
        if (iter >= 3) break;
    }
    cout << endl;
}

void switchcase(int a, int b) {
    switch (a) {
        case 1:
            int c;
            c = a - b;
            // int c = a - b; - error
            cout << c << endl;
            break;
        case 2:
        case 3:
        case 4:
            c = a * b;
            cout << c << endl;
            break;
        default:
            cout << a + b << endl;
            break;
    }
}

void operators() {
    int assignment = 12345; // = - assignment operator

    // arithmetic:
    int add = 1 + 2; // 3,
    float add_f = 1.2 + 3.4; // 4.6

    int sub = 1 - 2; // -1
    float sub_f = 1.2 - 3.4; // -2.2

    int mult = 1 * 2; // 2
    float mult_f = 1.2 * 3.4; // 4.08

    int div1 = 1 / 2; // !!! 0; if nominator and denominator are integers, then works as floordiv
    int div2 = 1.0 / 2; // 0, integer type floors division
    float div_f1 = 1. / 2; // 0.5
    float div_f2 = 1 / 2.; // 0.5
    float div_f3 = 1 / 2;

    int mod = 1 % 2; // 1, module division, returns remainder of division, works only with integers

    int unary_plus = +mod; // 1
    int unary_minus = -mod; // -1

    int post_inc = unary_plus++; // 2
    int post_dec = unary_minus--; // -2
    int prev_inc = ++unary_plus; // 2
    int prev_dec = --unary_minus; // -2

    // post and prev increment or decrement differs in cycles, ++var firstly increase var and after go to cycle body,
    // (similarly with prev decrement); var++ at first go to cycle body and after. on the next step, will increase var
    // (similarly with post decrement)

    // comparison:
    int var1 = 10, var2 = 20;
    bool equals = var1 == var2; // false; == - var1 equals to var2
    bool not_equals = var1 != var2; // true; != - var1 not equals to var2
    bool greater = var1 > var2; // false; > - var1 greater than var2
    bool less = var1 < var2; // true; < - var1 less than var2
    bool greater_or_equal = var1 >= var2; // false; >= - var1 greater than var2 or equals it'
    bool less_or_equal = var1 <= var2; // true; <= - var2 less than var2 or equals it

    // logic:
    bool logic_var1 = true;
    bool logic_var2 = false;
    bool _not1 = not logic_var1; // false; not var (or !var) - reverse boolean variable;
    bool _not2 = !logic_var1; // false;
    bool _or1 = logic_var1 or logic_var2; // true; var1 or var2 (or var1 || var2) - boolean "or"
    bool _or2 = logic_var1 || logic_var2; // true;
    bool _and1 = logic_var1 and logic_var2; // false; var1 and var2 (or var1 && var2) - boolean "and"
    bool _and2 = logic_var1 && logic_var2;

    // bitwise:
    int bit_not1 = ~4; // 3, bitwise not
    int bit_not2 = compl 6; // 3
    int bit_and1 = 4 & 6; // 8, bitwise and
    int bit_and2 = 4 bitand 6; // 8
    int bit_or1 = 4 | 6; // 10, bitwise or
    int bit_or2 = 4 bitor 6;
    int bit_xor1 = 4 ^ 6; // 2, bitwise xor
    int bit_xor2 = 4 xor 6;
    int left_shift = 4 << 1; // 8, bitwise leftshift
    int right_shift = 4 >> 1; // 2, bitwise rightshift

    // assignments:
    int var = 5;
    var += 10; // 15, equals var = var + 10
    var -= 10; // 5, equals var = var - 10
    var *= 10; // 50, equals var = var * 10
    var /= 10; // 5, equals var = var / 10
    var %= 10; // 5, equals var = var % 10
    var &= 10; // 0, equals var = var & 10
    // var and_eq 10 do same
    var |= 10; // 10, equals var = var | 10
    // var or_eq 10 do same
    var ^= 10; // 0, equals var = var ^ 10
    // var xor_eq 10 do same
    var = 8;
    var <<= 10; // 8192, equals var = var << 10
    var >>= 10; // 8, equals var = var >> 10

    // other:
    int int_array[10];
    int x = int_array[0]; // idk, cuz values inits randomly, value at the first position of array
}

void ifelse(const int &input1, const int &input2) {
    cout << "1: ";
    if (input1 == input2) cout << "Nice";
    else cout << "(((";
    cout << endl;

    cout << "2: ";
    if (input1 != input2) {
        cout << "They're not equal( ";
        cout << "But it's several actions";
    } else cout << "Nice, they are equal";
    cout << endl;

    cout << "3: ";
    if (input1 < input2) cout << input1 << " < " << input2;
    else if (input1 == input2) {
        cout << "They're equal! ";
        cout << "Nice!";
    } else cout << "They aren't equal(((";
    cout << endl;

    cout << "4: ";
    int result = (input1 == input2) ? 1 : -1;
    cout << result << endl;

}