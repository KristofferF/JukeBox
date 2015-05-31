/*
 * MenuItem.h
 *
 *  Created on: 31 maj 2015
 *      Author: Kristoffer
 */

#ifndef SRC_MENUITEM_H_
#define SRC_MENUITEM_H_

#include<string>
using namespace std;

class MenuItem{
private:
    string text;
    bool enabled;

public:
    MenuItem();
    MenuItem(string text, bool enabled;
    void setText(string text);
    string getText() const;
    void setEnabled(bool enabled);
    bool getEnabled() const;
};

#endif /* SRC_MENUITEM_H_ */
