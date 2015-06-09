/*
 * Time.cpp
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#include "Time.h"

const int SEC_PER_HOUR = 3600;
const int SEC_PER_MIN = 60;

Time::Time(){

}

Time::Time(int seconds){
    hours = seconds/SEC_PER_HOUR;
    seconds = seconds%SEC_PER_HOUR;
    minutes = seconds/SEC_PER_MIN;
    seconds = seconds%SEC_PER_MIN;
    this->seconds = seconds;
}

int Time::getTime() const{
    return seconds+(minutes*SEC_PER_MIN)+(hours*SEC_PER_HOUR);
}

void Time::setTime(int seconds){

}

//------------------------------------------------------------------------------
// overloaded << operator
//
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Time &time) {
    os  << time.getTime();
    return os;
}

//------------------------------------------------------------------------------
// overloaded >> operator
//
//------------------------------------------------------------------------------
istream &operator>>(istream &is, Time &time) {
    string tmpLength;
    getline(is, tmpLength, '\n');
    time.setTime(atoi(tmpLength.c_str()));
    return is;
}
