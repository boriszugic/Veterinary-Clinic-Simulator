#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(int d, int m, int y, int h, int min)
{
  setDate(d, m, y);
  time = Time(h, min);
}

Date::~Date(){}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y >= 2023) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

int Date::lastDayInMonth() const
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear() const
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::validate(int day, int month, int year){

  Date temp = Date(day, month, year);
  
  if (temp.day && temp.month && temp.year)
    return true;
  
  return false;
}

bool Date::operator==(const Date& d) const{

  if (this->year == d.year && this->month == d.month && this->day == d.day && this->time == d.time)
    return true;

  return false;
}

bool Date::operator<(const Date& d) const{

  if (this->year < d.year || (this->year == d.year && this->month < d.month) || (this->year == d.year && this->month == d.month && this->day < d.day)
  || (this->year == d.year && this->month == d.month && this->day == d.day && this->time < d.time))
    return true;
  
  return false;
}

bool Date::operator>(const Date& d) const{

  if (this->year > d.year || (this->year == d.year && this->month > d.month) || (this->year == d.year && this->month == d.month && this->day > d.day))
    return true;

  return false;
}

ostream& operator<<(ostream& output, Date& d){

  output.fill('0');
  output << d.year << "-" << setw(2) << d.month << "-" << setw(2) << d.day << " @ " <<  d.time;

  return output;
}

bool Date::sameDay(const Date& d) const{
  return (this->year == d.year && this->month == d.month && this->day == d.day);
}

Time& Date::getTime(){return time;}