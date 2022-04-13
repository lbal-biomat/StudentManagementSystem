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
  TClassroomReservation res(num, c, startTime, endTime, startDate, endDate, days);
  room->addReservation(res);

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

bool ClassroomsController::isAvailable(int num, TTime startTime, TTime endTime, TDate startDate, TDate endDate,
                                       const std::vector<DayOfWeek> &days) {
  return repoClassrooms.classrooms[num].available(startDate, endDate, startTime, endTime, days);
}
