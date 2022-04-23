//
// Created by lucia on 9/4/22.
//

#include "../include/TTranscript.h"
#include <utility>
#include <iomanip>

TTranscript::TTranscript(int id, std::string name, std::vector<TApproval> ap, float avg, int credits) :
                    id(id), name(std::move(name)), approvals(std::move(ap)), avgGrade(avg), totCredits(credits) {
}
using namespace std;
std::ostream &operator<<(std::ostream & os, TTranscript& t) {
  os << left << setfill('.') << setw(50) << "\nStudent ID: " << right << setfill('.') << setw(51) << t.id << "\n";
  os << left << setfill('.') << setw(50) << "Name: " << right << setfill('.') << setw(50) << t.name << "\n";
  if (!t.approvals.empty()) {
    os << "Approvals: " << "\n";
    for (auto & a : t.approvals) {
      os << "\t" << a;
    }
  }
  os << left << setfill('.') << setw(50) << "Average Grade: " << right << setfill('.') << setw(50) << t.avgGrade << "\n";
  os << left << setfill('.') << setw(50) << "Total Credits: " << right << setfill('.') << setw(50) << t.totCredits << "\n";
  return os;
}