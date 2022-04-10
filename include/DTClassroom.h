//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_DTCLASSROOM_H
#define SISTEMABEDELIA_DTCLASSROOM_H

#include "DTReservation.h"
#include <vector>
#include "TDate.h"
#include "TTime.h"

class DTClassroom {
  private:
    int number; //classrooms are identified by their number
    int capacity;
    std::vector<DTReservation> reservations;

  public:
    DTClassroom(int num, int cap, std::vector<DTReservation> res);
    int getNumber() const;
    int getCapacity() const;
    std::vector<DTReservation> getReservations() const;
};

std::ostream& operator<<(std::ostream& os, DTClassroom& c);



#endif //SISTEMABEDELIA_DTCLASSROOM_H
