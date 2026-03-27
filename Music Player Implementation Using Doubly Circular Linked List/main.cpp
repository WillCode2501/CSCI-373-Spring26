//main.cpp

#include "MusicPlayer.h"

int DNode::activeNodes = 0;

int main() {
    // - **Initialization**: 
    //   - Create a MusicPlayer instance initialized 
    MusicPlayer m1("Music Player M4"); 
    //   - Add 3 songs 
    m1.addSong(Song("Rude Boy", "Rihanna")); // Name this 1
    m1.addSong(Song("Just the Way You are", "Bruno Mars")); // Name this 2
    m1.addSong(Song("God's Plan", "Drake")); // Name this 3 
    // 1 -> 2 -> 3 -> 1 ..., cursor on 3 (newest added)

    // - **Initial Playback**: 
    //   - Play Current Song: Start by playing the current song (call play()) in the playlist.
    m1.play();
    // Next Songs Playback: Play the next song three times (call next() three times), 
    // showing ability to move forward in the playlist.
    m1.next();
    m1.next();
    m1.next();
    // Previous Song Playback: Play the previous song (call previous()), showing ability to 
    // navigate backward.
    m1.previous();

    // **Playlist Review**: 
    // Print Forward: Use the print(true) method to list all songs from the 
    // current position forward.
    m1.print(true);
    // Print Reverse: Use the print(false) method to list all songs in reverse 
    // order, demonstrating the doubly circular list's bidirectional traversal.
    m1.print(false);

    // **Modifying the Playlist**:
    // Remove Current Song: Remove the song currently being played (call removeSong())
    // from the playlist.
    m1.removeSong();
    // After removal, continue playback to show how the list updates:
    // Play Current Song: Play the new current song (call play()) in the playlist.
    m1.play();
    // Next Songs Playback: Play the next song three times (call next() three times)
    // to show how the playlist works after removal.
    m1.next();
    m1.next();
    m1.next();

    // **Final Playlist Review**: 
    // Final Print Forward: Use the print(true) method to display the updated 
    // list of songs from the current position forward.
    m1.print(true);
    // Final Print Reverse: Use the print(false) method to display the songs in 
    // reverse order, showing the final playlist state.
    m1.print(false);


    
    return 0;
}
