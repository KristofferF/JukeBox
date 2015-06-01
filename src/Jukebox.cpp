/*
 * Jukebox.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include"Jukebox.h"

void showMenu();

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
Jukebox::Jukebox(){
    mainMenu.setLabel("JUKE BOX");
    mainMenu.addItem("File...", true);
    mainMenu.addItem("Add an album", false);
    mainMenu.addItem("Delete an album", false);
    mainMenu.addItem("Print...", false);
    mainMenu.addItem("Play...", false);
    mainMenu.addItem("Exit", true);

    fileMenu.setLabel("FILE");
    fileMenu.addItem("Open", true);
    fileMenu.addItem("Save", false);
    fileMenu.addItem("Back to main menu", true);

    printMenu.setLabel("PRINT");
    printMenu.addItem("Print one album", true);
    printMenu.addItem("Print all sorted by album name", true);
    printMenu.addItem("Print all sorted by album total time", true);
    printMenu.addItem("Print simple sorted by album name", true);
    printMenu.addItem("Print simple sorted by album total time", true);
    printMenu.addItem("Back to main menu", true);

    playMenu.setLabel("PLAY");
    playMenu.addItem("Create a play list from songs", true);
    playMenu.addItem("Create a random list", true);
    playMenu.addItem("Play list", true);
    playMenu.addItem("Back to main menu", true);
}

void Jukebox::run(){

    //showMenu();

    bool again = true;
    do{
        mainMenu.printMenuItems();
        switch(mainMenu.getMenuChoices()){
            case 1:
                file();
                break;
            case 2:
                addAlbum();
                break;
            case 3:
                removeAlbum();
                break;
            case 4:
                print();
                break;
            case 5:
                play();
                break;
            case 6:
                again = false;
                break;
        }
    }while(again);
}

void Jukebox::file(){
    cout << "file" << endl;
}

void Jukebox::addAlbum(){
    cout << "add album" << endl;
}

void Jukebox::removeAlbum(){
    cout << "remove album" << endl;
}

void Jukebox::print(){
    cout << "print" << endl;
}

void Jukebox::play(){
    cout << "play" << endl;
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
