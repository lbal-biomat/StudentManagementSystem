//
// Created by lucia on 5/4/22.
//

#include "../include/studentInterface.h"



void studentInterface::enrollStudent() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    system.enrollStudentInCourse(student, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully enrolled.\n";

}

void studentInterface::unEnrollStudent() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    system.unenrollStudentFromCourse(student, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully unenrolled.\n";
}



studentInterface::studentInterface(System &sis, int st) : Interface(sis){
  student = st;
  menu = {{{1, {"Enroll student in course", [this]{return enrollStudent();}}},
           {2, {"Unenroll student from course", [this]{return unEnrollStudent();}}},
           {3, {"Print current enrollments for student", [this]{return system.printStudentEnrollments(student);}}},
           {4, {"Print student transcripts", [this]{return system.printStudentTranscript(student);}}},
           {5, {"Exit", []{return ;}}},
          }};
}
