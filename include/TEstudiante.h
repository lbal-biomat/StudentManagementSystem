//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TESTUDIANTE_H
#define SISTEMABEDELIA_TESTUDIANTE_H

#include "TAprobacion.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class TEstudiante {
  private:
    int CI; //los estudiantes se identifican por su CI
    string nombre;
    vector<TAprobacion> aprobaciones;
    vector<TCurso*> inscripciones;
  public:
    TEstudiante(int doc, string nom);
    int getCI() const;
    string getNombre();
    vector<TAprobacion> getAprobaciones();
    int getCreditos();
    float getPromedioCalificaciones();
    vector<TCurso*> getInscripciones();
    void agregarInscripcion(TCurso* c);
    void agregarAprobacion(TAprobacion a);
    bool estaInscripto(int codigoCurso);
    void imprimirEscolaridad();
};

std::ostream& operator<<(std::ostream& os, TEstudiante& h);

#endif//SISTEMABEDELIA_TESTUDIANTE_H
