/*
 * Album.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include "Album.h"
#include <fstream>
#include <iomanip>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Album::Album() {

}

void Album::setTitle(string title){
    this->title = title;
}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Album &album) {
//    os  << person.getName() << endl  << person.getAddress()
//            << endl  << person.getPersNr() << endl  << person.getShoeSize();
//    return os;
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
    cout << title << " 1 " << title.length() << endl;

    string size;
    getline(is, size, '\n');
    int sizes = stoi(size);
    cout << sizes << endl;

    string tmp;
    getline(is, tmp, '|');
    cout << tmp << " 3 " << tmp.length() << endl;
    getline(is, tmp, '|');
    cout << tmp << " 4 " << tmp.length() << endl;
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
}
