/*
 * Album.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include "Album.h"
#include <fstream>

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Album::Album() {

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
