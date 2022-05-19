#include "Lista.h"
// Constructor
template <typename Dato>
Lista<Dato>::Lista() {
    primero = 0;
    cantidad = 0;
}

//Pregunta si esta vacia
template <typename Dato>
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

//Pregunta la cantidad de nodos(Espacio)
template <typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}

//Destructor
template <typename Dato>
Lista<Dato>::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

// Consulta
template <typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

//Alta al final
template <typename Dato>
void Lista<Dato>::alta(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (cantidad == 0) {
        primero = nuevo;
    }
    else {
        Nodo<Dato>* ultimo = obtener_nodo(cantidad);
        ultimo->cambiar_siguiente(nuevo);
    }
    cantidad++;
}


// alta
template <typename Dato>
void Lista<Dato>::alta(Dato e, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}



// baja
template <typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato> * borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}


//Cambia el valor actual

template <typename Dato >
void Lista<Dato>::cambiar_dato(Dato d, int pos){
    obtener_nodo(pos)->cambiar_dato(d);
}



// obtener_nodo
template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}
