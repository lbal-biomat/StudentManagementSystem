//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_ADMININTERFACE_H
#define SISTEMABEDELIA_ADMININTERFACE_H


#include "Menu.h"
#include "Interface.h"
#include "StudentsController.h"
#include "CoursesController.h"
#include "ClassroomsController.h"

class System;

class adminInterface : public Interface {
  private:
    StudentsController& studentsController;
    ClassroomsController& classroomsController;
    CoursesController& coursesController;
    void registerStudent();
    void addClassroom();
    void addCourse();
    void addApproval();
    void addPreRequisite();
    void addReservation();
    void printCourseEnrollments();
    void printPrerequisites();
    void printReservations();
  public:
    explicit adminInterface(StudentsController& stcont, ClassroomsController& clscont, CoursesController& coucont);
};


#endif //SISTEMABEDELIA_ADMININTERFACE_H
