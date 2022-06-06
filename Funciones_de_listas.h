#ifndef FUNCIONES_DE_LISTAS_H
#define FUNCIONES_DE_LISTAS_H

#include <iostream>
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

class Funciones_de_listas{
private:
  Lista<Escritor *> * lista_de_escritores;
  Lista<Lectura *> * lista_de_lecturas;
public:
  //PRE: Recibe 2 listas sobre las cuales trabajar
  //POST: Almacena las 2 direcciones de memoria
  Funciones_de_listas(Lista< Escritor* > * lista_escritores, Lista< Lectura * > * lista_lecturas);

  //PRE:
  //POST:Las listas apuntan a nullptr
  ~Funciones_de_listas();

  //PRE: lista  lectura creada
  //POST: imprime por pantalla los datos de la lista lecturas
  void listar_lecturas();//5

  //PRE: lista escritores creada
  //POST:imprime por pantalla los datos de la lista lecturas
  void listar_escritores();//7

  //PRE:Usuario interfaz
  //POST: Agrega un escritor a la lista de escritores
  void agregar_escritor();//3

  //PRE: Usuario interfaz
  //POST: Agrega un escritor a la lista de escritores
  void agregar_lectura();//1

  //PRE: Usuario interfaz
  //POST:Quita una lectura de la lista
  void quitar_lectura();//2

  //PRE:
  //POST: Modifica el año de fallecimiento de un escritor en la lista
  void modificar_ano_fallecimiento_escritor();//4

  //PRE: lista de lecturas creada
  //POST: Sortea una lectura a leer e imprime por pantalla cual
  void sortear_lectura();//6

  //PRE: El usuario ingresa un rango de años
  //POST: Imprime las lecturas con esos años de cotas
  void listar_lectura_filtrada_por_ano();//8

  //PRE: El usuario ingresa el escritor
  //POST: Imprime todas sus lecturas
  void listar_lecturas_filtrado_por_escritor();//9

  //PRE:El usuario elige un genero
  //POST: Imprime las novelas del genero elegido
  void listar_lecturas_filtradas_por_genero();//10

private:

  //PRE: Recibe las variables donde almacenar los datos
  //POST: El usuario ingresa datos de una lectura a agregar
  void ingresos_usuario(string* ref_lectura, string* titulo, int* duracion, int* ano );

  //PRE:----
  //POST: Imprime los datos importantes de escritores para visualizar
  void catalogo_escritores();

  //PRE: El usuario ingresa datos para un escritor
  //POST: Devuelve el Escritor creado
  Escritor* ingreso_autor();

  //PRE: recibe un entero para comparar en la lista lectura
  //POST:Devuelve la posicion donde debera ingresarse la lectura en la lista
  int comparar(int anio_lectura_actual);

  //PRE: recibe un string que representa el genero
  //POST: Devuelve el enumerado del genero
  Generos de_string_a_enumerado(string genero_string);

  //PRE:---
  //POST: Imprime por pantalla los datos de la lectura al usuario
  void catalogo_lecturas();

  //PRE:
  //POST: Imprime el nombre y el fallecimiento del escritor
  void mostrar_nombre_y_fallecimiento_escritor();

};



/*









*/


#endif //FUNCIONES_DE_LISTAS_H
