#ifndef NODO_NODO_H
#define NODO_NODO_H



#include <string>

template <class Objeto>
class Nodo {
    // Atributos
private:
    Objeto dato;
    Nodo<Objeto> * siguiente;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye un Nodo con dato "d" y siguiente nullptr
    */
    Nodo(Objeto d);

    //Destructor
    ~Nodo();

    //Pre: Recibe una direccion de memoria a un nodo
    //Post: Modifica la direccion del proximo nodo
    void cambiar_siguiente(Nodo<Objeto>* n);

    //Pre:-
    //Post: Devuelve el dato
    Objeto obtener_dato();

    //Pre: Recibe un dato
    //Post: Modifica lo que almacena d con lo recibido
    void cambiar_dato(Objeto d);

    //Pre: -
    //Post: Devuelve la direccion del proximo nodo
    Nodo<Objeto>* obtener_siguiente();

};

// Constructor
template <typename Objeto>
Nodo<Objeto>::Nodo(Objeto d) {
    dato = d;
    siguiente = 0;
}
//Destructor
template < typename Objeto >
Nodo<Objeto>::~Nodo() {
    siguiente = 0;
    delete dato;
    delete siguiente;
}

// cambiar proximo nodo
template <typename Objeto>
void Nodo<Objeto>::cambiar_siguiente(Nodo<Objeto>* n) {
    siguiente = n;
}

// obtener dato
template <typename Objeto>
Objeto Nodo<Objeto>::obtener_dato() {
    return dato;
}

//Cambiar dato
template < typename Objeto >
void Nodo<Objeto>::cambiar_dato(Objeto d)
{
    dato = d;
}

// obtener anterior
template < typename Objeto >
Nodo<Objeto>* Nodo<Objeto>::obtener_siguiente() {
    return siguiente;
}

#endif //NODO_NODO_H
