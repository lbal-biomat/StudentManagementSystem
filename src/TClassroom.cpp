//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroom.h"


TClassroom::TClassroom(int cod, int cap) : number (cod), capacity (cap) {}

int TClassroom::getNumber() const {
  return number;
}

int TClassroom::getCapacity() const {
  return capacity;
}


bool TClassroom::available(TDate startDate, TDate endDate, int horaIni, int horaFin, const vector<DayOfWeek>& days) {
  for (auto & res : reservations) {
    bool match = false;
    for (auto & day : res.getDays())
      for (auto &d: days)
        if (day == d)
          match = true;
    if (!match) //no overlapping days of week
      return true;
    else if ((startDate < res.getEndDate()) && (res.getStartDate() < endDate)) //overlapping dates
      for (int j = 0; j < res.getDays().size(); ++j)
        if (!((horaIni <= res.getEndTime()) && (res.getStartTime() <= horaFin))) //overlapping times
          return false; //is not available
  }
  return true;
}

void TClassroom::addReservation(const TClassroomReservation& res) {
  reservations.push_back(res);
}

vector<TClassroomReservation> TClassroom::getReservations() {
  return reservations;
}

TClassroom::TClassroom() {
  capacity = 0;
  number = 0;
}
