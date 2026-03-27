//Fraction.h

#include <iostream>

class Fraction {
    private:
        int numerator;
        int denominator;
    
    public:
        Fraction(); // (Default constructor)
        Fraction(int num, int denom); // (Parameterized constructor)
        Fraction(const Fraction& other); // (Copy constructor)
        int getNumerator() const; // (Getter for the numerator)
        int getDenominator() const; // (Getter for the denominator)
        void setNumerator(int num); // (Setter for the numerator)
        void setDenominator(int denom); // (Setter for the denominator)
        
        // Overload the arithmetic operators +, -, *, and / to perform operations with Fraction objects.
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        
        void print() const; // (Method to display the fraction)
        void simplify(); // (Method to reduce the fraction to its simplest form)
};
