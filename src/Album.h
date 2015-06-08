/*
 * Album.h
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#ifndef SRC_ALBUM_H_
#define SRC_ALBUM_H_

#include "Song.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Album{
private:
    vector<Song> songs;
    string title;

public:
    Album();
    void setTitle(string title);
    void addSong(string title, string artist, int length);
    void printAll();
};

ostream &operator<<(ostream &os, const Album &person);
istream &operator>>(istream &is, Album &person);

#endif /* SRC_ALBUM_H_ */
