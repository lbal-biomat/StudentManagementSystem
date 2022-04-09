//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_DTRESERVATION_H
#define SISTEMABEDELIA_DTRESERVATION_H

#include "TDate.h"
#include "DayOfWeek.h"

#include <vector>

typedef std::vector<DayOfWeek> Tdays;

class DTReservation {
  private:
    int classroom;
    int course;
    int startTime;
    int endTime;
    TDate startDate;
    TDate endDate;
    std::vector<DayOfWeek> days;
  public:
    DTReservation(int classroom, int course, int tini, int tend, TDate dateIni, TDate dateEnd, Tdays days);
    int getClassroom() const;
    int getCourse() const;
    int getStartTime() const;
    int getEndTime() const;
    TDate getStartDate();
    TDate getEndDate();
    Tdays getDays();
};



#endif //SISTEMABEDELIA_DTRESERVATION_H
