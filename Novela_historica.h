#ifndef LECTURAS_NOVELA_HISTORICA_H
#define LECTURAS_NOVELA_HISTORICA_H

#include <iostream>
#include <string>
using namespace std;
#include "Novela.h"

class Novela_historica: public Novela {
private:
    long unsigned int tamanio_char;
    char* tema;
public:

    //PRE: Recibe los datos a almacenar
    //POST: Almacena los datos
    Novela_historica(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , Generos genero, string tema_string);

    //PRE:
    //POST: Libera la memoria pedida durante el programa
    ~Novela_historica();

    //PRE:
    //POST:Imprime por pantalla los datos
    void mostrar()override;

};


#endif //LECTURAS_NOVELA_HISTORICA_H
