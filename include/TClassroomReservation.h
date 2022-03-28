//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOMRESERVATION_H
#define SISTEMABEDELIA_TCLASSROOMRESERVATION_H

#include "TDate.h"
#include "DayOfWeek.h"

#include <vector>
#include <chrono>

using std::vector;

class TClassroom;
class TCourse;

class TClassroomReservation {
  private:
    TCourse* course;
    int startTime;
    int endTime;
    TDate startDate;
    TDate endDate;
    vector<DayOfWeek> days;
  public:
    TClassroomReservation(TCourse*, int tini, int tend, TDate dateIni, TDate dateEnd, vector<DayOfWeek> days);
    TCourse* getCourse();
    int getStartTime() const;
    int getEndTime() const;
    TDate getStartDate();
    TDate getEndDate();
    std::vector<DayOfWeek> getDays();
};

std::ostream& operator<<(std::ostream& os, TClassroomReservation& c);

#endif //SISTEMABEDELIA_TCLASSROOMRESERVATION_H
