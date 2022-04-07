//
// Created by lucia on 6/4/22.
//

#include "../include/ClassroomsRepo.h"


ClassroomsRepo &ClassroomsRepo::GetInstance() {
  static ClassroomsRepo instance;
  return instance;
}