
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

    //PRE: Recibe los datos a almacenar
    //POST: Almacena los datos
    Lectura ( char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor );
    //PRE:
    //POST:
    virtual ~Lectura();
    virtual void mostrar () = 0;

    //PRE: objeto creado
    //POST: Devuelve el estado de leido
    bool get_leido ();

    //PRE: recibe un estado de tipo bool
    //POST: Almacena el estado en leido
    void set_leido ( bool leido );

    //PRE:--
    //POST: Devuelve el titulo
    string get_titulo();

    //PRE:
    //POST:Devuelve el tiempo de lectura
    int get_tiempo_lectura();

    //PRE:
    //POST:Devuelve el año
    int get_anio();

    //PRE: Recibe un string para comparar con el que almacena el escritor
    //POST:Muestra los datos si es que el escritor tiene la referencia
    void mostar_filtrado_por_escritor(Escritor * referencia_a_escritor);

    //PRE:
    //POST:
    virtual void mostrar_filtrado_por_genero(Generos genero_a_filtrar);
    //Escritor* get_autor();


};


#endif //LECTURAS_LECTURA_H
