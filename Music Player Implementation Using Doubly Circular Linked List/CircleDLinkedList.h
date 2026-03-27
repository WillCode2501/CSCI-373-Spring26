//CircleDLinkedList.h

#include <iostream>
#include "DNode.h"
#include <stdexcept>

class CircleDLinkedList {
    private:
        DNode* cursor; // Pointer to the current song
        int n; // Current number of songs
        
    public:
        CircleDLinkedList() {     // Constructor
            cursor = nullptr;
            n = 0;
        }
        
        ~CircleDLinkedList() {    // Destructor 
            while (!empty()) {
                remove();
            }
        }
        
        bool empty() const {      // Checks if the list is empty
            return n == 0;
        }
        
        int size() const {        // Returns current number of nodes
            return n;
        }
                      
                
        void add(const Song& s) {   // Adds a song after the current song, and updates cursor to point to the new song
            DNode* newNode = new DNode(s);
            if(empty()) {  // first node, points to itself
                newNode->next = newNode;
                newNode->prev = newNode;
                cursor = newNode;
            } else { // insert newNode after cursor
                DNode* tmp = cursor->next; // c <-> tmp
                newNode->next = tmp; // nN -> tmp
                newNode->prev = cursor; // c <- nN -> tmp
                cursor->next = newNode; // c <-> nN -> tmp
                tmp->prev = newNode; // c <-> nN <-> tmp
                cursor = newNode; 
            }
            n++;
        }
                                                                                 
        void remove() {     // Removes the current song, and updates cursor to point to next song
            if(empty()) {
                throw std::out_of_range("List is empty, cannot remove");
            }
            DNode* p = cursor;
            if (n==1) { // delete last node
                cursor = nullptr; 
            } else {
                DNode* pp = p->prev; // pp <-> p
                DNode* pn = p->next; // pp <-> p <-> pn
                pp->next = pn; // pp -> pn
                pn->prev = pp; // pp <-> pn
                cursor = pn; // pp <-> cursor
            }
            delete p; 
            n--; 
        }
        
        void advance() {          // Moves to the next song
            cursor = cursor->next;
        }
        
        void retreat() {          // Moves to the previous song
            cursor = cursor->prev;
        }   
        
        Song getCurrentSong() const {  // Returns the current song
            return cursor->elem;
        }
        
        // Prints all songs in list starting from current position (forward or reverse)
        void print(bool forward = true) const {
            DNode * p = cursor; // start from beginning
            for(int i=1; i <= n; i++) {
                std::cout << i << ") Song Title: " << p->elem << std::endl;
                p = forward ? p->next : p->prev;
            }
        }
};
