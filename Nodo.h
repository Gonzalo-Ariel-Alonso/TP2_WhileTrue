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

#endif //NODO_NODO_H
