//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_COURSESREPO_H
#define SISTEMABEDELIA_COURSESREPO_H

#include "TCourse.h"
#include <unordered_map>

class CoursesRepo {
  public:
    std::unordered_map<int, TCourse> courses; //the code is the key
    static CoursesRepo& GetInstance();
    // Delete copy/move so extra instances can't be created/moved.
    CoursesRepo(const CoursesRepo&) = delete;
    CoursesRepo& operator=(const CoursesRepo&) = delete;
    CoursesRepo(CoursesRepo&&) = delete;
    CoursesRepo& operator=(CoursesRepo&&) = delete;
  private:
    CoursesRepo() = default;

};


#endif //SISTEMABEDELIA_COURSESREPO_H
