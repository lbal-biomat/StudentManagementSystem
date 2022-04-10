//
// Created by lucia on 9/4/22.
//

#include "../include/DTCourse.h"
#include <iostream>

#include <utility>

DTCourse::DTCourse(int cod, int cred, std::string nom) :
                  code(cod), credits(cred), name(std::move(nom)) {}

int DTCourse::getCode() const {
  return code;
}

int DTCourse::getCredits() const {
  return credits;
}

std::string DTCourse::getName() const {
  return name;
}

std::ostream& operator<<(std::ostream& os, DTCourse& c) {
  os << "Name: " << c.getName() << std::endl;
  os << "Code: " << c.getCode() << std::endl;
  os << "Credits awarded: " << c.getCredits() << std:: endl;
  return os;
}