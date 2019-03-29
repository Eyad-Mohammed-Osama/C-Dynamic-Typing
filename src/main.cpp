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
    char s[] = "Hello World , This is a string literal";

    // Let's declare an array of objects
    DynamicTyping::Object arr[] = {a, b, c, d, e, f, g, h, s};

    for (int i = 0; i < 9; i++) {
        cout << arr[i] << "\t\t" << arr[i].GetDeepType() << endl;
    }

    cout << endl;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    // Now let's create a variable which can hold any datatype
    DynamicTyping::Object variable = 5; // starting with an integer
    cout << variable << endl;

    variable = 6.33f;    //  set the value to a floating point
    cout << variable << endl;

    variable = 'a';     //  set the value to a character
    cout << variable << endl;

    variable = false;     //  set the value to a boolean
    cout << variable << endl;

    variable = string("Hello World");     //  set the value to a string
    cout << variable << endl;

    variable = "Hello World As A String Literal";   //  set the value as a string literal
    cout << variable << endl;

    DynamicTyping::Object anotherVariable = variable;   // here's another one
    cout << anotherVariable << endl;    //  this will print the memory address of anotherVariable

    variable = Person("John", "Doe");   // set the value to an instance of Person
    cout << variable << endl;           // print the memory address of variable

    cout << endl;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    // Two objects are equal if and only if they point at the same memory address

    variable = 5;
    anotherVariable = variable;

    cout << (variable == anotherVariable) << endl;  //  true

    anotherVariable = 6;
    cout << (variable == anotherVariable) << endl;  // false
    
    cin.get();
    return 0;
}