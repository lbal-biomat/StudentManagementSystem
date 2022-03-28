//
// Created by lucia on 27/3/22.
//

//TODO: implementar un mencanismo de persistencia de datos
//TODO: implementar tabla hash para buscar students y courses
//TODO: implementar sistema de login que permita al estudiante inscribirse/desinscribirse, consultar sus incripciones y obtener su escolaridad

#ifndef SISTEMABEDELIA_SYSTEM_H
#define SISTEMABEDELIA_SYSTEM_H

#include "TStudent.h"
#include "TCourse.h"
#include "TClassroom.h"

#include <vector>
#include <string>

using std::vector;

class System {
  private:
    vector<TStudent> students;
    vector<TCourse> courses;
    vector<TClassroom> classrooms;
    TStudent* getPointerToStudent(int ID);
    TCourse* getPointerToCourse(int cod);
    TClassroom* getPointerToClassroom(int cod);
  public:
    void registerStudent(int ID, string name);
    void addClassroom(int code, int capacity);
    void addCourse(int code, int credits, string name);
    void enrollStudentInCourse(int ID, int code);
    void unenrollStudentFromCourse(int ID, int code);
    void addClassroomReservation(int numRoom, int codeCourse, int startTime, int endTime, TDate startDate,
                                 TDate endDate, vector<DayOfWeek> days);
    vector<TCourse*> queryPrerequisiteCourses(int codeCourse);
    vector<TClassroomReservation> queryReservations(int numRoom);
    vector<TCourse> getCourses();
    vector<TStudent> getStudents();
    void printStudentTranscript(int ID);
    void addApprovalToStudent(int ID, int courseNum, int grade, TDate date);
    vector<TStudent*> getEnrolledStudents(int courseCode);
    bool existsStudent(int ID);
    bool existsClassroom(int classNum);
    bool existsCourse(int code);
};


#endif //SISTEMABEDELIA_SYSTEM_H
