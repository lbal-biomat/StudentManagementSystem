//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TRESERVASALON_H
#define SISTEMABEDELIA_TRESERVASALON_H

#include "TFecha.h"
#include "DiaSemana.h"

#include <vector>
#include <chrono>

using std::vector;

class TSalon;
class TCurso;

class TReservaSalon {
  private:
    TCurso* curso;
    int horaInicio;
    int horaFin;
    TFecha fechaInicio;
    TFecha fechaFin;
    vector<DiaSemana> dias;
  public:
    TReservaSalon(TCurso*, int horaIni, int horaFin, TFecha fini, TFecha ffin, vector<DiaSemana> dias);
    TCurso* getCurso();
    int getHoraInicio() const;
    int getHoraFin() const;
    TFecha getFechaInicio();
    TFecha getFechaFin();
    std::vector<DiaSemana> getDias();
};


#endif //SISTEMABEDELIA_TRESERVASALON_H
