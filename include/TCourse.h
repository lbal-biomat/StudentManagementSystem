//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCOURSE_H
#define SISTEMABEDELIA_TCOURSE_H

#include "DTCourse.h"
#include <vector>
#include <string>


class TStudent;

class TCourse {
  private:
    int code; //Courses are identified by the code
    int credits;
    std::string name;
    std::vector<TCourse*> prerequisiteCourses;
    std::vector<TStudent*> enrolledStudents;
  public:
    TCourse();
    TCourse(int cod, int cred, std::string nom);
    int getCode() const;
    int getCredits() const;
    std::string getName() const;
    void addPreRequiredCourse(TCourse*);
    std::vector<TCourse*> getPrerequisiteCourses() const;
    std::vector<TStudent*> getEnrolledStudents() const;
    void enrollStudent(TStudent *s);
    void unenrollStudent(int ID);
    DTCourse getDTCourse() const;
};

#endif //SISTEMABEDELIA_TCOURSE_H
