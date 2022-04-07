//
// Created by lucia on 6/4/22.
//

#include "../include/CoursesRepo.h"

CoursesRepo &CoursesRepo::GetInstance() {
  static CoursesRepo instance;
  return instance;
}
