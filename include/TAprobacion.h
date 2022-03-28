//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TAPROBACION_H
#define SISTEMABEDELIA_TAPROBACION_H

#include "TFecha.h"

class TCurso;

class TAprobacion {
  private:
    TCurso* curso;
    int calificacion;
    TFecha fecha;
  public:
    TAprobacion(TCurso* curso, int nota, TFecha fecha);
    //getters
    TCurso* getCurso();
    [[nodiscard]] int getCalificacion() const;
    TFecha getFechaAprobacion();
};

std::ostream& operator<<(std::ostream& os, TAprobacion& h);

#endif//SISTEMABEDELIA_TAPROBACION_H
