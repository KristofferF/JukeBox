/*
 * Jukebox.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include"Jukebox.h"

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Jukebox::Jukebox(){

}

void Jukebox::run() const{
    showMenu();
}

void Jukebox::showMenu() const{
    cout << "**** JUKEBOX ****";
    int selection = 0;
    bool active = true;
    while(active){
        cout << endl << "1. File...\n"
                "2. Add an album\n"
                "3. Delete an album\n"
                "4. Print...\n"
                "5. Play...\n"
                "6. Exit\n\n"
                "My choice: ";
        cin >> selection;
        while(cin.fail() || selection < 1 || selection > 6){
            cin.clear();
            cin.ignore(256,'\n');
            cout << "You have to enter a valid choice. Please enter your selection again: ";
            cin >> selection;
        }
        cout << endl;
        switch (selection){
        case 1:
//            file();
            break;
        case 2:
//            addAlbum();
            break;
        case 3:
//            deleteAlbum();
            break;
        case 4:
//            print();
            break;
        case 5:
//            play();
            break;
        case 6:
//            exit();
            break;
        }
    }
    cout << "Thanks for using JukeBox" << endl;
}
