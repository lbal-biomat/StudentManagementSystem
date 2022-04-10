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
  public:
    TCourse();
    TCourse(int cod, int cred, string nom);
    int getCode() const;
    int getCredits() const;
    string getName() const;
    void addPreRequiredCourse(TCourse*);
    vector<TCourse*> getPrerequisiteCourses() const;
    vector<TStudent*> getEnrolledStudents() const;
    void enrollStudent(TStudent *s);
    void unenrollStudent(int ID);
    DTCourse getDTCourse() const;
};

#endif //SISTEMABEDELIA_TCOURSE_H
