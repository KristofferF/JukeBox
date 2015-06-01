//
// Created by Kristoffer on 2015-06-01.
//

#include <iostream>
#include "Menu.h"

const string LABEL_PREFIX = "**** ";
const string LABEL_SUFFIX = " ****";

Menu::Menu() {

    // TODO maybee add something here
}

void Menu::addItem(string menuText, bool enabled){

}

void Menu::printMenuItems(){
    cout << LABEL_PREFIX << label << LABEL_SUFFIX << endl;
    //int i = 1;
    for (int i = 0; i < 3; i++){
        cout << i << ". " << menuItems[i].getMenuText() << endl;
//        if (item.getEnabled()){
//            cout << i << ". " << item.getMenuText() << endl;
//        }
    }
}

size_t Menu::getMenuChoices(){
    size_t selection = 0;
    cout << "My choice: ";
    cin >> selection;
    while(cin.fail() || selection < 1 || selection > menuItems.size()+1){
        cin.clear();
        cin.ignore(256,'\n');
        cout << "You have to enter a valid choice. Please enter your selection again: ";
        cin >> selection;
    }
    return selection;
}

void Menu::setLabel(string label) {
    this->label = label;
}