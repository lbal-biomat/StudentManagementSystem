//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_CLASSROOMSREPO_H
#define SISTEMABEDELIA_CLASSROOMSREPO_H

#include "TClassroom.h"
#include <unordered_map>

class ClassroomsRepo {
  public:
    std::unordered_map<int, TClassroom> classrooms;
    static ClassroomsRepo& GetInstance();
    // Delete copy/move so extra instances can't be created/moved.
    ClassroomsRepo(const ClassroomsRepo&) = delete;
    ClassroomsRepo& operator=(const ClassroomsRepo&) = delete;
    ClassroomsRepo(ClassroomsRepo&&) = delete;
    ClassroomsRepo& operator=(ClassroomsRepo&&) = delete;
  private:
    ClassroomsRepo() = default;
};



#endif //SISTEMABEDELIA_CLASSROOMSREPO_H
