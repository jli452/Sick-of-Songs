#pragma once
#include <iostream>
#include <stdlib.h>
#include "BST.h"
#include "Song.h"
#include "User.h"

using namespace std;

class System {
 public:
  System();
  void addSong(Song);
  void addUser(User);
  void addUserFriend(User);
  void showSongs();
  void showUsers();
  void removeSong(Song);
  void removeUser(User);
  User getUserObj(string);
  bool userExist(User);
  bool songExist(Song);
 private:
  int numSongs;
  BST<Song> sys;
  BST<User> users;
};
