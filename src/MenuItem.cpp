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
    text = "";
    enabled = "false";
}

//------------------------------------------------------------------------------
// Förvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
MenuItem::MenuItem(string text, bool enabled){
    this->text = text;
    this->enabled = enabled;
}

//------------------------------------------------------------------------------
// setText
// Datamedlemmen text ges värdet av parametern text
//------------------------------------------------------------------------------
void MenuItem::setText(string text){
    this->text = text;
}

//------------------------------------------------------------------------------
// getText
// Returnerar datamedlemmen text
//------------------------------------------------------------------------------
string MenuItem::getText() const{
    return text;
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




