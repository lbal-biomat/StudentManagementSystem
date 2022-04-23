//
// Created by lucia on 9/4/22.
//

/*This class represents a data type, and as such it doesn't have a default constructor nor setters.*/

#ifndef SISTEMABEDELIA_DTCOURSE_H
#define SISTEMABEDELIA_DTCOURSE_H

#include <vector>
#include <string>

#include "DTStudent.h"

class DTCourse {
  private:
    int code; //Courses are identified by the code
    int credits;
    std::string name;
  public:
    DTCourse(int cod, int cred, std::string nom);
    friend std::ostream& operator<<(std::ostream& os, DTCourse& c);
};



#endif //SISTEMABEDELIA_DTCOURSE_H
