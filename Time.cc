#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m) : hours(h), minutes(m){}

bool Time::operator==(const Time& t) const
{
  if (this->hours == t.hours && this->minutes == t.minutes)
    return true;

  return false;
}

bool Time::operator<(const Time& t) const
{
  if (this->hours < t.hours || (this->hours == t.hours && this->minutes < t.minutes))
    return true;

  return false;
}

ostream& operator<<(ostream& output, Time& t)
{
  output << setfill('0') << setw(2) << t.hours << ":"
       << setfill('0') << setw(2) << t.minutes;

  return output;
}

void Time::add(int h, int m){

  this->hours += h + ((this->minutes + m) / 60);
  this->hours %= 24;
  this->minutes = (this->minutes + (m % 60)) % 60; 
}