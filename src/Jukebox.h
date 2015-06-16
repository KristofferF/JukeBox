/*
 * Jukebox.h
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#ifndef SRC_JUKEBOX_H_
#define SRC_JUKEBOX_H_

#include <string>
#include <iostream>
#include <vector>
#include "Album.h"
#include "Menu.h"
using namespace std;

class Jukebox{
private:
    vector<Album> albums;
    Menu mainMenu;
    Menu fileMenu;
    Menu printMenu;
    Menu playMenu;
    string fileName;

    void file();
    void open();
    void setAvailableOptions(bool enabled);
    void save();
    void addAlbum(Album album);
    void removeAlbum();
    void print();
    void printAlbum();
    void printSortedAlbums(int choice);
    bool compareStrings(const string& a, const string& b);

//    void printSortedAlbumsTime();
    void play();
public:
    Jukebox();
    void run();
};

#endif /* SRC_JUKEBOX_H_ */
