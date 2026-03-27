//Integer.h

class Integer{
    private:
        int value;
    public: 
        Integer(); // (Default constructor)
        Integer(int val); // (Parameterized constructor)
        int getValue() const; // (Getter for the value)
        void setValue(int val); // (Setter for the value)
        
        // Overload the arithmetic operators +, -, *, and / to perform operations with Integer objects.
        Integer operator+(const Integer& other) const;
        Integer operator-(const Integer& other) const;
        Integer operator*(const Integer& other) const;
        Integer operator/(const Integer& other) const;
        
};
