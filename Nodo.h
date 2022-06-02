#ifndef NODO_NODO_H
#define NODO_NODO_H



#include <string>

template <typename Dato>
class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo<Dato>* siguiente;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye un Nodo con dato "d" y siguiente nullptr
    */
    Nodo(Dato d);

    //Destructor
    ~Nodo();

    //Pre: Recibe una direccion de memoria a un nodo
    //Post: Modifica la direccion del proximo nodo
    void cambiar_siguiente(Nodo<Dato>* n);

    //Pre:-
    //Post: Devuelve el dato
    Dato obtener_dato();

    //Pre: Recibe un dato
    //Post: Modifica lo que almacena d con lo recibido
    void cambiar_dato(Dato d);

    //Pre: -
    //Post: Devuelve la direccion del proximo nodo
    Nodo<Dato>* obtener_siguiente();

};

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
    //delete dato; // BORRA EL DATO
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


#endif //NODO_NODO_H
