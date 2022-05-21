#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Escritor.h"
#include <string>

typedef Escritor* Dato;

class Nodo {
    // Atributos
private:
    Dato objeto;
    Nodo* siguiente;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye un Nodo con d como dato anterior en nullptr
    */
    Nodo(Dato _objeto);

    void cambiar_siguiente(Nodo* n);

    Dato obtener_dato();

    Nodo* obtener_siguiente();

};

#endif // NODO_H_INCLUDED