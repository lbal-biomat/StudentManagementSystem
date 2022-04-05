//
// Created by lucia on 4/4/22.
//

#ifndef SISTEMABEDELIA_MENU_H
#define SISTEMABEDELIA_MENU_H

#include <map>
#include <functional>


class Menu {

  public :
    std::map<int, std::pair<std::string, std::function<void()>>> options;
    int input;
};

std::ostream &operator<<(std::ostream &os, const Menu &m);
std::istream &operator>>(std::istream &is, Menu &m);

#endif //SISTEMABEDELIA_MENU_H
