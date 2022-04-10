//
// Created by lucia on 27/3/22.
//

#include "../include/TCourse.h"
#include "../include/TStudent.h"

#include <utility>

int TCourse::getCode() const {
  return code;
}

int TCourse::getCredits() const {
  return credits;
}

string TCourse::getName() const {
  return name;
}

vector<TCourse *> TCourse::getPrerequisiteCourses() const {
  return prerequisiteCourses;
}

vector<TStudent *> TCourse::getEnrolledStudents() const {
  return enrolledStudents;
}

void TCourse::enrollStudent(TStudent *s) {
  for (auto &course: prerequisiteCourses) {
    if (!s->hasApproval(course->getCode())) {
      throw std::invalid_argument("Student doesn't meet the prerequisites of this course.");
    }
  }
  enrolledStudents.push_back(s);
}

void TCourse::unenrollStudent(int ID) {
  for (int i = 0; i < enrolledStudents.size(); i++) {
    if (enrolledStudents.at(i)->getID() == ID)
      enrolledStudents.erase(enrolledStudents.begin() + i);
  }
}


TCourse::TCourse(int cod, int cred, string nom) : code(cod), credits(cred), name(std::move(nom)) {}


TCourse::TCourse() {
  code = 0;
  credits = 0;
}

void TCourse::addPreRequiredCourse(TCourse* c) {
  prerequisiteCourses.push_back(c);
}

DTCourse TCourse::getDTCourse() const {
  return {code, credits, name};
}