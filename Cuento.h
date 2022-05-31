#ifndef LECTURAS_CUENTO_H
#define LECTURAS_CUENTO_H

#include <iostream>
#include <string>
using namespace std;

#include "Lectura.h"
#include "Escritor.h"


class Cuento : public Lectura {
private:
    string titulo_de_libro;
public:
    Cuento (string titulo, int tiempo_lectura, int anio , Escritor * autor , string titulo_de_libro);
    ~Cuento()=default;
    void mostrar() override;

};


#endif //LECTURAS_CUENTO_H
