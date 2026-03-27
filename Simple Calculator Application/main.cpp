//main.cpp

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "Integer.h"

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Implement a loop that repeats the calculation process 10 times.
    for (int i = 0; i < 10; ++i) {
        // Inside this loop, generate random integers 
        // and perform calculations
        
        // Generate two random numbers between 1 and 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;

        // Create two Integer objects using the randomly generated numbers.
        Integer int1(num1);
        Integer int2(num2);

        /* Generate a random integer between 0 and 3 to randomly select 
        an arithmetic operation (+, -, *, /). Use a switch statement 
        to map the number to an operation.*/
        int randomOperation = rand() % 4;
        char operation;
        switch (randomOperation) {
            case 0: operation = '+'; break;
            case 1: operation = '-'; break;
            case 2: operation = '*'; break;
            case 3: operation = '/'; break;
        }
        
        /* Use another switch statement to perform the selected operation 
        using the overloaded operators from the Integer class. For division, 
        make sure to handle division by zero by checking if the second 
        integer is not zero.*/
        switch (operation) {
            case '+':
                std::cout << int1.getValue() << " + " << int2.getValue() 
                    << " = " << (int1 + int2).getValue() << std::endl;
                break;
            case '-':
                std::cout << int1.getValue() << " - " << int2.getValue() 
                    << " = " << (int1 - int2).getValue() << std::endl;
                break;
            case '*':
                std::cout << int1.getValue() << " * " << int2.getValue() 
                    << " = " << (int1 * int2).getValue() << std::endl;
                break;
            case '/':
                if (int2.getValue() != 0) {
                    std::cout << int1.getValue() << " / " << int2.getValue() 
                        << " = " << (int1 / int2).getValue() << std::endl;
                } else {
                    std::cout << "Division by zero is not allowed." << std::endl;
                }
                break;
        }
    }

    return 0;
}
