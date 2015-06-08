/*
 * Album.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include "Album.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Album::Album() {

}

void Album::setTitle(string title){
    this->title = title;
}

void Album::addSong(string title, string artist, int length){
    Song song = Song(title, artist, length);
    songs.push_back(song);
}

void Album::printAll(){
    for (auto song : songs){
        cout << song << endl;
    }
}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Album &album) {
//    os  << person.getName() << endl  << person.getAddress()
//            << endl  << person.getPersNr() << endl  << person.getShoeSize();
//    return os;
        return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Album &album) {
    Song song;
    string title;
    getline(is, title, '\n');
    album.setTitle(title);

    string tmpSize;
    getline(is, tmpSize, '\n');
    // TODO stoi instead
    int size = atoi(tmpSize.c_str());

    string tmpTitle;
    string tmpArtist;
    string tmpLength;

    for (int i = 0; i < size; i++){
        getline(is, tmpTitle, '|');
        cout << tmpTitle << " ";
        getline(is, tmpArtist, '|');
        cout << tmpArtist << " ";
        getline(is, tmpLength, '\n');
        cout << tmpLength << endl;
        album.addSong(tmpTitle, tmpArtist, atoi(tmpLength.c_str()));
    }

//    Name tmpName;
//    Address tmpAddress;
//    string tmpPersNr;
//    int tmpShoeSize;
//    is >> tmpName;
//    is.ignore();
//    is >> tmpAddress;
//    is.ignore();
//    is >> tmpPersNr;
//    is.ignore();
//    is >> tmpShoeSize;
//    is.ignore();
//    person.setName(tmpName);
//    person.setAddress(tmpAddress);
//    person.setPersNr(tmpPersNr);
//    person.setShoeSize(tmpShoeSize);
//    return is;
    return is;
}
