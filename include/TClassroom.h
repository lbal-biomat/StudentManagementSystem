//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOM_H
#define SISTEMABEDELIA_TCLASSROOM_H

#include "TDate.h"
#include "TTime.h"
#include "TClassroomReservation.h"
#include "DTClassroom.h"
#include <vector>


class TClassroom {
  private:
    int number; //classrooms are identified by their number
    int capacity;
    std::vector<TClassroomReservation> reservations;

  public:
    TClassroom();
    TClassroom(int cod, int cap);
    bool available(TDate startDate, TDate endDate, TTime startTime, TTime endTime, const std::vector<DayOfWeek>& days);
    void addReservation(const TClassroomReservation&);
    [[nodiscard]] std::vector<TClassroomReservation> getReservations() const;
    [[nodiscard]] DTClassroom getDTClassroom() const;
};


#endif //SISTEMABEDELIA_TCLASSROOM_H
