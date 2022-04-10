//
// Created by lucia on 5/4/22.
//

#include "../include/adminInterface.h"


void adminInterface::registerStudent() {

  int ID = getInt("\nEnter student ID: ");
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

  int num = getInt("\nEnter classroom number: ");
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
  coursesController.addCourse(cod, cred, name);
  std::cout << "Successfully added.\n";
}

void adminInterface::addApproval() {
  int ID = getInt("\nEnter student ID: ");
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
  try {
    TDate d = getDate("Enter date of approvals: ");
    studentsController.addApprovalToStudent(ID, cod, grade, d);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::addPreRequisite() {
  int cod = getInt("\nEnter course code: ");
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


DTReservation adminInterface::getReservationData() {
  int num = getInt("\nEnter classroom number: ");
  if (!classroomsController.existsClassroom(num)) {
    throw std::invalid_argument("There isn't any classroom with that number in the system.\n");
  }
  TDate fini = getDate("Enter start date as DD MM YYYY: ");
  TDate fend = getDate("Enter end date as DD MM YYYY: ");
  if (!(fini < fend)) {
    throw std::invalid_argument("Error: End date must come after the start date.\n");
  }
  TTime tini = getTime("Enter start time as HH MM: ");
  TTime tend = getTime("Enter end time as HH MM: ");
  if (!(tini < tend)) {
    throw std::invalid_argument("Error: End time must come after the start time.\n");
  }
  vector<DayOfWeek> dow = getDaysOfWeek();
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (dow.empty()) {
    throw std::invalid_argument("Error: No days selected.\n");
  }
  DTReservation res(num, -1, tini, tend, fini, fend, dow);
  return res;
}

void adminInterface::addReservation() {
  int cod = getInt("\nEnter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  try {
    DTReservation res = getReservationData();
    classroomsController.addClassroomReservation(res.getClassroom(), cod, res.getStartTime(),
              res.getEndTime(), res.getStartDate(), res.getEndDate(), res.getDays());
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  std::cout << "Successfully added.\n";
}

void adminInterface::printCourseEnrollments() {
  int cod = getInt("\nEnter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  std::vector<DTStudent> stds = coursesController.getEnrolledStudents(cod);
  for (auto & s : stds) {
    std::cout << s << "\n";
  }
}


void adminInterface::printPrerequisites() {
  int cod = getInt("\nEnter course code: ");
  if (!coursesController.existsCourse(cod)) {
    std::cerr << "There isn't any course with that code in the system.\n";
    return;
  }
  std::vector<DTCourse> pre = coursesController.getPrerequisiteCourses(cod);
  for (auto & p : pre) {
    std::cout << p << "\n";
  }
}

void adminInterface::printReservations() {
  int num = getInt("\nEnter classroom number: ");
  if (!classroomsController.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  std::vector<DTReservation> res = classroomsController.getClassroomsReservations(num);
  for (auto & r: res) {
    std::cout << r << "\n";
  }
}

void adminInterface::printCourses() {
  std::vector<DTCourse> courses = coursesController.getCoursesInformation();
  for (auto & c: courses) {
    std::cout << c << "\n";
  }
}

void adminInterface::printStudents() {
  std::vector<DTStudent> st = studentsController.getStudentsInformation();
  for (auto & s: st) {
    std::cout << s << "\n";
  }
}

void adminInterface::isAvailableClassroom() {
  try {
    DTReservation res = getReservationData();
    std::cout << (classroomsController.isAvailable(res.getClassroom(), res.getStartTime(), res.getEndTime(),
                  res.getStartDate(),res.getEndDate(), res.getDays()) ? "Is available" : "Is not available");
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
}

void adminInterface::printClassroomInformation() {
  int num = getInt("\nEnter classroom number: ");
  if (!classroomsController.existsClassroom(num)) {
    std::cerr << "There isn't any classroom with that number in the system.\n";
    return;
  }
  DTClassroom cl = classroomsController.getClassroomInformation(num);
  std::cout << cl << "\n";
}


adminInterface::adminInterface(StudentsController& stcont, ClassroomsController& clscont, CoursesController& coucont) :
        studentsController(stcont), classroomsController(clscont), coursesController(coucont) {
  menu = {{{1, {"Register student", [this]{return registerStudent();}}},
           {2, {"Add classroom", [this]{return addClassroom();}}},
           {3, {"Add course", [this]{return addCourse();}}},
           {4, {"Print enrolled students in course", [this]{return printCourseEnrollments();}}},
           {5, {"Add approvals to student records", [this]{return addApproval();}}},
           {6, {"Print course prerequisites", [this]{return printPrerequisites();}}},
           {7, {"Add prerequisite to course", [this]{return addPreRequisite();}}},
           {8, {"Print classroom information", [this]{return printClassroomInformation();}}},
           {9, {"Check classroom availability", [this]{return isAvailableClassroom();}}},
           {10, {"Add classroom reservation", [this]{return addReservation();}}},
           {11, {"Print classroom reservations", [this]{return printReservations();}}},
           {12, {"Print all courses in system", [this]{return printCourses();}}},
           {13, {"Print all students in system", [this]{return printStudents();}}},
           {14, {"Log Out", []{return ;}}},
       }};
}