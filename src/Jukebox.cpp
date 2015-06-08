/*
 * Jukebox.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include "Jukebox.h"
#include <algorithm>
#include <fstream>

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
    fileMenu.addItem("Save", true);
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

    fileName = "jukebox.txt";
}

void Jukebox::run(){
    bool again = true;
    do{
        mainMenu.printMenuItems();
        switch(mainMenu.getMenuChoices()){
            case 1:
                file();
                break;
            case 2:
                //addAlbum();
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
    cout << "Thanks for using JukeBox" << endl;
}

void Jukebox::file(){
    bool again = true;
    do{
        fileMenu.printMenuItems();
        switch(fileMenu.getMenuChoices()){
            case 1:
                open();
                break;
            case 2:
                save();
                break;
            case 3:
                again = false;
                break;
        }
    }while(again);
}

void Jukebox::open(){
    albums.clear();
    fstream inFile(fileName, ios::in);
    Album tmpAlbum;
    inFile >> tmpAlbum;
    addAlbum(tmpAlbum);
    inFile.close();
    tmpAlbum.printAll();
}

void Jukebox::save(){
    fstream outFile(fileName, ios::out);
    outFile << "Hey" << endl;
    outFile.close();
}

void Jukebox::addAlbum(Album album){
    cout << "add album" << endl;
}

void Jukebox::removeAlbum(){
    cout << "remove album" << endl;
}

void Jukebox::print(){
    bool again = true;
    do{
        printMenu.printMenuItems();
        switch(printMenu.getMenuChoices()){
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "2";
                break;
            case 3:
                cout << "3";
                break;
            case 4:
                cout << "4";
                break;
            case 5:
                cout << "5";
                break;
            case 6:
                again = false;
                break;
        }
    }while(again);
}

void Jukebox::play(){
    bool again = true;
    do{
        playMenu.printMenuItems();
        switch(playMenu.getMenuChoices()){
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "2";
                break;
            case 3:
                cout << "3";
                break;
            case 4:
                again = false;
                break;
        }
    }while(again);
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


            break;
        case 5:
//            play();
            break;
        case 6:
//            exit();
            break;
        }
    }

}
