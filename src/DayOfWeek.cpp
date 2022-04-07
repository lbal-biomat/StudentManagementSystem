//
// Created by lucia on 7/4/22.
//

#include "../include/DayOfWeek.h"

std::ostream &operator<<(std::ostream &os, DayOfWeek &dow) {
  switch(dow) {
    case sunday:
      os << "Sunday ";
      break;
    case monday:
      os << "Monday ";
      break;
    case tuesday:
      os << "Tuesday ";
      break;
    case wednesday:
      os << "Wednesday ";
      break;
    case thursday:
      os << "Thursday ";
      break;
    case friday:
      os << "Friday ";
      break;
    case saturday:
      os << "Saturday ";
      break;
  }
  return os;
}
