
#include "include/System.h"
#include "include/adminInterface.h"
#include "include/Menu.h"


int main() {
  System sis;
  adminInterface inter(sis);
  bool exit = false;
  while (!exit) {
    std::cout << inter.menu;
    std::cin >> inter.menu;

    if (!inter.menu.options.contains(inter.menu.input)) {
      std::cout << "Not a valid option. Try again.\n"  << std::endl;
      std::cin.clear();
      std::cin.ignore(999,'\n');
    }
    else {
      if (inter.menu.options[inter.menu.input].first == "Exit") {
        exit = true;
      }
      else {
        inter.menu.options[inter.menu.input].second();
      }
    }
  }
  return 0;
}
