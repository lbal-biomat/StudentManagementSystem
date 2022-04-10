//
// Created by lucia on 6/4/22.
//

#include "../include/CoursesController.h"
#include "../include/TStudent.h"
#include "../include/DTCourse.h"
#include <iostream>
#include <cassert>

void CoursesController::addCourse(int code, int credits, std::string name, int maxStudents) {
  assert(!existsCourse(code));
  repoCourses.courses[code] = TCourse(code, credits, std::move(name), maxStudents);
}

void CoursesController::printEnrolledStudents(int courseCode) {
  assert (existsCourse(courseCode));
  TCourse course = repoCourses.courses[courseCode];
  for (auto & s: course.getEnrolledStudents()) {
    std::cout << *s << std::endl;
  }
}

void CoursesController::addPreRequiredCourse(int code, int requiredCode) {
  assert (existsCourse(code) && existsCourse(requiredCode));
  TCourse* c = &repoCourses.courses[code];
  TCourse* pre = &repoCourses.courses[requiredCode];
  c->addPreRequiredCourse(pre);
}

std::vector<DTCourse> CoursesController::getPrerequisiteCourses(int codeCourse) {
  assert (existsCourse(codeCourse));
  TCourse course = repoCourses.courses[codeCourse];
  std::vector<DTCourse> dtc;
  for (auto & c: course.getPrerequisiteCourses()) {
    dtc.push_back(c->getDTCourse());
  }
  return dtc;
}

std::vector<DTCourse> CoursesController::getCoursesInformation() {
  std::vector<DTCourse> dtcourses;
  for( std::pair<const int, TCourse>& course : repoCourses.courses ) {
    DTCourse dtc = course.second.getDTCourse();
    dtcourses.push_back(dtc);
  }
  return dtcourses;
}

bool CoursesController::existsCourse(int code) const {
  return repoCourses.courses.contains(code);
}
