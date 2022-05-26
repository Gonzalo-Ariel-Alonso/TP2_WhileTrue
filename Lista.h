#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

class Lista {
    // Atributos
private:
    Nodo* primero;
    int cantidad;
    Nodo* cursor;

    // Metodos
public:
    /* Constructor
    PRE: -
    POS: construye una Lista vacia */
    Lista();

    /* Alta
    PRE: e es un Dato valido y 1 <= pos <= obtener_cantidad() + 1
    POS: agrega el elemento en la posicion pos (se empieza por 1) */

    void alta(Dato e, int pos);
    /* Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1 */

    void baja(int pos);
    /* Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1 */

    Dato consulta(int pos);
    /*Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario */
    
    bool vacia();

    int obtener_cantidad();

    // Destructor
    ~Lista();

private:

    Nodo* obtener_nodo(int pos);
};

#endif // LISTA_H_INCLUDED