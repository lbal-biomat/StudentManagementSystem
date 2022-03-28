//
// Created by lucia on 27/3/22.
//

#include "../include/TSalon.h"
#include "../include/DiaSemana.h"

#include <boost/date_time.hpp>

TSalon::TSalon(int cod, int cap) : codigo (cod), capacidad (cap) {}

int TSalon::getCodigo() const {
  return codigo;
}

int TSalon::getCapacidad() const {
  return capacidad;
}

//funcion auxiliar que devuelve dia de la semana de una fecha
DiaSemana getDiaSemana(TFecha f) {
  boost::gregorian::date d(f.getAnio(), f.getMes(), f.getDia());
  int dia = d.day_of_week();
  return static_cast<DiaSemana>(dia);
}

bool TSalon::disponible(TFecha f, int horaIni, int horaFin) {
  DiaSemana dia = getDiaSemana(f);
  for (auto res : reservas) {
    if ((f > res.getFechaInicio()) && (f < res.getFechaFin()))
      for (int j = 0; j < res.getDias().size(); ++j)
        if (res.getDias().at(j) == dia) //f coincide con el dia de la semana de la reserva
          if (!((horaIni <= res.getHoraFin()) && (res.getHoraInicio() <= horaFin))) //las horas se solapan
            return false; //no esta disponible
  }
  return true;
}

void TSalon::agregarReserva(const TReservaSalon& res) {
  reservas.push_back(res);
}

vector<TReservaSalon> TSalon::getReservas() {
  return reservas;
}
