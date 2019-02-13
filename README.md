# C++ Dynamic Typing
A C++ class to give the ability to use dynamic typing.

# API Index
- <a href="#usage">Usage</a>
- <a href="#api-reference">API Reference</a>
    - <a>DynamicTyping::Types</a>
    - <a>DynamicTyping::Object</a>
        - <a>DynamicTyping::Object::Object()</a>
        - <a>DynamicTyping::Object::operator<<()</a>
        - <a>DynamicTyping::Object::operator=()</a>
        - <a>DynamicTyping::Object::operator==()</a>
        - <a>DynamicTyping::Object::operator!=()</a>
        - <a>DynamicTyping::Object::GetType()</a>
        - <a>DynamicTyping::Object::ToString()</a>
- <a href="#notes">Notes</a>
- <a href="#noticed-issues">Noticed issues</a>
- <a href="#report-issues">Report issues</a>

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

# API Reference
## DynamicTyping::Types
An `enum` class that simplify dealing with the underlying types of `Object` instances.

We will demonstrate each of these types in the following table:

<table class="tg" style="undefined;table-layout: fixed; width: 1247px">
<colgroup>
<col style="width: 415px">
<col style="width: 415px">
<col style="width: 417px">
</colgroup>
  <tr>
    <th class="tg-kluc">Type</th>
    <th class="tg-6ibf">Description</th>
    <th class="tg-kluc">Possible values</th>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::Char<br></td>
    <td class="tg-6ibf">Represents an 8-bit ASCII Character<br></td>
    <td class="tg-6ibf">Range from 0 to 255<br></td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::Bool</td>
    <td class="tg-6ibf">Represents a boolean value</td>
    <td class="tg-6ibf">true or false</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::Int16</td>
    <td class="tg-6ibf">Represents a 16-bit signed integer</td>
    <td class="tg-6ibf">Range from -32768 to 32767</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::UInt16</td>
    <td class="tg-6ibf">Represents a 16-bit unsigned integer</td>
    <td class="tg-6ibf">Range from 0 to 65535</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::Int32</td>
    <td class="tg-6ibf">Represents a 32-bit signed integer</td>
    <td class="tg-6ibf">Range from -2147483648 to 2147483647</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::UInt32</td>
    <td class="tg-6ibf">Represents a 32-bit unsigned integer</td>
    <td class="tg-6ibf">Range from 0 to 4294967295</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::Int64</td>
    <td class="tg-6ibf">Represents a 64-bit signed integer<br><br></td>
    <td class="tg-6ibf">Range from -9223372036854775808 to 9223372036854775807</td>
  </tr>
  <tr>
    <td class="tg-6ibf">Type::UInt64</td>
    <td class="tg-6ibf">Represents a 64-bit unsigned integer</td>
    <td class="tg-6ibf">Range from 0 to 18446744073709551615</td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::Float</td>
    <td class="tg-hjji">Represents a 32-bit floating point number</td>
    <td class="tg-hjji">Positive:<br>Range from 1.17549e-38 to 3.40282e+38<br><br>Negative:<br>Range from -1.17549e-38 to -3.40282e+38</td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::Double</td>
    <td class="tg-hjji">Represents a 64-bit floating point number</td>
    <td class="tg-hjji">Positive:<br>Range from 2.22507e-308 to 1.79769e+308<br><br>Negative:<br>Range from -2.22507e-308 to -1.79769e+308<br></td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::String</td>
    <td class="tg-hjji">Represents an instance of the std::string class</td>
    <td class="tg-hjji"></td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::Object</td>
    <td class="tg-hjji">Represents an instance of the DynamicTyping::Object class that is assigned to another instance of the DynamicTyping::Object class</td>
    <td class="tg-hjji"></td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::Other</td>
    <td class="tg-hjji">Represents an instance of some another class , this value is automatically used when non of the above types are assigned to the DynamicTyping::Object instance</td>
    <td class="tg-hjji"></td>
  </tr>
  <tr>
    <td class="tg-hjji">Type::NoType</td>
    <td class="tg-hjji">Represents an uninitialized instance of the DynamicTyping::Object class</td>
    <td class="tg-hjji"></td>
  </tr>
</table>

## DynamicTyping::Object
Provides the necessary methods and functionalities to enable dynamic typing.

### DynamicTyping::Object::Object()
A constructor with 14 different prototypes.

```c++

DynamicTyping::Object::Object();                            // Instantiate an uninitialized object
DynamicTyping::Object::Object(char);                        // Instantiate an object and initialize it with an 8-bit ASCII character
DynamicTyping::Object::Object(bool);                        // Instantiate an object and initialize it with a boolean value
DynamicTyping::Object::Object(short int);                   // Instantiate an object and initialize it with a 16-bit signed integer
DynamicTyping::Object::Object(unsigned short int);          // Instantiate an object and initialize it with a 16-bit unsigned integer
DynamicTyping::Object::Object(int);                         // Instantiate an object and initialize it with a 32-bit signed integer
DynamicTyping::Object::Object(unsigned int);                // Instantiate an object and initialize it with a 32-bit unsigned integer
DynamicTyping::Object::Object(long long int);               // Instantiate an object and initialize it with a 64-bit signed integer
DynamicTyping::Object::Object(unsigned long long int);      // Instantiate an object and initialize it with a 64-bit unsigned integer
DynamicTyping::Object::Object(float);                       // Instantiate an object and initialize it with an 32-bit floating point number
DynamicTyping::Object::Object(double);                      // Instantiate an object and initialize it with an 64-bit floating point number
DynamicTyping::Object::Object(std::string);                 // Instantiate an object and initialize it with an instance of std::string
DynamicTyping::Object::Object(const Object&);               // Instantiate an object and initialize it with another instance of DynamicTyping::Object

template<typename any>
DynamicTyping::Object::Object(const any&);                    // Instantiate an object and initialize it with an object from any type (except those listed above)

```

### DynamicTyping::Object::operator<<()
An overloaded version for the stream insertion operator , this helps you to directly `cout` an instance of `DynamicTyping::Object`.

```c++

DynamicTyping::Object o = 4;
std::cout << o << std::endl;    // print 4

o = 'A';
std::cout << o << std::endl;    // print 'A'

```

The operator works according to the following rules:

1. If the object type is `Type::Char` , `Type::Bool` , `Type::Int16` , `Type::UInt16` , `Type::Int32` , `Type::UInt32` , `Type::Int64` , `Type::UInt64` , `Type::Float` , `Type::Double` , or `Type::String` , then the object's value is directly printed as is.
2. If the object type is `Type::Object` , then the memory address of the object's value is printed , for example:

```c++

DynamicTyping::Object u = 4;
DynamicTyping::Object v = u;

std::cout << v << std::endl;    // print something similar to: Object at memory address <0x557bb12a0e90>

```

3. If the object type is `Type::Other` , then the deep type of the object's value is printed , for example:

```c++

class Complex {
    private:
    double real;
    double imaginary;
};

int main() {
    DynamicTyping::Object u = Complex();
    std::cout << u << std::endl;        // print something similar to: 7Complex
    return 0;
}

```

4. If the object is uninitialized (i.e. its type is `Type::NoType`) , then an `std::runtime_exception()` exception is thrown , and execution is halted.

### DynamicTyping::Object::operator=()

An overloaded version for the assignment operator with 13 different operators.

```c++

DynamicTyping::Object operator=(const char&);
DynamicTyping::Object operator=(const bool&);
DynamicTyping::Object operator=(const short int&);
DynamicTyping::Object operator=(const unsigned short int&);
DynamicTyping::Object operator=(const int&);
DynamicTyping::Object operator=(const unsigned int&);
DynamicTyping::Object operator=(const long long int&);
DynamicTyping::Object operator=(const unsigned long long int&);
DynamicTyping::Object operator=(const float&);
DynamicTyping::Object operator=(const double&);
DynamicTyping::Object operator=(const std::string&);
DynamicTyping::Object operator=(const DynamicTyping::Object&);

template<typename any> 
DynamicTyping::Object operator=(const any&);

```

### DynamicTyping::Object::operator==()

An overloaded version for the equality operator.

We say that two instances of `DynamicTyping::Object` are equal if and only if both instances points at the same memory address.

```c++

DynamicTyping::Object u = 4;
DynamicTyping::Object v = u;

std::cout << (u == v) << std::endl;     // true , because both `u` and `v` points at the same memory address

```

### DynamicTyping::Object::operator!=()

An overloaded version for the inequality operator.

It does the opposite functionality of `DynamicTyping::Object::operator!=()` , that is , it check whether two instances of `DynamicTyping::Object` points to the same memory address , and returns true if they don't.

### DynamicTyping::Object::GetType()

Returns `DynamicTyping::Type` that describes the type of a `DynamicTyping::Object` instance.

### DynamicTyping::Object::ToString()

Returns a textual representation of a `DynamicTyping::Object` instance , it follows the same rules of `DynamicTyping::Object::operator<<()`.


# Notes
- When assigning a value or a variable to an instance of `DynamicTyping::Object` , the type inference happens automatically according to the underlying variable type , there's nothing special you need to do.
- When assigning a variable of type `Type::Other` , the API understands the deep type of this variable (i.e. what class was instantiated to produce this variable).
- As for printing an instance of `DynamicTyping::Object` with `Type::Other` , the printed value in this case depends on what `typeid().name()` returns.
- The behavior of `DynamicTyping::Object::operator==()` and `DynamicTyping::Object::operator!=()` is inspired from the `Object` datatype in `C#`.

# Noticed issues
- String literals doesn't work:

```c++

DynamicTyping::Object var1 = "Hello World";           // won't compile
DynamicTyping::Object var2 = string("Hello World");   // compiles fine

```
(Hopefully this will be fixed in the future releases)

- Possible memory lacks (the implementation adds a layer above the `void*` datatype , and since deallocating a `void` pointer is undefined behavior , it was left as is) .

# Report issues
I don't expect this to be perfect , especially when this is the first release , there must be issues i haven't noticed.

In case you found some of those issues , please don't hesitate to open an <a href="https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing/issues/new">Issue</a> 

Maybe some people get disturbed or frustrated when they see issues in their repositories , but i feel happy when i see issues in my repository , issues make me feel happy :) .
