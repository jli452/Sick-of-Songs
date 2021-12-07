#include <iostream>
#include <stdlib.h>
#include "System.h"


using namespace std;

System::System() {
  BST<User> users;
  BST<Song> sys;
  numSongs = 0;
}

void System::addSong(Song song) {
  if (!sys.search(song)) {
    sys.insert(song);
    numSongs++;
    cout << "Added song: " << song.getTitle() << endl;
  }
  else cout << "error: Duplicate song not allowed" << endl;
}

void System::addUser(User user) {
  if (!users.search(user)) {
    users.insert(user);
    cout << "Added user: " << user << endl;
  }
  else cout << "error: Duplicate users not allowed" << endl;
}

bool System::userExist(User user) {
  return users.search(user);
}

bool System::songExist(Song song) {
  return sys.search(song);
}

void System::addUserFriend(User user) {
  if (!users.search(user)) {
    users.insert(user);
  }
}

User System::getUserObj(string username) {
  User temp = User(username);
  return users.searchTdata(temp);
}


void System::showSongs() {
  sys.display();
}

void System::showUsers() {
  users.display();
}

void System::removeSong(Song song) {
 if (sys.search(song)) {
    sys.remove(song);
    numSongs--;
    cout << "Removed song: " << song.getTitle() << endl;
   }
 else cout << "error: Song not in system" << endl;
}

void System::removeUser(User user) {
  users.remove(user);
}
