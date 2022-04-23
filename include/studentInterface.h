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

    /* Responsibility: Enrolls the student in a course. It will prompt the user to enter the course code.
     * Reports an error if there is not a course in the system whose member code matches the given code
     * Reports an error if the student is already enrolled in the course */
    void enrollInCourse();

    /* Responsibility: Unenrolls the student from a course. It will prompt the user to enter the course code.
     * Reports an error if there is not a course in the system whose member code matches the given code
     * Reports an error if the student is not enrolled in the course */
    void unEnrollFromCourse();

    /* Responsibility: Prints the pre required courses for a given course.
     * It will prompt the user to enter the course code.
     * Reports an error if there is not a course in the system whose member code matches the given code */
    void printCoursePrerequisites();

    /* Responsibility: Prints the information for every course in the list of current enrollments of the student */
    void printStudentEnrollments();

    /* Responsibility: Prints the student transcripts. */
    void printStudentTranscript();
  public:
    studentInterface(StudentsController& stctr, CoursesController& crctr, int& id);
    static int studentLogIn();
};


#endif //SISTEMABEDELIA_STUDENTINTERFACE_H