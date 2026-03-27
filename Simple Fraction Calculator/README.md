-------------------------------------------------------------------------------
# Implementation Explanation Document

## Student Information
- Full Name: Wei Wang
- Course Name: CSCI 373 - Advanced Data Structures
- Course Description: This course explores advanced data structures in C++ with 
a focus on fundamental concepts including pointers, arrays, abstract data types,
and complexity analysis.
- Assignment Title: Simple Fraction Calculator Application
- Date: [02/17/2026]

## 1. Introduction
In this assignment, I was tasked with developing a Simple Fraction Calculator Application
in C++ that performs basic arithmetic operations (addition, subtraction,
multiplication, and division) on two fraction values. The objectives were not only
to practice using classes and functions but also to align this application with
the broader course goals of understanding object-oriented programming techniques
and their practical applications. This project helps me build my technical skills
and knowledge by applying them in real-life examples.

## 2. Tools and Technologies Used
- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: [ChatGPT (Used for providing guidance on code implementation)]

## 3. Implementation Details
### Key Components
- Classes 
    - Fraction: This class private numerator and denominator, getter and setter to read and 
        modify those values as well as operator overloading to handles all arithmetic operations 
        for fractions as well as simplify and print the fraction in a readable format.
        It contains methods for addition, subtraction, multiplication, and division.
- Functions
    - Fraction() is the default constructor, set the numerator to 0 and denominator
        to 1 because cannot divide by 0.
    - Fraction(int num, int denom) is the parameterized constructor, set num to numerator
        and denom to denominator.
    - Fraction(const Fraction& other) is the copy constructor, set other.numerator to 
        numerator and other.denominator to denominator.
    - int getNumerator() const is the getter to view numerator in private.
    - int getDenominator() const is the getter to view denominator in private.
    - void setNumerator(int num) is the setter to modify value of numerator.
    - void setDenominator(int denom) is the setter to modify value of denominator.
    - Fraction operator+(const Fraction& other) const is the operator overload
        and help add fraction with other fraction.
    - Fraction operator-(const Fraction& other) const is the operator overload
        and help subtract fraction with other fraction.
    - Fraction operator*(const Fraction& other) const is the operator overload
        and help multiply fraction with other fraction.
    - Fraction operator/(const Fraction& other) const is the operator overload
        and help divide fraction with other fraction.
    - void print() const is used to view the result after arithmetic operations.
    - void simplify() is to simply fraction into a more easier readable format.
- Algorithm 
    - Euclidean Algorithm is used to find the greatest common divisor of the 
        numerator and denominator to help with simplify fraction.

### Design Choices
Encapsulated arithmetic operations within the Fraction class to promote
modularity and reusability of code. Each operation is easily modified or
extended without affecting other parts of the program. Methods are kept simple
to focus on their primary task, and error handling is minimal, given the scope
of the assignment.


## 4. Challenges, Solutions, and Error Report
### Technical Challenges
- Challenge 1: Proper implementation of simplify function
  - Solution: Add the simplify function into the parameterized constructor so 
                everytime when the arithmetic operation operator overload return 
                the parameterized constructor, the simplify() will also be called.

- Challenge 2: Correctly simplify the fractions into its lowest form
  - Solution: Implementing the Euclidean Algorithm to compute the greatest common 
                divisor of the numerator and denominator and divide the gcd with 
                the numerator and denominator to ensure proper simplification.

### Error Report
- Common Errors Encountered:
  - Error 1: Invalid use of void with implementing simplify().
    - Cause: Attempting to print result as ((frac1 + frac2).simplify()).print()
    - Solution: Added simplify() into parameterized constructor so when 
                (frac1 + frac2) is called, the operator+ overload would called 
                the parameterized constuctor and simplify() inside it as well.

## 5. Testing Strategy
### Verification Methods
- Test Case 1: Manually tested the operator+ overload with different fraction pairs,
               using numbers between 1 and 15 inclusive to confirm correct result.
  - Example: `frac1(2, 3)+frac2(3,5)' returned '19/15' which is correct.
- Test Case 2: Manually tested the operator/ overload with different fraction pairs,
               including scenarios where the second numerator is zero, to
               confirm that the error handling works as expected.
  - Example: 'frac1(4,5)/frac2(0,9)' threw an exception:
             "Error: Division by zero is not allowed."
- Test Case 3: Manually tested the operator- overload using both positive
               and negative fractions to confirm correct behavior.
  - Example: 'frac1(15,1)-frac2(-6,3)' returned '17/1' which is correct.
- Test Case 4: Manually tested the operator* overload with pairs of fractions
               to ensure correct multiplication results.
  - Example: 'frac1(9,12)*frac2(5,8)' returned '15/32' which is correct.

## 6. Conclusion
This assignment is similar to assignment1 with the calculation with integer except
this one is more tricky especially with the addition of simplify function. This exercise 
reinforced my understanding of how classes, functions, and operator overload can 
can be utilized to create simple yet effective programs while the simplify function
help me learn more about proper way of implementing functions. Handling basic error like 
division by zero was like a trap given in the code example because when dividing 
with fractions instead of doing exception for the denominator, the exception is 
supposed to be for the second numerator. This assignment taught me more on how to
do proper implementation of classes, functions, operator overloads, and exception
handling that could apply for my future projects.

## 7. References
- Reference 1: https: www.jjay-csci272.org/course-materials/lesson-9

-------------------------------------------------------------------------------
