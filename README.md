# C++ Dynamic Typing
A C++ class to give the ability to use dynamic typing.

# Usage
It's very simple to use this class , you just need to include the `Object.hpp` header file in your C++ source file.

Next , create an instance from the `Object` class and assign any value to it.

```c++

#include <iostream>
#include <string>
#include "./Object.hpp"
using namespace std;

class Person {
    private:
    string fname;
    string lname;

    public:
    Person(string fname, string lname) {
        this->fname = fname;
        this->lname = lname;
    }
};

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
  
  variable = g;                         //  now assign an instance of the `Person` class
  cout << variable << endl;
  
  DynamicTyping::Object anotherVariable = variable;   // here's another one
  cout << (anotherVariable == variable) << endl;      // `true`, because both variables points at the same instance
  
  return 0;
}

```

Finally , you can safely compile it.

Notice that the compilation must be done using C++ 2011 standard , if you're on `g++` you will need to use the `-std=c++11` or `-std=gnu++11` flag:

`g++ Object.cpp main.cpp -std=c++11 -o main.exe`

`g++ Object.cpp main.cpp -std=gnu++11 -o main.exe`

(The implementation depends on scoped enums which isn't supported before C++ 2011).

# Noticed issues
- String literals doesn't work:

```c++
DynamicTyping::Object var1 = "Hello World";           // won't compile
DynamicTyping::Object var2 = string("Hello World");   // compiles fine
```
(Hopefully this will be fixed in the future releases)

- Possible memory lacks (the implementation adds a layer above the `void*` datatype , and since deallocating a `void` pointer is undefined behavior , it was left as is) .
