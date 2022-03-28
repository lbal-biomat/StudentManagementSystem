//
// Created by lucia on 27/3/22.
//

#include "../include/Sistema.h"

#include <exception>
#include <utility>


void Sistema::registrarEstudiante(int documento, string nombre) {
  for (auto &estudiante : estudiantes) {
    if (documento == estudiante.getCI())
      throw std::invalid_argument("Ya existe un estudiante con ese correo.");
  }
  TEstudiante nuevo_Est(documento, std::move(nombre));
  estudiantes.push_back(nuevo_Est);
}

void Sistema::agregarSalon(int codigo, int capacidad) {
  for (auto & salone : salones) {
    if (codigo == salone.getCodigo())
      throw std::invalid_argument("Ya existe un salon con ese codigo.");
  }
  TSalon nuevoSalon(codigo, capacidad);
  salones.push_back(nuevoSalon);
}

void Sistema::agregarCurso(int codigo, int creditos, string nombre, vector<TCurso *> previas) {
  for (auto & curso : cursos) {
    if (codigo == curso.getCodigo())
      throw std::invalid_argument("Ya existe un curso con ese codigo.");
  }
  TCurso nuevoCurso(codigo, creditos, std::move(nombre), std::move(previas));
  cursos.push_back(nuevoCurso);
}

void Sistema::inscribirEstudianteACurso(int documento, int codigo) {
  TEstudiante* est = getPunteroEstudiante(documento);
  TCurso* cur = getPunteroCurso(codigo);
  cur->agregarEstudiante(est);
}

void Sistema::borrarEstudianteDeCurso(int documento, int codigo) {
  TCurso* cur = getPunteroCurso(codigo);
  cur->removerEstudiante(documento);
}

void Sistema::agregarReservaSalon(int codS, int codC, int hi, int hf, TFecha fini, TFecha ffin, vector<DiaSemana> d) {
  TCurso* cur = getPunteroCurso(codC);
  TSalon* sal = getPunteroSalon(codS);
  TReservaSalon res(cur, hi, hf, fini, ffin, std::move(d));
  sal->agregarReserva(res);
}

vector<TCurso *> Sistema::consultarPrevias(int cod) {
  return getPunteroCurso(cod)->getPrevias();
}

vector<TReservaSalon> Sistema::consultarReservas(int cod) {
  return getPunteroSalon(cod)->getReservas();
}

TEstudiante *Sistema::getPunteroEstudiante(int CI) {
  for (auto & estudiante : estudiantes) {
    if (estudiante.getCI() == CI)
      return &estudiante;
  }
  return nullptr;
}

TCurso *Sistema::getPunteroCurso(int cod) {
  for (auto & curso : cursos) {
    if (curso.getCodigo() == cod)
      return &curso;
  }
  return nullptr;
}

TSalon *Sistema::getPunteroSalon(int cod) {
  for (auto & salon : salones) {
    if (salon.getCodigo() == cod)
      return &salon;
  }
  return nullptr;
}

vector<TCurso> Sistema::obtenerCursos() {
  return cursos;
}

vector<TEstudiante> Sistema::obtenerEstudiantes() {
  return estudiantes;
}
