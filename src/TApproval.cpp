//
// Created by lucia on 27/3/22.
//

#include "../include/TApproval.h"
#include "../include/TCourse.h"
#include <iomanip>

TApproval::TApproval(TCourse* c, int n, TDate f) : course(c), grade(n), date(f) {}

TCourse* TApproval::getCourse() const {
  return course;
}


int TApproval::getGrade() const {
  return grade;
}

using namespace  std;
std::ostream& operator<<(std::ostream& os, TApproval& apr) {
  TCourse* c = apr.course;
  os << "Course: " << right << setfill('.') << setw(12) << c->getName()
     << right << setfill(' ') << setw(20) << " Credits: " << right << setfill(' ') << setw(2)<< c->getCredits()
     << right << setfill(' ') << setw(20) << " Grade: " << right << setfill(' ') << setw(2) << apr.getGrade()
     << right << setfill(' ') << setw(20) << " Date: " << apr.date
     << "\n";
  return os;
}