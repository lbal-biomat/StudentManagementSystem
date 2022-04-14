//
// Created by lucia on 27/3/22.
//


#include "../include/TDate.h"
#include "ctime"


TDate::TDate(int d, int m, int y) {
  date = {};
  date.tm_year = y - 1900;
  date.tm_mon = m - 1;
  date.tm_mday = d;
  if (!isValidDate()) {
    throw std::invalid_argument("Invalid date");
  }
}

int TDate::getDay() const {
  return date.tm_mday;
}

int TDate::getMonth() const {
  return date.tm_mon + 1;
}

int TDate::getYear() const {
  return date.tm_year + 1900;
}

bool TDate::operator==(TDate f) const {
  return (date.tm_year == f.date.tm_year && date.tm_mon == f.date.tm_mon && date.tm_mday == f.date.tm_mday);
}

bool TDate::operator<(TDate f) {
  return difftime(mktime( &date ), mktime(& f.date)) < 0;
}

bool TDate::operator>(TDate f) {
  return difftime(mktime( &date ), mktime(& f.date)) > 0;

}

std::ostream& operator<<(std::ostream& os, TDate& f) {
  os << f.getDay() << '/' << f.getMonth() + 1 << '/' << f.getYear() + 1900;
  return os;
}

bool TDate::isValidDate() {
  tm copy = date;
  mktime(&copy);
  return (copy.tm_year == date.tm_year && copy.tm_mon == date.tm_mon && copy.tm_mday == date.tm_mday);
}