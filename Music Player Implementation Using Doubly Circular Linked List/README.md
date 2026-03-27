-------------------------------------------------------------------------------
# Implementation Explanation Document

## Student Information
- Full Name: Wei Wang
- Course Name: CSCI 373 - Advanced Data Structures
- Course Description: This course explores advanced data structures in C++ with 
a focus on fundamental concepts including pointers, arrays, abstract data types,
and complexity analysis. 
- Assignment Title: Music Player Implementation Using Doubly Circular Linked List
- Date: [03/23/2026]

## 1. Introduction
In this assignment, I was tasked with developing a music player in C++ that performs
adding or removing a song, playing the next or previous song, and print out all the songs 
from the list. The objectives were to use everything covered throughout the course of
the semester including classes, functions, pointers, recursions, and managing a linked list
which in this assignment is the doubly circular linked list.


## 2. Tools and Technologies Used
- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: Claude (Used for debugging and providing guidance on code implementation)

## 3. Implementation Details
### Key Components
- Classes 
    - Song: This class represents an individual song storing title and singer names 
        for other classes and have getter, setter, and << operator overload to print
        organized output.
    - DNode: This class represents a node storing Song object and pointers to neighbor nodes.
        This class also track the number of active nodes using static variable activeNodes.
    - CircleDLinkedList: This class represents linked list structure using DNode pointers
        and is the concrete implementation of doubly circular linked list. 
    - MusicPlayer: This class serves as the abstract data type for the music player. Defines
        music player functions such as play(), next(), previous(), addSong(), removeSong(), 
        using the implementation in CircleDLinkedList.
- Functions 
    Song.h:
        Song(std::string sTitle = "", std::string sName = ""): Parameterized constructor
            used to initialize the song title and singer name of each song.
        ~Song(): Destructor to free memory when Song is deleted.
        std::string getSongTitle(): Return songTitle.
        std::string getSingerName(): Return singerName.
        void setSongTitle(std::string): Modify songTitle.
        void setSingerName(std::string); Modify singerName.
        friend std::ostream& operator<<(std::ostream& os, const Song& song): operator
            << overload to print out clean string for the information in song.
    DNode.h:
        DNode(const Song&, DNode* p = nullptr, DNode* n = nullptr): Is a parameterized 
            constructor, used to initialize Song, pointers to neighbor nodes, and increase 
            increments on activeNodes.
        ~DNode(): Is the destructor for DNode constructor, called when node is destroyed.
            Also decrements on activeNodes.
    CircleDLinkedList.h:
        CircleDLinkedList(): Is a default constructor
        ~CircleDLinkedList(): Is the destructor for CircleDLinkedList constructor, called
            when the list is destroyed.
        bool empty() const: Return whether the list is empty or not.
        int size() const: Return the size of the linked list.
        void add(const Song&): Add new song after the current song and update cursor to the
            newly added song.
        void remove(): Remove a node and move cursor to next node. Maintain connections
            so all the data in the list remain in doubly circular linked list.
        void advance(): Update cursor to next node.
        void retreat(): Update cursor to previous node.
        Song getCurrentSong() const: Return element of cursor node.
        void print(bool forward = true) const: Print out the entire list either 
            in forward order or reverse order based on true or false. 
    MusicPlayer.h:
        MusicPlayer(std::string): Is a parameterized constructor, initialize the
            type of MusicPlayer.
        virtual ~MusicPlayer(): Is the destructor of MusicPlayer to free memory when
            deleted.
        void play(): Print out the current song.
        void next(): Update cursor to next song and print the song information.
        void previous(): Update cursor to previous song and print the song information.
        void addSong(const Song&): Add new song information in front of current song
            and then update cursor to the newly added song.
        void removeSong(): Remove current song from the list and update cursor to the
            next song. 
        int size() const: Return the size of the playlist.
        bool empty() const: Return whether the list is empty or not.
        Song getCurrentSong() const: Return the song information of current cursor.
        void print(bool); Print out the entire list either in forward order or 
            reverse order based on true or false. Use recursion to repeatedly print 
            the whole list until every song is printed once.

### Design Choices
Encapsulated node information within the Song and DNode class and to promote
modularity and reusability of code. CircleDLinkedList class is used to manage the doubly 
linked list. With DNode constructor being made in private, a friend class was used 
to allow access for CircleDLinkedList to prevent the nodes from being created outside of 
the list. Exception handling are implemented using <stdexcept> such as std::out_of_range
exceptions for cases such as removing element with empty list. MusicPlayer class is used 
to present a clean functions for main.cpp while most of the implementation is hidden away
under CircleDLinkedList, DNode, and Song class. 

## 4. Challenges, Solutions, and Error Report
### Technical Challenges
- Challenge 1: Implementing recursion on a doubly circular linked list.
  - Solution: Use a countdown parameter such as int remaining which allows to start at
        playlist.size() and decrementing by 1 until it reaches 0. This way recursion
        would repeat until every node in the list is printed. Also by setting printHelper()
        to private the countdown stays hidden,  while print() provides a clean 
        public interface. 

- Challenge 2: Correctly rewiring pointers in add() and remove()
  - Solution: Used temporary pointers such as tmp, pp, and pn to save neighboring node
        address before modifying anything. Handled special cases separately such as
        empty list for add() and single node for remove(). 

### Error Report
- Common Errors Encountered:
  - Error 1: Invalid syntax for creating nodes in CricleDLinkedList::add().
    - Cause: The parameter was declared as const Song& with no name, so the Song object
        could not be referenced inside the function.
    - Solution: Add variable s after Song& in parameter, replace Song& with s in 
        the functions.
  
  - Error 2: Invalid syntax by return cursor->next != nullptr for empty().
    - Cause: When the list is empty cursor is nullptr, so cursor->next immediately crashes.
        When list is not empty, the circular list does not have nullptr so the condition
        would never correctly detect an empty list.
    - Solution: Replaced with return n==0, which uses the node counter.

## 5. Testing Strategy
### Verification Methods
The program was tested using predefined value without user input. After adding 3 
songs, the play(), next(), previous(), print(true) and print(false) were called 
to verify that the cursor was pointing to the correct song and that the list traversed 
in the correct order both forward and backward. Additional testing was conducted by 
removing the current song and calling next() 3 times to confirm the remaining songs
stayed properly linked after deletion. The playlist was printed after each major operation
to manually verify the output matched the expected result.

## 6. Conclusion
This project tested my ability to think carefully and methodically, as many mistakes from
my first submission became clear when reviewing it more carefully. This assignment deepened
my understanding of the doubly circular linked list and how encapsulation works in practice.
Concrete implementation such as Song, DNode, and CircleDLinkedList are hidden from the 
user, while the abstract data type layer such as MusicPlayer presents a clean and functional 
interface for the user. While having some trouble with implementing recursion, the subject
became clearer for me in how recursion works.
 

## 7. References
- https://www.jjay-csci373.org/course-materials/lesson-4/lesson-4
- https://github.com/maksikutrolli/Data-Structures-in-Cpp/tree/main/Linked%20List/Generic%20Singly%20Linked%20List

-------------------------------------------------------------------------------
