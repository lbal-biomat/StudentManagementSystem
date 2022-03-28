//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TFECHA_H
#define SISTEMABEDELIA_TFECHA_H

#include <iostream>


class TFecha {
  private:
    int dia, mes, anio;

  public:

    TFecha(int dia, int mes, int anio);

    //getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    bool operator>(TFecha f) const;
    bool operator<(TFecha f) const;
    bool operator==(TFecha) const; //compara dos fechas, true si son iguales, false en otro caso
};

std::ostream& operator<<(std::ostream& os, TFecha& f);

#endif //SISTEMABEDELIA_TFECHA_H
