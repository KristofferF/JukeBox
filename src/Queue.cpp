//
// Created by kristoffer on 2015-06-17.
//

#include "Queue.h"

const int startSize = 5;

//------------------------------------------------------------------------------
// FÃ¶rvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Queue::Queue() {
    songs = new Song[startSize];
    first = 0;
    last = 0;
    size = startSize;
}

//------------------------------------------------------------------------------
// add
// Lägger till låten som ges som parameter i kön
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
// Tar bort den första låten i kön och returnerar den
//------------------------------------------------------------------------------
Song Queue::remove() {
    Song song = songs[first];
    first = (first+1) % size;
    last--;
    return song;
}

//------------------------------------------------------------------------------
// emptyQueue
// Tömmer kön
//------------------------------------------------------------------------------
void Queue::emptyQueue() {
	// TODO implement or remove
}

//------------------------------------------------------------------------------
// resize
// Datamedlemmen text ges vÃ¤rdet av parametern menuText
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
// setMenuText
// Datamedlemmen text ges vÃ¤rdet av parametern menuText
//------------------------------------------------------------------------------
bool Queue::isEmpty() {
    return last == 0;
}
