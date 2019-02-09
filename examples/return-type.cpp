/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    return-type.cpp
 * Using DynamicTyping::Object as a return type of a function.
 * 
 * */

#include <iostream>
#include <string>
#include "../src/Object.hpp"
using namespace std;

// A simple addition function that return a string message if one of the passed integers is negative , otherwise it returns the sum.
DynamicTyping::Object add(int x, int y) {
    if (x < 0 || y < 0) {
        return std::string("Negative numbers inserted");
    }
    return x + y;
}

int main(int argc, const char **argv) {
  int u, v;
  cin >> u >> v;
  DynamicTyping::Object value = add(u, v);
  cout << value << endl;
  return 0;
}
