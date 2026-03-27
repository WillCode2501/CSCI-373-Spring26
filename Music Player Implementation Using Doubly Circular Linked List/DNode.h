//DNode.h

#include "Song.h"

class CircleDLinkedList;

class DNode {
    private:
        Song elem;
        DNode * next; 
        DNode * prev;
        
        // Constructor increments activeNodes
        DNode(const Song& s, DNode* p = nullptr, DNode* n = nullptr) {
            elem = s;
            prev = p;
            next = n;
            activeNodes++;
        }
        
    public:
        // Static variable to track the number of active 
        static int activeNodes;
        
        // destuctor is empty except activeNode because only store elem
        // next and prev pointer belongs to CircleDLinkedList
        ~DNode() {
            activeNodes--;
        }
        
        friend class CircleDLinkedList;
        
};
    
