//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TSTUDENT_H
#define SISTEMABEDELIA_TSTUDENT_H

#include "TApproval.h"
#include "DTStudent.h"
#include "TTranscript.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class TStudent {
  private:
    int ID; //Students are identified by the ID
    string name;
    vector<TApproval> approvals;
    vector<TCourse*> enrollments;
  public:
    TStudent();
    TStudent(int ID, string nom);
    int getID() const;
    int getCredits() const;
    float getAverageGrade() const;
    vector<TCourse*> getCurrentEnrollments() const;
    bool isEnrolled(int courseCode);
    void enroll(TCourse* course);
    void unenroll(int cod);
    bool hasApproval(int courseCode) const;
    void addApproval(TApproval a);
    DTStudent getDTStudent() const;
    TTranscript getTranscript() const;
};

#endif//SISTEMABEDELIA_TSTUDENT_H
