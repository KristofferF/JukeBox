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
    Time *length; // TODO ska det vara pekare?

public:
    Song();
    Song(string title, string artist, int time);
    // TODO destructor and smartpointer for time




    string getTitle() const;
    string getArtist() const;
    Time* getTime() const;
    void setTitle(string title);
    void setArtist(string artist);
    string getPrintableTime() const;
    bool operator==(const Song &song) const;
};

ostream &operator<<(ostream &os, const Song &song);
istream &operator>>(istream &is, Song &song);

#endif /* SRC_SONG_H_ */
