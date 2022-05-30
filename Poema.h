#ifndef LECTURAS_POEMA_H
#define LECTURAS_POEMA_H


#include "Lectura.h"

class Poema: public Lectura {
private:
    int versos;
public:
    Poema (string titulo, float tiempo_lectura, int anio , Escritor * autor , int versos);
    ~Poema()=default;
    void mostrar()override;
};


#endif //LECTURAS_POEMA_H
