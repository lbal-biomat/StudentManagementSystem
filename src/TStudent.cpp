//
// Created by lucia on 27/3/22.
//

#include "../include/TStudent.h"
#include "../include/TCourse.h"

#include <utility>
#include <iostream>


int TStudent::getIDnumber() const {
  return ID.getIDnumber();
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

/*void TStudent::addEnrollment(TCourse* course) {

  for (auto & c : course->getPrerequisiteCourses()) {
    bool meetThis = false;
    for (auto & ap : getApprovals()) {
      meetThis = meetThis || (ap.getCourse()->getCode() == c->getCode());
    }
    if (!meetThis) {
      throw std::invalid_argument("Student doesn't meet the prerequisites of this course.");
    }
  }
  enrollments.push_back(course);
}*/

void TStudent::addEnrollment(TCourse* course) {

  for (auto & c : course->getPrerequisiteCourses()) {
    if (std::none_of(getApprovals().begin(), getApprovals().end(), \
            [c](TApproval &a) { return c->getCode() == a.getCourse()->getCode(); })) {
      //student doesn't meet the prerequisite of this course
      throw std::invalid_argument("Student doesn't meet the prerequisites of this course.");
    }
  }
  enrollments.push_back(course);
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

TStudent::TStudent(int doc, string nom) : name(std::move(nom)), ID(doc) {}

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
  os << "ID: " << e.getIDnumber() << endl;
  for (auto & c:e.getCurrentEnrollments()) {
    os << c;
  }
  return os;
}