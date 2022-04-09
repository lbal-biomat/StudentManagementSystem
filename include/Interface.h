//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_INTERFACE_H
#define SISTEMABEDELIA_INTERFACE_H


#include "Menu.h"
#include "TDate.h"
#include "TTime.h"
#include "DayOfWeek.h"
#include <vector>


class Interface {
  protected:
    static int getInt(const std::string& message);
    static TDate getDate(const std::string& message);
    static TTime getTime(const std::string& message);
    static std::vector<DayOfWeek> getDaysOfWeek();
    static bool validateID(int ID);
  public:
    static void callMenu(Menu menu, const std::string& exitCall);
    Menu menu;
};


#endif //SISTEMABEDELIA_INTERFACE_H
