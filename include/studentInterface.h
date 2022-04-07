//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_STUDENTINTERFACE_H
#define SISTEMABEDELIA_STUDENTINTERFACE_H

#include "Interface.h"
#include "StudentsController.h"
#include "CoursesController.h"

class studentInterface : public Interface {
  private:
    StudentsController& studentsController;
    CoursesController& coursesController;
    int student;
    void enrollStudent();
    void unEnrollStudent();
    void printPrerequisites();
  public:
    studentInterface(StudentsController& stctr, CoursesController& crctr);
    bool studentLogIn();
};


#endif //SISTEMABEDELIA_STUDENTINTERFACE_H