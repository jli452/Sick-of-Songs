#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include "BST.h"
#include "Song.h"
using namespace std;

class Heap{
    private:
        int heapSize;
        vector<Song> heap;
        BST<Song> songs;
        int PARENT(int);
        int LEFT(int);
        int RIGHT(int);
    public:
        Heap();
        int size();
        void insert(Song);
        void increaseKey(int, int);
        Song extractMax();
        void heapify_down(int);
        void printAll();
        int index(string);
        void incSong(string, int);
        void printNum(int);
};
