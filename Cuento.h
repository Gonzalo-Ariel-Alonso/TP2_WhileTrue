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
  //PRE:Recibe los parametros para cargar el objeto padre e hijo
  //POST:Almacena los datos
    Cuento (char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , string titulo_de_libro);
    ~Cuento()=default;
    //PRE:----
    //POST:Imprime los datos por pantalla
    void mostrar() override;

};


#endif //LECTURAS_CUENTO_H
