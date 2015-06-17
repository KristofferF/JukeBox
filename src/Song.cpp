/*
 * Song.cpp
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#include "Song.h"
#include <iostream>

const char DELIM = '|';

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Song::Song(){
    length = new Time();
}

Song::Song(string title, string artist, int time){
    this->title = title;
    this->artist = artist;
    length = new Time();
    length->setTime(time);
}

//------------------------------------------------------------------------------
// getTitle
// Returnerar datamedlemmen title
//------------------------------------------------------------------------------
string Song::getTitle() const{
    return title;
}

//------------------------------------------------------------------------------
// getArtist
// Returnerar datamedlemmen artist
//------------------------------------------------------------------------------
string Song::getArtist() const{
    return artist;
}

//------------------------------------------------------------------------------
// getPrintableTime
// Returnerar tiden f�r en l�t som en utskriftsv�nlig string
//------------------------------------------------------------------------------
string Song::getPrintableTime() const{
    return length->getPrintableTime();
}

//------------------------------------------------------------------------------
// getTime
// Returnerar datamedlemmen length
//------------------------------------------------------------------------------
Time* Song::getTime() const{
    return length;
}

//------------------------------------------------------------------------------
// setTitle
// Datamedlemmen title ges värdet av parametern title
//------------------------------------------------------------------------------
void Song::setTitle(string title){
    this->title = title;
}

//------------------------------------------------------------------------------
// setArtist
// Datamedlemmen artist ges värdet av parametern artist
//------------------------------------------------------------------------------
void Song::setArtist(string artist){
    this->artist = artist;
}

//------------------------------------------------------------------------------
// overloaded == operator
//
//------------------------------------------------------------------------------
bool Song::operator==(const Song &song) const {
    return title == song.getTitle() && artist == song.getArtist() && length == song.getTime();
}

//------------------------------------------------------------------------------
// overloaded << operator
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Song &song){
    os << song.getTitle() << DELIM << song.getArtist() << DELIM << (*song.getTime()) << endl;
    return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
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
