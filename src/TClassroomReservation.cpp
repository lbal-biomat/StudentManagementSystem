//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroomReservation.h"

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

TClassroomReservation::TClassroomReservation(TCourse* c, int tini, int tend, TDate dini, TDate dend, vector<DayOfWeek> days) :
        course(c), startTime(tini), endTime(tend), startDate(dini), endDate(dend), days(std::move(days)) {}


std::ostream& operator<<(std::ostream& os, TClassroomReservation& r) {
  os << r.getCourse();
  TDate startDate = r.getStartDate();
  os << "Start date: " << startDate;
  TDate endDate = r.getStartDate();
  os << "End date: " << endDate;
  os << "Start time: " << r.getStartTime() << std::endl;
  os << "End time: " << r.getEndTime() << std::endl;
  os << "Days of the week: ";
  vector<DayOfWeek> vec = r.getDays();
  for (auto & i : vec) {
    switch(i)
    {
      case sunday:
       os << "Sunday ";
        break;
      case monday:
        os << "Monday ";
        break;
      case tuesday:
        os << "Tuesday ";
        break;
      case wednesday:
        os << "Wednesday ";
        break;
      case thursday:
        os << "Thursday ";
        break;
      case friday:
        os << "Friday ";
        break;
      case saturday:
        os << "Saturday ";
        break;
    }
  }
  return os;
}
