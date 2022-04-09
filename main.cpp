
#include "include/adminInterface.h"
#include "include/studentInterface.h"
#include "include/Menu.h"


void runAsStudent(StudentsController sc, CoursesController cc) {
  int id = studentInterface::studentLogIn();
  if (id == -1) {
    return;
  }
  studentInterface st(sc, cc, id);
  studentInterface::callMenu(st.menu, "Log Out");
}

int main() {
  ClassroomsController clc;
  CoursesController cc;
  StudentsController sc;
  adminInterface ad(sc, clc, cc);
  Menu menu = {{{0, {"Exit", []{return ;}}},
                {1, {"Login is admin", [ad]{adminInterface::callMenu(ad.menu, "Log Out");}}},
                {2, {"Login is student", [sc, cc]{ runAsStudent(sc, cc);}}},
                }};

  Interface::callMenu(menu, "Exit");

  return 0;
}
