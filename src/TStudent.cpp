//
// Created by lucia on 27/3/22.
//

#include "../include/TStudent.h"
#include "../include/TCourse.h"

#include <utility>
#include <iostream>
#include <cassert>


int TStudent::getID() const {
  return ID;
}

string TStudent::getName() {
  return name;
}

vector<TApproval> TStudent::getApprovals() {
  return approval;
}

vector<TCourse *> TStudent::getCurrentEnrollments() {
  return enrollments;
}

void TStudent::enroll(TCourse* course) {
  assert(!isEnrolled(course->getCode()));
  for (auto & c : course->getPrerequisiteCourses()) {
    if (std::none_of(getApprovals().begin(), getApprovals().end(), \
            [c](TApproval &a) { return c->getCode() == a.getCourse()->getCode(); })) {
      //student doesn't meet the prerequisite of this course
      throw std::invalid_argument("Student doesn't meet the prerequisites of this course.");
    }
  }
  enrollments.push_back(course);
}

void TStudent::unenroll(int cod) {
  assert(isEnrolled(cod));
  for (int i = 0; i < enrollments.size(); i++) {
    if (enrollments[i]->getCode() == cod)
      enrollments.erase(enrollments.begin()+i);
  }
}

void TStudent::addApproval(TApproval a) {
  approval.push_back(a);
}


bool TStudent::isEnrolled(int code) {
  for (auto & e : enrollments) { //NOLINT
    if (e->getCode() == code)
      return true;
  }
  return false;
}

int TStudent::getCredits() {
  int credits = 0;
  for (auto & a : approval) {
    credits += a.getCourse()->getCredits();
  }
  return credits;
}

TStudent::TStudent(int doc, string nom) : name(std::move(nom)), ID(doc) {}

float TStudent::getAverageGrade() {
  if (approval.empty()) {
    return 0;
  }
  int sum = 0;
  for (auto & a : approval) {
    sum += a.getGrade();
  }
  return static_cast<float>(sum) / approval.size(); //NOLINT //casting to float so it returns float and no int
}

using namespace  std;

void TStudent::printTranscripts() {
  cout << *this;
  cout << "Approvals: " << endl;
  for (auto & a : getApprovals()) {
    cout << "\t" << a;
  }
  cout << "Average Grade: " << getAverageGrade() << endl;
  cout << "Total Credits: " << getCredits() << endl;
}

TStudent::TStudent() : ID(-1){}

std::ostream& operator<<(std::ostream& os, TStudent& e) {
  os << "Name: " << e.getName() << endl;
  os << "ID: " << e.getID() << endl;
  return os;
}