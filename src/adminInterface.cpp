//
// Created by lucia on 5/4/22.
//

#include "../include/adminInterface.h"


void adminInterface::registerStudent() {

  int ID = getInt("Enter student ID: ");
  if (system.existsStudent(ID)) {
    std::cerr << "There is a student with that ID in the system.\n";
    return;
  }
  string name;
  std::cout << "Enter student name: ";
  std::cin >> name;
  try {
    system.registerStudent(ID, name);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully registered.\n";
}

void adminInterface::addClassroom() {

  int num = getInt("Enter classroom number: ");
  if (system.existsClassroom(num)) {
    std::cerr << "There is a classroom with that number in the system.\n";
    return;
  }
  int cap = getInt("Enter capacity: ");
  system.addClassroom(num, cap);
  std::cout << "Successfully entered.\n";
}

void adminInterface::addCourse() {
  int cod = getInt("Enter course code: ");
  if (system.existsCourse(cod)) {
    std::cerr << "There is a course with that code in the system.\n";
    return;
  }
  string name;
  std::cout << "Enter course name: ";
  std::cin >> name;
  int cred = getInt("Enter course credits: ");
  int max = getInt("Enter course maximum number of students: ");
  system.addCourse(cod, cred, name, max);
  std::cout << "Successfully added.\n";
}

void adminInterface::enrollStudent() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    system.enrollStudentInCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully enrolled.\n";
}

void adminInterface::unEnrollStudent() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    system.unenrollStudentFromCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully unenrolled.\n";
}

void adminInterface::addApproval() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  int grade = getInt("Enter grade: ");
  while (grade > 12) {
    std::cerr << "Grade can not be greater than 12. Try again.\n";
    grade = getInt("Enter grade: ");
  }
  TDate d = getDate("Enter date of approval: ");
  try {
    system.addApprovalToStudent(ID, cod, grade, d);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::addPreRequisite() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  int pre = getInt("Enter pre required course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    system.addPreRequiredCourse(cod, pre);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::addReservation() {
  int num = getInt("Enter classroom number: ");
  if (!system.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  TDate fini = getDate("Enter start date: ");
  TDate fend = getDate("Enter end date: ");
  if (!(fini < fend)) {
    std::cerr << "Error: End date must come after the start date.\n";
    return;
  }
  int tini = getInt("Enter start time in military time: ");
  int tend = getInt("Enter end time in military time: ");
  if (tini >= tend) {
    std::cerr << "Error: End time must come after the start time.\n";
    return;
  }
  vector<DayOfWeek> dow = getDaysOfWeek();
  std::cin.clear();
  std::cin.ignore(999,'\n');
  try {
    system.addClassroomReservation(num, cod, tini, tend, fini, fend, dow);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::printStudentEnrollments() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  system.printStudentEnrollments(ID);
}

void adminInterface::printCourseEnrollments() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  system.printEnrolledStudents(cod);
}

void adminInterface::printTranscripts() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  system.printStudentTranscript(ID);
}

void adminInterface::printPrerequisites() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  system.printPrerequisiteCourses(cod);
}

void adminInterface::printReservations() {
  int num = getInt("Enter classroom number: ");
  if (!system.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  system.printReservations(num);
}


adminInterface::adminInterface(System& sis) : Interface(sis) {
  menu = {{{1, {"Register student", [this]{return registerStudent();}}},
           {2, {"Add classroom", [this]{return addClassroom();}}},
           {3, {"Add course", [this]{return addCourse();}}},
           {4, {"Enroll student in course", [this]{return enrollStudent();}}},
           {5, {"Unenroll student from course", [this]{return unEnrollStudent();}}},
           {6, {"Print current enrollments for student", [this]{return printStudentEnrollments();}}},
           {7, {"Print enrolled students in course", [this]{return printCourseEnrollments();}}},
           {8, {"Add approval to student records", [this]{return addApproval();}}},
           {9, {"Print student transcripts", [this]{return printTranscripts();}}},
           {10, {"Print course prerequisites", [this]{return printPrerequisites();}}},
           {11, {"Add prerequisite to course", [this]{return addPreRequisite();}}},
           {12, {"Add classroom reservation", [this]{return addReservation();}}},
           {13, {"Print classroom reservations", [this]{return printReservations();}}},
           {14, {"Print all courses in system", [this]{return system.printCourses();}}},
           {15, {"Print all students in system", [this]{return system.printStudents();}}},
           {16, {"Log Out", []{return ;}}},
       }};
}
