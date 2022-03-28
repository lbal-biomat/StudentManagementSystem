//
// Created by lucia on 27/3/22.
//

#ifndef SISTEMABEDELIA_TCURSO_H
#define SISTEMABEDELIA_TCURSO_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class TEstudiante;

class TCurso {
  private:
    int codigo;
    int creditos;
    string nombre;
    vector<TCurso*> previas;
    vector<TEstudiante*> inscriptos;
  public:
    TCurso(int cod, int cred, string nom, vector<TCurso*> previas);
    int getCodigo() const;
    int getCreditos() const;
    string getNombre();
    vector<TCurso*> getPrevias();
    vector<TEstudiante*> getInscriptos();
    void agregarEstudiante(TEstudiante*);
    void removerEstudiante(int CI);
    void removerNoHabilitados();
};

std::ostream& operator<<(std::ostream& os, TCurso& c);

#endif //SISTEMABEDELIA_TCURSO_H
