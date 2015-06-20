/*
 * Jukebox.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: Kristoffer
 */

#include "Jukebox.h"
#include "Song.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>

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

    generator = default_random_engine(static_cast<unsigned>(time(0)));
}

//------------------------------------------------------------------------------
// run
// Huvudloopen i programmet
//------------------------------------------------------------------------------
void Jukebox::run(){
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
    cout << "Thanks for using JukeBox" << endl;
}

//------------------------------------------------------------------------------
// file
// Genomf�r valt filalternativ
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// open
// �ppnar en fil och l�ser in album
//------------------------------------------------------------------------------
void Jukebox::open(){
    setAvailableOptions(true);
    albums.clear();
    fstream inFile(fileName, ios::in);
    Album tmpAlbum;
    while(inFile >> tmpAlbum){
        albums.push_back(tmpAlbum);
        tmpAlbum = Album();
    }
    inFile.close();
}

//------------------------------------------------------------------------------
// setAvailableOptions
// �ndrar s� alla alternativ i menyerna blir tillg�ngliga
//------------------------------------------------------------------------------
void Jukebox::setAvailableOptions(bool enabled){ // TODO Maybee no param
    mainMenu.setAvailableOptions(enabled);
    fileMenu.setAvailableOptions(enabled);
    playMenu.setAvailableOptions(enabled);
    printMenu.setAvailableOptions(enabled);

}

//------------------------------------------------------------------------------
// save
// Sparar alla albumen p� en fil.
//------------------------------------------------------------------------------
void Jukebox::save(){
    cout << "save" << endl;
    fstream outFile("test.txt", ios::out); // TODO change save location
    for (auto& album : albums){
        outFile << album;
    }
    outFile.close();
}

//------------------------------------------------------------------------------
// addAlbum
// L�gger til album
//------------------------------------------------------------------------------
void Jukebox::addAlbum(){
    cout << "Enter album name: ";
    string title;
    cin.ignore();
    getline(cin, title);
    string songTitle;
    string songArtist;
    string songLength;
    vector<Song> songs;
    bool go = true;
    while(go){
		cout << "Enter title of the song or enter 0 to stop enter songs: ";
		getline(cin, songTitle);
		if(songTitle == "0"){ // TODO test if it works
			break;
		}
		cout << "Enter artist of the song: ";
		getline(cin, songArtist);
		cout << "Enter length of the song in seconds: ";
		bool catchError = true;
		int time = 0;
		while(catchError){
            getline(cin, songLength);
            try {
                time = stoi(songLength);
                catchError = false;
            } catch (...) {
                cout << "Incorrect entry. You must enter a number: ";
            }
		}
		Song song(songTitle, songArtist, time);
		songs.push_back(song);
		cout << songTitle << " " << songArtist << " " << songLength << endl;
    }
    Album album(title, songs);
    albums.push_back(album);
    cout << "Album " << title <<  " added!" << endl;
}

//------------------------------------------------------------------------------
// removeAlbum
// Tar bort angivet album om det finns i albumslistan
//------------------------------------------------------------------------------
void Jukebox::removeAlbum(){
	cout << "Enter album name to look for: ";
	string searchName;
	bool found = false;
	cin.ignore();
	getline(cin, searchName);
	cout << searchName << endl;
	for(auto it = begin(albums); it != end(albums); ++it){
        if(compareStrings((*it).getTitle(), searchName)){
	    	cout << (*it).getTitle() << "removed!" << endl;
	    	it = albums.erase(it);
            found = true;
	    	break;
	    }
	}
	if(!found){ // TODO is it enough with just break above. Then remove if here
		cout << "Couldn´t find album. Maybee you misspelled." << endl;
	}
}

//------------------------------------------------------------------------------
// print
// Skriver ut valt alternativ
//------------------------------------------------------------------------------
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
    if(!found){ // TODO is it enough with just break above. Then remove if here
        cout << "Couldn´t find album. Maybee you misspelled." << endl;
    }
}

//------------------------------------------------------------------------------
// compareStrings
//	J�mf�r tv� strings utan att ta h�nsyn till versaler och gemener
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

//------------------------------------------------------------------------------
// sortByTime
// J�mf�r tv� album efter l�ngd
//------------------------------------------------------------------------------
bool sortByTime(Album a1, Album a2) { // TODO skall de vara en del av Jukebox::
    return a1.getLengthOfAlbum() > a2.getLengthOfAlbum();
}

//------------------------------------------------------------------------------
// printAll
// Skriver ut albumen och respektive inneh�ll
//------------------------------------------------------------------------------
void printAll(Album album){ // TODO skall de vara en del av Jukebox::
    cout << "Album: " << album.getTitle() << endl << "Songs: " << endl;
    for (auto song : album.getSongs()){
        cout << song.getTitle() << "-" << song.getArtist() << " " << song.getPrintableTime() << endl;
    }
}

//------------------------------------------------------------------------------
// printSimple
// Skriver ut albumnamnen i namnordning
//------------------------------------------------------------------------------
void printSimple(Album album){ // TODO skall de vara en del av Jukebox::
    cout << album.getTitle() << endl;
}

//------------------------------------------------------------------------------
// printSimpleTime
// Skriver ut albumnamnen i ordning efter l�ngd
//------------------------------------------------------------------------------
void printSimpleTime(Album album){ // TODO skall de vara en del av Jukebox::
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


//------------------------------------------------------------------------------
// play
// Simulerar en uppspelning
//------------------------------------------------------------------------------
void Jukebox::play(){
    bool again = true;
    do{
        playMenu.printMenuItems();
        switch(playMenu.getMenuChoices()){
            case 1:
                createPlaylist(1);
                break;
            case 2:
                createPlaylist(2);
                break;
            case 3:
                playList();
                break;
            case 4:
                again = false;
                break;
        }
    }while(again);
}


void Jukebox::createPlaylist(int choice) {
    queue.emptyQueue();
    cout << "Add songs to playlist" << endl;
    {
        size_t i = 0;
        vector<Song> songs;
        for (auto album : albums) {
            for (auto song : album.getSongs()) {
                i++;
                if (choice == 1){
                    cout << i << ": " << song.getTitle() << " - " << song.getArtist() << endl;
                }

                songs.push_back(song);
            }
        }
        vector<int> selectionArray;
        if (choice == 1){
            selectSongsForPlaylist(i, selectionArray);
        }
        else if (choice == 2){
            randomSongsForPlaylist(i, selectionArray);
        }
        for (auto songNumber : selectionArray) {
            queue.add(songs[songNumber - 1]);
        }
    }
}

void Jukebox::selectSongsForPlaylist(int size, vector<int>& selectionArray) {
    cout << "Type number to the songs you wish to add to the playlist.\n"
            "Example: 2, 12, 4, 28\nEnter your selection: ";
    string selection;
    cin.ignore();
    getline(cin, selection);
    stringstream stream(selection);
    string tmpSelection;
    bool errors = false;
    while (getline(stream, tmpSelection, ',')) {
        try {
            int selectedNumber = stoi(tmpSelection);
            if (selectedNumber <= size && selectedNumber > 0) {
                selectionArray.push_back(selectedNumber);
            } else {
                errors = true;
            }
        } catch (...) {
            errors = true;
        }
    }
    if (errors) {
        cout << "Skipped some entries because they we're invalid" << endl;
    }
}

void Jukebox::randomSongsForPlaylist(int size, vector<int>& selectionArray) {
    cout << "How many songs do you wish to be in the playlist?\nChoose a number between 1 and " <<
            size << ": ";
    string selection;
    bool go = true;
    int selectionAsInt = 0;
    while(go){
        cin.ignore();
        getline(cin, selection);
        try {
            selectionAsInt = stoi(selection);
            if (selectionAsInt <= size && selectionAsInt > 0) {
                go = false;
            } else {
                cout << "Choose a number between 1 and " << size << ": ";
            }
        } catch (...) {
            cout << "Choose a number between 1 and " << size << ": ";
        }
    }
    uniform_int_distribution<int> random(1, size);
    for (int i = 0; i < selectionAsInt; i++){
        int tmp = random(generator);
        while (find(selectionArray.begin(), selectionArray.end(), tmp) != selectionArray.end()){
            tmp = random(generator);
        }
        selectionArray.push_back(tmp);
    }
}

void Jukebox::playList() {
    Queue tmpQueue = queue;
    if (!tmpQueue.isEmpty()){
        cout << "Playing your list of songs!" << endl;
        while (!tmpQueue.isEmpty()) {
            Song tmpSong = tmpQueue.remove();
            cout << tmpSong.getTitle() << " - " << tmpSong.getArtist() << endl;
            sleep(2);
        }
        cout << "All songs played!" << endl << endl;
    } else {
        cout << "No songs in the playlist!" << endl << endl;
    }
}
