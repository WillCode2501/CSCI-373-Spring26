//main.cpp

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "Fraction.h"

int main() {
    // Initialize Random Number Generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Loop for Repeated Calculations
    for (int i = 0; i < 10; ++i) {
        
        // Generate Random Fractions
        int num1 = rand() % 15 + 1;
        int den1 = rand() % 15 + 1;
        int num2 = rand() % 15 + 1;
        int den2 = rand() % 15 + 1;
    
        // Create Fraction Objects
        Fraction frac1(num1, den1);
        Fraction frac2(num2, den2);
        std::cout<< num1 << "/" << den1 << " " << num2 << "/" << den2 << std::endl;
        
        // Randomly Select an Operation
        int randomOperation = rand() % 4;
        char operation;
        switch (randomOperation) {
            case 0: operation = '+'; break;
            case 1: operation = '-'; break;
            case 2: operation = '*'; break;
            case 3: operation = '/'; break;
        }
        std::cout << operation << std::endl;
        
        // Perform the Operation
        switch (operation) {
            case '+':
                (frac1 + frac2).print();
                break;
            case '-':
                (frac1 - frac2).print();
                break;
            case '*':
                (frac1 * frac2).print();
                break;
            case '/':
                // num2 cannot be zero when dividing fractions
                if (frac2.getNumerator() != 0) {
                    (frac1 / frac2).print();
                } else {
                    std::cout << "Division by zero is not allowed." << std::endl;
                }
                break;
        }
    }
    
    return 0;
}
