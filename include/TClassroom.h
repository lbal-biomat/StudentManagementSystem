//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCLASSROOM_H
#define SISTEMABEDELIA_TCLASSROOM_H

#include "TDate.h"
#include "TClassroomReservation.h"
#include <vector>

using std::vector;

class TClassroom {
  private:
    int number; //classrooms are identified by their number
    int capacity;
    vector<TClassroomReservation> reservations;

  public:
    TClassroom(int cod, int cap);
    int getNumber() const;
    int getCapacity() const;
    bool available(TDate startDate, TDate endDate, int timeStart, int timeEnd, const vector<DayOfWeek>& days);
    void addReservation(const TClassroomReservation&);
    vector<TClassroomReservation> getReservations();
};


#endif //SISTEMABEDELIA_TCLASSROOM_H
