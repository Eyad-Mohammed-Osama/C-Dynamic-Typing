/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    Object.cpp
 * This file contains the actual implementation.
 * 
 * */

#include "./Object.hpp"     // let's include the prototypes

DynamicTyping::Object::Object() {
    this->value = new void*();
    this->type = Type::NoType;
}

DynamicTyping::Object::Object(char value) {
    this->value = new char(value);
    this->type = Type::Char;
}

DynamicTyping::Object::Object(bool value) {
    this->value = new bool(value);
    this->type = Type::Bool;
}

DynamicTyping::Object::Object(short int value) {
    this->value = new short int(value);
    this->type = Type::Int16;
}

DynamicTyping::Object::Object(unsigned short int value) {
    this->value = new unsigned short int(value);
    this->type = Type::UInt16;
}

DynamicTyping::Object::Object(int value) {
    this->value = new int(value);
    this->type = Type::Int32;
}

DynamicTyping::Object::Object(unsigned int value) {
    this->value = new unsigned int(value);
    this->type = Type::UInt32;
}

DynamicTyping::Object::Object(long long int value) {
    this->value = new long long int(value);
    this->type = Type::Int64;
}

DynamicTyping::Object::Object(unsigned long long int value) {
    this->value = new unsigned long long int(value);
    this->type = Type::UInt64;
}

DynamicTyping::Object::Object(float value) {
    this->value = new float(value);
    this->type = Type::Float;
}

DynamicTyping::Object::Object(double value) {
    this->value = new double(value);
    this->type = Type::Double;
}

DynamicTyping::Object::Object(std::string value) {
    this->value = new std::string(value);
    this->type = Type::String;
}

DynamicTyping::Object::Object(const Object &var) {
    this->value = var.value;
    this->type = Type::Object;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const char &variable) {
    this->value = new char(variable);
    this->type = Type::Char;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const bool &variable) {
    this->value = new bool(variable);
    this->type = Type::Bool;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const short int &variable) {
    this->value = new short int(variable);
    this->type = Type::Int16;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const unsigned short int &variable) {
    this->value = new unsigned short int(variable);
    this->type = Type::UInt16;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const int &variable) {
    this->value = new int(variable);
    this->type = Type::Int32;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const unsigned int &variable) {
    this->value = new unsigned int(variable);
    this->type = Type::UInt32;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const long long int &variable) {
    this->value = new long long int(variable);
    this->type = Type::Int64;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const unsigned long long int &variable) {
    this->value = new unsigned long long int(variable);
    this->type = Type::UInt64;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const float &variable) {
    this->value = new float(variable);
    this->type = Type::Float;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const double &variable) {
    this->value = new double(variable);
    this->type = Type::Double;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const std::string &variable) {
    this->value = new std::string(variable);
    this->type = Type::String;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const DynamicTyping::Object &variable) {
    this->value = variable.value;
    this->type = Type::Object;
    return *this;
}

bool DynamicTyping::Object::operator==(const DynamicTyping::Object &variable) {
    return (this->value == variable.value);
}

bool DynamicTyping::Object::operator!=(const DynamicTyping::Object &variable) {
    return (this->value != variable.value);
}

DynamicTyping::Type DynamicTyping::Object::GetType() {
    return this->type;
}