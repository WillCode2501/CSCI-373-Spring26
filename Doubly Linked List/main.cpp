//main.cpp

#include "DLinkedList.h"

int DNode::activeNodes = 0;

int main() {

    // Create an instance of DLinkedList.
    DLinkedList D1;
    
    // Add 3 elements to the front of the list.
    D1.addFront(6);
    D1.addFront(5214);
    D1.addFront(263);
    
    // Add 2 elements to the back of the list.
    D1.addBack(431);
    D1.addBack(7833);
    
    // Traverse the list from head and print elements.
    D1.print(true);
    
    // Traverse the list from trailer and print elements in reverse order.
    D1.print(false);
    
    // Remove one element from the front and one from the back.
    D1.removeFront();
    D1.removeBack();
    
    // Print the list again after removals.
    D1.print(true);
    
    // Add another element to the front and one to the back.
    D1.addFront(35);
    D1.addBack(53);
    
    // Print the list after all operations.
    D1.print(true);
    
    
    return 0;
}
