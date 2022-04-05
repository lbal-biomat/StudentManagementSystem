
#include "include/System.h"
#include "include/Interface.h"
#include "include/adminInterface.h"
#include "include/studentInterface.h"
#include "include/Menu.h"

int studentLogIn() {
  int input = -1;
  bool valid = false;
  do {
    std::cout << "Enter ID: " << std::flush;
    std::cin >> input;
    if (std::cin.good() && System::validateID(input)) {
      valid = true;
    }
    else {
      std::cin.clear();
      std::cin.ignore(999,'\n');
      std::cerr << "Invalid entry, try again. " << std::endl;
    }
  } while (!valid);
  return input;
}


int main() {
  System sis;
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
        inter = new adminInterface(sis);
      }
      else if (val == 1) {
        int id = studentLogIn();
        if (!sis.existsStudent(id)) {
          std::cerr << "There isn't any student with that ID in the system.\n";
          continue; //go back to main menu
        }
        inter = new studentInterface(sis, id);
      }
      else {
        std::cerr << "Not an option, try again.\n";
        continue;
      }
      std::cout << inter->menu;
      std::cin >> inter->menu;
      if (!inter->menu.options.contains(inter->menu.input)) { //bad option
        std::cerr << "Not a valid option. Try again.\n";
        std::cin.clear();
        std::cin.ignore(999, '\n');
      }
      else if (!(inter->menu.options[inter->menu.input].first == "Log Out")) { //option is not log out
        inter->menu.options[inter->menu.input].second();
      }
    }
  }
  return 0;
}
