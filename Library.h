#pragma once
#include <iostream>
#include <stdlib.h>
#include "BST.h"
#include "Song.h"

using namespace std;

class Library {
 public:
  Library();
  void addSong(Song);
  void removeSong(Song);
  void showSongs();
 private:
  int numSongs;
  BST<Song> lib;
};
