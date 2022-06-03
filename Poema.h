#ifndef LECTURAS_POEMA_H
#define LECTURAS_POEMA_H
#include <iostream>
#include <string>
using namespace std;

#include "Lectura.h"
#include "Escritor.h"
class Poema: public Lectura {
private:
    int versos;
public:
    Poema (char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , int versos);
    ~Poema()=default;
    void mostrar()override;
};


#endif //LECTURAS_POEMA_H
