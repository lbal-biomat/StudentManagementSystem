//
// Created by lucia on 27/3/22.
//

/*For simplicity, dates are treated as every month having 30 days*/

#include "../include/TDate.h"

TDate::TDate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

int TDate::getDay() const {
  return day;
}

int TDate::getMonth() const {
  return month;
}

int TDate::getYear() const {
  return year;
}

bool TDate::operator==(TDate f) const {
  return (year == f.year &&
          month == f.month && day == f.day);
}

bool TDate::operator<(TDate f) const {
  int dias_param = f.day + f.month * 30 + f.year * 360;
  int dias_this = day + month * 30 + year * 360;
  int dif = dias_param - dias_this;
  if (dif > 0) {
    return true;
  }
  return false;
}

bool TDate::operator>(TDate f) const {
  int dias_param = f.day + f.month * 30 + f.year * 360;
  int dias_this = day + month * 30 + year * 360;
  int dif = dias_this - dias_param;
  if (dif > 0) {
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, TDate& f) {
  os << f.getDay() << '/' << f.getMonth() << '/' << f.getYear();
  return os;
}