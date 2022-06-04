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

  Funciones_de_listas(Lista< Escritor* > * lista_escritores, Lista< Lectura * > * lista_lecturas);
  ~Funciones_de_listas();
  void listar_lecturas();//5
  void listar_escritores();//7
  void agregar_escritor();//3
  void agregar_lectura();//1
  void quitar_lectura();//2
  void modificar_ano_fallecimiento_escritor();//4
  void sortear_lectura();//6
  void listar_lectura_filtrada_por_ano();//8
  void listar_lecturas_filtrado_por_escritor();//9
  void listar_lecturas_filtradas_por_genero();//10

private:
  void ingresos_usuario(string* ref_lectura, string* titulo, int* duracion, int* ano );
  void catalogo_escritores();
  Escritor* ingreso_autor();
  int comparar(int anio_lectura_actual);
  Generos de_string_a_enumerado(string genero_string);
  void catalogo_lecturas();
  void mostrar_nombre_y_fallecimiento_escritor();

};



/*









*/


#endif //FUNCIONES_DE_LISTAS_H
