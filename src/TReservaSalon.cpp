//
// Created by lucia on 27/3/22.
//

#include "../include/TReservaSalon.h"

#include <utility>


TCurso *TReservaSalon::getCurso() {
  return curso;
}

int TReservaSalon::getHoraInicio() const {
  return horaInicio;
}

int TReservaSalon::getHoraFin() const {
  return horaFin;
}

TFecha TReservaSalon::getFechaInicio() {
  return fechaInicio;
}

TFecha TReservaSalon::getFechaFin() {
  return fechaFin;
}

std::vector<DiaSemana> TReservaSalon::getDias() {
  return dias;
}

TReservaSalon::TReservaSalon(TCurso* c, int hi, int hf, TFecha fini, TFecha ffin, vector<DiaSemana> d) :
    curso(c), horaInicio(hi), horaFin(hf), fechaInicio(fini), fechaFin(ffin), dias(std::move(d)) {}


std::ostream& operator<<(std::ostream& os, TReservaSalon& r) {
  os << r.getCurso();
  TFecha fini = r.getFechaInicio();
  os << "Start date: " << fini;
  TFecha fend = r.getFechaInicio();
  os << "End date: " << fend;
  os << "Start time: " << r.getHoraInicio() << std::endl;
  os << "End time: " << r.getHoraFin() << std::endl;
  os << "Days of the week: ";
  vector<DiaSemana> vec = r.getDias();
  for (auto & i : vec) {
    switch(static_cast<int>(i))
    {
      case 0:
       os << "Sunday ";
        break;
      case 1:
        os << "Monday ";
        break;
      case 2:
        os << "Tuesday ";
        break;
      case 3:
        os << "Wednesday ";
        break;
      case 4:
        os << "Thursday ";
        break;
      case 5:
        os << "Friday ";
        break;
      case 6:
        os << "Saturday ";
        break;
    }
  }
  return os;
}
