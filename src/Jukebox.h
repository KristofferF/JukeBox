/*
 * Jukebox.h
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#ifndef SRC_JUKEBOX_H_
#define SRC_JUKEBOX_H_

//#include<string>
#include<iostream>
#include<vector>
#include"Album.h"
#include"Menu.h"
using namespace std;

class Jukebox{
private:
    vector<Album> albums;
    Menu mainMenu;
    Menu fileMenu;
    Menu printMenu;
    Menu playMenu;

    void showMenu() const;
    void file();
    void open();
    void save();
    void addAlbum();
    void removeAlbum();
    void print();
    void play();

public:
    Jukebox();
    void run();

};

#endif /* SRC_JUKEBOX_H_ */
