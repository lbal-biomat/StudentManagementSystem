//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
#define SISTEMABEDELIA_CLASSROOMSCONTROLLER_H

#include <vector>
#include "ClassroomsRepo.h"
#include "CoursesRepo.h"

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

    /*Pre: existsClassroom(num) */
    void printClassroomInformation(int num);

    /*Responsibility: returns true if the classroom c such that c.getNumber() == num is available for the given days,
      date and time, returns false otherwise
     * Pre: existsClassroom(num) */
    bool isAvailable(int num, int startTime, int endTime, TDate startDate,
                     TDate endDate, std::vector<DayOfWeek>& days);

    /* Responsibility: Adds a reservation with the given information.
     * Pre: existsClassroom(num)
     * Pre: there is a course c in the system such that c.getCode() == codeCourse
     * Pre: isAvailable(num, startTime, endTime, startDate, endDate, days)
     * Throws an invalid_argument exception if the classroom is not available */
    void addClassroomReservation(int num, int codeCourse, int startTime, int endTime, TDate startDate,
                                 TDate endDate, std::vector<DayOfWeek>& days);

    /*Responsibility: prints the information for every reservation for the classroom c such that c.getNumber() == num
     * Pre: existsClassroom(num) */
    void printReservations(int num);

    /*Responsibility: returns true if there is a classroom c in the system such that c.getNum() == num,
     * returns false otherwise */
    [[nodiscard]] bool existsClassroom(int num) const;
};

#endif //SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
