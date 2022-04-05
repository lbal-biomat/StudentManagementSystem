//
// Created by lucia on 5/4/22.
//

#include "../include/adminInterface.h"

TDate adminInterface::getDate(const string& message) {
  int day, month, year;
  bool valid;
  do {
    std::cout << message;
    std::cin >> day;
    std::cin >> month;
    std::cin >> year;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
      std::cout << "Invalid date. Try again." << std::endl;
      valid = false;
    }
    else valid = true;
  } while (!valid);
  return {day, month, year};
}

int adminInterface::getInt(const string& mes) {
  int input = -1;
  bool valid = false;
  do {
    std::cout << mes;
    std::cin >> input;
    if (std::cin.good()) {	valid = true;}
    else {
      std::cin.clear();
      std::cin.ignore(999,'\n');
      std::cout << "Invalid entry, try again: ";
    }
  } while (!valid);
  return input;
}

vector<DayOfWeek> adminInterface::getDaysOfWeek() {

  std::cout << "Enter every day of the week the reservation applies to and end with '.' : \n" <<
        "0-Sunday\n" <<
        "1-Monday\n" <<
        "2-Tuesday\n" <<
        "3-Wednesday\n" <<
        "4-Thursday\n" <<
        "5-Friday\n" <<
        "6-Saturday\n";
  vector<DayOfWeek> vec;
  int day;
  while (std::cin >> day) {
    vec.push_back(static_cast<DayOfWeek>(day));
  }
  return vec;
}


void adminInterface::registerStudent() {

  int ID = getInt("Enter student ID: ");
  if (system.existsStudent(ID)) {
    std::cout << "There is a student with that ID in the system." << std::endl;
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
  std::cout << "Successfully registered." << std::endl;
}

void adminInterface::addClassroom() {

  int num = getInt("Enter classroom number: ");
  if (system.existsClassroom(num)) {
    std::cout << "There is a classroom with that number in the system." << std::endl;
    return;
  }
  int cap = getInt("Enter capacity: ");
  system.addClassroom(num, cap);
  std::cout << "Successfully entered." << std::endl;
}

void adminInterface::addCourse() {
  int cod = getInt("Enter course code: ");
  if (system.existsCourse(cod)) {
    std::cout << "There is a course with that code in the system." << std::endl;
    return;
  }
  string name;
  std::cout << "Enter course name: ";
  std::cin >> name;
  int cred = getInt("Enter course credits: ");
  int max = getInt("Enter course maximum number of students: ");
  system.addCourse(cod, cred, name, max);
  std::cout << "Successfully added." << std::endl;
}

void adminInterface::enrollStudent() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cout << "There isn't any student with that ID in the system." << std::endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  try {
    system.enrollStudentInCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully enrolled." << std::endl;
}

void adminInterface::unEnrollStudent() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cout << "There isn't any student with that ID in the system." << std::endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  try {
    system.unenrollStudentFromCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully unenrolled." << std::endl;
}

void adminInterface::addApproval() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cout << "There isn't any student with that ID in the system." << std::endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  int grade = getInt("Enter grade: ");
  while (grade > 12) {
    std::cout << "Grade can not be larger than 12. Try again: " << std::endl;
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
  std::cout << "Successfully added." << std::endl;
}

void adminInterface::addPreRequisite() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  int pre = getInt("Enter pre required course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  try {
    system.addPreRequiredCourse(cod, pre);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added." << std::endl;
}

void adminInterface::addReservation() {
  int num = getInt("Enter classroom number: ");
  if (!system.existsClassroom(num)) {
    std::cout << "There isn't any classroom with that number in the system." << std::endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  TDate fini = getDate("Enter start date: ");
  TDate fend = getDate("Enter end date: ");
  if (!(fini < fend)) {
    std::cout << "Error: End date must come after the start date.";
    return;
  }
  int tini = getInt("Enter start time in military time: ");
  int tend = getInt("Enter end time in military time: ");
  if (tini >= tend) {
    std::cout << "Error: End time must come after the start time.";
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
  std::cout << "Successfully added." << std::endl;
}

void adminInterface::printStudentEnrollments() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cout << "There isn't any student with that ID in the system." << std::endl;
    return;
  }
  system.printStudentEnrollments(ID);
}

void adminInterface::printCourseEnrollments() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  system.printEnrolledStudents(cod);
}

void adminInterface::printTranscripts() {
  int ID = getInt("Enter student ID: ");
  if (!system.existsStudent(ID)) {
    std::cout << "There isn't any student with that ID in the system." << std::endl;
    return;
  }
  system.printStudentTranscript(ID);
}

void adminInterface::printPrerequisites() {
  int cod = getInt("Enter course code: ");
  if (!system.existsCourse(cod)) {
    std::cout << "There isn't any course with that code in the system." << std::endl;
    return;
  }
  system.printPrerequisiteCourses(cod);
}

void adminInterface::printReservations() {
  int num = getInt("Enter classroom number: ");
  if (!system.existsClassroom(num)) {
    std::cout << "There isn't any classroom with that number in the system." << std::endl;
    return;
  }
  system.printReservations(num);
}


adminInterface::adminInterface(System& sis) {
  system = sis;
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
           {16, {"Exit", []{return ;}}},
       }};
}
