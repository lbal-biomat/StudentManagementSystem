//
// Created by lucia on 9/4/22.
//

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
    int getHour() const;
    int getMin() const;

    bool operator>(TTime) const;
    bool operator<(TTime) const;
    bool operator==(TTime) const;

};

std::ostream& operator<<(std::ostream& os, TTime& t);


#endif //SISTEMABEDELIA_TTIME_H