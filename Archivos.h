#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Lista.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"

using namespace std;

class Archivos{
private:
  Lista<Escritor *> * lista_de_escritores;
  Lista<Lectura *> * lista_de_lecturas;
  string escritores_txt, lecturas_txt;
public:
  //PRE: Recibe la direccion de memoria de la lista a llenar, y los nombres de los archivos
  //POST: Carga las listas con la informacion del archivo
  Archivos(Lista<Escritor *> * lista_de_escritores, Lista<Lectura *> * lista_de_lecturas, string escritor_txt, string lecturas_txt);

  //PRE:---
  //POST:Apunta a nullptr los punteros de listas
  ~Archivos();

  //PRE: Direcciones de memorias cargadas
  //POST: Carga lista de escritores
  void crear_lista_escritores();

  //PRE: Direcciones de memorias cargadas
  //POST: Carga lista de lecturas
  void crear_lista_lecturas();
private:

  //PRE:Recibe un string de referencia que esta almacenado en el TDA escritor
  //POST: Devuelve el escritor que almacena cierta referencia
  Escritor* escritor_por_referencia(string referencia);

  //PRE: recibe un entero y lo compara con los almacenados en cada lectura
  //POST: Devuelve la posicion para agregarlo en la lista de manera ordenada
  int comparar(int anio_lectura_actual);

  //PRE: Recibe un string
  //POST: Devuelve el genero enumerado
  Generos de_string_a_enumerado(string genero_string);



};


#endif
