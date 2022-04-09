
#include "include/adminInterface.h"
#include "include/studentInterface.h"
#include "include/Menu.h"


void runAsStudent() {
  int id = studentInterface::studentLogIn();
  if (id == -1) {
    return;
  }
  studentInterface st(id);
  studentInterface::callMenu(st.menu, "Log Out");
}

int main() {
  adminInterface ad;
  Menu menu = {{{0, {"Exit", []{return ;}}},
                {1, {"Login is admin", [ad]{adminInterface::callMenu(ad.menu, "Log Out");}}},
                {2, {"Login is student", []{ runAsStudent();}}},
                }};

  Interface::callMenu(menu, "Exit");

  return 0;
}
