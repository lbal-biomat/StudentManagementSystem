//
// Created by lucia on 6/4/22.
//

#include "../include/CoursesController.h"
#include "../include/TStudent.h"
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

void CoursesController::printPrerequisiteCourses(int codeCourse) {
  assert (existsCourse(codeCourse));
  TCourse course = repoCourses.courses[codeCourse];
  for (auto & c: course.getPrerequisiteCourses()) {
    std::cout << *c << std::endl;
  }
}

void CoursesController::printCourses() {
  for( std::pair<const int, TCourse>& st : repoCourses.courses ) {
    std::cout << st.second << std::endl;
  }
}

bool CoursesController::existsCourse(int code) const {
  return repoCourses.courses.contains(code);
}
