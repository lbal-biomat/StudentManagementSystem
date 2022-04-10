//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_DTSTUDENT_H
#define SISTEMABEDELIA_DTSTUDENT_H

#include "DTCourse.h"
#include "TApproval.h"
#include <vector>
#include <string>

class DTStudent {
  private:
    int id; //Students are identified by the ID
    std::string name;
  public:
    DTStudent(int ID, std::string nom);
    int getID() const;
    std::string getName();
};

std::ostream& operator<<(std::ostream& os, DTStudent& s);

#endif //SISTEMABEDELIA_DTSTUDENT_H
