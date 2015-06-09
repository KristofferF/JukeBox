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

void Album::addSong(Song song){
    songs.push_back(song);
}

string Album::getTitle() const{
    return title;
}

size_t Album::getSize() const{
    return songs.size();
}

vector<Song> Album::getSongs() const{
    return songs;
}

void Album::printAll() const{
    for (auto song : songs) {
        cout << song;
    }
}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Album &album) {
    os  << album.getTitle() << endl << album.getSize() << endl;
    for (auto song : album.getSongs()) {
        os << song;
    }
    return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Album &album) {
    string title;
    getline(is, title, '\n');
    album.setTitle(title);

    string tmpSize;
    getline(is, tmpSize, '\n');
    // TODO stoi instead
    int size = atoi(tmpSize.c_str());

    for (int i = 0; i < size; i++){
        Song song;
        is >> song;
        album.addSong(song);
    }

    return is;
}
