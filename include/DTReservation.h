//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_DTRESERVATION_H
#define SISTEMABEDELIA_DTRESERVATION_H

#include "TDate.h"
#include "TTime.h"
#include "DayOfWeek.h"

#include <vector>

typedef std::vector<DayOfWeek> Tdays;

class DTReservation {
  private:
    int classroom;
    int course;
    TTime startTime;
    TTime endTime;
    TDate startDate;
    TDate endDate;
    std::vector<DayOfWeek> days;
  public:
    DTReservation(int classroom, int course, TTime tini, TTime tend, TDate dateIni, TDate dateEnd, Tdays days);
    [[nodiscard]] int getClassroom() const;
    [[nodiscard]] int getCourse() const;
    [[nodiscard]] TTime getStartTime() const;
    [[nodiscard]] TTime getEndTime() const;
    [[nodiscard]] TDate getStartDate() const;
    [[nodiscard]] TDate getEndDate() const;
    [[nodiscard]] Tdays getDays() const;

    friend std::ostream& operator<<(std::ostream& os, DTReservation& c);
};



#endif //SISTEMABEDELIA_DTRESERVATION_H
