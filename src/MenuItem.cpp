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
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
MenuItem::MenuItem(string menuText, bool enabled){
    this->menuText = menuText;
    this->enabled = enabled;
}

//------------------------------------------------------------------------------
// setText
// Datamedlemmen text ges värdet av parametern menuText
//------------------------------------------------------------------------------
void MenuItem::setMenuText(string menuText){
    this->menuText = menuText;
}

//------------------------------------------------------------------------------
// getText
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




