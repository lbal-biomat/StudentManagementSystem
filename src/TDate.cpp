//
// Created by lucia on 27/3/22.
//

/*For simplicity, dates are treated as every month having 30 days*/

#include "../include/TDate.h"

TDate::TDate(int dia, int mes, int anio) {
  this->day = dia;
  this->month = mes;
  this->year = anio;
}

int TDate::getDay() const {
  return this->day;
}

int TDate::getMonth() const {
  return this->month;
}

int TDate::getYear() const {
  return this->year;
}

bool TDate::operator==(TDate f) const {
  return (this->year == f.year &&
          this->month == f.month && this->day == f.day);
}

bool TDate::operator<(TDate f) const {
  int dias_param = f.day + f.month * 30 + f.year * 360;
  int dias_this = this->day + this->month * 30 + this->year * 360;
  int dif = dias_param - dias_this;
  if (dif > 0) {
    return true;
  }
  return false;
}

bool TDate::operator>(TDate f) const {
  int dias_param = f.day + f.month * 30 + f.year * 360;
  int dias_this = this->day + this->month * 30 + this->year * 360;
  int dif = dias_this - dias_param;
  if (dif > 0) {
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, TDate& f)
{
  os << f.getYear() << '/' << f.getMonth() << '/' << f.getDay();
  return os;
}