/*
 * Time.cpp
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#include "Time.h"
#include <stdlib.h>

const int SEC_PER_HOUR = 3600;
const int SEC_PER_MIN = 60;

Time::Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

int Time::getTime() const{
    return seconds+(minutes*SEC_PER_MIN)+(hours*SEC_PER_HOUR);
}

void Time::setTime(int seconds){
    hours = seconds/SEC_PER_HOUR;
    seconds = seconds%SEC_PER_HOUR;
    minutes = seconds/SEC_PER_MIN;
    seconds = seconds%SEC_PER_MIN;
    this->seconds = seconds;
}

//------------------------------------------------------------------------------
// overloaded == operator
//
//------------------------------------------------------------------------------
bool Time::operator==(const Time &time) const {
    return getTime() == time.getTime();
}

//------------------------------------------------------------------------------
// overloaded < operator
//
//------------------------------------------------------------------------------
bool Time::operator<(const Time &time) const {
    if (getTime() < time.getTime()) {
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
// overloaded + operator
//
//------------------------------------------------------------------------------
Time Time::operator+(const Time &time) const{
    int seconds = getTime() + time.getTime();
    Time newTime;
    newTime.setTime(seconds);
    return newTime;
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
    getline(is, tmpLength, '\r');
    is.ignore();
    time.setTime(atoi(tmpLength.c_str()));
    return is;
}
