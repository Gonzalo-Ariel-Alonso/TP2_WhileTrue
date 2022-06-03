#ifndef LECTURAS_NOVELA_H
#define LECTURAS_NOVELA_H


#include <iostream>
#include <string>
using namespace std;
#include "Lectura.h"
#include "Escritor.h"
#include "Genero.h"

using namespace std;

class Novela: public Lectura{
protected:
    Generos genero;
public:
    Novela(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , Generos genero);
    ~Novela()=default;
    virtual void mostrar();
    string de_enumerado_a_string(Generos genero);
};


#endif //LECTURAS_NOVELA_H
