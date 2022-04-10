//
// Created by lucia on 9/4/22.
//

#include "../include/DTReservation.h"

#include <utility>



DTReservation::DTReservation(int cl, int c, TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays d) :
classroom(cl), course(c), startTime(tini), endTime(tend), startDate(dateIni), endDate(dateEnd), days(std::move(d)) {}

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
  os << "Course: " << r.getCourse() << "\n";
  TDate startDate = r.getStartDate();
  os << "Start date: " << startDate << "\n";
  TDate endDate = r.getEndDate();
  os << "End date: " << endDate << "\n";
  TTime startTime = r.getStartTime();
  os << "Start time: " << startTime << "\n";
  TTime endTime = r.getEndTime();
  os << "End time: " << endTime << "\n";
  os << "Days of the week: " << "\n";
  std::vector<DayOfWeek> vec = r.getDays();
  for (auto & i : vec) {
    os << i;
  }
  os << "\n";
  return os;
}