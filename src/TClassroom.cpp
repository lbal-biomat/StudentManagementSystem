//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroom.h"
#include "../include/DayOfWeek.h"

#include <boost/date_time.hpp>

TClassroom::TClassroom(int cod, int cap) : number (cod), capacity (cap) {}

int TClassroom::getCode() const {
  return number;
}

int TClassroom::getCapacity() const {
  return capacity;
}

//aux funtion to get the day of the week of a TDate
DayOfWeek getDayOfWeek(TDate f) {
  boost::gregorian::date d(f.getYear(), f.getMonth(), f.getDay());
  int day = d.day_of_week();
  return static_cast<DayOfWeek>(day);
}

bool TClassroom::available(TDate f, int horaIni, int horaFin) {
  DayOfWeek dia = getDayOfWeek(f);
  for (auto res : reservations) {
    if ((f > res.getStartDate()) && (f < res.getEndDate()))
      for (int j = 0; j < res.getDays().size(); ++j)
        if (res.getDays().at(j) == dia) //matching day of week
          if (!((horaIni <= res.getEndTime()) && (res.getStartTime() <= horaFin))) //overlaping times
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
