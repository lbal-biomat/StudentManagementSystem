//
// Created by lucia on 9/4/22.
//

#include "../include/DTStudent.h"

#include <utility>

DTStudent::DTStudent(int ID, std::string nom) : id(ID), name(std::move(nom)) {}

int DTStudent::getID() const {
  return id;
}

std::string DTStudent::getName() const {
  return name;
}


std::ostream& operator<<(std::ostream& os, DTStudent& e) {
  os << "Name: " << e.getName() << "\n";
  os << "ID: " << e.getID() << "\n";
  return os;
}