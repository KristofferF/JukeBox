/*
 * Song.cpp
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#include "Song.h"
#include <iostream>

const char DELIM = '|';

Song::Song(){
    length = new Time();
}

Song::Song(string title, string artist, int time){
    this->title = title;
    this->artist = artist;
    length = new Time();
    length->setTime(time);
}

string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

string Song::getPrintableTime() const{
    return length->getPrintableTime();
}

Time* Song::getTime() const{
    return length;
}

void Song::setTitle(string title){
    this->title = title;
}

void Song::setArtist(string artist){
    this->artist = artist;
}


ostream &operator<<(ostream &os, const Song &song){
    os << song.getTitle() << DELIM << song.getArtist() << DELIM << (*song.getTime()) << endl;
    return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Song &song) {
    string tmpTitle;
    string tmpArtist;
    getline(is, tmpTitle, DELIM);
    song.setTitle(tmpTitle);
    getline(is, tmpArtist, DELIM);
    song.setArtist(tmpArtist);
    is >> (*song.getTime());
    return is;
}
