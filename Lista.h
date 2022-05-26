#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H


#include "Nodo.h"

template <class Objeto>
class Lista {
    // Atributos
private:
    Nodo<Objeto> * primero;
    int cantidad;
    //Nodo<Escritor> * cursor;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista();

    /*Alta al final de la lista
    PRE: Recibe un dato
    Post: Agrega el dato al final de la lista*/
    void alta(Objeto e);

    /*
    Alta
    PRE: e es un Escritor valido y 1 <= pos <= obtener_cantidad() + 1
    POS: agrega el elemento en la posicion pos (se empieza por 1)
    */
    void alta(Objeto e, int pos);

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    void baja(int pos);

    //Pre: Recibe un dato
    //Post: Modifica el dato actual del nodo por el nuevo
    void cambiar_dato(Objeto d, int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    Objeto consulta(int pos);

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

    Nodo<Objeto> * obtener_nodo(int pos);
};

//DEFINICION DE METODOS

// Constructor
template <typename Objeto>
Lista<Objeto>::Lista() {
    primero = 0;
    cantidad = 0;
}

//Pregunta si esta vacia
template <typename Objeto>
bool Lista<Objeto>::vacia() {
    return (cantidad == 0);
}

//Pregunta la cantidad de nodos(Espacio)
template <typename Objeto>
int Lista<Objeto>::obtener_cantidad() {
    return cantidad;
}

//Destructor
template <typename Objeto>
Lista<Objeto>::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

// Consulta
template <typename Objeto>
Objeto Lista<Objeto>::consulta(int pos) {
    Nodo<Objeto>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

//Alta al final
template <typename Objeto>
void Lista<Objeto>::alta(Objeto e) {
    Nodo<Objeto>* nuevo = new Nodo<Objeto>(e);
    if (cantidad == 0) {
        primero = nuevo;
    }
    else {
        Nodo<Objeto>* ultimo = obtener_nodo(cantidad);
        ultimo->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

// alta
template <typename Objeto>
void Lista<Objeto>::alta(Objeto e, int pos) {
    Nodo<Objeto>* nuevo = new Nodo<Objeto>(e);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo<Objeto>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

// baja
template <typename Objeto>
void Lista<Objeto>::baja(int pos) {
    Nodo<Objeto> * borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Objeto>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

//Cambia el valor actual

template <typename Objeto >
void Lista<Objeto>::cambiar_dato(Objeto d, int pos){
    obtener_nodo(pos)->cambiar_dato(d);
}

// obtener_nodo
template <typename Objeto>
Nodo<Objeto>* Lista<Objeto>::obtener_nodo(int pos) {
    Nodo<Objeto>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

#endif //LISTA_LISTA_H
