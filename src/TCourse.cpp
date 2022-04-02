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
  for (auto &course: prerequisiteCourses) {
    if (std::none_of(s->getApprovals().begin(), s->getApprovals().end(), \
            [course](TApproval &a) { return course->getCode() == a.getCourse()->getCode(); })) {
      //student doesn't meet the prerequisite of this course
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


TCourse::TCourse(int cod, int cred, string nom, int max) : code(cod), credits(cred), name(std::move(nom)), maxStudents(max) {}

int TCourse::getMaxStudents() const {
  return maxStudents;
}

TCourse::TCourse() {
  code = 0;
  credits = 0;
  maxStudents = 0;
}

std::ostream& operator<<(std::ostream& os, TCourse& c) {
  os << "Name: " << c.getName() << std::endl;
  os << "Code: " << c.getCode() << std::endl;
  os << "Credits awarded: " << c.getCredits() << std:: endl;
  return os;
}