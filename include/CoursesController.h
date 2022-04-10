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
    void addCourse(int code, int credits, std::string name);
    std::vector<DTStudent> getEnrolledStudents(int courseCode);
    void addPreRequiredCourse(int code, int requiredCode);
    std::vector<DTCourse> getPrerequisiteCourses(int codeCourse);
    std::vector<DTCourse> getCoursesInformation();
    [[nodiscard]] bool existsCourse(int code) const;

};


#endif //SISTEMABEDELIA_COURSESCONTROLLER_H
