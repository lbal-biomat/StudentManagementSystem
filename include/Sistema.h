//
// Created by lucia on 27/3/22.
//

//TODO: implementar un mencanismo de persistencia de datos
//TODO: implementar tabla hash para buscar estudiantes y cursos
//TODO: implementar sistema de login que permita al estudiante inscribirse/desinscribirse, consultar sus incripciones y obtener su escolaridad

#ifndef SISTEMABEDELIA_SISTEMA_H
#define SISTEMABEDELIA_SISTEMA_H

#include "TEstudiante.h"
#include "TCurso.h"
#include "TSalon.h"

#include <vector>
#include <string>

using std::vector;

class Sistema {
  private:
    vector<TEstudiante> estudiantes;
    vector<TCurso> cursos;
    vector<TSalon> salones;
    TEstudiante* getPunteroEstudiante(int CI);
    TCurso* getPunteroCurso(int cod);
    TSalon* getPunteroSalon(int cod);
  public:
    void registrarEstudiante(int documento, string nombre);
    void agregarSalon(int codigo, int capacidad);
    void agregarCurso(int codigo, int creditos, string nombre);
    void inscribirEstudianteACurso(int documento, int codigo);
    void borrarEstudianteDeCurso(int documento, int codigo);
    void agregarReservaSalon(int codSalon, int codCurso, int horaIni, int horaFin, TFecha fini, TFecha ffin,
                             vector<DiaSemana> dias);
    vector<TCurso*> consultarPrevias(int codCurso);
    vector<TReservaSalon> consultarReservas(int codSalon);
    vector<TCurso> obtenerCursos();
    vector<TEstudiante> obtenerEstudiantes();

};


#endif //SISTEMABEDELIA_SISTEMA_H
