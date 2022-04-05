//
// Created by lucia on 5/4/22.
//

#include "../include/Interface.h"

int Interface::getInt(const string &message) {
  int input = -1;
  bool valid = false;
  do {
    std::cout << message;
    std::cin >> input;
    if (std::cin.good()) {	valid = true;}
    else {
      std::cin.clear();
      std::cin.ignore(999,'\n');
      std::cerr << "Invalid entry, try again.\n ";
    }
  } while (!valid);
  return input;
}

TDate Interface::getDate(const string& message) {
  int day, month, year;
  bool valid = false;
  do {
    std::cout << message;
    std::cin >> day;
    std::cin >> month;
    std::cin >> year;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
      std::cerr << "Invalid date. Try again.\n";
    }
    else {valid = true;}
  } while (!valid);
  return {day, month, year};
}

vector<DayOfWeek> Interface::getDaysOfWeek() {

  std::cout << "Enter every day of the week the reservation applies to and end with '.' : \n" <<
            "0-Sunday\n" <<
            "1-Monday\n" <<
            "2-Tuesday\n" <<
            "3-Wednesday\n" <<
            "4-Thursday\n" <<
            "5-Friday\n" <<
            "6-Saturday\n";
  vector<DayOfWeek> vec;
  int day;
  while (std::cin >> day) {
    vec.push_back(static_cast<DayOfWeek>(day));
  }
  return vec;
}


Interface::Interface(System& sis) {
  system = sis;
}