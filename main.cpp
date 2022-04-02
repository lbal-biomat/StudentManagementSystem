#include <iostream>

#include "include/System.h"

using namespace std;


static TDate getDate(const string& mes) {
  int day, month, year;
  cout << mes;
  cin >> day;
  cin >> month;
  cin >> year;
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

int main() {
  System sis;

  int option = 0;
  do {
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

    cin >> option;
    cin.get(); //limpia el newline
    switch (option) {
      case 1: {
        int ID = getInt("Enter student ID: ");
        if (sis.existsStudent(ID)) {
          cout << "There is a student with that ID in the system." << endl;
          break;
        }
        string name;
        cout << "Enter student name: ";
        cin >> name;
        try {
          sis.registerStudent(ID, name);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Unexpected error: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully registered." << endl;
        break;
      }
      case 2: {
        int num = getInt("Enter classroom number: ");
        if (sis.existsClassroom(num)) {
          cout << "There is a classroom with that number in the system." << endl;
          break;
        }
        int cap = getInt("Enter capacity: ");
        sis.addClassroom(num, cap);
        cout << "Successfully entered." << endl;
        break;
      }
      case 3: {
        int cod = getInt("Enter course code: ");
        if (sis.existsCourse(cod)) {
          cout << "There is a course with that code in the system." << endl;
          break;
        }
        string name;
        cout << "Enter course name: ";
        cin >> name;
        int cred = getInt("Enter course credits: ");
        int max = getInt("Enter course maximum number of students: ");
        sis.addCourse(cod, cred, name, max);
        cout << "Successfully added." << endl;
        break;
      }
      case 4: {
        int ID = getInt("Enter student ID: ");
        if (!sis.existsStudent(ID)) {
          cout << "There isn't any student with that ID in the system." << endl;
          break;
        }
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        try {
          sis.enrollStudentInCourse(ID, cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Unexpected error: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully enrolled." << endl;
        break;
      }
      case 5 : {
        int ID = getInt("Enter student ID: ");
        if (!sis.existsStudent(ID)) {
          cout << "There isn't any student with that ID in the system." << endl;
          break;
        }
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        try {
          sis.unenrollStudentFromCourse(ID, cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Unexpected error: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully unenrolled." << endl;
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
        int ID = getInt("Enter student ID: ");
        if (!sis.existsStudent(ID)) {
          cout << "There isn't any student with that ID in the system." << endl;
          break;
        }
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
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
          break;
        }
        cout << "Successfully added." << endl;
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
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        int pre = getInt("Enter pre required course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        try {
          sis.addPreRequiredCourse(cod, pre);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Unexpected error: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
        break;
      }
      case 12 : {
        int num = getInt("Enter classroom number: ");
        if (!sis.existsClassroom(num)) {
          cout << "There isn't any classroom with that number in the system." << endl;
          break;
        }
        int cod = getInt("Enter course code: ");
        if (!sis.existsCourse(cod)) {
          cout << "There isn't any course with that code in the system." << endl;
          break;
        }
        TDate fini = getDate("Enter start date: ");
        TDate fend = getDate("Enter end date: ");
        if (!(fini < fend)) {
          cout << "Error: End date must come after the start date.";
          break;
        }
        int tini = getInt("Enter start time in military time: ");
        int tend = getInt("Enter end time in military time: ");
        if (tini >= tend) {
          cout << "Error: End time must come after the start time.";
          break;
        }
        vector<DayOfWeek> dow = getDaysOfWeek();
        cin.clear();
        cin.ignore(999,'\n');
        try {
          sis.addClassroomReservation(num, cod, tini, tend, fini, fend, dow);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Unexpected error: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
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
  } while (option != 15);

  return 0;
}
