//MusicPlayer.h

#include "CircleDLinkedList.h"

class MusicPlayer{
    private:
        std::string type;             // Type of music player
        CircleDLinkedList playlist;   // Doubly circular linked list of songs
    
    public:
        MusicPlayer(std::string type) {   // Constructor
            this->type = type;
        }
        
        virtual ~MusicPlayer() {      // Destructor, empty because playlist is member object, not a pointer
        }
        // virtual in case creating derived class like PremiumPlayer
        // help delete the derived class to prevent memory leak
        
        void play() {                 // Plays the current song (prints the song details)
            if (empty()) {
                std::cout << "Playlist is empty" << std::endl;
                return;
            }
            std::cout << "Playing: " << playlist.getCurrentSong() << std::endl;
        }
        
        void next() {                 // Moves to the next song and plays it
            if (empty()) {
                std::cout << "Playlist is empty" << std::endl;
                return;
            }
            playlist.advance();
            play();
        }
        
        void previous() {             // Moves to the previous song and plays it
            if (empty()) {
                std::cout << "Playlist is empty" << std::endl;
                return;
            }
            playlist.retreat();
            play();
        }
    
        void addSong(const Song& s) {   // Adds a song after the current song
            playlist.add(s);
        }
        
        void removeSong() {           // Removes the current song
            playlist.remove();
        }
        
        int size() const {            // Returns current number of songs
            return playlist.size();
        }
        
        bool empty() const {          // Checks if the music player is empty
            return playlist.empty();
        }
        
        Song getCurrentSong() const {  // Returns the current song
            return playlist.getCurrentSong();
        }
    // Prints playlist from current song (true = forward, false = reverse,  recursive)
    //Should be implemented as an recursive function
    private:
        void printHelper(bool forward, int remaining) {
            if (remaining == 0) 
                return;
            int index = playlist.size() - remaining + 1; // list the numbers
            std::cout << index << ") "<<playlist.getCurrentSong() << std::endl;
            if (forward)
                playlist.advance();
            else
                playlist.retreat();
            printHelper(forward, remaining-1);
        }
        
    public:
        void print(bool forward) {    
            if (empty())
                return;
            printHelper(forward, playlist.size());
        }
};
    
  
