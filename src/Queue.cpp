//
// Created by kristoffer on 2015-06-17.
//

#include "Queue.h"

const int startSize = 5;

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Queue::Queue() {
    songs = new Song[startSize];
    first = 0;
    last = 0;
    size = startSize;
}

//------------------------------------------------------------------------------
// Kopierings konstruktor (Copy constructor)
//------------------------------------------------------------------------------
Queue::Queue(const Queue& queue) {
    size = queue.getSize();
    songs = new Song[size];
    first = queue.getFirst();
    last = queue.getLast();
    for (size_t i = 0; i < last; i++){
        songs[i] = queue.getSongs()[(first + i) % size];
    }
}

//------------------------------------------------------------------------------
// Destruktor (Destructor)
//------------------------------------------------------------------------------
Queue::~Queue() {
    delete []songs;
}

//------------------------------------------------------------------------------
// add
// L�gger till l�ten som ges som parameter i k�n
//------------------------------------------------------------------------------
void Queue::add(Song song) {
    if (last + 1 > size){
        resize();
    }
    songs[(first+last) % size] = song;
    last++;
}

//------------------------------------------------------------------------------
// remove
// Tar bort den f�rsta l�ten i k�n och returnerar den
//------------------------------------------------------------------------------
Song Queue::remove() {
    Song song = songs[first];
    first = (first+1) % size;
    last--;
    return song;
}

//------------------------------------------------------------------------------
// emptyQueue
// T�mmer k�n
//------------------------------------------------------------------------------
void Queue::emptyQueue() {
    delete []songs;
    songs = new Song[startSize];
    first = 0;
    last = 0;
    size = startSize;
}

//------------------------------------------------------------------------------
// resize
// Ändra stroleken på listan
//------------------------------------------------------------------------------
void Queue::resize() {
    size += 5;
    Song *tmp = new Song[size];
    for (size_t i = 0; i < last; i++){
        tmp[i] = songs[(first + i) % size];
    }
    delete []songs;
    songs = tmp;
    first = 0;
}

//------------------------------------------------------------------------------
// isEmpty
// returnerar true om listan är tom
//------------------------------------------------------------------------------
bool Queue::isEmpty() {
    return last == 0;
}

//------------------------------------------------------------------------------
// getSize
// returnerar datamedlemmen size
//------------------------------------------------------------------------------
int Queue::getSize() const{
    return size;
}

//------------------------------------------------------------------------------
// getFirst
// returnerar datamedlemmen first
//------------------------------------------------------------------------------
int Queue::getFirst() const{
    return first;
}

//------------------------------------------------------------------------------
// getLast
// returnerar datamedlemmen last
//------------------------------------------------------------------------------
int Queue::getLast() const{
    return last;
}

//------------------------------------------------------------------------------
// getSongs
// returnerar datamedlemmen songs
//------------------------------------------------------------------------------
Song* Queue::getSongs() const{
    return songs;
}
