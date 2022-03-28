//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TSALON_H
#define SISTEMABEDELIA_TSALON_H

#include "TFecha.h"
#include "TReservaSalon.h"
#include <vector>

using std::vector;

class TSalon {
  private:
    int codigo;
    int capacidad;
    vector<TReservaSalon> reservas;

  public:
    TSalon(int cod, int cap);
    int getCodigo() const;
    int getCapacidad() const;
    bool disponible(TFecha f, int horaIni, int horaFin);
    void agregarReserva(const TReservaSalon&);
    vector<TReservaSalon> getReservas();
};


#endif //SISTEMABEDELIA_TSALON_H
