
#ifndef LECTURAS_LECTURA_H
#define LECTURAS_LECTURA_H

#include <iostream>
#include <string>
#include "Escritor.h"
#include "Genero.h"
using namespace std;

class Lectura {
protected:
    char tipo_de_objeto;
    string titulo;
    int tiempo_lectura;
    int anio;
    Escritor * autor;
    bool leido;
public:
    Lectura ( char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor );
    virtual ~Lectura();
    virtual void mostrar () = 0;
    bool get_leido ();
    void set_leido ( bool leido );
    string get_titulo();
    int get_tiempo_lectura();
    int get_anio();
    void mostar_filtrado_por_escritor(Escritor * referencia_a_escritor);
    virtual void mostrar_filtrado_por_genero(Generos genero_a_filtrar);
    //Escritor* get_autor();


};


#endif //LECTURAS_LECTURA_H
