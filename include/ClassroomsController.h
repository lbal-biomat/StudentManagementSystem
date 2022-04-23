//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
#define SISTEMABEDELIA_CLASSROOMSCONTROLLER_H

#include <vector>
#include "ClassroomsRepo.h"
#include "CoursesRepo.h"
#include "../include/DTReservation.h"

class TDate;

class ClassroomsController {
  private:
    ClassroomsRepo& repoClassrooms = ClassroomsRepo::GetInstance();
    CoursesRepo& repoCourses = CoursesRepo::GetInstance();
  public:

    /* Responsibility: Adds a classroom to the system.
     * Pre: !existsClassroom(num)
     * Post: existsClassroom(num) */
    void addClassroom(int num, int capacity);

    /* Pre: existsClassroom(num) */
    DTClassroom getClassroomInformation(int num);

    /* Responsibility: returns true if the classroom c such that c.getNumber() == num is available for the given days,
       date and time, returns false otherwise
     * Pre: existsClassroom(num) */
    bool isAvailable(const DTReservation&);

    /* Responsibility: Adds a reservation with the given information. Creates a link from the course to the reservation
     * Pre: existsClassroom(num)
     * Pre: there is a course c in the system such that c.getCode() == codeCourse
     * Pre: isAvailable(num, startTime, endTime, startDate, endDate, days)
     * Throws an invalid_argument exception if the classroom is not available */
    void addClassroomReservation(const DTReservation&);

    /* Responsibility: Returns a vector of DTReservations for the classroom c such that c.getNumber() == num
     * Pre: existsClassroom(num) */
    std::vector<DTReservation> getClassroomsReservations(int num);

    /* Responsibility: returns true if there is a classroom c in the system such that c.getNum() == num,
       returns false otherwise */
    [[nodiscard]] bool existsClassroom(int num) const;
};

#endif //SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
