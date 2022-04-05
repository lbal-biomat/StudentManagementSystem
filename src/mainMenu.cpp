//
// Created by lucia on 3/4/22.
//

#include "../include/mainMenu.h"
#include <iostream>

using namespace std;


static TDate getDate(const string& message) {
  int day, month, year;
  bool valid;
  do {
    cout << message;
    cin >> day;
    cin >> month;
    cin >> year;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
      cout << "Invalid date. Try again." << endl;
      valid = false;
    }
    else valid = true;
  } while (!valid);
  return {day, month, year};
}

static int getInt(const string& mes) {
  int input = -1;
  bool valid = false;
  do {
    cout << mes;
    cin >> input;
    if (cin.good()) {	valid = true;}
    else {
      cin.clear();
      cin.ignore(999,'\n');
      cout << "Invalid entry, try again: ";
    }
  } while (!valid);
  return input;
}

static vector<DayOfWeek> getDaysOfWeek() {
  cout << "Enter every day of the week the reservation applies to and end with '.' : " << endl;
  cout << "0-Sunday\n";
  cout << "1-Monday\n";
  cout << "2-Tuesday\n";
  cout << "3-Wednesday\n";
  cout << "4-Thursday\n";
  cout << "5-Friday\n";
  cout << "6-Saturday\n";
  vector<DayOfWeek> vec;
  int day;
  while (cin >> day) {
    vec.push_back(static_cast<DayOfWeek>(day));
  }
  return vec;
}

void printMenu() {
  cout << "Enter option: " << endl << \
						"1-Register student " << endl << \
						"2-Add classroom" << endl << \
						"3-Add course " << endl << \
						"4-Enroll student in course " << endl << \
						"5-Unenroll student from course" << endl << \
            "6-Print current enrollments for student" << endl << \
            "7-Print enrolled students in course" << endl << \
            "8-Add approval to student records" << endl <<\
            "9-Print student transcripts" << endl << \
						"10-Print course prerequisites" << endl << \
            "11-Add prerequisite to course" << endl << \
						"12-Add reservation to classroom " << endl << \
            "13-Print classroom reservations" << endl << \
            "14-Print all courses in system" << endl << \
            "15-Print all students in system" << endl << \
            "16-Exit" << endl;
}


void registerStudent(System& sis) {

  int ID = getInt("Enter student ID: ");
  if (sis.existsStudent(ID)) {
    cout << "There is a student with that ID in the system." << endl;
    return;
  }
  string name;
  cout << "Enter student name: ";
  cin >> name;
  try {
    sis.registerStudent(ID, name);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully registered." << endl;
}

void addClassroom(System& sis) {

  int num = getInt("Enter classroom number: ");
  if (sis.existsClassroom(num)) {
    cout << "There is a classroom with that number in the system." << endl;
    return;
  }
  int cap = getInt("Enter capacity: ");
  sis.addClassroom(num, cap);
  cout << "Successfully entered." << endl;
}

void addCourse(System& sis) {
  int cod = getInt("Enter course code: ");
  if (sis.existsCourse(cod)) {
    cout << "There is a course with that code in the system." << endl;
    return;
  }
  string name;
  cout << "Enter course name: ";
  cin >> name;
  int cred = getInt("Enter course credits: ");
  int max = getInt("Enter course maximum number of students: ");
  sis.addCourse(cod, cred, name, max);
  cout << "Successfully added." << endl;
}

void enrollStudent(System& sis) {
  int ID = getInt("Enter student ID: ");
  if (!sis.existsStudent(ID)) {
    cout << "There isn't any student with that ID in the system." << endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  try {
    sis.enrollStudentInCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully enrolled." << endl;

}

void unEnrollStudent(System& sis) {

  int ID = getInt("Enter student ID: ");
  if (!sis.existsStudent(ID)) {
    cout << "There isn't any student with that ID in the system." << endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  try {
    sis.unenrollStudentFromCourse(ID, cod);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully unenrolled." << endl;
}

void addApproval(System& sis) {

  int ID = getInt("Enter student ID: ");
  if (!sis.existsStudent(ID)) {
    cout << "There isn't any student with that ID in the system." << endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  int grade = getInt("Enter grade: ");
  while (grade > 12) {
    cout << "Grade can not be larger than 12. Try again: " << endl;
    grade = getInt("Enter grade: ");
  }
  TDate d = getDate("Enter date of approval: ");
  try {
    sis.addApprovalToStudent(ID, cod, grade, d);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully added." << endl;

}

void addPreRequisite(System& sis) {

  int cod = getInt("Enter course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  int pre = getInt("Enter pre required course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  try {
    sis.addPreRequiredCourse(cod, pre);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully added." << endl;

}

void addReservation(System& sis) {
  int num = getInt("Enter classroom number: ");
  if (!sis.existsClassroom(num)) {
    cout << "There isn't any classroom with that number in the system." << endl;
    return;
  }
  int cod = getInt("Enter course code: ");
  if (!sis.existsCourse(cod)) {
    cout << "There isn't any course with that code in the system." << endl;
    return;
  }
  TDate fini = getDate("Enter start date: ");
  TDate fend = getDate("Enter end date: ");
  if (!(fini < fend)) {
    cout << "Error: End date must come after the start date.";
    return;
  }
  int tini = getInt("Enter start time in military time: ");
  int tend = getInt("Enter end time in military time: ");
  if (tini >= tend) {
    cout << "Error: End time must come after the start time.";
    return;
  }
  vector<DayOfWeek> dow = getDaysOfWeek();
  cin.clear();
  cin.ignore(999,'\n');
  try {
    sis.addClassroomReservation(num, cod, tini, tend, fini, fend, dow);
  }
  catch (std::invalid_argument& err) {
    std::cerr << "Unexpected error: " << err.what() << std::endl;
    return;
  }
  cout << "Successfully added." << endl;
}

int mainMenu(System& sis) {
  int option = 0;
  do {
    printMenu();
    cin >> option;
    cin.get(); //limpia el newline
    switch (option) {
      case 1: {
        registerStudent(sis);
        break;
      }
      case 2: {
        addClassroom(sis);
        break;
      }
      case 3: {
        addCourse(sis);
        break;
      }
      case 4: {
        enrollStudent(sis);
        break;
      }
      case 5 : {
        unEnrollStudent(sis);
        break;
      }
      case 6 : {
        int ID = getInt("Enter student ID: ");
        if (!sis.existsStudent(ID)) {
          cout << "There isn't any student with that ID in the system." << endl;
          break;
        }
        sis.printStudentEnrollments(ID);
        break;
      }
      case 7 : {
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        sis.printEnrolledStudents(cod);
        break;
      }
      case 8 : {
        addApproval(sis);
        break;
      }
      case 9 : {
        int ID = getInt("Enter student ID: ");
        if (!sis.existsStudent(ID)) {
          cout << "There isn't any student with that ID in the system." << endl;
          break;
        }
        sis.printStudentTranscript(ID);
        break;
      }
      case 10 : {
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        sis.printPrerequisiteCourses(cod);
        break;
      }
      case 11: {
        addPreRequisite(sis);
        break;
      }
      case 12 : {
        addReservation(sis);
        break;
      }
      case 13 : {
        int num = getInt("Enter classroom number: ");
        if (!sis.existsClassroom(num)) {
          cout << "There isn't any classroom with that number in the system." << endl;
          break;
        }
        sis.printReservations(num);
        break;
      }
      case 14 : {
        sis.printCourses();
        break;
      }
      case 15 : {
        sis.printStudents();
        break;
      }
      case 16 : {
        cout << "Session ended." << endl;
        break;
      }
      default: {
        cout << "Invalid entry, try again.";
        cin.clear();
        cin.ignore(999, '\n');
        break;
      }
    }
  } while (option != 16);

  return 0;
}
