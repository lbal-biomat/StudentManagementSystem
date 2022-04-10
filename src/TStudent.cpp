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

vector<TApproval> TStudent::getApprovals() const {
  return approval;
}

vector<TCourse *> TStudent::getCurrentEnrollments() const {
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

int TStudent::getCredits() const {
  int credits = 0;
  for (auto & a : approval) {
    credits += a.getCourse()->getCredits();
  }
  return credits;
}

TStudent::TStudent(int doc, string nom) : name(std::move(nom)), ID(doc) {}

float TStudent::getAverageGrade() const {
  if (approval.empty()) {
    return 0;
  }
  int sum = 0;
  for (auto & a : approval) {
    sum += a.getGrade();
  }
  return static_cast<float>(sum) / approval.size(); //NOLINT //casting to float so it returns float and no int
}


TStudent::TStudent() : ID(-1){}

DTStudent TStudent::getDTStudent() const {
  return {ID, name};
}

TTranscript TStudent::getTranscript() const {
  return {ID, name, approval, getAverageGrade(), getCredits()};
}