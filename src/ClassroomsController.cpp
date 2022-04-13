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


void ClassroomsController::addClassroomReservation(const DTReservation& res) {
  assert (existsClassroom(res.getClassroom()));
  assert(repoCourses.courses.contains(res.getCourse()));
  TCourse* course = &repoCourses.courses[res.getCourse()];
  TClassroom* room = &repoClassrooms.classrooms[res.getClassroom()];
  if (!room->available(res.getStartDate(), res.getEndDate(), res.getStartTime(),
                       res.getEndTime(), res.getDays())) {
    throw std::invalid_argument("Classroom is not available.");
  }
  std::string cod = std::to_string(res.getClassroom()) + std::to_string(res.getCourse()) +
          std::to_string(res.getStartDate().getDay()) + std::to_string(res.getEndDate().getMonth()) +
          std::to_string(res.getStartDate().getYear()) +
          std::to_string(res.getStartTime().getHour()) + std::to_string(res.getStartTime().getMin());
  TClassroomReservation r(res.getClassroom(), course, cod, res.getStartTime(), res.getEndTime(),
                          res.getStartDate(), res.getEndDate(), res.getDays());
  room->addReservation(r);

}

std::vector<DTReservation> ClassroomsController::getClassroomsReservations(int num) {
  assert (existsClassroom(num));
  std::vector<TClassroomReservation> res = repoClassrooms.classrooms[num].getReservations();
  std::vector<DTReservation> dtres;
  dtres.reserve(res.size());
  for (auto & r : res) {
    DTReservation dtr = r.getDTReservation();
    dtres.push_back(dtr);
  }
  return  dtres;
}

bool ClassroomsController::existsClassroom(int classNum) const {
  return repoClassrooms.classrooms.contains(classNum);
}

bool ClassroomsController::isAvailable(const DTReservation& res) {
  assert (existsClassroom(res.getClassroom()));
  return repoClassrooms.classrooms[res.getClassroom()].available(res.getStartDate(), res.getEndDate(),
                                  res.getStartTime(), res.getEndTime(), res.getDays());
}
