/*
 * Song.cpp
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#include "Song.h"
#include <iostream>

Song::Song(){

}

Song::Song(string title, string artist, int length){
    this->title = title;
    this->artist = artist;
    this->length = Time(length);
}

string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

int Song::getLength() const{
    return 35;
}

ostream &operator<<(ostream &os, const Song &song){
        os << song.getTitle() << " " << song.getArtist() << " " << song.getLength();
        return os;
}
