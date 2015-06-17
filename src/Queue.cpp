//
// Created by kristoffer on 2015-06-17.
//

#include "Queue.h"

const int startSize = 5;

Queue::Queue() {
    songs = new Song[startSize];
    first = 0;
    last = 0;
    size = startSize;
}

void Queue::add(Song song) {
    if (last + 1 > size){
        resize();
    }
    songs[(first+last) % size] = song;
    last++;
}


Song Queue::remove() {
    Song song = songs[first];
    first = (first+1) % size;
    last--;
    return song;
}

void Queue::emptyQueue() {

}

void Queue::resize() {
    size *= 2;
    Song *tmp = new Song[size];
    for (size_t i = 0; i < last; i++){
        tmp[i] = songs[(first + i) % size];
    }
    delete []songs;
    songs = tmp;
    first = 0;
}

bool Queue::isEmpty() {
    return last == 0;
}
