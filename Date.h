#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Time.h"

using namespace std;

/**
 * @brief This class represents a date object. A date has a day, month, and year. Basic functionality is provided.
 * 
 * @author Boris Zugic
 */
class Date
{
  friend ostream& operator<<(ostream&, Date&);
  
  public:
    Date(int=0, int=0, int=2023, int = 0, int = 0);
    ~Date();
    static bool validate(int, int, int);
    Time& getTime();

    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool sameDay(const Date&) const;


  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth() const;
    bool leapYear() const;
    string getMonthStr() const;
    void setDate(int, int, int);
    Time time;
};

#endif
