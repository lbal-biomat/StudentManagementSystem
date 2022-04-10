//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOMRESERVATION_H
#define SISTEMABEDELIA_TCLASSROOMRESERVATION_H

#include "TDate.h"
#include "TTime.h"
#include "DayOfWeek.h"
#include "DTReservation.h"

#include <vector>


class TClassroom;
class TCourse;

typedef std::vector<DayOfWeek> Tdays;

class TClassroomReservation {
  private:
    int classroom;
    TCourse* course;
    TTime startTime;
    TTime endTime;
    TDate startDate;
    TDate endDate;
    Tdays days;
  public:
    TClassroomReservation(int classroom, TCourse*, TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays days);
    TCourse* getCourse() const;
    TTime getStartTime() const;
    TTime getEndTime() const;
    TDate getStartDate() const;
    TDate getEndDate() const;
    Tdays getDays() const;
    DTReservation getDTReservation() const;

};

#endif //SISTEMABEDELIA_TCLASSROOMRESERVATION_H
