
#include "include/adminInterface.h"
#include "include/studentInterface.h"
#include "include/Menu.h"
#include "include/StudentsController.h"
#include "include/CoursesController.h"
#include "include/ClassroomsController.h"


int studentLogIn() {
  int id = Interface::getInt("Enter ID: ");
  bool valid = Interface::validateID(id);
  while (!valid) {
    std::cerr << "Invalid entry, try again. " << std::endl;
    id = Interface::getInt("Enter ID: ");
    valid = Interface::validateID(id);
  }
  return id;
}

void callMenu(Interface* inter) {
  bool logout = false;
  do {
    std::cout << inter->menu;
    std::cin >> inter->menu;
    if (!inter->menu.options.contains(inter->menu.input)) { //bad option
      std::cerr << "Not a valid option. Try again.\n";
      std::cin.clear();
      std::cin.ignore(999, '\n');
    } else if ((inter->menu.options[inter->menu.input].first == "Log Out")) {
      logout = true;
    }
    else { //valid option, not log out, proceed
      inter->menu.options[inter->menu.input].second();
    }
  } while (!logout);
}


int main() {
  ClassroomsController classroomsController;
  CoursesController coursesController;
  StudentsController studentsController;
  bool exit_all = false;
  int val;
  while (!exit_all) {
    std::cout << " \n0-Login as admin, 1-Login as student, 2-Exit\n";
    std::cin >> val;
    if (val == 2) { // exit all
      exit_all = true;
    }
    else {
      Interface *inter;
      if (val == 0) {
        inter = new adminInterface(studentsController, classroomsController, coursesController);
      }
      else if (val == 1) {
        int id = studentLogIn();
        if (!studentsController.existsStudent(id)) {
          std::cerr << "There isn't any student with that ID in the system.\n";
          continue; //go back to main menu
        }
        inter = new studentInterface(studentsController, coursesController, id);
      }
      else {
        std::cerr << "Not an option, try again.\n";
        continue;
      }
      callMenu(inter);
      delete inter;
    }
  }
  return 0;
}
