/*
 * Song.h
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef SRC_SONG_H_
#define SRC_SONG_H_

#include <string>
#include "Time.h"
using namespace std;

class Song{
private:
    string title;
    string artist;
    Time length;

public:
    Song();
    Song(string title, string artist, int length);
    string getTitle() const;
    string getArtist() const;
    int getLength() const;

};

ostream &operator<<(ostream &os, const Song &song);
//istream &operator>>(istream &is, Album &person);

#endif /* SRC_SONG_H_ */
