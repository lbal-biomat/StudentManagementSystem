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

void TCourse::addStudent(TStudent *) {
  enrolledStudents.push_back(e);
}

void TCourse::unenrollStudent(int CI) {
  for (int i = 0; i < enrolledStudents.size(); i++) {
      enrolledStudents.erase(enrolledStudents.begin() + i);
  }
}

void TCourse::removerNoHabilitados() {
  for (int i = 0; i < enrolledStudents.size(); i++)
    for (auto & previa : prerequisiteCourses)
      if (!enrolledStudents.at(i)->isEnrolled(previa->getCode()))  //si no esta inscripto
        enrolledStudents.erase(enrolledStudents.begin() + i); //borro estudiante
}

TCourse::TCourse(int cod, int cred, string nom) : code(cod), credits(cred), name(std::move(nom)) {}

std::ostream& operator<<(std::ostream& os, TCourse& c) {
  os << "Name: " << c.getName() << std::endl;
  os << "Code: " << c.getCode() << std::endl;
  os << "Credits awarded: " << c.getCredits() << std:: endl;
  return os;
}