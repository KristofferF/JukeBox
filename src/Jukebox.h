/*
 * Jukebox.h
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#ifndef SRC_JUKEBOX_H_
#define SRC_JUKEBOX_H_

//#include<string>
//#include<iostream>
using namespace std;

class Jukebox{
private:
    void showMenu() const;

public:
    Jukebox();
    void run() const;
};

#endif /* SRC_JUKEBOX_H_ */
