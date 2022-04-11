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


class TStudent {
  private:
    int ID; //Students are identified by the ID
    std::string name;
    std::vector<TApproval> approvals;
    std::vector<TCourse*> enrollments;
  public:
    TStudent();
    TStudent(int ID, std::string nom);
    int getID() const;
    int getCredits() const;
    float getAverageGrade() const;
    std::vector<TCourse*> getCurrentEnrollments() const;
    bool isEnrolled(int courseCode);
    void enroll(TCourse* course);
    void unenroll(int cod);
    bool hasApproval(int courseCode) const;
    void addApproval(TApproval a);
    DTStudent getDTStudent() const;
    TTranscript getTranscript() const;
};

#endif//SISTEMABEDELIA_TSTUDENT_H
