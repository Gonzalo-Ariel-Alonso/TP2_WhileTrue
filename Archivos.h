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
  Archivos(Lista<Escritor *> * lista_de_escritores, Lista<Lectura *> * lista_de_lecturas, string escritor_txt, string lecturas_txt);
  ~Archivos();
  void crear_lista_escritores();
  void crear_lista_lecturas();
private:
  Escritor* escritor_por_referencia(string referencia);
  int comparar(int anio_lectura_actual);
  Generos de_string_a_enumerado(string genero_string);



};


#endif
