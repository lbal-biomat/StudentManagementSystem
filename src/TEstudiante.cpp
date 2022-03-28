//
// Created by lucia on 27/3/22.
//

#include "../include/TEstudiante.h"
#include "../include/TCurso.h"

#include <utility>
#include <iostream>


int TEstudiante::getCI() const {
  return CI;
}

string TEstudiante::getNombre() {
  return nombre;
}

vector<TAprobacion> TEstudiante::getAprobaciones() {
  return aprobaciones;
}

vector<TCurso *> TEstudiante::getInscripciones() {
  return inscripciones;
}

void TEstudiante::agregarInscripcion(TCurso* c) {
  inscripciones.push_back(c);
}

void TEstudiante::agregarAprobacion(TAprobacion a) {
  aprobaciones.push_back(a);
}


bool TEstudiante::estaInscripto(int codigoCurso) {
  for (auto & inscripcion : inscripciones) {
    if (inscripcion->getCodigo() == codigoCurso)
      return true;
  }
  return false;
}

int TEstudiante::getCreditos() {
  int creditos = 0;
  for (auto & aprobacione : aprobaciones) {
    creditos += aprobacione.getCurso()->getCreditos();
  }
  return creditos;
}

TEstudiante::TEstudiante(int doc, string nom) : CI(doc), nombre(std::move(nom)) {}

float TEstudiante::getPromedioCalificaciones() {
  int sum = 0;
  for (auto & aprobacione : aprobaciones) {
    sum += aprobacione.getCalificacion();
  }
  return static_cast<float>(sum)/aprobaciones.size(); //NOLINT //El cast a float es para que fevuelva float y no int
}

using namespace  std;

void TEstudiante::imprimirEscolaridad() {
  cout << this;
  cout << "Aprobaciones: " << endl;
  for (auto & aprob : getAprobaciones()) {
    cout << "\t" << aprob;
  }
  cout << "Promedio aprobaciones: " << getPromedioCalificaciones() << endl;
  cout << "Total créditos: " << getCreditos() << endl;
}

std::ostream& operator<<(std::ostream& os, TEstudiante& e) {
  os << "Nombre: " << e.getNombre() << endl;
  os << "Cedula de Identidad: " << e.getCI() << endl;
  return os;
}