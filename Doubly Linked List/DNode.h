//DNode.h

class DLinkedList;

class DNode {
    private:
        int elem; // Element stored in the node
        DNode* prev; // Pointer to the previous node
        DNode* next; // Pointer to the next node
    public:
        // Static variable to track the number of active nodes
        static int activeNodes;
    private:
        // Inside the constructor, increment activeNodes by one 
        // whenever a node is created
        DNode(int e = 0, DNode* p = nullptr, DNode* n = nullptr) {
            elem = e;
            prev = p;
            next = n;
            activeNodes++;
        }
        
        friend class DLinkedList;
        
    public:
        // Inside the destructor, decrement activeNodes by one 
        // whenever a node is destroyed
        ~DNode() {
            activeNodes--;
        }

};
