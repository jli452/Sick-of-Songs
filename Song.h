#pragma once
#include <iostream>
#include <string> 
using namespace std;

class Song{
private:
  string title;
  int listenCount;
  int heapIndex;
public:
  Song(string);
  Song();
  void setTitle(string);
  void listen(int);
  int getListen();
  string getTitle();
  void setIndex(int);
  int getIndex();
  friend ostream& operator<<(ostream& os, const Song& sg);
  friend bool operator==(const Song &other, const Song &other2);
  friend bool operator!=(const Song& lhs, const Song& rhs);
  friend bool operator> (const Song &lhs, const Song &rhs);
  friend bool operator< (const Song &lhs, const Song &rhs);
  Song& operator=(const Song &other);
  void resetListen();
};
