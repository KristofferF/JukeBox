//
// Created by Kristoffer on 2015-06-01.
//

#ifndef JUKEBOX_MENU_H
#define JUKEBOX_MENU_H

#include<vector>
#include<string> // TODO MAYBEE UNNECESSARY
#include"MenuItem.h"

class Menu{
private:
    vector<MenuItem> menuItems;
    string label;
public:
    Menu();
    void addItem(string menuText, bool enabled);
    void printMenuItems();
    size_t getMenuChoices();
    void setLabel(string label);
};

#endif //JUKEBOX_MENU_H
