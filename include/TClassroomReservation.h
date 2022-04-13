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
    int code;
    TTime startTime;
    TTime endTime;
    TDate startDate;
    TDate endDate;
    Tdays days;
  public:
    TClassroomReservation(int classroom, TCourse*, int cod, TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays days);
    [[nodiscard]] TTime getStartTime() const;
    [[nodiscard]] TTime getEndTime() const;
    [[nodiscard]] TDate getStartDate() const;
    [[nodiscard]] TDate getEndDate() const;
    [[nodiscard]] Tdays getDays() const;
    [[nodiscard]] int getCode() const;
    [[nodiscard]] DTReservation getDTReservation() const;

};

#endif //SISTEMABEDELIA_TCLASSROOMRESERVATION_H
