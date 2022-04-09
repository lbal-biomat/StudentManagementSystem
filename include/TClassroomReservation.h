//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOMRESERVATION_H
#define SISTEMABEDELIA_TCLASSROOMRESERVATION_H

#include "TDate.h"
#include "TTime.h"
#include "DayOfWeek.h"

#include <vector>


class TClassroom;
class TCourse;

typedef std::vector<DayOfWeek> Tdays;

class TClassroomReservation {
  private:
    TCourse* course;
    TTime startTime;
    TTime endTime;
    TDate startDate;
    TDate endDate;
    Tdays days;
  public:
    TClassroomReservation(TCourse*, TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays days);
    TCourse* getCourse();
    TTime getStartTime() const;
    TTime getEndTime() const;
    TDate getStartDate();
    TDate getEndDate();
    Tdays getDays();
};

std::ostream& operator<<(std::ostream& os, TClassroomReservation& c);

#endif //SISTEMABEDELIA_TCLASSROOMRESERVATION_H
