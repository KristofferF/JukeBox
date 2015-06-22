//
// Created by Kristoffer on 2015-06-01.
//

#include <iostream>
#include "Menu.h"

const string LABEL_PREFIX = "**** ";
const string LABEL_SUFFIX = " ****";

Menu::Menu() {
}


//------------------------------------------------------------------------------
// addItem
// L�gger till objekt till menyn
//------------------------------------------------------------------------------
void Menu::addItem(string menuText, bool enabled){
    menuItems.push_back(MenuItem(menuText, enabled));
}

//------------------------------------------------------------------------------
// printMenuItems
// Skriver ut menyalternativen
//------------------------------------------------------------------------------
void Menu::printMenuItems(){
    cout << LABEL_PREFIX << label << LABEL_SUFFIX << endl;
    selectableMenuItems.clear();
    for (auto& item: menuItems){
        if (item.getEnabled()){
            selectableMenuItems.push_back(item);
            cout << selectableMenuItems.size() << ". " << item.getMenuText() << endl;
        }
    }
}

//------------------------------------------------------------------------------
// getMenuChoices
// L�ter anv�ndaren v�lja ett menyalternativ
//------------------------------------------------------------------------------
size_t Menu::getMenuChoices(){
    size_t selection = 0;
    cout << "My choice: ";
    cin >> selection;
    while(cin.fail() || selection < 1 || selection > selectableMenuItems.size()){
        cin.clear();
        cin.ignore(256,'\n');
        cout << "You have to enter a valid choice. Please enter your selection again: ";
        cin >> selection;
    }
    cout << endl;
    size_t i = 0;
    for (auto& item: menuItems){
        i++;
        if (item.getMenuText() == selectableMenuItems[selection-1].getMenuText()){
            return i;
        }
    }

}

//------------------------------------------------------------------------------
// setLabel
// Datamedlemmen label ges värdet av parametern label
//------------------------------------------------------------------------------
void Menu::setLabel(string label) {
    this->label = label;
}

//------------------------------------------------------------------------------
// setAvailableOptions
// Synligheten p� samtliga menyalternativ ges v�rdet av parametern enabled
//------------------------------------------------------------------------------
void Menu::setAvailableOptions(bool enabled){
    for (auto& item : menuItems){
        item.setEnabled(enabled);
    }
}
