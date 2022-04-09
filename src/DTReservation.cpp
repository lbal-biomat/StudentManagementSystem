//
// Created by lucia on 9/4/22.
//

#include "../include/DTReservation.h"

#include <utility>



DTReservation::DTReservation(int cl, int c, int tini, int tend, TDate dateIni, TDate dateEnd, Tdays d) :
classroom(cl), course(c), startTime(tini), endTime(tend), startDate(dateIni), endDate(dateEnd), days(std::move(d)) {}

int DTReservation::getStartTime() const {
  return startTime;
}

int DTReservation::getEndTime() const {
  return endTime;
}

TDate DTReservation::getStartDate() {
  return startDate;
}

TDate DTReservation::getEndDate() {
  return endDate;
}

Tdays DTReservation::getDays() {
  return days;
}

int DTReservation::getClassroom() const {
  return classroom;
}

int DTReservation::getCourse() const {
  return course;
}
