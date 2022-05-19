#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H


#include "Nodo.h"

template <typename Dato>
class Lista {
    // Atributos
private:
    Nodo<Dato> * primero;
    int cantidad;
    //Nodo<Dato> * cursor;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista();


    /*
    Alta al final de la lista
    PRE: Recibe un dato
    Post: Agrega el dato al final de la lista
    */
    void alta(Dato e);

    /*
    Alta
    PRE: e es un Dato valido y 1 <= pos <= obtener_cantidad() + 1
    POS: agrega el elemento en la posicion pos (se empieza por 1)
    */
    void alta(Dato e, int pos);

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    void baja(int pos);

    //Pre: Recibe un dato
    //Post: Modifica el dato actual del nodo por el nuevo
    void cambiar_dato(Dato d, int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    Dato consulta(int pos);


    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();


    int obtener_cantidad();

    // Destructor
    ~Lista();

private:

    Nodo<Dato> * obtener_nodo(int pos);
};

#endif //LISTA_LISTA_H
