#include <iostream>
#include <stdlib.h>
#include "Library.h"

using namespace std;

Library::Library() {
  BST<Song> lib;
  numSongs = 0;
}

void Library::addSong(Song song) {
  if (!lib.search(song)) {
    lib.insert(song);
    numSongs++;
    cout << "Added song to Primary User library: " << song.getTitle() << endl;
  }
  else cout << "error: Duplicate song not allowed" << endl;
}

void Library::removeSong(Song song) {
 if (lib.search(song)) {
    lib.remove(song);
    numSongs--;
    cout << "Removed song: " << song.getTitle() << endl;
   }
 else cout << "error: Song not in system" << endl;
}

void Library::showSongs() {
  lib.display();
}

