//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroom.h"


TClassroom::TClassroom(int cod, int cap) : number (cod), capacity (cap) {}


bool TClassroom::available(TDate startDate, TDate endDate, TTime startTime, TTime endTime, const std::vector<DayOfWeek>& days) {
  for (auto & res : reservations) {
    bool match = false;
    for (auto & day : res.getDays())
      if (std::any_of(days.begin(), days.end(), [day](const DayOfWeek & d) {return d == day;})) {
          match = true;
          break;
      }
    if (match) //overlapping days of week
      if (startDate < res.getEndDate() && res.getStartDate() < endDate) //overlapping dates
        if (startTime < res.getEndTime() && res.getStartTime() < endTime) //overlapping times
          return false; //is not available
  }
  return true;
}

void TClassroom::addReservation(const TClassroomReservation& res) {
  reservations.push_back(res);
}

std::vector<TClassroomReservation> TClassroom::getReservations() const {
  return reservations;
}

TClassroom::TClassroom() {
  capacity = 0;
  number = 0;
}

DTClassroom TClassroom::getDTClassroom() const {
  std::vector<DTReservation> dtres;
  for (auto & r : reservations) {
    DTReservation dtr = r.getDTReservation();
    dtres.push_back(dtr);
  }
  return {number, capacity, dtres};
}
