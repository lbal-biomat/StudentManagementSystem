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

string TCourse::getName() {
  return name;
}

vector<TCourse *> TCourse::getPrerequisiteCourses() {
  return prerequisiteCourses;
}

vector<TStudent *> TCourse::getEnrolledStudents() {
  return enrolledStudents;
}

void TCourse::addStudent(TStudent *s) {
  for (auto & c:prerequisiteCourses) {
    bool meetThis = false;
    for (auto & ap : s->getApprovals()) {
      meetThis = meetThis || (ap.getCourse()->getCode() == c->getCode());
    }
    if (!meetThis) {
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

std::ostream& operator<<(std::ostream& os, TCourse& c) {
  os << "Name: " << c.getName() << std::endl;
  os << "Code: " << c.getCode() << std::endl;
  os << "Credits awarded: " << c.getCredits() << std:: endl;
  return os;
}