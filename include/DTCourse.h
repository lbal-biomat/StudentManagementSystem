//
// Created by lucia on 9/4/22.
//

#ifndef SISTEMABEDELIA_DTCOURSE_H
#define SISTEMABEDELIA_DTCOURSE_H

#include <vector>
#include <string>

class DTStudent;

class DTCourse {
  private:
    int code; //Courses are identified by the code
    int credits;
    std::string name;
    std::vector<DTCourse*> prerequisiteCourses;
    std::vector<DTStudent*> enrolledStudents;
    int maxStudents;
  public:
    DTCourse(int cod, int cred, std::string nom, int maxSt);
    int getCode() const;
    int getCredits() const;
    std::string getName();
    std::vector<DTCourse*> getPrerequisiteCourses();
    std::vector<DTStudent*> getEnrolledStudents();
    int getMaxStudents() const;

};


std::ostream& operator<<(std::ostream& os, DTCourse& c);

#endif //SISTEMABEDELIA_DTCOURSE_H
