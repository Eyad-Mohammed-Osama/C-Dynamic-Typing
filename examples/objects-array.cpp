/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    object-arrays.cpp
 * How to create an array of objects.
 * 
 * */

#include <iostream>
#include <string>
#include "./Object.hpp"

#ifndef M_PI
#define M_PI    3.14159265358979323846    // re-defining the M_PI constant in case it's not defined
#endif

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
    DynamicTyping::Object arr[6] = {
        int(5), 
        float(3.66f), 
        double(M_PI),
        char('a'),
        Person("Syrian", "Lucianos"),
        string("Hello World")
    };

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}
