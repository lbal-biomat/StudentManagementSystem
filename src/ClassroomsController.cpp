//
// Created by lucia on 6/4/22.
//

#include <cassert>
#include "../include/ClassroomsController.h"


void ClassroomsController::addClassroom(int num, int capacity) {
  assert(!existsClassroom(num));
  repoClassrooms.classrooms[num] = TClassroom(num, capacity);

}

void ClassroomsController::addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime, TDate startDate,
                                                   TDate endDate, std::vector<DayOfWeek>& days) {
  assert (existsClassroom(numRoom));
  TCourse* c = &repoCourses.courses[codeCourse];
  TClassroom* room = &repoClassrooms.classrooms[numRoom];
  if (room->getCapacity() < c->getMaxStudents()) {
    throw std::invalid_argument("Classroom is too small for the course.");
  }
  if (!room->available(startDate, endDate, startTime, endTime, days)) {
    throw std::invalid_argument("Classroom is not available.");
  }
  TClassroomReservation res(c, startTime, endTime, startDate, endDate, std::move(days));
  room->addReservation(res);

}

void ClassroomsController::printReservations(int numRoom) {
  assert (existsClassroom(numRoom));
  TClassroom clas = repoClassrooms.classrooms[numRoom];
  for (auto & r : clas.getReservations()) {
    std::cout << r << std::endl;
  }
}

bool ClassroomsController::existsClassroom(int classNum) const {
  return repoClassrooms.classrooms.contains(classNum);
}