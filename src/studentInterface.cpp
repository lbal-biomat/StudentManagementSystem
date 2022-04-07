//
// Created by lucia on 5/4/22.
//

#include "../include/studentInterface.h"



void studentInterface::enrollStudent() {
  int cod = getInt("Enter course code: ");
  if (!studentsController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    studentsController.enrollStudentInCourse(student, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully enrolled.\n";

}

void studentInterface::unEnrollStudent() {
  int cod = getInt("Enter course code: ");
  if (!studentsController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    studentsController.unenrollStudentFromCourse(student, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully unenrolled.\n";
}

void studentInterface::printPrerequisites() {
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  coursesController.printPrerequisiteCourses(cod);
}



studentInterface::studentInterface(StudentsController &stctr, CoursesController &crctr, int st) :
  studentsController(stctr), coursesController(crctr), student(st) {
  menu = {{{1, {"Enroll in course", [this]{return enrollStudent();}}},
           {2, {"Unenroll from course", [this]{return unEnrollStudent();}}},
           {3, {"Print current enrollments", [this]{return studentsController.printStudentEnrollments(student);}}},
           {4, {"Print transcripts", [this]{return studentsController.printStudentTranscript(student);}}},
           {5, {"Print course prerequisites", [this]{return printPrerequisites();}}},
           {6, {"Log Out", []{return ;}}},
          }};
}