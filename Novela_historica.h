#ifndef LECTURAS_NOVELA_HISTORICA_H
#define LECTURAS_NOVELA_HISTORICA_H

#include <iostream>
#include <string>
using namespace std;
#include "Novela.h"

class Novela_historica: public Novela {
private:
    int tamanio_char;
    char* tema;
public:
    Novela_historica(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , Generos genero, string tema_string);

    ~Novela_historica();
    void mostrar()override;

};


#endif //LECTURAS_NOVELA_HISTORICA_H
