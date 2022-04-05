//
// Created by lucia on 4/4/22.
//

#include "../include/Menu.h"
#include <iostream>
#include <iterator>


std::ostream &operator<<(std::ostream &os, const Menu &m) {
  os << "Enter an option: \n";
  for (auto const& x : m.options) {
    os << x.first << ':' << x.second.first << std::endl;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Menu &m) {
  m.input = *std::istream_iterator<int>{is};

  if(!m.options.contains(m.input)) {
    is.setstate(is.rdstate() & std::ios_base::failbit);
  }

  return is;
}


