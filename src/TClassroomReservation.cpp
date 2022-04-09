//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroomReservation.h"
#include "../include/TCourse.h"
#include <utility>


TCourse *TClassroomReservation::getCourse() {
  return course;
}

int TClassroomReservation::getStartTime() const {
  return startTime;
}

int TClassroomReservation::getEndTime() const {
  return endTime;
}

TDate TClassroomReservation::getStartDate() {
  return startDate;
}

TDate TClassroomReservation::getEndDate() {
  return endDate;
}

std::vector<DayOfWeek> TClassroomReservation::getDays() {
  return days;
}

TClassroomReservation::TClassroomReservation(TClassroom* cl, TCourse* c, int tini, int tend, TDate dini, TDate dend,
                                             Tdays days) : classroom(cl), course(c), startTime(tini), endTime(tend),
                                             startDate(dini), endDate(dend), days(std::move(days)) {}

TClassroom *TClassroomReservation::getClassroom() {
  return classroom;
}


std::ostream& operator<<(std::ostream& os, TClassroomReservation& r) {
  TCourse* c = r.getCourse();
  os << "Course: " << c->getCode() << " - " << c->getName() << std::endl;
  TDate startDate = r.getStartDate();
  os << "Start date: " << startDate << std::endl;
  TDate endDate = r.getEndDate();
  os << "End date: " << endDate << std::endl;
  os << "Start time: " << r.getStartTime() << std::endl;
  os << "End time: " << r.getEndTime() << std::endl;
  os << "Days of the week: " << std::endl;
  vector<DayOfWeek> vec = r.getDays();
  for (auto & i : vec) {
    os << i;
  }
  os << std::endl;
  return os;
}
