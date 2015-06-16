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
    setAvailableOptions(true);
    albums.clear();
    fstream inFile(fileName, ios::in);
    Album tmpAlbum;
    while(inFile >> tmpAlbum){
        addAlbum(tmpAlbum);
        tmpAlbum = Album();
    }
    inFile.close();
}

void Jukebox::setAvailableOptions(bool enabled){ // TODO Maybee no param
    mainMenu.setAvailableOptions(enabled);
    fileMenu.setAvailableOptions(enabled);
    playMenu.setAvailableOptions(enabled);
    printMenu.setAvailableOptions(enabled);

}

void Jukebox::save(){
    cout << "save" << endl;
    fstream outFile("test.txt", ios::out);
    for (auto& album : albums){
        outFile << album;
    }
    outFile.close();
}

void Jukebox::addAlbum(Album album){
    cout << "Enter album name: ";
    string title;
    cin.ignore();
    getline(cin, title);
    string songTitle;
    string songArtist;
    string songLength;
    cout << "Enter a song" << endl << Enter title of a song
    cin >> songTitle;
    if(!found){
        cout << "Couldn´t find album. Maybee you misspelled." << endl;
    }
    albums.push_back(album);
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
                cout << "Printing content of searched album" << endl;
                printAlbum();
                break;
            case 2:
                cout << "Printing all albums sorted by album name" << endl;
                printSortedAlbums(1);
                break;
            case 3:
                cout << "Printing all albums sorted by album total time" << endl;
                printSortedAlbums(2);
                break;
            case 4:
                cout << "Printing all albumnames sorted by album name" << endl;
                printSortedAlbums(3);
                break;
            case 5:
                cout << "Printing all albumnames sorted by album total time" << endl;
                printSortedAlbums(4);
                break;
            case 6:
                again = false;
                break;
        }
    }while(again);
}

//------------------------------------------------------------------------------
// printAlbum
// Låter användaren mata in sökt album och skriver ut det om det finns i listan med album.
//------------------------------------------------------------------------------
void Jukebox::printAlbum() {
    cout << "Enter album name to look for: ";
    string searchName;
    bool found = false;
    cin.ignore();
    getline(cin, searchName);
    cout << searchName << endl;
    for (auto& album : albums){
        if (compareStrings(album.getTitle(), searchName)){
            found = true;
            cout << album.getTitle() << endl;
            for (auto song : album.getSongs()){
                cout << song.getTitle() << "-" << song.getArtist() << " " << song.getPrintableTime() << endl;
            }
        }
    }
    if(!found){
        cout << "Couldn´t find album. Maybee you misspelled." << endl;
    }
}

//------------------------------------------------------------------------------
// compareStrings
//
//------------------------------------------------------------------------------
bool Jukebox::compareStrings(const string& a, const string& b){
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

bool sortByTime(Album a1, Album a2) {
    return a1.getLengthOfAlbum() > a2.getLengthOfAlbum();
}

void printAll(Album album){
    cout << album.getTitle() << endl;
    for (auto song : album.getSongs()){
        cout << song.getTitle() << "-" << song.getArtist() << " " << song.getPrintableTime() << endl;
    }
}

void printSimple(Album album){
    cout << album.getTitle() << endl;
}

void printSimpleTime(Album album){
    cout << album.getTitle() << " " << album.getPrintableTime() << endl;
}

//------------------------------------------------------------------------------
// printSortedAlbums
// Skriver ut albumen i en sorterad ordning
//------------------------------------------------------------------------------
void Jukebox::printSortedAlbums(int choice) {
    vector<Album> sortedAlbums(albums);
    switch(choice) {
        case 1:
            sort(sortedAlbums.begin(), sortedAlbums.end());
            for_each (sortedAlbums.begin(), sortedAlbums.end(), printAll);
            break;
        case 2:
            sort(sortedAlbums.begin(), sortedAlbums.end(), sortByTime);
            for_each (sortedAlbums.begin(), sortedAlbums.end(), printAll);
            break;
        case 3:
            sort(sortedAlbums.begin(), sortedAlbums.end());
            for_each (sortedAlbums.begin(), sortedAlbums.end(), printSimple);
            break;
        case 4:
            sort(sortedAlbums.begin(), sortedAlbums.end(), sortByTime);
            for_each (sortedAlbums.begin(), sortedAlbums.end(), printSimpleTime);
            break;
    }
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
