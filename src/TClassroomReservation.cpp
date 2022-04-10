//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroomReservation.h"
#include "../include/TCourse.h"
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

TClassroomReservation::TClassroomReservation(int cl, TCourse* c, TTime tini, TTime tend, TDate dini, TDate dend,
                                             Tdays days) : classroom(cl), course(c), startTime(tini), endTime(tend),
                                             startDate(dini), endDate(dend), days(std::move(days)) {}

DTReservation TClassroomReservation::getDTReservation() {
  return {classroom, course ->getCode(), startTime, endTime, startDate, endDate, days};
}

