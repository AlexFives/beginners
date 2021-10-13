#include "strings.h"

void stringDemo() {
    string str1 = "Hello,";
    string str2("world!");
    stringIO();
    stringOPERATORS(str1, str2);
    stringMETHODS(str1);
}

void stringIO() {
    // input
    string str1;
    cin >> str1;
    string str2;
    getline(cin, str2);
    cout << str1 << endl;
    printf("%s", str2.c_str());
}

void stringOPERATORS(string &str1, string &str2) {
    string str;
    char *c_string = "C_STRING";
    str = c_string;
    str = str2;
    str = str1;
    str += str2;
    str = str1 + str2;
    bool equal = str1 == str2;
    bool not_equal = str1 != str2;
    bool lower = str1 < str2;
    bool lower_equal = str1 <= str2;
    bool greater = str1 > str2;
    bool greater_equal = str1 >= str2;
}

void stringMETHODS(string &str) {
    string _str = str;
    int string_size = str.size();
    int string_len = str.length();
    bool empty = str.empty();
    char *c_string = "C_STRING";
    _str.resize(32);
    string_size = _str.size();
    string_len = _str.length();
    _str = str;
    _str.append(c_string); // _str + "C_STRING"
    _str = str;
    _str.append(c_string, 3); // _str + "C_S"
    // appends 3 chars to _str
    _str = str;
    _str.insert(0, c_string); // "C_STRING" + _str
    // inserts c_string at _str 0 position
    _str = str;
    _str.insert(0, c_string, 1, 3); // "_ST" + _str
    // inserts 3 chars from c_string 1st position at _str 0 position
    _str = str;
    _str.replace(1, 3, c_string);
    // replaces 3 chars from position 1 to c_string
    _str = str;
    _str.replace(0, 2, c_string, 3, 4);
    // replaces 2 chars from 0 position to 4 chars of c_string from 3rd position
    _str = str;
    _str.erase(0, 3);
    // erases 3 chars from 0 position
    _str = str;
    int pos;
    // return position of the first entry, if didn't find: -1
    // search from begin to end
    pos = _str.find('e');
    pos = _str.find("el", 1);
    // abc abc abc
    // search from end to begin
    pos = _str.rfind('w');
    pos = _str.rfind("d!", 13);
}