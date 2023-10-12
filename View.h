#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief This class serves to display menu options, and read in the option chosen by user. A helper class of Control.
 * 
 * @author Boris Zugic
 */
class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
