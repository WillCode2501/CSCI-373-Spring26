//Song.h

class Song {
    private:
        std::string songTitle;
        std::string singerName;
        
    public:
        // Constructor
        Song(std::string sTitle = "", std::string sName = "") {
            songTitle=sTitle;
            singerName=sName;
        }
        
        // Destructor is empty because no printer, only stored strings.
        ~Song() {
            
        }
        
        // Returns the song title
        std::string getSongTitle() {
            return songTitle;
        }
        
        // Returns the singer name
        std::string getSingerName() {
            return singerName;
        }
        
        // Sets the song title
        void setSongTitle(std::string songTitle) {
            this->songTitle = songTitle;
        }
        
        // Sets the singer name
        void setSingerName(std::string singerName) {
            this->singerName = singerName;
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Song& song) {
            os<< "{"<<song.songTitle<< " ; "<< song.singerName << "}";
            return os;
        }
        
        
};

    
