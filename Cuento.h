#ifndef LECTURAS_CUENTO_H
#define LECTURAS_CUENTO_H


#include "Lectura.h"

class Cuento : public Lectura {
private:
    string titulo_de_libro;
public:
    Cuento (string titulo, float tiempo_lectura, int anio , Escritor * autor , string titulo_de_libro);
    ~Cuento()=default;
    void mostrar() override;

};


#endif //LECTURAS_CUENTO_H
