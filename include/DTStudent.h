//
// Created by lucia on 9/4/22.
//

/*This class represents a data type, and as such it doesn't have a default constructor nor setters.*/

#ifndef SISTEMABEDELIA_DTSTUDENT_H
#define SISTEMABEDELIA_DTSTUDENT_H

#include "TApproval.h"
#include <vector>
#include <string>

class DTStudent {
  private:
    int id; //Students are identified by the ID
    std::string name;
  public:
    DTStudent(int ID, std::string nom);
    friend std::ostream& operator<<(std::ostream& os, DTStudent& s);
};


#endif //SISTEMABEDELIA_DTSTUDENT_H
