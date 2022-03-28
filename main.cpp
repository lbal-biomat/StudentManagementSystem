#include <iostream>

#include "include/System.h"

using namespace std;

static bool getBool(const string& mes) {
  int input = -1;
  bool valid = false;
  do {
    cout << mes;
    cin >> input;
    if (cin.good() && ((input == 0) || (input == 1))) {
      valid = true;
    }
    else {
      input = -1;
      cin.clear();
      cin.ignore(999,'\n');
      cout << "Invalid entry, try again." << endl;
    }
  } while (!valid);
  bool b = input;
  return b;
}


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
						"7-Check course requirements" << endl << \
            "8-Check classroom reservations" << endl << \
            "9-Check all courses in system" << endl << \
            "10-Check all students in system" << endl << \
            "11-Print student transcripts" << endl << \
            "12-Add approval to student records" << endl <<\
            "13-Get enrolled students in course" << endl << \
            "14-Exit" << endl;

    cin >> option;
    cin.get(); //limpia el newline
    switch (option) {
      case 1: {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        int ID = getInt("Enter student ID: ");
        sis.registerStudent(ID, name);
        cout << "Successfully registered." << endl;
        break;
      }
      case 2: {
        int num = getInt("Enter classroom number: ");
        int cap = getInt("Enter capacity: ");
        sis.addClassroom(num, cap);
        cout << "Successfully entered." << endl;
        break;
      }
      case 3: {
        int cod = getInt("Enter course code: ");
        string name;
        cout << "Enter course name: ";
        cin >> name;
        int cred = getInt("Enter course credits: ");
        sis.addCourse(cod, cred, name);
        cout << "Successfully added." << endl;
        break;
      }
      case 4: {
        int ID = getInt("Enter student ID: ");
        int cod;
        cout << "Enter course code: ";
        cin >> cod;
        sis.enrollStudentInCourse(ID, cod);
        cout << "Successfully enrolled." << endl;
        break;
      }
      case 5 : {
        int ID = getInt("Enter student ID: ");
        int cod = getInt("Enter course code: ");
        sis.unenrollStudentFromCourse(ID, cod);
        cout << "Successfully unenrolled." << endl;
        break;
      }
      case 6 : {
        int num = getInt("Enter classroom number: ");
        int cod = getInt("Enter course code: ");
        TDate fini = getDate("Enter start date: ");
        TDate fend = getDate(" Enter end date: ");
        int tini = getInt("Enter start time in military time: ");
        int tend = getInt("Enter end time in military time: ");
        vector<DayOfWeek> dow = getDaysOfWeek();
        sis.addClassroomReservation(num, cod, tini, tend, fini, fend, dow);
        cout << "Successfully added." << endl;
        break;
      }
      case 7 : {
        int cod = getInt("Enter course code: ");
        vector<TCourse*> prev = sis.queryPrerequisiteCourses(cod);
        for (auto & c : prev) {
          cout << c;
        }
        break;
      }
      case 8 : {
        int num;
        cout << "Enter classroom number: ";
        cin >> num;
        vector<TClassroomReservation> res = sis.queryReservations(num);
        for (auto & r : res) {
          cout << r;
        }
        break;
      }
      case 9 : {
        vector<TCourse> courses = sis.getCourses();
        for (auto & c : courses) {
          cout << c;
        }
        break;
      }
      case 10 : {
        vector<TStudent> stud = sis.getStudents();
        for (auto & s : stud) {
          cout << s;
        }
        break;
      }
      case 11 : {
        int ID = getInt("Enter student ID: ");
        sis.printStudentTranscript(ID);
      }
      case 12 : {
        int ID = getInt("Enter student ID: ");
        int cod = getInt("Enter course code: ");
        int grade = getInt("Enter grade: ");
        TDate d = getDate("Enter date of approval: ");
        sis.addApprovalToStudent(ID, cod, grade, d);
        cout << "Successfully added." << endl;
      }
      case 13 : {
        int cod = getInt("Enter course code: ");
        vector<TStudent *> vec = sis.getEnrolledStudents(cod);
        for (auto & st:vec) {
          cout << st;
        }
      }
      case 14 : {
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
