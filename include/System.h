//
// Created by lucia on 27/3/22.
//

//TODO: implementar un mecanismo de persistencia de datos
//TODO: implementar sistema de login que permita al estudiante inscribirse/desinscribirse, consultar sus inscripciones y obtener su escolaridad

#ifndef SISTEMABEDELIA_SYSTEM_H
#define SISTEMABEDELIA_SYSTEM_H

#include "TStudent.h"
#include "TCourse.h"
#include "TClassroom.h"

#include <vector>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class System {
  private:
    unordered_map<int, TStudent> students; //the key is the ID
    unordered_map<int, TCourse> courses; //the code is the key
    unordered_map<int, TClassroom> classrooms;
  public:
    void registerStudent(int ID, string name);
    void addClassroom(int code, int capacity);
    void addCourse(int code, int credits, string name, int maxStudents);
    void enrollStudentInCourse(int ID, int code);
    void unenrollStudentFromCourse(int ID, int code);
    void printEnrolledStudents(int courseCode);
    void printStudentEnrollments(int ID);
    void addPreRequiredCourse(int code, int requiredCode);
    void printPrerequisiteCourses(int codeCourse);
    void addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime, TDate startDate,
                                 TDate endDate, vector<DayOfWeek> days);
    void printReservations(int numRoom);
    void addApprovalToStudent(int ID, int courseNum, int grade, TDate date);
    void printStudentTranscript(int ID);
    void printCourses();
    void printStudents();
    bool existsStudent(int ID);
    bool existsClassroom(int classNum);
    bool existsCourse(int code);
    static bool validateID(int ID);
};


#endif //SISTEMABEDELIA_SYSTEM_H
