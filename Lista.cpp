#include "lista.h"

// Constructor
Lista::Lista() {
    primero = 0;
    cantidad = 0;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

int Lista::obtener_cantidad() {
    return cantidad;
}

Lista::~Lista() {
    while (! vacia())
        baja(1);
}
// Consulta
Dato Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}


// alta
void Lista::alta(Dato e, int pos) {
    Nodo* nuevo = new Nodo(e);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}


// baja
void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

// obtener_nodo
Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}