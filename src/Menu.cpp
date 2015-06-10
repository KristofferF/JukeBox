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
    menuItems.push_back(MenuItem(menuText, enabled));
}

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
    size_t i = 0;
    for (auto& item: menuItems){
        i++;
        if (item.getMenuText() == selectableMenuItems[selection-1].getMenuText()){
            return i;
        }
    }
}

void Menu::setLabel(string label) {
    this->label = label;
}

void Menu::setAvailableOptions(bool enabled){
    for (auto& item : menuItems){
        item.setEnabled(enabled);
    }
}
