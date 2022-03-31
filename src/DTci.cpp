//
// Created by lucia on 31/3/22.
//

#include "../include/DTci.h"
#include <string>
#include <stdexcept>
using std::string;


int DTci::getCInumber() const {
  return ci;
}

bool DTci::validate(const std::string &ci) {

    bool valid = true;
    for (char const& c : ci) {
      if (!isdigit(c)) valid = false;
    }
    int numericCI = stoi(ci);
    if (1111111 > numericCI || 99999999 < numericCI)
      valid = false;
    if (!valid) {
      throw std::invalid_argument("Entrada invalida");
    }
    const char valChar = ci[ci.size()-1];
    int valDig = valChar - '0';

    string baseNumber = "8123476";
    if (ci.size() == 7) {
      baseNumber = "123476";
    }
    int sum = 0;

    for (int i = 0; i < ci.size() - 1; i++) {
      int n = ci[i] - '0';
      int base = baseNumber[i] - '0';
      sum += n*base;
    }

    int res = sum % 10;
    return res == valDig;

}

bool DTci::operator==(DTci id) const {
  return ci == id.getCInumber();
}

DTci::DTci(int num) {
  ci = num;
}

bool DTci::operator==(int num) const {
  return ci == num;
}
