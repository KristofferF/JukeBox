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

//const string sortTime = "sortTime";
//const string sortName = "sortName";

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

bool Album::operator<(const Album &album) const{
    if (getTitle() < album.getTitle()) {
        return true;
    }
    return false;
}

int Album::getLengthOfAlbum(){
    Time time;
    for (auto& song : songs) {
        time = time + *(song.getTime());
    }
    return time.getTime();
}

string Album::getPrintableTime(){
    int seconds = getLengthOfAlbum();
    int hours = seconds/SEC_PER_HOUR;
    seconds = seconds%SEC_PER_HOUR;
    int minutes = seconds/SEC_PER_MIN;
    seconds = seconds%SEC_PER_MIN;
    string time = "";
    if (hours > 0){
        time += hours + ":";
    }
    if (minutes > 0){
        time += minutes + ":";
    }
    time += seconds;
    return time;
}

void Album::sortByName(){

}

void Album::sortByTime(){

}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Album &album) {
    os  << album.getTitle() << endl << album.getSize() << endl;
    for (auto& song : album.getSongs()) {
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
    getline(is, title, '\r');
    is.ignore();
    album.setTitle(title);

    string tmpSize;

    getline(is, tmpSize, '\r');
    is.ignore(); // TODO can it bee \r\n instead? same in time class
    // TODO stoi instead
    int size = atoi(tmpSize.c_str());

    for (int i = 0; i < size; i++){
        Song song;
        is >> song;
        album.addSong(song);
    }

    return is;
}
