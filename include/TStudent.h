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
    [[nodiscard]] int getID() const;
    [[nodiscard]] int getCredits() const;
    [[nodiscard]] float getAverageGrade() const;
    [[nodiscard]] std::vector<TCourse*> getCurrentEnrollments() const;
    bool isEnrolled(int courseCode);
    void enroll(TCourse* course);
    void unenroll(int cod);
    [[nodiscard]] bool hasApproval(int courseCode) const;
    void addApproval(TApproval a);
    [[nodiscard]] DTStudent getDTStudent() const;
    [[nodiscard]] TTranscript getTranscript() const;
};

#endif//SISTEMABEDELIA_TSTUDENT_H
