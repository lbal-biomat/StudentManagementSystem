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

int TCourse::addStudent(TStudent *s) {
  for (auto & c:prerequisiteCourses) {
    if ( std::none_of(s->getApprovals().begin(), s->getApprovals().end(), \
        [this](const TCourse& c){return this->code == c.getCode();}) ) {
      //student doesn't meet the prerequisite of this course
      return 1;
    }
  }
  enrolledStudents.push_back(s);
  return 0;
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