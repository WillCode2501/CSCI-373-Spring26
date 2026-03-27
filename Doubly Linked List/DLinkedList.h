//DLinkedList.h

#include <iostream>
#include "DNode.h"
#include <stdexcept>

class DLinkedList {
    private:
        DNode* head; // Pointer to the first node
        DNode* trailer; // Pointer to the last node
        int n; // Stores the current number of elements in the list
    public:
        // Constructor
        DLinkedList(): head(nullptr), trailer(nullptr), n(0) {}
        
        // Destructor
        ~DLinkedList(){
            while(!empty()) 
                removeFront();
        }
        
        // Check if the list is empty
        bool empty() const {
            return head == nullptr;
        }
        
        // Get front element
        const int& front() const {
            return head->elem;
        }
        
        // Get back element
        const int& back() const{
            return trailer->elem;
            
        }
        
    public:
        // Add to the front of the list
        void addFront(const int& e) {
            DNode* newNode = new DNode(e);
            if(empty()) {
                head = newNode;
                trailer = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            n++;
        }
        
        // Add to the back of the list
        void addBack(const int& e) {
            DNode* newNode = new DNode(e);
            if(empty()) {
                head = newNode;
                trailer = newNode;
            } else {
                trailer->next = newNode;
                newNode->prev = trailer;
                trailer = newNode;
            }
            n++;
        }
        
        // Remove front item from the list
        void removeFront() {
            if(empty()) // empty
                throw std::out_of_range("List is empty, cannot remove");
            DNode* tmp = head;
            if(n==1) { // 1 node
                head = nullptr;
                trailer = nullptr;
            } else { // multiple nodes
                head = head->next;      
                head->prev = nullptr;
            }
            delete tmp;
            n--;
        }
        
        // Remove back item from the list
        void removeBack() {
            if(empty())
                throw std::out_of_range("List is empty, cannot remove");
            DNode* tmp = trailer;
            if(n==1) {
                head = nullptr;
                trailer = nullptr;
            } else { 
                trailer = trailer->prev;
                trailer->next = nullptr;
            }
            delete tmp;
            n--;
        }
        
        // Print the list starting from the head when the parameter front value is true,
        // and prints starting from the trailer when the parameter front value is false. 
        void print(bool front = true) const {
            if(empty()) 
                throw std::out_of_range("List is empty, nothing to print");
            DNode* p = front ? head:trailer; // if true p=head, if false p=trailer
            while(p != nullptr) {
                std::cout<< p->elem <<" -> ";
                p = front ? p->next : p->prev; // if true move forward, if false move backward.
            } std::cout << "nullptr"<<std::endl;
        }
        
        // Returns the current number of elements in the list
        int size() const {
            return n;
        }
        
        // Return the count of active DNodes
        int activeNodeCount() const {
            return DNode::activeNodes;
        }

};
