//
// Created by lucia on 31/3/22.
//

#include "../include/DTid.h"
#include <string>
#include <stdexcept>
using std::string;


int DTid::getIDnumber() const {
  return ci;
}

bool DTid::validate(int numCI) {

    bool valid = true;
    if (1111111 > numCI || 99999999 < numCI)
      valid = false;
    if (!valid) {
      throw std::invalid_argument("Entrada invalida");
    }
    string ci = std::to_string(numCI);
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

bool DTid::operator==(DTid id) const {
  return ci == id.getIDnumber();
}

DTid::DTid(int id) {
  bool valid = validate(id);
  if (!valid) {
    throw std::invalid_argument("Invalid ID");
  }
  ci = id;
}

bool DTid::operator==(int num) const {
  return ci == num;
}
