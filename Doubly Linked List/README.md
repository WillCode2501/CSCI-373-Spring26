-------------------------------------------------------------------------------
# Implementation Explanation Document

## Student Information
- Full Name: Wei Wang
- Course Name: CSCI 373 - Advanced Data Structures
- Course Description: This course explores advanced data structures in C++ with 
a focus on fundamental concepts including pointers, arrays, abstract data types,
and complexity analysis.
- Assignment Title: Doubly Linked List Implementation
- Date: [03/22/2026]

## 1. Introduction
In this assignment, I was tasked with developing a doubly linked list in C++ that 
supports adding and removing nodes both in front and back, printing the list in froward 
and reverse order, and tracking the count of nodes for verify correct memory management. 
The objectives were not only to practice designing classes and implmenting pointer-based 
data structures but also to align this application with the broader course goals of 
understanding object-oriented programming techniques and their practical applications.

## 2. Tools and Technologies Used
- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: Claude AI (Used for debugging codes)

## 3. Implementation Details
### Key Components
- Classes:
    - DNode: This class represent a single node, storing the node's element and 
        pointers for next and previous nodes. It also tracks the total number of 
        active nodes using a static variable.
    - DLinkedList: This class mananges the doubly linked list, it maintain pointers
        to head and trailer nodes allowing for add and remove from both ends of the list.
        This class helps manipulating the list and printing them in forward or reverse order.
- Functions:
    - DNode(int e = 0, DNode* p = nullptr, DNode* n = nullptr): Is a parameterized 
        constructor, used to initialize elem, pointers to neighbor nodes, and increase 
        increments on activeNodes.
    - ~DNode(): Is the destructor for DNode constructor, called when node is destroyed.
        Also decrements on activeNodes.
    - DLinkedList(): Is the default constructor, initialize head, trailer, and size in the list.
    - ~DLinkedList(): Is the destructor to free allocated memory when deleting the list.
    - bool empty() const: Return if the list is empty or not.
    - const int& front() const: Return the element stored at head.
    - const int& back() const: Return the element stored at trailer.
    - void addFront(const int& e): Insert element at the front of the list and become
        the new head of the list.
    - void addBack(const int& e): Insert element at the back of the list and become
        the new trailer of the list.
    - void removeFront(): Remove the front node and properly connect the list.
    - void removeBack(): Remove the back node and properly connect the list.
    - void print(bool front = true) const: Traverses the list from both directions
        based on the bool and print each elements.
    - int size() const: Return the current element count in the list.
    - int activeNodeCount() const: Return the DNode::activeNodes.

### Design Choices
Encapsulated node information within the DNode class and to promote
modularity and reusability of code. DlinkedList class is used to manage the doubly 
linked list. With DNode constructor being made in private, a friend class was used 
to allow access for DLinkedList to prevent the nodes from being created outside of 
the list. Exception handling are implemented using <stdexcept> such as std::out_of_range
exceptions for cases such as removing element with empty list.

## 4. Challenges, Solutions, and Error Report
### Technical Challenges
- Challenge 1: Implementating doubly linked list without sentinel nodes
  - Solution: Functions needs to include check for empty list and single node case 
    since a new node becomes both head and trailer.
- Challenge 2: Implementating the print() correctly.
  - Solution: Function uses print(bool front = true) const, so paramater front must be used.
    Utilized the ternary operator to set DNode* p = front ? head : trailer, so when
    print(true) is called, it will print from the front of the list., and print(false) 
    will print from the back of the list.

### Error Report
- Common Errors Encountered:
  - Error 1: Logic error with print() function in DLinkedList.h
    - Cause: Used for(int i=0; i<n; i++), ignoring front parameter and leaving out 
        the reverse print function.
    - Solution: Used while loop to print until it reaches nullptr, which is the end 
        in both order. Also used ternary operator to determine if list get print 
        from the front or from the back.
  
  - Error 2: Missing for 1 node case during node removal.
    - Cause: For remove functions, did not include case for 1 node in list, which 
        treat it with same modification as multiple nodes in the list.
    - Solution: Create a case where n==1, set both head and trailer to nullptr, and 
        include the creation of temporary node outside the if statement so it applies
        to both 1 node case and multiple node case.

## 5. Testing Strategy
### Verification Methods
The program was tested using predefined value without user input. After adding 3 
elements to the front and 2 to the back, the print(true) and print(false) were called 
to verify the list order and the elements stored. More trials were conducted by removing
and adding elements both in front and back of the list and printing each session to 
manually review if the list is accurate as what is input.

## 6. Conclusion
This assignment was a great practice in helping understand doubly linked list, 
especially the challenge of implementing it without sentinel nodes as taught in class.
Removing the dummy nodes, I had to be mindful with handling empty list and single node cases. 
The static variable activeNodes was also new for me, now I know it's used to verify that 
the number of active nodes matches the number of elements in the list to ensure destructor
was utilized correctly. The print() function of printing in reverse order had me to 
think a bit as I tried to implement a for loop using int n, number of elements in
the list, instead of using while loop.

## 7. References
- https://www.jjay-csci373.org/course-materials/lesson-4/lesson-4
- https://github.com/maksikutrolli/Data-Structures-in-Cpp/tree/main/Linked%20List/Generic%20Singly%20Linked%20List

-------------------------------------------------------------------------------
