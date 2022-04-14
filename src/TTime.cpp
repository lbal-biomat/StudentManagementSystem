//
// Created by lucia on 9/4/22.
//

#include "../include/TTime.h"


TTime::TTime(int h, int m) : hour(h), min(m) {
  if (!isValidTime()) {
    throw std::invalid_argument("Invalid time");
  }
}

bool TTime::operator>(TTime t) const {
  return hour*60 + min > t.hour * 60 + t.min;
}

bool TTime::operator<(TTime t) const {
  return hour*60 + min < t.hour * 60 + t.min;
}

bool TTime::operator==(TTime) const {
  return false;
}

bool TTime::isValidTime() const {
  return (hour >= 0 && hour < 24 && min >= 0 && min < 60);
}

std::ostream &operator<<(std::ostream &os, TTime &t) {
  os << t.hour << ":" << t.min;
  return os;
}
