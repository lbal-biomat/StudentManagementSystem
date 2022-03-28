//
// Created by lucia on 27/3/22.
//

#include "../include/System.h"

#include <utility>

void System::registerStudent(int ID, string name) {
  for (auto &s : students) {
    if (ID == s.getID())
      throw std::invalid_argument("There is a student with that ID in the system.");
  }
  TStudent newStudent(ID, std::move(name));
  students.push_back(newStudent);
}

void System::addClassroom(int code, int capacity) {
  for (auto & c : classrooms) {
    if (code == c.getCode())
      throw std::invalid_argument("There is a classroom with that number in the system.");
  }
  TClassroom nuevoSalon(code, capacity);
  classrooms.push_back(nuevoSalon);
}

void System::addCourse(int code, int credits, string nombre) {
  for (auto & course : courses) {
    if (code == course.getCode())
      throw std::invalid_argument("There is a course with that code in the system.");
  }
  TCourse newCode(code, credits, std::move(nombre));
  courses.push_back(newCode);
}

void System::enrollStudentInCourse(int ID, int code) {
  //agregar throw si estudiante no esta registrado
  TStudent* est = getPointerToStudent(ID);
  if (est->isEnrolled(code)) {
    throw std::invalid_argument("Student is already enrolled.");
  }
  TCourse* course = getPointerToCourse(code);
  course->addStudent(est);
  est->addEnrollment(course);
}

void System::unenrollStudentFromCourse(int ID, int code) {
  TCourse* cur = getPointerToCourse(code);
  cur->unenrollStudent(ID);
}

void System::addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime,
                                     TDate startDate, TDate endDate, vector<DayOfWeek> days) {
  TCourse* c = getPointerToCourse(codeCourse);
  TClassroom* room = getPointerToClassroom(numRoom);
  if (room->available(startDate, endDate, startTime, endTime, days)) {
    TClassroomReservation res(c, startTime, endTime, startDate, endDate, std::move(days));
    room->addReservation(res);
  }
}

vector<TCourse *> System::queryPrerequisiteCourses(int codeCourse) {
  return getPointerToCourse(codeCourse)->getPrerequisiteCourses();
}

vector<TClassroomReservation> System::queryReservations(int numRoom) {
  return getPointerToClassroom(numRoom)->getReservations();
}

TStudent *System::getPointerToStudent(int ID) {
  for (auto & s : students) {
    if (s.getID() == ID)
      return &s;
  }
  return nullptr;
}

TCourse *System::getPointerToCourse(int cod) {
  for (auto & curso : courses) {
    if (curso.getCode() == cod)
      return &curso;
  }
  return nullptr;
}

TClassroom *System::getPointerToClassroom(int cod) {
  for (auto & c : classrooms) {
    if (c.getCode() == cod)
      return &c;
  }
  return nullptr;
}

vector<TCourse> System::getCourses() {
  return courses;
}

vector<TStudent> System::getStudents() {
  return students;
}

void System::printStudentTranscript(int ID) {
  getPointerToStudent(ID)->printTranscripts();
}

void System::addApprovalToStudent(int ID, int courseNum, int grade, TDate date) {
  TStudent* st = getPointerToStudent(ID);
  TCourse* c = getPointerToCourse(courseNum);
  st->addApproval({c, grade, date});
}

vector<TStudent *> System::getEnrolledStudents(int courseCode) {
  return getPointerToCourse(courseCode)->getEnrolledStudents();
}
