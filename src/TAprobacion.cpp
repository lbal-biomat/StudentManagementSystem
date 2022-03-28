//
// Created by lucia on 27/3/22.
//

#include "../include/TAprobacion.h"
#include "../include/TCurso.h"
#include "../include/TFecha.h"

TAprobacion::TAprobacion(TCurso* c, int n, TFecha f) : curso(c), calificacion(n), fecha(f) {}

TCurso* TAprobacion::getCurso() {
  return curso;
}

TFecha TAprobacion::getFechaAprobacion() {
  return fecha;
}

int TAprobacion::getCalificacion() const {
  return calificacion;
}

using namespace  std;
std::ostream& operator<<(std::ostream& os, TAprobacion& apr) {
  TCurso* c = apr.getCurso();
  TFecha f = apr.getFechaAprobacion();
  os << "Curso: " << c->getNombre() << " - " << c->getCodigo() << " - Cred: " << c->getCreditos() << " - Nota: " << \
  apr.getCalificacion() << " - Fecha: " << f << endl;
  return os;
}