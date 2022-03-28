//
// Created by lucia on 27/3/22.
//

#include "../include/TFecha.h"

TFecha::TFecha(int dia, int mes, int anio) {
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

int TFecha::getDia() const {
  return this->dia;
}

int TFecha::getMes() const {
  return this->mes;
}

int TFecha::getAnio() const {
  return this->anio;
}

bool TFecha::operator==(TFecha f) const {
  return (this->anio == f.anio &&
          this->mes == f.mes && this->dia == f.dia);
}

bool TFecha::operator<(TFecha f) const {
  int dias_param = f.dia + f.mes*30 + f.anio*360;
  int dias_this = this->dia + this->mes*30 + this->anio*360;
  int dif = dias_param - dias_this;
  if (dif > 0) {
    return true;
  }
  return false;
}

bool TFecha::operator>(TFecha f) const {
  int dias_param = f.dia + f.mes*30 + f.anio*360;
  int dias_this = this->dia + this->mes*30 + this->anio*360;
  int dif = dias_this - dias_param;
  if (dif > 0) {
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, TFecha& f)
{
  os << f.getAnio() << '/' << f.getMes() << '/' << f.getDia();
  return os;
}