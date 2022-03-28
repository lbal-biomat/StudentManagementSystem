//
// Created by lucia on 27/3/22.
//

#include "../include/TCurso.h"
#include "../include/TEstudiante.h"

#include <utility>

int TCurso::getCodigo() const {
  return codigo;
}

int TCurso::getCreditos() const {
  return creditos;
}

string TCurso::getNombre() {
  return nombre;
}

vector<TCurso *> TCurso::getPrevias() {
  return previas;
}

vector<TEstudiante *> TCurso::getInscriptos() {
  return inscriptos;
}

void TCurso::agregarEstudiante(TEstudiante *e) {
  inscriptos.push_back(e);
}

void TCurso::removerEstudiante(int CI) {
  for (int i = 0; i < inscriptos.size(); i++) {
      inscriptos.erase(inscriptos.begin() + i);
  }
}

void TCurso::removerNoHabilitados() {
  for (int i = 0; i < inscriptos.size(); i++) //recorro estudiantes inscriptos
    for (auto & previa : previas) //recorro previas del curso
      if (!inscriptos.at(i)->estaInscripto(previa->getCodigo()))  //si no esta inscripto
        inscriptos.erase(inscriptos.begin() + i); //borro estudiante
}

TCurso::TCurso(int cod, int cred, string nom, vector<TCurso *> p) : codigo(cod), creditos(cred), nombre(std::move(nom)),
  previas(std::move(p)) {}

std::ostream& operator<<(std::ostream& os, TCurso& c) {
  os << "Nombre: " << c.getNombre() << std::endl;
  os << "Codigo: " << c.getCodigo() << std::endl;
  os << "Creditos: " << c.getCreditos() << std:: endl;
  return os;
}