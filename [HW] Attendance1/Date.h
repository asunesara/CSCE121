#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  int years;
  int months;
  int days;
  int hours;
  int mins;
  int secs;

public:
  Date(int years, int months, int days, int hours, int mins, int secs);
  Date(int hours, int mins, int secs=0); 
  int getYear() const { return years; }
  int getMonth() const { return months; }
  int getDay() const { return days; }
  int getHour() const { return hours; }
  int getMin() const { return mins; }
  int getSec() const { return secs; }
  std::string getDateTime() const;
  std::string getDate() const;
  std::string getTime(bool withSeconds=true) const;
  bool isValid() const;

  bool operator<(const Date& d) const;
  bool operator>(const Date& d) const;
  bool operator<=(const Date& d) const;
  bool operator>=(const Date& d) const;
};

#endif