#pragma once

#include <iostream>

using namespace std;

void printString(char [], const int &);
void istreamDemoCIN(const int &);
void istreamDemoGET(const int &);
void istreamDemoGETLINE(const int &);
void istreamDemoSCANF(const int &);

char *initStr();
void ostreamDemoCOUT(char[], const int &);
void ostreamDemoPUT(char[], const int &);
void ostreamDemoWRITE(char[], const int &);
void ostreamDemoPRINTF(char[], const int &);

void istreamDemo();
void ostreamDemo();
void iostreamDemo();

#include "iostream.cpp"