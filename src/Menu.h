//
// Created by Kristoffer on 2015-06-01.
//

#ifndef JUKEBOX_MENU_H
#define JUKEBOX_MENU_H

#include<vector>
#include<string>
#include"MenuItem.h"

class Menu{
private:
    vector<MenuItem> menuItems;
    vector<MenuItem> selectableMenuItems;
    string label;
public:
    Menu();
    void addItem(string menuText, bool enabled);
    void printMenuItems();
    size_t getMenuChoices();
    void setLabel(string label);
    void setAvailableOptions(bool enabled);
};

#endif //JUKEBOX_MENU_H
