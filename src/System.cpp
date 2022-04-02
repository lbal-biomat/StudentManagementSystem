//
// Created by lucia on 27/3/22.
//

#include "../include/System.h"

#include <utility>
#include <iostream>

void System::registerStudent(int ID, string name) {
  bool valid = validateID(ID);
  if (!valid) {
    throw std::invalid_argument("Invalid ID.");
  }
  if (existsStudent(ID)) {
    throw std::invalid_argument("There is a student with that ID in the system.");
  }
  students[ID] = TStudent(ID, std::move(name));
}

void System::addClassroom(int num, int capacity) {
  if (existsClassroom(num)) {
    throw std::invalid_argument("There is a classroom with that number in the system.");
  }
  classrooms[num] = TClassroom(num, capacity);
}

void System::addCourse(int code, int credits, string nombre, int maxStudents) {
  if (existsCourse(code)) {
    throw std::invalid_argument("There is a course with that code in the system.");
  }
  courses[code] = TCourse(code, credits, std::move(nombre), maxStudents);
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
  if (room->getCapacity() < c->getMaxStudents()) {
    throw std::invalid_argument("Classroom is too small for the course.");
  }
  TClassroomReservation res(c, startTime, endTime, startDate, endDate, std::move(days));
  room->addReservation(res);
}

void System::printPrerequisiteCourses(int codeCourse) {
  if (!existsCourse(codeCourse)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TCourse course = courses[codeCourse];
  for (auto & c: course.getPrerequisiteCourses()) {
    std::cout << c << std::endl;
  }
}

void System::printReservations(int numRoom) {
  if (!existsClassroom(numRoom)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.");
  }
  TClassroom clas = classrooms[numRoom];
  for (auto & r : clas.getReservations()) {
    std::cout << r << std::endl;
  }
}

TStudent *System::getPointerToStudent(int ID) {
  if (!existsStudent(ID)) {
    throw std::invalid_argument("There isn't any student with that ID in the system.");
  }
  return &students[ID];
}

TCourse *System::getPointerToCourse(int cod) {
  if (!existsCourse(cod)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  return &courses[cod];
}

TClassroom *System::getPointerToClassroom(int num) {
  if (!existsClassroom(num)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.");
  }
  return &classrooms[num];
}

void System::printCourses() {
  for( std::pair<const int, TCourse>& st : courses ) {
    std::cout << st.second << std::endl;
  }
}

void System::printStudents() {
  for( std::pair<const int, TStudent>& st : students ) {
    std::cout << st.second << std::endl;
  }
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

void System::printEnrolledStudents(int courseCode) {
  if (!existsCourse(courseCode)) {
    throw std::invalid_argument("There isn't any course with that code in the system.");
  }
  TCourse course = courses[courseCode];
  for (auto & s: course.getEnrolledStudents()) {
    std::cout << s << std::endl;
  }
}


bool System::existsStudent(int ID) {
  return students.contains(ID);
}

bool System::existsClassroom(int classNum) {
  return classrooms.contains(classNum);
}

bool System::existsCourse(int code) {
  return courses.contains(code);
}

bool System::validateID(int numID) {

  bool valid = true;
  if (1111111 > numID || 99999999 < numID)
    valid = false;
  if (!valid) {
    throw std::invalid_argument("Entrada invalida");
  }
  string id = std::to_string(numID);
  const char valChar = id[id.size() - 1];
  int valDig = valChar - '0';

  string baseNumber = "8123476";
  if (id.size() == 7) {
    baseNumber = "123476";
  }
  int sum = 0;

  for (int i = 0; i < id.size() - 1; i++) {
    int n = id[i] - '0';
    int base = baseNumber[i] - '0';
    sum += n*base;
  }

  int res = sum % 10;
  return res == valDig;
}
