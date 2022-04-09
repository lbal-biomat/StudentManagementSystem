//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOMRESERVATION_H
#define SISTEMABEDELIA_TCLASSROOMRESERVATION_H

#include "TDate.h"
#include "DayOfWeek.h"

#include <vector>


class TClassroom;
class TCourse;

typedef std::vector<DayOfWeek> Tdays;

class TClassroomReservation {
  private:
    TCourse* course;
    int startTime;
    int endTime;
    TDate startDate;
    TDate endDate;
    Tdays days;
  public:
    TClassroomReservation(TCourse*, int tini, int tend, TDate dateIni, TDate dateEnd, Tdays days);
    TCourse* getCourse();
    int getStartTime() const;
    int getEndTime() const;
    TDate getStartDate();
    TDate getEndDate();
    Tdays getDays();
};

std::ostream& operator<<(std::ostream& os, TClassroomReservation& c);

#endif //SISTEMABEDELIA_TCLASSROOMRESERVATION_H
