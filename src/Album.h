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
using namespace std;

class Album{
private:
    vector<Song> songs;
    string title;

public:
    Album();
    void setTitle(string title);
};

ostream &operator<<(ostream &os, const Album &person);
istream &operator>>(istream &is, Album &person);

#endif /* SRC_ALBUM_H_ */
