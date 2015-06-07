/*
 * Song.h
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef SRC_SONG_H_
#define SRC_SONG_H_

#include <string>
using namespace std;

class Song{
private:
    string title;
    string artist;
    Time length;

public:
    Song();
};

//ostream &operator<<(ostream &os, const Album &person);
//istream &operator>>(istream &is, Album &person);

#endif /* SRC_SONG_H_ */
