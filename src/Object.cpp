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
    this->value = nullptr;
    this->type = Type::Null;
}

DynamicTyping::Object::Object(std::nullptr_t value) {
    this->value = nullptr;
    this->type = Type::Null;
}

DynamicTyping::Object::Object(char value) {
    this->value = new char(value);
    this->type = Type::Char;
}

DynamicTyping::Object::Object(char *value) {
    this->value = new std::string(value);
    this->type = Type::StringLiteral;
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

DynamicTyping::Object DynamicTyping::Object::operator=(const std::nullptr_t &variable) {
    this->value = nullptr;
    this->type = Type::Null;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const char &variable) {
    this->value = new char(variable);
    this->type = Type::Char;
    return *this;
}

DynamicTyping::Object DynamicTyping::Object::operator=(const char *variable) {
    this->value = new std::string(variable);
    this->type = Type::StringLiteral;
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

std::string DynamicTyping::Object::ToString() {
    if (this->type == Type::Char) {
        char temp = *(char*)this->value;
        return std::string(1, temp);
    }
    else if (this->type == Type::Bool) {
        bool temp = *(bool*)this->value;
        if (temp == 0) {
            return std::string("false");
        }
        return std::string("true");
    }
    else if (this->type == Type::Int16) {
        short int temp = *(short int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::UInt16) {
        unsigned short int temp = *(unsigned short int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::Int32) {
        int temp = *(int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::UInt32) {
        unsigned int temp = *(unsigned int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::Int64) {
        long long int temp = *(long long int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::UInt64) {
        unsigned long long int temp = *(unsigned long long int*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::Float) {
        float temp = *(float*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::Double) {
        double temp = *(double*)this->value;
        return std::to_string(temp);
    }
    else if (this->type == Type::String || this->type == Type::StringLiteral) {
        std::string temp = *(std::string*)this->value;
        return temp;
    } 
    else if (this->type == Type::Object) {
        std::string temp = "Object";
        return temp;
    }
    else if (this->type == Type::Other) {
        std::string temp = this->deep_type;
        return temp;
    }
    else if (this->type == Type::Null) {
        throw std::runtime_error("Object doesn't reference any variable of any type");
    }
}

std::string DynamicTyping::Object::GetDeepType() {
    return this->deep_type;
}