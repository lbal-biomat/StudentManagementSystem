//
// Created by lucia on 4/4/22.
//

#include "../include/Menu.h"
#include <iostream>
#include <iterator>


std::ostream &operator<<(std::ostream &os, const Menu &m) {
  os << "\nEnter an option: \n";
  for (auto const& x : m.options) {
    os << x.first << ':' << x.second.first << "\n";
  }
  os << "\n[+] Your option: ";
  return os;
}

std::istream &operator>>(std::istream &is, Menu &m) {
  m.input = *std::istream_iterator<int>{is};

  if(!m.options.contains(m.input)) {
    is.setstate(is.rdstate() | std::ios_base::failbit); //sets a failbit flag if the input value is not an option
  }

  return is;
}


