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
    void addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime, TDate startDate,
                                 TDate endDate, std::vector<DayOfWeek>& days);
    void printReservations(int numRoom);
    [[nodiscard]] bool existsClassroom(int classNum) const;
};

#endif //SISTEMABEDELIA_CLASSROOMSCONTROLLER_H
