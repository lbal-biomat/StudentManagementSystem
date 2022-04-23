//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_COURSESCONTROLLER_H
#define SISTEMABEDELIA_COURSESCONTROLLER_H

#include "CoursesRepo.h"
#include "ClassroomsRepo.h"

#include <string>

class CoursesController {
  private:
    CoursesRepo& repoCourses = CoursesRepo::GetInstance();
    ClassroomsRepo& repoClassrooms = ClassroomsRepo::GetInstance();
  public:
    /* Responsibility: adds a course with the given information to the system
     * Pre: !existsCourse(code)*/
    void addCourse(int code, int credits, std::string name);

    /* Responsibility: returns a vector of DTStudent, with an instance of DTStudent for every student enrolled
       in the given course.
     * Pre: existsCourse(code)*/
    std::vector<DTStudent> getEnrolledStudents(int courseCode);

    /* Responsibility: adds the course whose member code matches requiredCode to the list of pre required courses
       of the course whose member code matches cod
     * Pre: existsCourse(cod)
     * Pre: existsCourse(requiredCode)*/
    void addPreRequiredCourse(int cod, int requiredCode);

    /* Responsibility: returns a vector of DTCourse with an instance of DTCourse for every pre required course
       for the course whose member code matches codeCourse
     * Pre: existsCourse(codeCourse)*/
    std::vector<DTCourse> getPrerequisiteCourses(int codeCourse);

    /* Responsibility: returns a vector of DTReservation with an instance of DTReservation for every reservation
       in the list of reservations of the course whose member code matches code
     * Pre: existsCourse(code)*/
    std::vector<DTReservation> getCourseReservations(int code);

    /* Responsibility: returns a vector of DTCourse with an instance of DTCourse for every course in the system*/
    std::vector<DTCourse> getCoursesInformation();

    /* Responsibility: returns true if there is a course c in the system such that c.code matches code,
       returns false otherwise*/
    [[nodiscard]] bool existsCourse(int code) const;

};


#endif //SISTEMABEDELIA_COURSESCONTROLLER_H
