//
// Created by lucia on 27/3/22.
//

#include "../include/TApproval.h"
#include "../include/TCourse.h"

TApproval::TApproval(TCourse* c, int n, TDate f) : course(c), grade(n), date(f) {}

TCourse* TApproval::getCourse() const {
  return course;
}

TDate TApproval::getDateOfApproval() const {
  return date;
}

int TApproval::getGrade() const {
  return grade;
}

using namespace  std;
std::ostream& operator<<(std::ostream& os, TApproval& apr) {
  TCourse* c = apr.getCourse();
  TDate f = apr.getDateOfApproval();
  os << "Course: " << c->getName() << " - " << c->getCode() << " - Cred: " << c->getCredits() << " - Grade: " << \
  apr.getGrade() << " - Date of Approval: " << f << endl;
  return os;
}