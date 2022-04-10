//
// Created by lucia on 6/4/22.
//

#include <cassert>
#include "../include/ClassroomsController.h"


void ClassroomsController::addClassroom(int num, int capacity) {
  assert(!existsClassroom(num));
  repoClassrooms.classrooms[num] = TClassroom(num, capacity);

}

DTClassroom ClassroomsController::getClassroomInformation(int num) {
 return repoClassrooms.classrooms[num].getDTClassroom();
}


void ClassroomsController::addClassroomReservation(int num, int codeCourse, TTime startTime, TTime endTime, TDate startDate,
                                                   TDate endDate, const std::vector<DayOfWeek>& days) {
  assert (existsClassroom(num));
  assert(repoCourses.courses.contains(codeCourse));
  TCourse* c = &repoCourses.courses[codeCourse];
  TClassroom* room = &repoClassrooms.classrooms[num];
  if (!room->available(startDate, endDate, startTime, endTime, days)) {
    throw std::invalid_argument("Classroom is not available.");
  }
  TClassroomReservation res(num, c, startTime, endTime, startDate, endDate, days);
  room->addReservation(res);

}

std::vector<DTReservation> ClassroomsController::getClassroomsReservations(int num) {
  assert (existsClassroom(num));
  vector<TClassroomReservation> res = repoClassrooms.classrooms[num].getReservations();
  std::vector<DTReservation> dtres;
  for (auto & r : res) {
    DTReservation dtr = r.getDTReservation();
    dtres.push_back(dtr);
  }
  return  dtres;
}

bool ClassroomsController::existsClassroom(int classNum) const {
  return repoClassrooms.classrooms.contains(classNum);
}

bool ClassroomsController::isAvailable(int num, TTime startTime, TTime endTime, TDate startDate, TDate endDate,
                                       const vector<DayOfWeek> &days) {
  return repoClassrooms.classrooms[num].available(startDate, endDate, startTime, endTime, days);
}
