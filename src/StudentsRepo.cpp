//
// Created by lucia on 6/4/22.
//

#include "../include/StudentsRepo.h"

StudentsRepo &StudentsRepo::GetInstance() {
  static StudentsRepo instance;
  return instance;
}
