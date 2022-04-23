//
// Created by lucia on 9/4/22.
//

#include "../include/DTStudent.h"

#include <utility>

DTStudent::DTStudent(int ID, std::string nom) : id(ID), name(std::move(nom)) {}


std::ostream& operator<<(std::ostream& os, DTStudent& e) {
  os << "Name: " << e.name << "\n";
  os << "ID: " << e.id << "\n";
  return os;
}