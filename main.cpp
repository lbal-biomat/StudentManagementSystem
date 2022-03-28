#include <iostream>

#include "include/Sistema.h"

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


static TFecha getDate(const string& mes) {
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

static vector<DiaSemana> getDaysOfWeek() {
  cout << "Enter every day of the week the reservation applies to and end with '.' : " << endl;
  cout << "0-Sunday\n";
  cout << "1-Monday\n";
  cout << "2-Tuesday\n";
  cout << "3-Wednesday\n";
  cout << "4-Thursday\n";
  cout << "5-Friday\n";
  cout << "6-Saturday\n";
  vector<DiaSemana> vec;
  int day;
  while (cin >> day) {
    vec.push_back(static_cast<DiaSemana>(day));
  }
  return vec;
}

int main() {
  Sistema sis;

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
            "8-Check clasroom reservations" << endl << \
            "9-Check all courses in system" << endl << \
            "10-Check all students in system" << endl << \
            "11-Exit" << endl;

    cin >> option;
    cin.get(); //limpia el newline
    switch (option) {
      case 1: {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        int ID = getInt("Enter student ID: ");
        sis.registrarEstudiante(ID, name);
        cout << "Succesfully registered." << endl;
        break;
      }
      case 2: {
        int num = getInt("Enter classroom number: ");
        int cap = getInt("Enter capacity: ");
        sis.agregarSalon(num, cap);
        cout << "Succesfully entered." << endl;
        break;
      }
      case 3: {
        int cod = getInt("Enter course code: ");
        string name;
        cout << "Enter course name: ";
        cin >> name;
        int cred = getInt("Enter course credits: ");
        sis.agregarCurso(cod, cred, name);
        cout << "Succesfully added." << endl;
        break;
      }
      case 4: {
        int ID = getInt("Enter student ID: ");
        int cod;
        cout << "Enter course code: ";
        cin >> cod;
        sis.inscribirEstudianteACurso(ID, cod);
        cout << "Succesfully enrolled." << endl;
        break;
      }
      case 5 : {
        int ID = getInt("Enter student ID: ");
        int cod = getInt("Enter course code: ");
        sis.borrarEstudianteDeCurso(ID, cod);
        cout << "Succesfully unenrolled." << endl;
        break;
      }
      case 6 : {
        int num = getInt("Enter classroom number: ");
        int cod = getInt("Enter course code: ");
        TFecha fini = getDate("Enter start date: ");
        TFecha fend = getDate(" Enter end date: ");
        int tini = getInt("Enter start time in military time: ");
        int tend = getInt("Enter end time in military time: ");
        vector<DiaSemana> dow = getDaysOfWeek();
        sis.agregarReservaSalon(num, cod, tini, tend, fini, fend, dow);
        cout << "Succesfully added." << endl;
        break;
      }
      case 7 : {
        int cod = getInt("Enter course code: ");
        vector<TCurso*> prev = sis.consultarPrevias(cod);
        for (auto & c : prev) {
          cout << c;
        }
        break;
      }
      case 8 : {
        int num;
        cout << "Enter classroom number: ";
        cin >> num;
        vector<TReservaSalon> res = sis.consultarReservas(num);
        for (auto & r : res) {
          cout << r;
        }
        break;
      }
      case 9 : {
        vector<TCurso> courses = sis.obtenerCursos();
        for (auto & c : courses) {
          cout << c;
        }
        break;
      }
      case 10 : {
        vector<TEstudiante> stud = sis.obtenerEstudiantes();
        for (auto & s : stud) {
          cout << s;
        }
        break;
      }
      case 11 : {
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
