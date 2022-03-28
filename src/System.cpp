//
// Created by lucia on 27/3/22.
//

#include "../include/System.h"

#include <utility>
#include <iostream>

void System::registerStudent(int ID, string name) {
  if (existsStudent(ID)) {
    throw std::invalid_argument("There is a student with that ID in the system.");
  }
  TStudent newStudent(ID, std::move(name));
  students.push_back(newStudent);
}

void System::addClassroom(int num, int capacity) {
  if (existsClassroom(num)) {
    throw std::invalid_argument("There is a classroom with that number in the system.");
  }
  TClassroom nuevoSalon(num, capacity);
  classrooms.push_back(nuevoSalon);
}

void System::addCourse(int code, int credits, string nombre) {
  if (existsCourse(code)) {
    throw std::invalid_argument("There is a course with that code in the system.");
  }
  TCourse newCode(code, credits, std::move(nombre));
  courses.push_back(newCode);
}

void System::enrollStudentInCourse(int ID, int code) {
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  if (!existsCourse(code)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TStudent* est = getPointerToStudent(ID);
  if (est->isEnrolled(code)) {
    throw std::invalid_argument("Student is already enrolled.");
  }
  TCourse* course = getPointerToCourse(code);
  course->addStudent(est);
  est->addEnrollment(course);

}

void System::unenrollStudentFromCourse(int ID, int code) {
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  if (!existsCourse(code)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TStudent* est = getPointerToStudent(ID);
  if (!est->isEnrolled(code)) {
    throw std::invalid_argument("Student isn't enrolled in this course.");
  }
  TCourse* cur = getPointerToCourse(code);
  cur->unenrollStudent(ID);
}

void System::addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime,
                                     TDate startDate, TDate endDate, vector<DayOfWeek> days) {
  if (!existsClassroom(numRoom)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.");
  }
  if (!existsCourse(codeCourse)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TCourse* c = getPointerToCourse(codeCourse);
  TClassroom* room = getPointerToClassroom(numRoom);
  if (!room->available(startDate, endDate, startTime, endTime, days)) {
    throw std::invalid_argument("Classroom is not available.");
  }
  TClassroomReservation res(c, startTime, endTime, startDate, endDate, std::move(days));
  room->addReservation(res);
}

vector<TCourse *> System::queryPrerequisiteCourses(int codeCourse) {
  if (!existsCourse(codeCourse)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  return getPointerToCourse(codeCourse)->getPrerequisiteCourses();
}

vector<TClassroomReservation> System::queryReservations(int numRoom) {
  if (!existsClassroom(numRoom)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.");
  }
  return getPointerToClassroom(numRoom)->getReservations();
}

TStudent *System::getPointerToStudent(int ID) {
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  for (auto & s : students) {
    if (s.getID() == ID)
      return &s;
  }
  return nullptr;
}

TCourse *System::getPointerToCourse(int cod) {
  if (!existsCourse(cod)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  for (auto & curso : courses) {
    if (curso.getCode() == cod)
      return &curso;
  }
  return nullptr;
}

TClassroom *System::getPointerToClassroom(int num) {
  if (!existsClassroom(num)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.");
  }
  for (auto & c : classrooms) {
    if (c.getNumber() == num)
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
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  getPointerToStudent(ID)->printTranscripts();
}

void System::addApprovalToStudent(int ID, int courseCod, int grade, TDate date) {
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  if (!existsCourse(courseCod)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TStudent* st = getPointerToStudent(ID);
  TCourse* c = getPointerToCourse(courseCod);
  st->addApproval({c, grade, date});
}

vector<TStudent *> System::getEnrolledStudents(int courseCode) {
  if (!existsCourse(courseCode)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  return getPointerToCourse(courseCode)->getEnrolledStudents();
}


bool System::existsStudent(int ID) {
  for (auto & s : students) {
    if (s.getID() == ID) {
      return true;
    }
  }
  return false;
}

bool System::existsClassroom(int classNum) {
  for (auto & c: classrooms) {
    if (c.getNumber() == classNum)
      return true;
  }
  return false;
}

bool System::existsCourse(int code) {
  for (auto & c: courses) {
    if (c.getCode() == code)
      return true;
  }
  return false;
}
