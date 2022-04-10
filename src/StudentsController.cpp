//
// Created by lucia on 6/4/22.
//

#include "../include/StudentsController.h"

#include <cassert>

void StudentsController::registerStudent(int ID, std::string name) {
  assert(!existsStudent(ID));
  repoStudents.students[ID] = TStudent(ID, std::move(name));
}

void StudentsController::addApprovalToStudent(int ID, int courseCod, int grade, TDate date) {
  assert (existsStudent(ID));
  TStudent* st = &repoStudents.students[ID];
  for (auto & a : st->getApprovals()) {
    if (a.getCourse()->getCode() == courseCod) {
      throw std::invalid_argument("There is an approval for this course in the student's records.");
    }
  }
  TCourse* c = &repoCourses.courses[courseCod];
  st->addApproval({c, grade, date});

}

void StudentsController::enrollStudentInCourse(int ID, int code) {
  assert (existsStudent(ID));
  TStudent* est = &repoStudents.students[ID];
  if (est->isEnrolled(code)) {
    throw std::invalid_argument("Student is already enrolled.");
  }
  TCourse* course = &repoCourses.courses[code];
  course->addStudent(est);
  est->enroll(course);

}

void StudentsController::unenrollStudentFromCourse(int ID, int code) {
  assert (existsStudent(ID));
  TStudent* est = &repoStudents.students[ID];
  if (!est->isEnrolled(code)) {
    throw std::invalid_argument("Student isn't enrolled in this course.");
  }
  repoCourses.courses[code].unenrollStudent(ID);
  est->unenroll(code);

}

std::vector<DTCourse> StudentsController::getStudentEnrollments(int ID) {
  assert(existsStudent(ID));
  std::vector<DTCourse> courses;
  auto enr = repoStudents.students[ID].getCurrentEnrollments();
  courses.reserve(enr.size());
  for (auto & e : enr) {
    courses.push_back(e->getDTCourse());
  }
  return courses;
}

TTranscript StudentsController::getStudentTranscript(int ID) {
  assert (existsStudent(ID));
  return repoStudents.students[ID].getTranscript();
}

std::vector<DTStudent> StudentsController::getStudentsInformation() {
  std::vector<DTStudent> res;
  res.reserve(repoStudents.students.size());
  for( std::pair<const int, TStudent>& st : repoStudents.students ) {
    DTStudent dts = st.second.getDTStudent();
    res.push_back(dts);
  }
  return res;
}

bool StudentsController::existsStudent(int ID) const {
  return repoStudents.students.contains(ID);
}

bool StudentsController::existsCourse(int cod) const {
  return repoCourses.courses.contains(cod);
}
