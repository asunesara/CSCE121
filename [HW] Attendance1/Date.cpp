#include <ctime>
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Date.h"

using std::string, std::stringstream, std::setw,  std::setfill, std::cout, std::endl;

// TODO: implement the two constructors
Date::Date(int year, int month, int day, int hour, int min, int sec): years(year), months(month), days(day), hours(hour), mins(min), secs(sec)
{

}
Date::Date(int hour, int min, int sec): hours(hour), mins(min), secs(sec)
{
  years =0;
  months =0;
  days =0;
}

// TODO: implement the < comparison operator
bool Date::operator<(const Date& rhs) const 
{
   if(hours < rhs.hours)
   {
     return true;
   }
    else if(hours > rhs.hours)
   {
     return false;
   }
    else if(mins<rhs.mins)
   {
     return true;
   }

   else if(mins > rhs.mins)
   {
     return false;
   }

   else if(secs<rhs.secs)
   {
     return true;
   }

    else if(secs > rhs.secs)
   {
     return false;
   }
   else
   {
     return false;
   }
}

// methods below are provided to students

string Date::getDateTime() const {
  stringstream ss;
  ss << months << "/" << days << "/" << years << " ";
  ss << setw(2) << setfill('0') << hours << ":"; 
  ss << setw(2) << setfill('0') << mins << ":";
  ss << setw(2) << setfill('0') << secs;
  return ss.str();
}

string Date::getDate() const {
  stringstream ss;
  ss << months << "/" << days << "/" << years;
  return ss.str();
}

string Date::getTime(bool withSeconds) const {
  stringstream ss;
  ss << setw(2) << setfill('0') << hours << ":"; 
  ss << setw(2) << setfill('0') << mins;
  if (withSeconds)
    ss << ":" << setw(2) << setfill('0') << secs;
  return ss.str();
}



bool Date::operator>(const Date& rhs) const 
{
  return rhs < *this;   
}

bool Date::operator<=(const Date& rhs) const 
{
  return !(*this > rhs);
     
}

bool Date::operator>=(const Date& rhs) const {
  return !(*this < rhs);
}

bool leap_year(unsigned int year) {
  /* From wikipedia: year which is a multiple of 4 (except for years evenly divisible by 100, 
   * which are not leap years unless evenly divisible by 400).
   */
  if (year % 400 == 0 
      || (year % 4 == 0 && year % 100 != 0)) {
    return true;
  }
  return false;
}

bool Date::isValid() const 
{
  if ((days == 0) || (months == 0)) 
  {
    return false;
  }
  if (months > 12) {
    return false;
  }
  unsigned int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31,
                                    31, 30, 31, 30, 31};
  if (leap_year(years)) {
    days_in_month[2] = 29;
  } 

  if (days > days_in_month[months]) {
    return false;
  }
  return true;
}