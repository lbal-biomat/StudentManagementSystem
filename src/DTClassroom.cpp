//
// Created by lucia on 9/4/22.
//

#include "../include/DTClassroom.h"

#include <utility>



DTClassroom::DTClassroom(int num, int cap, std::vector<DTReservation> res) :
                        number(num), capacity(cap), reservations(std::move(res)) {}

int DTClassroom::getNumber() const {
  return number;
}

int DTClassroom::getCapacity() const {
  return capacity;
}

std::vector<DTReservation> DTClassroom::getReservations() {
  return reservations;
}


std::ostream& operator<<(std::ostream& os, DTClassroom& c) {
  os << "Classroom number: " << c.getNumber() << "\n";
  os << "Capacity: " << c.getCapacity() << "\n";
  for (auto &r: c.getReservations()) {
    std::cout << r;
  }
  return os;
}