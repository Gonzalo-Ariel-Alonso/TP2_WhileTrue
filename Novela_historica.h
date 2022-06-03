#ifndef LECTURAS_NOVELA_HISTORICA_H
#define LECTURAS_NOVELA_HISTORICA_H

#include <iostream>
#include <string>
using namespace std;
#include "Novela.h"

class Novela_historica: public Novela {
private:
    char* tema;
public:
    Novela_historica(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , Generos genero, char* tema);

    ~Novela_historica()=default;
    void mostrar()override;

};


#endif //LECTURAS_NOVELA_HISTORICA_H
