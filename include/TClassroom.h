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

using std::vector;

class TClassroom {
  private:
    int number; //classrooms are identified by their number
    int capacity;
    vector<TClassroomReservation> reservations;

  public:
    TClassroom();
    TClassroom(int cod, int cap);
    int getNumber() const;
    int getCapacity() const;
    bool available(TDate startDate, TDate endDate, TTime timeStart, TTime timeEnd, const vector<DayOfWeek>& days);
    void addReservation(const TClassroomReservation&);
    vector<TClassroomReservation> getReservations();
    DTClassroom getDTClassroom();
};


#endif //SISTEMABEDELIA_TCLASSROOM_H
