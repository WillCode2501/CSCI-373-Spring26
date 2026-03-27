//Fraction.cpp

#include "Fraction.h"

// (Default constructor)
Fraction::Fraction() { // O(1)
    numerator = 0; // O(1)
    denominator = 1; // cannot divide by 0, setting it to 1 as default, // O(1)
}

// (Parameterized constructor)
Fraction::Fraction(int num, int denom) {  // O(log n)
    numerator = num; // O(1)
    denominator = denom; // O(1)
    
    simplify(); // O(log n)
} 

// (Copy constructor)
Fraction::Fraction(const Fraction& other) { // O(1)
    numerator = other.numerator; // O(1)
    denominator = other.denominator; // O(1)
}

 // (Getter for the numerator)
int Fraction::getNumerator() const { // O(1)
    return numerator; // O(1)
}

// (Getter for the denominator)
int Fraction::getDenominator() const { // O(1)
    return denominator; // O(1)
}

// (Setter for the numerator)
void Fraction::setNumerator(int num) { // O(1)
    numerator = num; // O(1)
} 

// (Setter for the denominator)
void Fraction::setDenominator(int denom) { // O(1)
    denominator = denom; // O(1)
}

// Overload the arithmetic operators +, -, *, and / to perform operations with Fraction objects.
Fraction Fraction::operator+(const Fraction& other) const { // O(log n)
    int num = numerator * other.denominator + denominator * other.numerator; // O(1)
    int den = denominator * other.denominator; // O(1)
    return Fraction(num, den); // O(log n)
}
Fraction Fraction::operator-(const Fraction& other) const { // O(log n)
    int num = numerator * other.denominator - denominator * other.numerator; // O(1)
    int den = denominator * other.denominator; // O(1)
    return Fraction(num, den); // O(log n)
}
Fraction Fraction::operator*(const Fraction& other) const { // O(log n)
    int num = numerator * other.numerator; // O(1)
    int den = denominator * other.denominator; // O(1)
    return Fraction(num, den); // O(log n))
}
Fraction Fraction::operator/(const Fraction& other) const { // O(log n)
    int num = numerator * other.denominator; // O(1)
    int den = denominator * other.numerator; // O(1)
    return Fraction(num, den); // O(log n)
}

// (Method to display the fraction)
void Fraction::print() const { // O(1)
    std::cout << numerator << "/" << denominator << std::endl;
}

// (Method to reduce the fraction to its simplest form)
void Fraction::simplify() { // O(log n)
    int a = numerator; // O(1)
    int b = denominator; // O(1)
    if (a < 0) a = -a; // O(1)
    if (b < 0) b = -b; // O(1)
    
    // example 8/12 
    // a = 8, b = 12
    // r = 8, a = 12, b = 8
    // r = 4, a = 8, b = 4
    // r = 0, a = 4, b = 0
    // a = 4 
    while (b !=0) { // O(log n)
        int r = a % b;
        a = b;
        b = r;
    }
    
    // example 8/12
    // a = 4
    // 8 / 4 = 2 
    // 12 / 4 = 3 
    // result: 2/3
    numerator /= a; // O(1)
    denominator /= a; // O(1)
    
    // Turn a/-b to -a/b
    if (denominator < 0) { // O(1)
        numerator = -numerator; // O(1)
        denominator = -denominator; // O(1)
    }
}
