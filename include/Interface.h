//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_INTERFACE_H
#define SISTEMABEDELIA_INTERFACE_H


#include "Menu.h"
#include "System.h"
#include "TDate.h"
#include "DayOfWeek.h"
#include <vector>

class Interface {
  protected:
    explicit Interface(System& sis);
    System system;
    static int getInt(const std::string& message);
    static TDate getDate(const std::string& message);
    static std::vector<DayOfWeek> getDaysOfWeek();
  public:
    Menu menu;
};


#endif //SISTEMABEDELIA_INTERFACE_H
