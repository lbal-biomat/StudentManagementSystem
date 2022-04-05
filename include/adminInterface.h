//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_ADMININTERFACE_H
#define SISTEMABEDELIA_ADMININTERFACE_H


#include "Menu.h"
#include "TDate.h"
#include "DayOfWeek.h"
#include <vector>
#include "System.h"

class System;

class adminInterface {
  private:
    static TDate getDate(const std::string& message);
    static int getInt(const std::string& mes);
    static std::vector<DayOfWeek> getDaysOfWeek();
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
    System system;
  public:
    explicit adminInterface(System& sis);
    Menu menu;
};


#endif //SISTEMABEDELIA_ADMININTERFACE_H
