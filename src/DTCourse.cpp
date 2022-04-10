//
// Created by lucia on 9/4/22.
//

#include "../include/DTCourse.h"
#include <iostream>

#include <utility>

DTCourse::DTCourse(int cod, int cred, std::string nom) :
                  code(cod), credits(cred), name(std::move(nom)) {}

std::ostream& operator<<(std::ostream& os, DTCourse& c) {
  os << "Name: " << c.name << std::endl;
  os << "Code: " << c.code << std::endl;
  os << "Credits awarded: " << c.credits << std:: endl;
  return os;
}