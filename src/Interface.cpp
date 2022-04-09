//
// Created by lucia on 5/4/22.
//

#include "../include/Interface.h"
#include <string>
#include <vector>

int Interface::getInt(const std::string &message) {
  int input = -1;
  bool valid = false;
  do {
    std::cout << message;
    std::cin >> input;
    if (std::cin.good()) {	valid = true;}
    else {
      std::cin.clear(std::cin.rdstate() & ~std::ios_base::failbit);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid entry, try again.\n ";
    }
  } while (!valid);
  return input;
}

TDate Interface::getDate(const std::string& message) {
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
  TDate d(day, month, year);
  return d;
}

std::vector<DayOfWeek> Interface::getDaysOfWeek() {
  std::cout << "Enter every day of the week the reservation applies to and end with '.' : \n" <<
            "0-Sunday\n1-Monday\n2-Tuesday\n3-Wednesday\n4-Thursday\n5-Friday\n6-Saturday\n";
  std::vector<DayOfWeek> vec;
  int day;
  while (std::cin >> day) {
    vec.push_back(static_cast<DayOfWeek>(day));
  }
  return vec;
}


bool Interface::validateID(int numID) {

  if (1111111 > numID || 99999999 < numID) {
    return false;
  }
  std::string id = std::to_string(numID);
  const char valChar = id[id.size() - 1];
  int valDig = valChar - '0';

  std::string baseNumber = "8123476";
  if (id.size() == 7) {
    baseNumber = "123476";
  }
  int sum = 0;

  for (int i = 0; i < id.size() - 1; i++) {
    int n = id[i] - '0';
    int base = baseNumber[i] - '0';
    sum += n*base;
  }

  int res = sum % 10;
  return res == valDig;
}

void Interface::callMenu(Menu menu, const std::string& exitCall) {
  bool exit = false;
  do {
    std::cout << menu;

    if (std::cin >> menu) {
      if ((menu.options[menu.input].first == exitCall)) {
        exit = true;
      } else {
        menu.options[menu.input].second();
      }
    }
    else { //bad option
      std::cout << "Not a valid option. Try again.\n";
      std::cin.clear(std::cin.rdstate() & ~std::ios_base::failbit);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (!exit);
}
