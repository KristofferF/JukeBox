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
// FÃ¶rvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Album::Album() {

}

Album::Album(string title, vector<Song> songs) {
	this->title = title;
	this->songs = songs;
}

//------------------------------------------------------------------------------
// setTitle
// Datamedlemmen title ges vÃ¤rdet av parametern title
//------------------------------------------------------------------------------
void Album::setTitle(string title){
    this->title = title;
}

//------------------------------------------------------------------------------
// getTitle
// returnerar datamedlemmen title
//------------------------------------------------------------------------------
string Album::getTitle() const{
    return title;
}

//------------------------------------------------------------------------------
// addSong
// Lägger till objektet song till albumet
//------------------------------------------------------------------------------
void Album::addSong(Song song){
    songs.push_back(song);
}

//------------------------------------------------------------------------------
// getSize
// returnerar storleken av datamedlemmen <vector> songs
//------------------------------------------------------------------------------
size_t Album::getSize() const{
    return songs.size();
}

//------------------------------------------------------------------------------
// getSongs
// returnerar datamedlemmen <vector> songs
//------------------------------------------------------------------------------
vector<Song> Album::getSongs() const{
    return songs;
}

//------------------------------------------------------------------------------
// getLengthOfAlbum
// returnerar totala tiden för alla låtarna i albumet
//------------------------------------------------------------------------------
int Album::getLengthOfAlbum(){
    Time time;
    for (auto& song : songs) {
        time = time + *(song.getTime());
    }
    return time.getTime();
}

//------------------------------------------------------------------------------
// getLengthOfAlbum
// returnerar totala tiden för alla låtarna i albumet som en utskriftsvänlig string
//------------------------------------------------------------------------------
string Album::getPrintableTime(){
    int seconds = getLengthOfAlbum();
    int hours = seconds/SEC_PER_HOUR;
    seconds = seconds%SEC_PER_HOUR;
    int minutes = seconds/SEC_PER_MIN;
    seconds = seconds%SEC_PER_MIN;
    string time = "";
    if (hours > 0){
        time += to_string(hours) + ":";
    }
    if (minutes > 0){
        time += to_string(minutes) + ":";
    }
    time += to_string(seconds);
    return time;
}


//------------------------------------------------------------------------------
// overloaded < operator
//------------------------------------------------------------------------------
bool Album::operator<(const Album &album) const{
    if (getTitle() < album.getTitle()) {
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
// overloaded << operator
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
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Album &album) {
    string title;
    getline(is, title, '\r');
    is.ignore();
    album.setTitle(title);

    string tmpSize;

    getline(is, tmpSize, '\r');
    is.ignore(); // TODO can it be \r\n instead? same in time class
    // TODO stoi instead
    int size = atoi(tmpSize.c_str());

    for (int i = 0; i < size; i++){
        Song song;
        is >> song;
        album.addSong(song);
    }

    return is;
}
