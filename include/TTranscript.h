//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_TTRANSCRIPT_H
#define SISTEMABEDELIA_TTRANSCRIPT_H

#include <string>
#include <vector>
#include "TApproval.h"

class TTranscript {
  private:
    int id;
    std::string name;
    std::vector<TApproval> approvals;
    float avgGrade;
    int totCredits;
  public:
    TTranscript(int id, std::string name, std::vector<TApproval> ap, float avgGrade, int totCredits);
    friend std::ostream &operator<<(std::ostream& os, TTranscript& t);

};

#endif //SISTEMABEDELIA_TTRANSCRIPT_H
