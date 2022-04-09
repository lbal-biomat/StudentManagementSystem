//
// Created by lucia on 6/4/22.
//

#include <cassert>
#include "../include/ClassroomsController.h"


void ClassroomsController::addClassroom(int num, int capacity) {
  assert(!existsClassroom(num));
  repoClassrooms.classrooms[num] = TClassroom(num, capacity);

}

void ClassroomsController::printClassroomInformation(int num) {
 std::cout << repoClassrooms.classrooms[num] << "\n";
}


void ClassroomsController::addClassroomReservation(int num, int codeCourse, int startTime, int endTime, TDate startDate,
                                                   TDate endDate, std::vector<DayOfWeek>& days) {
  assert (existsClassroom(num));
  assert(repoCourses.courses.contains(codeCourse));
  TCourse* c = &repoCourses.courses[codeCourse];
  TClassroom* room = &repoClassrooms.classrooms[num];
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

bool ClassroomsController::isAvailable(int num, int startTime, int endTime, TDate startDate, TDate endDate,
                                       vector<DayOfWeek> &days) {
  return repoClassrooms.classrooms[num].available(startDate, endDate, startTime, endTime, days);
}
