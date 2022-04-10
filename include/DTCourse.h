//
// Created by lucia on 9/4/22.
//

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
    int getCode() const;
    int getCredits() const;
    std::string getName() const;

};


std::ostream& operator<<(std::ostream& os, DTCourse& c);

#endif //SISTEMABEDELIA_DTCOURSE_H
