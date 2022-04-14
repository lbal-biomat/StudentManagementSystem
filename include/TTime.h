//
// Created by lucia on 9/4/22.
//

/*This class represents a data type, and as such it doesn't have a default constructor nor setters.*/

#ifndef SISTEMABEDELIA_TTIME_H
#define SISTEMABEDELIA_TTIME_H

#include <iostream>

class TTime {
  private:
    int hour;
    int min;
    [[nodiscard]] bool isValidTime() const;
  public:
    TTime(int h, int m);
    [[nodiscard]] int getHour() const;
    [[nodiscard]] int getMin() const;

    bool operator>(TTime) const;
    bool operator<(TTime) const;
    bool operator==(TTime) const;

};

std::ostream& operator<<(std::ostream& os, TTime& t);


#endif //SISTEMABEDELIA_TTIME_H
