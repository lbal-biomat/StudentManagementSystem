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
    void addClassroom(int num, int capacity);

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
    void printReservations(int numRoom);
    [[nodiscard]] bool existsClassroom(int classNum) const;
};

#endif //SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
