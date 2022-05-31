#ifndef LECTURAS_NOVELA_H
#define LECTURAS_NOVELA_H


#include <iostream>
#include <string>
using namespace std;
#include "Lectura.h"
#include "Escritor.h"

using namespace std;

class Novela: public Lectura{
protected:
    string genero;
public:
    Novela(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , string genero);

    ~Novela()=default;
    virtual void mostrar();
};


#endif //LECTURAS_NOVELA_H
