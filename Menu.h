#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "Archivos.h"
#include "Lista.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"
#include "Funciones_de_listas.h"
#include "Cola.h"

using namespace std;

class Menu {
private:

    Lista <Escritor * > lista_de_escritores;
    Lista <Lectura * > lista_de_lecturas;
    Cola <Lectura * > cola_ordenada;
    Funciones_de_listas * funciones;

public:

  //PRE: Recibe 2 strings
  //POST: carga las listas con la informacion de cada archivo
  Menu(string archivo_escritor_a_escritores, string archivo_lecturas);

  //PRE:
  //POST: Libera la memoria de lo almacenado
  ~Menu();

  //PRE: ---
  //POST:  Inicializacion de la interfaz
  void interfaz_usuario_con_ingreso();


private:

  //PRE:
  //POST: Imprime por pantalla el menu
  void mostrar_menu();

  //PRE: recibe una opcion de tipo entero
  //POST: Mediante un switch corre la opcion recibida
  void opciones_interfaz(int opcion);

  //PRE: El usuario inserta un valor
  //POST: Devuelve lo ingresado por el usuario
  int ingresar_opciones_interfaz();

  //PRE: Sirve en windows
  //POST: Valida todo tipo de entrada
  bool validar_entrada(int entrada,int parametro_minimo,int parametro_maximo);

  //PRE:  Listas cargadas
  //POST: Cola ordenada
  void cargar_cola_ordenada();

  //PRE: Cola ordenada creada
  //POST: El usuario recibe la lectura mas corta para leer
  void leer_una_lectura_cola();
};








#endif //MENU_H
