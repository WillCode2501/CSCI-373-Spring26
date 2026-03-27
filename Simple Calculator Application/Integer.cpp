//Integer.cpp

// Time Complexity of O(1), constant
#include "Integer.h"

// Default constructor
Integer::Integer() { //O(1)
    value = 0;
}

// Parameterized constructor
Integer::Integer(int val) { //O(1)
    value = val;
}

// Getter for the value
int Integer::getValue() const { //O(1)
    return value;
}

// Setter for the value
void Integer::setValue(int val) { //O(1)
    value = val;
}

// Operator overloads
Integer Integer::operator+(const Integer& other) const { //O(1)
    return Integer(value + other.value);
}

Integer Integer::operator-(const Integer& other) const { //O(1)
    return Integer(value - other.value);
}

Integer Integer::operator*(const Integer& other) const { //O(1)
    return Integer(value * other.value);
}

Integer Integer::operator/(const Integer& other) const { //O(1)
    return Integer(value / other.value);
}

