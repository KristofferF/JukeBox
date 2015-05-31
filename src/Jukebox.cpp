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
    cout << "**** FILE ****" << endl;
    int selection = 0;
    bool active = true;
    cout << "Welcome to the personnel register" << endl;
    while(active){
        cout << endl << "1. File...\n"
                "2. Add an album\n"
                "3. Delete an album\n"
                "4. Print...\n"
                "5. Play...\n"
                "6. Exit\n"
                "Choose an alternative: ";
        cin >> selection;
        while(cin.fail() || selection < 1 || selection > 8){
            cin.clear();
            cin.ignore(256,'\n');
            cout << "You have to enter a valid choice. Please enter your selection again: ";
            cin >> selection;
        }
        cout << endl;
        switch (selection){
        case 1:
//            addPerson();
            break;
        case 2:
//            printList();
            break;
        case 3:
//            writeToFile();
            break;
        case 4:
//            readFromFile();
            break;
        case 5:
//            sortName();
            break;
        case 6:
//            sortPersNr();
            break;
        case 7:
//            sortShoeSize();
            break;
        case 8:
            active = false;
            break;
        }
    }
    cout << "Thanks for using personnel register" << endl;
}
