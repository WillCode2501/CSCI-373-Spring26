-------------------------------------------------------------------------------
# Implementation Explanation Document

## Student Information
- Full Name: Wei Wang
- Course Name: CSCI 373 - Advanced Data Structures
- Course Description: This course explores advanced data structures in C++ with 
a focus on fundamental concepts including pointers, arrays, abstract data types,
and complexity analysis. 
- Assignment Title: Simple Calculator Application
- Date: [02/08/2026]

## 1. Introduction
In this assignment, I was tasked with developing a Integer Calculator with 
Operator Overloading in C++ that performs basic arithmetic operations (addition,
subtraction, multiplication, and division) on two integer values. The objectives 
were not only to practice using classes and functions but also to apply the use 
of operator overloading to align this application with the broader course goals 
of understanding object-oriented programming techniques and their practical 
applications. This project helps me build my technical skills and knowledge by 
applying them in real-life examples.

## 2. Tools and Technologies Used
- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: Website using https://www.jjay-csci272.org/course-materials/lesson-9
- Tool 3: ChatGPT

## 3. Implementation Details
### Key Components
- Classes 
    - Integer: This class private value, getter and setter to read and modify the 
        value as well as operator overloading to handles all arithmetic operations. 
        It contains methods for addition, subtraction, multiplication, and division.
- Functions
    - Integer(): is the default constructor, set the value to 0.
    - Integer(int val): is the parameterized constructor, set value to val.
    - int getValue() const: is the getter to view the value in private
    - void setValue(int val): is the setter, updates the value in private
    - Integer operator+(const Integer& other) const: is the operator overload
        and help add value with other value.
    - Integer operator-(const Integer& other) const: is the operator overload
        and help subtract value with other value.
    - Integer operator*(const Integer& other) const: is the operator overload
        and help multiply value with other value.
    - Integer operator/(const Integer& other) const: is the operator overload
        and help divide value with other value. 

### Design Choices
Used 3 separate files for header, header implementation, and main.cpp to keep codes
organized. Encapsulated the value as private to prevent modification from outside 
the class, can only be accessed through data members such as getter and setter. 
Used operator overloading to return arithmetic operation results to make the code
more natural and readable. Two switch statements are used to make the code clean
and organized rather than mutliple if-else statements.

## 4. Challenges, Solutions, and Error Report
### Technical Challenges
- No Challenge encountered

### Error Report
- No Error encountered

## 5. Testing Strategy
### Verification Methods
Manually run the programs multiple times to see if the result match the requirements
of the assignments or if it throw out any exceptions or errors.

## 6. Conclusion
This assignment allowed me more practice and more self-taught of how to implement 
operator overloading through reviewing CSCI-272 Lesson 9 slides again and using
ChatGPT to help explain the design choice of this assignment. While most of the 
codes are already given in Assignment.mk, it still help me review again why we 
use operator overloading ot make code more natural and readable.

## 7. References
- Reference 1: https://www.jjay-csci272.org/course-materials/lesson-9/lesson-9

-------------------------------------------------------------------------------
