/*
 * MenuItem.cpp
 *
 *  Created on: 31 maj 2015
 *      Author: Kristoffer
 */

#include"MenuItem.h"

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
MenuItem::MenuItem(){
    menuText = "";
    enabled = "false";
}

//------------------------------------------------------------------------------
// Konstruktor för initiering av datamedlemmar
//------------------------------------------------------------------------------
MenuItem::MenuItem(string menuText, bool enabled){
    this->menuText = menuText;
    this->enabled = enabled;
}

//------------------------------------------------------------------------------
// getMenuText
// Returnerar datamedlemmen menuText
//------------------------------------------------------------------------------
string MenuItem::getMenuText() const{
    return menuText;
}

//------------------------------------------------------------------------------
// setEnabled
// Datamedlemmen enabled ges värdet av parametern enabled
//------------------------------------------------------------------------------
void MenuItem::setEnabled(bool enabled){
    this->enabled = enabled;
}

//------------------------------------------------------------------------------
// getEnabled
// Returnerar datamedlemmen enabled
//------------------------------------------------------------------------------
bool MenuItem::getEnabled() const{
    return enabled;
}




