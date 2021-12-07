#include <iostream>
#include "Song.h"
#include <string> 

using namespace std;

Song::Song(){
    title = "";
    listenCount = 0;
}
Song::Song(string t){
    title = t;
    listenCount = 0;
}

ostream& operator<<(ostream& os, const Song& sg){
    os << sg.title << " | listen count: "<< sg.listenCount << endl;
    return os;
}   
bool operator==(const Song &other, const Song &other2) {
    return (other.title == other2.title);
}
bool operator!=(const Song& lhs, const Song& rhs){ 
    return !(lhs.title == rhs.title); 
}
bool operator> (const Song &lhs, const Song &rhs){
         if(lhs.title > rhs.title) {
            return true;
         }
         return false;
    }
bool operator< (const Song &lhs, const Song &rhs){
        if(lhs.title < rhs.title) {
	  return true;
        }
        return false;
}
void Song::listen(int n){
    if (n < 0){
        cout << "cant listen by negative amount" << endl;
        listenCount += 0;
    }
    else listenCount += n;
}
int Song::getListen(){
    return listenCount;
}

string Song::getTitle(){
    return title;
}
Song& Song::operator=(const Song &other) {
  if(this == &other)
    return *this;
  else{
    title = other.title;
    listenCount = other.listenCount;
    heapIndex = other.heapIndex;
    return *this;
  }
}
void Song::resetListen(){
    listenCount = 0;
}
void Song::setIndex(int x){
    heapIndex = x;
}
int Song::getIndex(){
    return heapIndex;
}
