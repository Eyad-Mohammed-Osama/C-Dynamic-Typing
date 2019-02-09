/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    parameters.cpp
 * Using DynamicTyping::Object as a parameter of function.
 * 
 * */

#include <iostream>
#include <string>
#include "../src/Object.hpp"
using namespace std;

void test(DynamicTyping::Object parameter) {
    if (parameter.GetType() == DynamicTyping::Type::Int16) {
        cout << "signed short int" << endl;
    }
    else if (parameter.GetType() == DynamicTyping::Type::Bool) {
        cout << "bool" << endl;
    }
    else {
        cout << "unknown" << endl;
    }
}

int main(int argc, const char **argv) {
  short int u = 5000;
  test(u);  // print "signed short int"
  
  bool v = false;
  test(v);  // print "bool"
  
  int w = 6000;
  test(w);  // print "unknown"
  return 0;
}
