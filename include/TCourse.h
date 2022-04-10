//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCOURSE_H
#define SISTEMABEDELIA_TCOURSE_H

#include "DTCourse.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class TStudent;

class TCourse {
  private:
    int code; //Courses are identified by the code
    int credits;
    string name;
    vector<TCourse*> prerequisiteCourses;
    vector<TStudent*> enrolledStudents;
    int maxStudents;
  public:
    TCourse();
    TCourse(int cod, int cred, string nom, int maxSt);
    int getCode() const;
    int getCredits() const;
    string getName();
    void addPreRequiredCourse(TCourse*);
    vector<TCourse*> getPrerequisiteCourses();
    vector<TStudent*> getEnrolledStudents();
    void addStudent(TStudent*);
    void unenrollStudent(int ID);
    int getMaxStudents() const;
    DTCourse getDTCourse();
};

#endif //SISTEMABEDELIA_TCOURSE_H
