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
  Menu(string archivo_escritor_a_escritores, string archivo_lecturas);
  ~Menu();
  void interfaz_usuario_con_ingreso();


private:
  void mostrar_menu();
  void opciones_interfaz(int opcion);
  int ingresar_opciones_interfaz();
  bool validar_entrada(int entrada,int parametro_minimo,int parametro_maximo);
  void cargar_cola_ordenada();
  void leer_una_lectura_cola();
};








#endif //MENU_H
