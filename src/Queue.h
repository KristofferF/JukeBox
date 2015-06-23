//
// Created by kristoffer on 2015-06-17.
//

#ifndef JUKEBOX_QUEUE_H
#define JUKEBOX_QUEUE_H
#include "Song.h"

class Queue {
private:
    Song *songs;
    size_t size;
    int first;
    int last;

public:
    Queue();
    Queue(const Queue& queue);
    ~Queue();
    void add(Song song);
    Song remove();
    void emptyQueue();
    void resize();
    bool isEmpty() const;
    int getSize() const;
    Song *getSongs() const;
    int getFirst() const;
    int getLast() const;
};


#endif //JUKEBOX_QUEUE_H
