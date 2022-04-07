//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_DAYOFWEEK_H
#define SISTEMABEDELIA_DAYOFWEEK_H

#include <iostream>

enum DayOfWeek {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

std::ostream& operator<<(std::ostream& os, DayOfWeek& dow);

#endif //SISTEMABEDELIA_DAYOFWEEK_H
