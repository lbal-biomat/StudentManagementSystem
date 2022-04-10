//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_STUDENTSCONTROLLER_H
#define SISTEMABEDELIA_STUDENTSCONTROLLER_H

#include <string>

#include "StudentsRepo.h"
#include "CoursesRepo.h"
#include "TTranscript.h"

class TDate;


class StudentsController {
  private:
    StudentsRepo& repoStudents = StudentsRepo::GetInstance();
    CoursesRepo& repoCourses = CoursesRepo::GetInstance();
  public:
    /* Responsibility: adds a student with the given information to the system.
     * Pre: !existsStudent(ID)*/
    void registerStudent(int ID, std::string name);

    /* Responsibility: Adds an approval with the given information for the course whose member code matches with code
       to the list of approvals of the student whose member ID matches ID.
     * Pre: existsStudent(ID)
     * Pre: existsCourse(code)
     * Pre: there is not an approvals for this course in the student's records */
    void addApprovalToStudent(int ID, int code, int grade, TDate date);

    /* Responsibility: Adds the student whose member ID matches ID to the list of enrolled students of the course whose
       member code matches code.
       Adds the course whose member code matches code to the list of current enrollments of the student
       whose member ID matches ID.
     * Pre: existsStudent(ID)
     * Pre: existsCourse(code)
     * Pre: student is not enrolled in the course*/
    void enrollStudentInCourse(int ID, int code);

    /* Responsibility: Removes the student whose member ID matches ID to the list of enrolled students of the course whose
       member code matches code.
       Removes the course whose member code matches code to the list of current enrollments of the student
       whose member ID matches ID.
     * Pre: existsStudent(ID)
     * Pre: existsCourse(code)
     * Pre: student is enrolled in the course*/
    void unenrollStudentFromCourse(int ID, int code);

    /* Responsibility: returns a vector of DTCourse with an instance of DTCourse for every course in the
       list of currents enrollments of the student whose member ID matches ID
     * Pre: existsStudent(ID)*/
    std::vector<DTCourse> getStudentEnrollments(int ID);

    /* Responsibility: Returns a TTranscript with the academic records of the student whose ember ID matches ID
     * Pre: existsStudent(ID) */
    TTranscript getStudentTranscript(int ID);

    /* Responsibility: returns a vector of DTStudent with an instance of DTStudent for every student in the system*/
    std::vector<DTStudent> getStudentsInformation();

    /* Responsibility: returns true if there is a student s in the system such that s.ID matches ID,
       returns false otherwise*/
    [[nodiscard]] bool existsStudent(int ID) const;

    /* Responsibility: returns true if there is a course c in the system such that c.code matches code.
       returns false otherwise*/
    [[nodiscard]] bool existsCourse(int cod) const;
    StudentsController() = default;
};


#endif //SISTEMABEDELIA_STUDENTSCONTROLLER_H
