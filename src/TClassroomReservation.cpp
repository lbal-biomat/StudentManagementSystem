//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroomReservation.h"
#include "../include/TCourse.h"
#include "../include/TTime.h"
#include <utility>


TCourse *TClassroomReservation::getCourse() {
  return course;
}

TTime TClassroomReservation::getStartTime() const {
  return startTime;
}

TTime TClassroomReservation::getEndTime() const {
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

TClassroomReservation::TClassroomReservation(TCourse* c, TTime tini, TTime tend, TDate dini, TDate dend,
                                             Tdays days) : course(c), startTime(tini), endTime(tend),
                                             startDate(dini), endDate(dend), days(std::move(days)) {}



std::ostream& operator<<(std::ostream& os, TClassroomReservation& r) {
  TCourse* c = r.getCourse();
  os << "Course: " << c->getCode() << " - " << c->getName() << "\n";
  TDate startDate = r.getStartDate();
  os << "Start date: " << startDate << "\n";
  TDate endDate = r.getEndDate();
  os << "End date: " << endDate << "\n";
  TTime startTime = r.getStartTime();
  os << "Start time: " << startTime << "\n";
  TTime endTime = r.getEndTime();
  os << "End time: " << endTime << "\n";
  os << "Days of the week: " << "\n";
  vector<DayOfWeek> vec = r.getDays();
  for (auto & i : vec) {
    os << i;
  }
  os << "\n";
  return os;
}
