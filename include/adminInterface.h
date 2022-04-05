//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_ADMININTERFACE_H
#define SISTEMABEDELIA_ADMININTERFACE_H


#include "Menu.h"
#include "System.h"
#include "Interface.h"

class System;

class adminInterface : public Interface {
  private:
    void registerStudent();
    void addClassroom();
    void addCourse();
    void enrollStudent();
    void unEnrollStudent();
    void addApproval();
    void addPreRequisite();
    void addReservation();
    void printStudentEnrollments();
    void printCourseEnrollments();
    void printTranscripts();
    void printPrerequisites();
    void printReservations();
  public:
    explicit adminInterface(System& sis);
};


#endif //SISTEMABEDELIA_ADMININTERFACE_H
