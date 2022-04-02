//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TSTUDENT_H
#define SISTEMABEDELIA_TSTUDENT_H

#include "TApproval.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class TStudent {
  private:
    int ID; //Students are identified by the ID
    string name;
    vector<TApproval> approval;
    vector<TCourse*> enrollments;
  public:
    TStudent();
    TStudent(int ID, string nom);
    int getID() const;
    string getName();
    vector<TApproval> getApprovals();
    int getCredits();
    float getAverageGrade();
    vector<TCourse*> getCurrentEnrollments();
    void addEnrollment(TCourse* c);
    void addApproval(TApproval a);
    bool isEnrolled(int courseCode);
    void printTranscripts();
};

std::ostream& operator<<(std::ostream& os, TStudent& s);

#endif//SISTEMABEDELIA_TSTUDENT_H
