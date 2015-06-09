/*
 * Time.h
 *
 *  Created on: 7 jun 2015
 *      Author: Kristoffer Freiholtz
 */

#ifndef SRC_TIME_H_
#define SRC_TIME_H_

using namespace std;
#include <iostream>

class Time{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    int getTime() const;
    void setTime(int seconds);
    bool operator==(const Time &time) const;
    bool operator<(const Time &time) const;
    Time operator+(const Time &time) const;

};

ostream &operator<<(ostream &os, const Time &time);
istream &operator>>(istream &is, Time &time);

#endif /* SRC_TIME_H_ */
