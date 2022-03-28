//
// Created by lucia on 27/3/22.
//

#include "../include/TStudent.h"
#include "../include/TCourse.h"

#include <utility>
#include <iostream>


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

int TStudent::addEnrollment(TCourse* course) {

  for (auto & c : course->getPrerequisiteCourses()) {
    bool meetThis = false;
    for (auto & ap : getApprovals()) {
      meetThis = meetThis || (ap.getCourse()->getCode() == c->getCode());
    }
    if (!meetThis) return 1;
  }
  enrollments.push_back(course);
  return 0;
}

void TStudent::addApproval(TApproval a) {
  approval.push_back(a);
}


bool TStudent::isEnrolled(int code) {
  for (auto & e : enrollments) {
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

TStudent::TStudent(int doc, string nom) : ID(doc), name(std::move(nom)) {}

float TStudent::getAverageGrade() {
  int sum = 0;
  for (auto & a : approval) {
    sum += a.getGrade();
  }
  return static_cast<float>(sum) / approval.size(); //NOLINT //casting to float so it returns float and no int
}

using namespace  std;

void TStudent::printTranscripts() {
  cout << this;
  cout << "Approvals: " << endl;
  for (auto & approv : getApprovals()) {
    cout << "\t" << approv;
  }
  cout << "Average Grade: " << getAverageGrade() << endl;
  cout << "Total Credits: " << getCredits() << endl;
}

std::ostream& operator<<(std::ostream& os, TStudent& e) {
  os << "Name: " << e.getName() << endl;
  os << "ID: " << e.getID() << endl;
  for (auto & c:e.getCurrentEnrollments()) {
    os << c;
  }
  return os;
}