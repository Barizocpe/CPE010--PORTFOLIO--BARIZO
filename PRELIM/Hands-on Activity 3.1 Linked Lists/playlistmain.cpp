#include <iostream>
#include <string>
#include "circular_ll.h"

int main() {
    // 1. Create a playlist using multiple songs
    CircularList<std::string>* playlist = cdllCreatePlaylist<std::string>(
        {"Bohemian Rhapsody", "Hotel California", "Imagine"});

    std::cout << "--- Initial Playlist ---\n";
    cdllPlayAll(playlist);

    // 2. Add a song to the playlist
    std::cout << "\n--- Adding 'Wonderwall' ---\n";
    cdllAddSong<std::string>("Wonderwall", &playlist);
    cdllPlayAll(playlist);

    // 3. Remove a song from the playlist
    std::cout << "\n--- Removing 'Hotel California' ---\n";
    cdllDeleteSong<std::string>("Hotel California", &playlist);
    cdllPlayAll(playlist);

    // 4. Move through the playlist with next/previous
    std::cout << "\n--- Testing Next / Previous ---\n";
    CircularList<std::string>* current = playlist;
    current = cdllNext(current);       // move forward
    current = cdllNext(current);       // move forward again
    current = cdllPrevious(current);   // move back one

    // 5. Play all songs one more time to confirm the list is intact
    std::cout << "\n--- Final Playlist ---\n";
    cdllPlayAll(playlist);

    // 6. Clean up
    cdllDeletePlaylist(&playlist);

    return 0;
}