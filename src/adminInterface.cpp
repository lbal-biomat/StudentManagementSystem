//
// Created by lucia on 5/4/22.
//

#include "../include/adminInterface.h"


void adminInterface::registerStudent() {

  int ID = getInt("Enter student ID: ");
  if (studentsController.existsStudent(ID)) {
    std::cerr << "There is a student with that ID in the system.\n";
    return;
  }
  string name;
  std::cout << "Enter student name: ";
  std::cin >> name;
  try {
    studentsController.registerStudent(ID, name);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully registered.\n";
}

void adminInterface::addClassroom() {

  int num = getInt("Enter classroom number: ");
  if (classroomsController.existsClassroom(num)) {
    std::cerr << "There is a classroom with that number in the system.\n";
    return;
  }
  int cap = getInt("Enter capacity: ");
  classroomsController.addClassroom(num, cap);
  std::cout << "Successfully entered.\n";
}

void adminInterface::addCourse() {
  int cod = getInt("Enter course code: ");
  if (coursesController.existsCourse(cod)) {
    std::cerr << "There is a course with that code in the system.\n";
    return;
  }
  string name;
  std::cout << "Enter course name: ";
  std::cin >> name;
  int cred = getInt("Enter course credits: ");
  int max = getInt("Enter course maximum number of students: ");
  coursesController.addCourse(cod, cred, name, max);
  std::cout << "Successfully added.\n";
}

void adminInterface::addApproval() {
  int ID = getInt("Enter student ID: ");
  if (!studentsController.existsStudent(ID)) {
    std::cerr << "There isn't any student with that ID in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
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
    studentsController.addApprovalToStudent(ID, cod, grade, d);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::addPreRequisite() {
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  int pre = getInt("Enter pre required course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    coursesController.addPreRequiredCourse(cod, pre);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::addReservation() {
  int num = getInt("Enter classroom number: ");
  if (!classroomsController.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
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
    classroomsController.addClassroomReservation(num, cod, tini, tend, fini, fend, dow);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::printCourseEnrollments() {
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  coursesController.printEnrolledStudents(cod);
}


void adminInterface::printPrerequisites() {
  int cod = getInt("Enter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  coursesController.printPrerequisiteCourses(cod);
}

void adminInterface::printReservations() {
  int num = getInt("Enter classroom number: ");
  if (!classroomsController.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  classroomsController.printReservations(num);
}


adminInterface::adminInterface(StudentsController& stcont, ClassroomsController& clscont, CoursesController& coucont) :
        studentsController(stcont), classroomsController(clscont), coursesController(coucont) {
  menu = {{{1, {"Register student", [this]{return registerStudent();}}},
           {2, {"Add classroom", [this]{return addClassroom();}}},
           {3, {"Add course", [this]{return addCourse();}}},
           {4, {"Print enrolled students in course", [this]{return printCourseEnrollments();}}},
           {5, {"Add approval to student records", [this]{return addApproval();}}},
           {6, {"Print course prerequisites", [this]{return printPrerequisites();}}},
           {7, {"Add prerequisite to course", [this]{return addPreRequisite();}}},
           {8, {"Add classroom reservation", [this]{return addReservation();}}},
           {9, {"Print classroom reservations", [this]{return printReservations();}}},
           {10, {"Print all courses in system", [this]{return coursesController.printCourses();}}},
           {11, {"Print all students in system", [this]{return studentsController.printStudents();}}},
           {12, {"Log Out", []{return ;}}},
       }};
}
