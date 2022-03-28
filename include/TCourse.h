//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCOURSE_H
#define SISTEMABEDELIA_TCOURSE_H

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
    TCourse(int cod, int cred, string nom);
    int getCode() const;
    int getCredits() const;
    string getName();
    vector<TCourse*> getPrerequisiteCourses();
    vector<TStudent*> getEnrolledStudents();
    void addStudent(TStudent*);
    void unenrollStudent(int ID);
};

std::ostream& operator<<(std::ostream& os, TCourse& c);

#endif //SISTEMABEDELIA_TCOURSE_H
