#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "Nodo.h"


template <typename Dato>
class Cola {
    // Atributos
private:
    Nodo<Dato>* primero;
    Nodo<Dato>* ultimo;
    int tam ;
    // Metodos
public:
    /*
    Constructor
    PRE: dato tiene que ser de tipo puntero o dinamico;
    POS: construye una Cola vacia
    */
    Cola();

    /*
    Alta
    PRE: e es un Dato valido
    POS: agrega el elemento al final de la Cola
    */
    void alta(Dato e);

    /*
    Baja
    PRE: la Cola no puede estar vacia
    POS: quita el elemento del principio de la Cola
    */
    void baja();

    /*
    Consulta
    PRE: la Cola no puede estar vacia
    POS: devuelve el elemento del principio de la Cola (pero no modifica)
    */
    Dato consulta();


    /*
    Vacia
    PRE: -
    POS: devuelve true si la Cola esta vacia, false de lo contrario
    */
    bool vacia();


    //PRE: Cola cargada
    //POST: Ordena la cola
    void cola_sort();

    // Destructor
    ~Cola();
};


// Constructor
template <typename Dato>
Cola<Dato>::Cola() {
    primero = 0;
    ultimo = 0;
    tam = 0;
}

// alta
template <typename Dato>
void Cola<Dato>::alta(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (primero)
        ultimo->cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
    tam ++;
}


// baja
template <typename Dato>
void Cola<Dato>::baja() {
    Nodo<Dato>* borrar = primero;
    primero = primero->obtener_siguiente();
    if (! primero)
        ultimo = 0;
    borrar->cambiar_dato(0); // Cambia el puntero a null asi no se borra con
                            // el delete en el destructor en la lista tambien
    delete borrar;
    tam --;
}

// consulta
template <typename Dato>
Dato Cola<Dato>::consulta() {
    return primero->obtener_dato();
}


// vacia
template <typename Dato>
bool Cola<Dato>::vacia() {
    return (ultimo == 0);
}


template <typename Dato>
void Cola<Dato>::cola_sort(){
  Nodo<Dato> * pAct = primero; //puntero Actual
  while(pAct != NULL){
      Nodo<Dato> * pSig = pAct->obtener_siguiente(); //puntero siguiente
      while(pSig != NULL){
          Dato datoAct = pAct->obtener_dato();
          Dato datoSig = pSig->obtener_dato();
          if (datoAct->get_tiempo_lectura() > datoSig->get_tiempo_lectura()){
              pSig->cambiar_dato(datoAct);
              pAct->cambiar_dato(datoSig);
          }
          pSig = pSig->obtener_siguiente();
      }
      pAct = pAct->obtener_siguiente();
  }

}



//Destructor
template <typename Dato>
Cola<Dato>::~Cola() {
    while (! vacia())
        baja();
}



#endif // COLA_H_INCLUDED
