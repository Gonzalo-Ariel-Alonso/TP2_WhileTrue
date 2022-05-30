

#ifndef LECTURAS_NOVELA_HISTORICA_H
#define LECTURAS_NOVELA_HISTORICA_H


#include "Novela.h"

class Novela_historica: public Novela {
private:
    char* tema;
public:
    Novela_historica(string titulo, float tiempo_lectura, int anio , Escritor * autor , string genero, char* tema);

    ~Novela_historica()=default;
    void mostrar()override;

};


#endif //LECTURAS_NOVELA_HISTORICA_H
