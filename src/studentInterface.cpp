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



studentInterface::studentInterface(StudentsController &stctr, CoursesController &crctr) :
  studentsController(stctr), coursesController(crctr), student(-1) {
  menu = {{{1, {"Enroll in course", [this]{return enrollStudent();}}},
           {2, {"Unenroll from course", [this]{return unEnrollStudent();}}},
           {3, {"Print current enrollments", [this]{return studentsController.printStudentEnrollments(student);}}},
           {4, {"Print transcripts", [this]{return studentsController.printStudentTranscript(student);}}},
           {5, {"Print course prerequisites", [this]{return printPrerequisites();}}},
           {6, {"Log Out", []{return ;}}},
          }};
}

int studentInterface::getID() {
  int id = getInt("Enter ID: ");
  bool valid = validateID(id);
  while (!valid) {
    std::cerr << "Invalid entry, try again. " << std::endl;
    id = getInt("Enter ID: ");
    valid = validateID(id);
  }
  return id;
}


bool studentInterface::studentLogIn() {
  int countErrors = 0;
  int id = getInt("Enter ID: ");
  bool valid = (validateID(id) && studentsController.existsStudent(id));
  while (!valid) {
    std::cerr << "There isn't any student with that ID in the system. Try again.\n";
    countErrors++;
    if (countErrors >= 3) {break;}
    id = getInt("Enter ID: ");
    valid = (validateID(id) && studentsController.existsStudent(id));
  }
  if (countErrors >= 3) {
    std::cerr << "Too many invalid login attempts.\n\n";
    return false;
  }
  student = id;
  return true;
}