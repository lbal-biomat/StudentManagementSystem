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
