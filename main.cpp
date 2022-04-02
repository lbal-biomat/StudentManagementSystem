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
						"6-Add reservation to classroom " << endl << \
						"7-Print course prerequisites" << endl << \
            "8-Add prerequisite to course" << endl << \
            "9-Print classroom reservations" << endl << \
            "10-Print all courses in system" << endl << \
            "11-Print all students in system" << endl << \
            "12-Print student transcripts" << endl << \
            "13-Add approval to student records" << endl <<\
            "14-Get enrolled students in course" << endl << \
            "15-Exit" << endl;

    cin >> option;
    cin.get(); //limpia el newline
    switch (option) {
      case 1: {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        int ID = getInt("Enter student ID: ");
        try {
          sis.registerStudent(ID, name);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully registered." << endl;
        break;
      }
      case 2: {
        int num = getInt("Enter classroom number: ");
        int cap = getInt("Enter capacity: ");
        try {
          sis.addClassroom(num, cap);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully entered." << endl;
        break;
      }
      case 3: {
        int cod = getInt("Enter course code: ");
        string name;
        cout << "Enter course name: ";
        cin >> name;
        int cred = getInt("Enter course credits: ");
        int max = getInt("Enter course maximum number of students: ");
        try {
          sis.addCourse(cod, cred, name, max);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
        break;
      }
      case 4: {
        int ID = getInt("Enter student ID: ");
        int cod;
        cout << "Enter course code: ";
        cin >> cod;
        try {
          sis.enrollStudentInCourse(ID, cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully enrolled." << endl;
        break;
      }
      case 5 : {
        int ID = getInt("Enter student ID: ");
        int cod = getInt("Enter course code: ");
        try {
          sis.unenrollStudentFromCourse(ID, cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully unenrolled." << endl;
        break;
      }
      case 6 : {
        int num = getInt("Enter classroom number: ");
        int cod = getInt("Enter course code: ");
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
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
        break;
      }
      case 7 : {
        int cod = getInt("Enter course code: ");
        try {
          sis.printPrerequisiteCourses(cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
        }
        break;
      }
      case 8: {
        int cod = getInt("Enter course code: ");
        int pre = getInt("Enter pre required course code: ");
        try {
          sis.addPreRequiredCourse(cod, pre);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
        break;
      }
      case 9 : {
        int num = getInt("Enter classroom number: ");
        try {
          sis.printReservations(num);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
        }
        break;
      }
      case 10 : {
        sis.printCourses();
        break;
      }
      case 11 : {
        sis.printStudents();
        break;
      }
      case 12 : {
        int ID = getInt("Enter student ID: ");
        try {
          sis.printStudentTranscript(ID);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
        }
        break;
      }
      case 13 : {
        int ID = getInt("Enter student ID: ");
        int cod = getInt("Enter course code: ");
        int grade = getInt("Enter grade: ");
        TDate d = getDate("Enter date of approval: ");
        try {
          sis.addApprovalToStudent(ID, cod, grade, d);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        cout << "Successfully added." << endl;
        break;
      }
      case 14 : {
        int cod = getInt("Enter course code: ");
        vector<TStudent *> vec;
        try {
          sis.printEnrolledStudents(cod);
        }
        catch (std::invalid_argument& err) {
          std::cerr << "Error inesperado: " << err.what() << std::endl;
          break;
        }
        break;
      }
      case 15 : {
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
  } while (option != 11);

  return 0;
}
