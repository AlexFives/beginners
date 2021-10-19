#pragma once

#include "syntax.h"

void launch1() {
    /*
     start of the program is function int main()
     and this is multiline comment
     */
    variableBytes();
    operators();

    int input1, input2, n;
    cin >> input1 >> input2 >> n;
    ifelse(input1, input2);
    cout << endl;
    cycles(n);
    cout << endl;
    int a, b;
    cin >> a >> b;
    switchcase(a, b);
    cout << endl;
}