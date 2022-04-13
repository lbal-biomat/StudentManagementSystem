//
// Created by lucia on 27/3/22.
//

#include "../include/TClassroomReservation.h"
#include "../include/TCourse.h"
#include <utility>


TTime TClassroomReservation::getStartTime() const {
  return startTime;
}

TTime TClassroomReservation::getEndTime() const {
  return endTime;
}

TDate TClassroomReservation::getStartDate() const {
  return startDate;
}

TDate TClassroomReservation::getEndDate() const {
  return endDate;
}

std::vector<DayOfWeek> TClassroomReservation::getDays() const {
  return days;
}

TClassroomReservation::TClassroomReservation(int cl, TCourse* c, std::string cod, TTime tini, TTime tend, TDate dini,
                       TDate dend, Tdays days) : classroom(cl), course(c), code(std::move(cod)), startTime(tini),
                       endTime(tend), startDate(dini), endDate(dend), days(std::move(days)) {}

DTReservation TClassroomReservation::getDTReservation() const {
  return {classroom, course->getCode(), code, startTime, endTime, startDate, endDate, days};
}

std::string TClassroomReservation::getCode() const {
  return code;
}

