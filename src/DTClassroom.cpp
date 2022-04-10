//
// Created by lucia on 9/4/22.
//

#include "../include/DTClassroom.h"

#include <utility>



DTClassroom::DTClassroom(int num, int cap, std::vector<DTReservation> res) :
                        number(num), capacity(cap), reservations(std::move(res)) {}


std::ostream& operator<<(std::ostream& os, DTClassroom& c) {
  os << "Classroom number: " << c.number << "\n";
  os << "Capacity: " << c.capacity << "\n";
  for (auto &r: c.reservations) {
    std::cout << r;
  }
  return os;
}