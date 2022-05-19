#include "Nodo.h"
// Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}
//Destructor
template < typename Dato >
Nodo<Dato>::~Nodo() {
    siguiente = 0;
    delete siguiente;
}

// cambiar proximo nodo
template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* n) {
    siguiente = n;
}

// obtener dato
template <typename Dato>
Dato Nodo<Dato>::obtener_dato() {
    return dato;
}

//Cambiar dato
template < typename Dato >
void Nodo<Dato>::cambiar_dato(Dato d)
{
    dato = d;
}

// obtener anterior
template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente() {
    return siguiente;
}
