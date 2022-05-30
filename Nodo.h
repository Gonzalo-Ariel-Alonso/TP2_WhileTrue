#ifndef NODO_NODO_H
#define NODO_NODO_H


#include "Poema.h"
#include "Cuento.h"
#include "Novela.h"
#include "Novela_historica.h"

using namespace std;

template <typename Dato>
class Nodo {
    // Atributos
private:
    char tipo_de_objeto;
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

    //PRE: Recibe un objeto de tipo Dato, un caracter que indica el tipo de objeto a almacenar, y un dato extra que
    // es el dato que guarda el objeto
    //POST: Crea el objeto y lo guarda en el nodo
    Nodo(string titulo, float tiempo_lectura, int anio, Escritor * autor, char tipo_de_objeto, string dato_hijo);

    //PRE: Recibe un objeto de tipo dato, el caracter que indica el tipo de objeto a almacenar y tiene los 2 datos que
    // va a almacenar el objeto
    //POST: Crea el objeto y lo guarda en el nodo
    Nodo(string titulo, float tiempo_lectura, int anio, Escritor * autor, char tipo_de_objeto, string dato_hijo, char* tema);

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

    //Pre:-
    //Post: Devuelve tipo_de_objeto;
    char obtener_tipo_de_objeto();

};


// Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    tipo_de_objeto = 'E';
    siguiente = 0;
}

template <typename Dato>
Nodo<Dato>::Nodo(string titulo, float tiempo_lectura, int anio, Escritor * autor, char tipo_de_objeto, string dato_hijo){

    this->tipo_de_objeto = tipo_de_objeto;

    if (tipo_de_objeto == 'P'){
        dato = new Poema(titulo, tiempo_lectura, anio, autor, stoi(dato_hijo));
    }
    else if( tipo_de_objeto == 'C'){
        dato = new Cuento(titulo, tiempo_lectura, anio, autor, dato_hijo);
    }
    else if( tipo_de_objeto == 'N' ) {
        dato = new Novela(titulo, tiempo_lectura, anio, autor, dato_hijo);
    }
}

template <typename Dato>
Nodo<Dato>::Nodo(string titulo, float tiempo_lectura, int anio, Escritor * autor, char tipo_de_objeto, string dato_hijo, char* tema){
    this->tipo_de_objeto = tipo_de_objeto;
    dato = new Novela_historica(titulo, tiempo_lectura, anio, autor, dato_hijo, tema);
}

//Destructor
template < typename Dato >
Nodo<Dato>::~Nodo() {
    siguiente = 0;
    delete dato;
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

//obtener dato

template < typename Dato >
char Nodo<Dato>::obtener_tipo_de_objeto(){
    return tipo_de_objeto;
}



#endif //NODO_NODO_H
