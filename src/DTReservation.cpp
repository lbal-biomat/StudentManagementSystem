//
// Created by lucia on 9/4/22.
//

#include "../include/DTReservation.h"

#include <utility>



DTReservation::DTReservation(int cl, int c, std::string cod,  TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays d) :
               classroom(cl), course(c), code(std::move(cod)), startTime(tini), endTime(tend), startDate(dateIni),
               endDate(dateEnd), days(std::move(d)) {}

TTime DTReservation::getStartTime() const {
  return startTime;
}

TTime DTReservation::getEndTime() const {
  return endTime;
}

TDate DTReservation::getStartDate() const {
  return startDate;
}

TDate DTReservation::getEndDate() const {
  return endDate;
}

Tdays DTReservation::getDays() const {
  return days;
}

int DTReservation::getClassroom() const {
  return classroom;
}

int DTReservation::getCourse() const {
  return course;
}


std::ostream& operator<<(std::ostream& os, DTReservation& r) {
  os << "Code: " << r.code << "\n";
  os << "Course: " << r.course << "\n";
  TDate startDate = r.startDate;
  os << "Start date: " << startDate << "\n";
  TDate endDate = r.endDate;
  os << "End date: " << endDate << "\n";
  TTime startTime = r.startTime;
  os << "Start time: " << startTime << "\n";
  TTime endTime = r.endTime;
  os << "End time: " << endTime << "\n";
  os << "Days of the week: " << "\n";
  std::vector<DayOfWeek> vec = r.days;
  for (auto & i : vec) {
    os << i;
  }
  os << "\n";
  return os;
}

std::string DTReservation::getCode() const {
  return code;
}
