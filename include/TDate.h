//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TDATE_H
#define SISTEMABEDELIA_TDATE_H

#include <iostream>
#include "ctime"


class TDate {
  private:
    tm date{};
    bool isValidDate();

  public:

    TDate(int d, int m, int y);

    //getters
    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getYear() const;

    bool operator>(TDate f);
    bool operator<(TDate f);
    bool operator==(TDate) const;

    friend std::ostream& operator<<(std::ostream& os, TDate& f);

};


#endif //SISTEMABEDELIA_TDATE_H
