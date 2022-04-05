//
// Created by lucia on 5/4/22.
//

#ifndef SISTEMABEDELIA_STUDENTINTERFACE_H
#define SISTEMABEDELIA_STUDENTINTERFACE_H

#include "Interface.h"
#include "Menu.h"

class studentInterface : public Interface {
  private:
    int student;
    void enrollStudent();
    void unEnrollStudent();
  public:
    explicit studentInterface(System& sis, int student);
};


#endif //SISTEMABEDELIA_STUDENTINTERFACE_H