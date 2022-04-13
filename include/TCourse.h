//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCOURSE_H
#define SISTEMABEDELIA_TCOURSE_H

#include "DTCourse.h"
#include <vector>
#include <string>


class TStudent;
class TClassroomReservation;

class TCourse {
  private:
    int code; //Courses are identified by the code
    int credits;
    std::string name;
    std::vector<TCourse*> prerequisiteCourses;
    std::vector<TStudent*> enrolledStudents;
    std::vector<TClassroomReservation*> reservations;
  public:
    TCourse();
    TCourse(int cod, int cred, std::string nom);
    [[nodiscard]] int getCode() const;
    [[nodiscard]] int getCredits() const;
    [[nodiscard]] std::string getName() const;
    void addPreRequiredCourse(TCourse*);
    [[nodiscard]] std::vector<TCourse*> getPrerequisiteCourses() const;
    [[nodiscard]] std::vector<TStudent*> getEnrolledStudents() const;
    void enrollStudent(TStudent *s);
    void unenrollStudent(int ID);
    [[nodiscard]] DTCourse getDTCourse() const;
    void addReservation(TClassroomReservation*);
};

#endif //SISTEMABEDELIA_TCOURSE_H
