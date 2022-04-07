//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_COURSESCONTROLLER_H
#define SISTEMABEDELIA_COURSESCONTROLLER_H

#include "CoursesRepo.h"

#include <string>

class CoursesController {
  private:
    CoursesRepo& repoCourses = CoursesRepo::GetInstance();
  public:
    void addCourse(int code, int credits, std::string name, int maxStudents);
    void printEnrolledStudents(int courseCode);
    void addPreRequiredCourse(int code, int requiredCode);
    void printPrerequisiteCourses(int codeCourse);
    void printCourses();
    [[nodiscard]] bool existsCourse(int code) const;

};


#endif //SISTEMABEDELIA_COURSESCONTROLLER_H
