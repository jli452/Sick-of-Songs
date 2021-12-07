#include <iostream>
#include "Heap.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <stdexcept>
using namespace std;
Heap::Heap(){
    vector<Song> heap;
    BST<Song> songs;
}
void Heap::insert(Song x){
    x.setIndex(size());
    songs.insert(x);
    heap.push_back(x);
}
int Heap::PARENT(int i){
    return (i-1)/2;
}
int Heap::LEFT(int i){
    return (2*i +1);
}
int Heap::RIGHT(int i){
    return (2*i +2);
}
void Heap::increaseKey(int i, int key){
    heap[i].listen(key);
    while(i > 0 && heap[PARENT(i)].getListen() < heap[i].getListen()){
        swap(heap[i], heap[PARENT(i)]);
        int temp = heap[i].getIndex();
        heap[i].setIndex(heap[PARENT(i)].getIndex());
        heap[PARENT(i)].setIndex(temp);
        songs.replace(heap[i], heap[i]);
        songs.replace(heap[PARENT(i)],heap[PARENT(i)]);
        i = PARENT(i);
    }
}

void Heap::heapify_down(int i){
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    if(left < size() && heap[left].getListen() > heap[i].getListen()){
        largest = left;
    }
    if (right < size() && heap[right].getListen() > heap[largest].getListen()) {
            largest = right;
    }
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        int temp = heap[i].getIndex();
        heap[i].setIndex(heap[largest].getIndex());
        heap[largest].setIndex(temp);
        songs.replace(heap[i], heap[i]);
        songs.replace(heap[largest],heap[largest]);
        heapify_down(largest);
    }
}
Song Heap::extractMax(){
  try {
    
    if (size() == 0){
      throw out_of_range("Heap underflow");
    }
  }
  catch (const out_of_range &oor) {
    cout << endl << oor.what();
  }
  if(size() == 1){
    Song max = heap[0];
    songs.remove(heap[0]);
    heap.pop_back();
    return max;
  }
  else{
    Song max = heap[0];
    songs.remove(heap[0]);
    heap[0] = heap[size()-1];
    heap[0].setIndex(0);
    songs.replace(heap[0], heap[0]);
    heap.pop_back();
    heapify_down(0);
    return max;
  }
}
void Heap::printAll(){
    for (std::vector<Song>::const_iterator i = heap.begin(); i != heap.end(); ++i)
    std::cout << *i << endl;
    cout << endl;
}
int Heap::size(){
    return heap.size();
}

// int Heap::index(string x){
//     for (int i = 0; i< size(); i++){
//         if (heap[i].getTitle() == x){
//             return i;
//         }
//     }
//     return 0;
// }
void Heap::incSong(string x, int key){
  Song temp = Song(x);
  if(songs.search(temp)){
    int tmp = songs.searchTdata(temp).getIndex();
    increaseKey(tmp, key);
  }
  else{
    cout << "Song not found in system" << endl;
    return;
  }
}

void Heap::printNum(int x){
    for (int i = 0; i< x; i++){
        cout << heap[i] << endl;
    }
}
