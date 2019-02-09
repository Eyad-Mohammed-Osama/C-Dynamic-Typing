/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    GetType.cpp
 * Demonstrating the GetType() and values which it returns.
 * 
 * */

#include <iostream>
#include <string>
#include "../src/Object.hpp"
using namespace std;

int main(int argc, const char **argv) {
  DynamicTyping::Object o = 0xFFFF;
  
  if (o.GetType() == DynamicTyping::Type::Bool) {         // "o" holds a boolean
    
  }
  else if (o.GetType() == DynamicTyping::Type::Char) {    // "o" holds an 8 bit character
  
  }
  else if (o.GetType() == DynamicTyping::Type::Int16) {   // "o" holds a 16 signed bit integer (signed short integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::UInt16) {  // "o" holds a 16 unsigned bit integer (unsigned short integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::Int32) {   // "o" holds a 32 signed bit integer (signed integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::UInt32) {  // "o" holds a 32 unsigned bit integer (unsigned integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::Int64) {   // "o" holds a 64 signed bit integer (signed long long integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::UInt64) {  // "o" holds a 64 unsigned bit integer (unsigned long long integer)
  
  }
  else if (o.GetType() == DynamicTyping::Type::Float) {   // "o" holds a 32 bit floating point number (float)
  
  }
  else if (o.GetType() == DynamicTyping::Type::Double) {   // "o" holds a 64 bit floating point number (double)
  
  }
  else if (o.GetType() == DynamicTyping::Type::String) {   // "o" holds a string
  
  }
  else if (o.GetType() == DynamicTyping::Type::Object) {   // "o" holds an instance of DynamicTyping::Object
  
  }
  else if (o.GetType() == DynamicTyping::Type::Other) {    // "o" holds a variable which its type is non of the above types
  
  }
  else if (o.GetType() == DynamicTyping::Type::NoType) {    // "o" holds an uninitialized instance of DynamicTyping::Object
  
  }
  
  return 0;
}
