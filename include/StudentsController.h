//
// Created by lucia on 6/4/22.
//

#ifndef SISTEMABEDELIA_STUDENTSCONTROLLER_H
#define SISTEMABEDELIA_STUDENTSCONTROLLER_H

#include <string>

#include "StudentsRepo.h"
#include "CoursesRepo.h"
#include "TTranscript.h"

class TDate;


class StudentsController {
  private:
    StudentsRepo& repoStudents = StudentsRepo::GetInstance();
    CoursesRepo& repoCourses = CoursesRepo::GetInstance();
  public:
    void registerStudent(int ID, std::string name);
    void addApprovalToStudent(int ID, int courseNum, int grade, TDate date);
    void enrollStudentInCourse(int ID, int code);
    void unenrollStudentFromCourse(int ID, int code);
    std::vector<DTCourse> getStudentEnrollments(int ID);
    TTranscript getStudentTranscript(int ID);
    std::vector<DTStudent> getStudentsInformation();
    [[nodiscard]] bool existsStudent(int ID) const;
    [[nodiscard]] bool existsCourse(int cod) const;
    StudentsController() = default;
};


#endif //SISTEMABEDELIA_STUDENTSCONTROLLER_H
