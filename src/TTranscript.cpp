//
// Created by lucia on 9/4/22.
//

#include "../include/TTranscript.h"
#include <utility>

TTranscript::TTranscript(int id, std::string name, std::vector<TApproval> ap, int avg, int credits) :
                    id(id), name(std::move(name)), approvals(std::move(ap)), avgGrade(avg), totCredits(credits) {
}

std::ostream &operator<<(std::ostream & os, TTranscript& t) {
  os << t.id << "\n";
  os << t.name << "\n";
  for (auto & a : t.approvals) {
    std::cout << "\t" << a;
  }
  std::cout << "Average Grade: " << t.avgGrade << "\n";
  std::cout << "Total Credits: " << t.totCredits << "\n";
  return os;
}