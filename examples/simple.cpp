/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    simple.cpp
 * The simplest usage of the library
 * 
 * */

#include <iostream>
#include <string>
#include "../src/Object.hpp"
using namespace std;

int main(int argc, const char **argv) {
  int a = 5;
  float b = 6.33f;
  double c = 9.3333332;
  char d = 'a';
  bool e = false;
  string f = "Hello World";
  Person g = Person("Syrian", "Lucianos");
  Person *h = &g;
  
  // The `Object` class is contained in the `DynamicTyping` namespace
  // You could add `using namespace DynamicTyping;` at the beginning to avoid writing the
  // `DynamicTyping` prefix everytime.
  
  DynamicTyping::Object variable = 5;   //  assign an integer
  cout << variable << endl;
  
  variable = 'a';   //  assign a character
  cout << variable << endl;
  
  variable = g;                         //  now assign an instance of the `Person` class
  cout << variable << endl;
  
  DynamicTyping::Object anotherVariable = variable;   // here's another one
  cout << (anotherVariable == variable) << endl;      // `true`, because both variables points at the same instance
  
  return 0;
}
