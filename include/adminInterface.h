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
#include "DTReservation.h"

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
    void printClassroomInformation();
    void printReservations();
    void printCourses();
    void printStudents();
    void isAvailableClassroom();
    DTReservation getReservationData();
  public:
    adminInterface(StudentsController& stcont, ClassroomsController& clscont, CoursesController& coucont);
};


#endif //SISTEMABEDELIA_ADMININTERFACE_H
