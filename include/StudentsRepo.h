//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_STUDENTSREPO_H
#define SISTEMABEDELIA_STUDENTSREPO_H

#include "TStudent.h"
#include <unordered_map>

/*Singleton class*/

class StudentsRepo {
  public:
    std::unordered_map<int, TStudent> students; //the key is the ID
    static StudentsRepo& GetInstance();
    // Delete copy/move so extra instances can't be created/moved.
    StudentsRepo(const StudentsRepo&) = delete;
    StudentsRepo& operator=(const StudentsRepo&) = delete;
    StudentsRepo(StudentsRepo&&) = delete;
    StudentsRepo& operator=(StudentsRepo&&) = delete;
  private:
    StudentsRepo() = default;
};


#endif //SISTEMABEDELIA_STUDENTSREPO_H
