//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TAPPROVAL_H
#define SISTEMABEDELIA_TAPPROVAL_H

#include "TDate.h"

class TCourse;

class TApproval {
  private:
    TCourse* course;
    int grade;
    TDate date;
  public:
    TApproval(TCourse* course, int grade, TDate d);
    //getters
    [[nodiscard]] TCourse* getCourse() const;
    [[nodiscard]] int getGrade() const;
    friend std::ostream& operator<<(std::ostream& os, TApproval& a);
};


#endif//SISTEMABEDELIA_TAPPROVAL_H
