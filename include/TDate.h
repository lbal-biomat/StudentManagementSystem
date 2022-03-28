//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TDATE_H
#define SISTEMABEDELIA_TDATE_H

#include <iostream>


class TDate {
  private:
    int day, month, year;

  public:

    TDate(int d, int m, int y);

    //getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator>(TDate f) const;
    bool operator<(TDate f) const;
    bool operator==(TDate) const;
};

std::ostream& operator<<(std::ostream& os, TDate& f);

#endif //SISTEMABEDELIA_TDATE_H
