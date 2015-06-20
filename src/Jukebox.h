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
#include "Queue.h"
#include <random>
using namespace std;

class Jukebox{
private:
    vector<Album> albums;
    Queue queue;
    Menu mainMenu;
    Menu fileMenu;
    Menu printMenu;
    Menu playMenu;
    string fileName;
    default_random_engine generator;

    void file();
    void open();
    void setAvailableOptions(bool enabled);
    void save();
    void addAlbum();
    void removeAlbum();
    void print();
    void printAlbum();
    void printSortedAlbums(int choice);
    bool compareStrings(const string& a, const string& b);

//    void printSortedAlbumsTime();
    void play();
    void createPlaylist(int choice);
    void selectSongsForPlaylist(int size, vector<int>& selections);
    void randomSongsForPlaylist(int size, vector<int>& selections);
    void playList();

public:
    Jukebox();
    void run();
};

#endif /* SRC_JUKEBOX_H_ */
