
#include "include/adminInterface.h"
#include "include/studentInterface.h"
#include "include/StudentsController.h"
#include "include/CoursesController.h"
#include "include/ClassroomsController.h"


int main() {
  ClassroomsController classroomsController;
  CoursesController coursesController;
  StudentsController studentsController;
  adminInterface ad(studentsController, classroomsController, coursesController);
  studentInterface st(studentsController, coursesController);
  Interface *inter;
  bool exit_all = false;
  while (!exit_all) {
    int val;
    std::cout << " \n0-Login as admin, 1-Login as student, 2-Exit\n";
    std::cin >> val;
    if (val == 2) {
      exit_all = true;
    }
    else {
      if (val == 0) {
        inter = &ad;
      }
      else if (val == 1) {
        bool valid = st.studentLogIn();
        if (!valid) { continue;} //go back to main menu
        inter = &st;
      }
      else {
        std::cerr << "Not an option, try again.\n";
        continue;
      }
      inter->callMenu();
    }
  }
  return 0;
}
