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
    vector<TApproval> approval;
    vector<TCourse*> enrollments;
  public:
    TStudent();
    TStudent(int ID, string nom);
    int getID() const;
    string getName() const;
    vector<TApproval> getApprovals() const;
    int getCredits() const;
    float getAverageGrade() const;
    vector<TCourse*> getCurrentEnrollments() const;
    void enroll(TCourse* course);
    void unenroll(int cod);
    void addApproval(TApproval a);
    bool isEnrolled(int courseCode);
    DTStudent getDTStudent() const;
    TTranscript getTranscript() const;
};

#endif//SISTEMABEDELIA_TSTUDENT_H
