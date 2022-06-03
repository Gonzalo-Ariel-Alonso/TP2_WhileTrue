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

using namespace std;

class Menu {
private:

    Lista <Escritor * > lista_de_escritores;
    Lista <Lectura * > lista_de_lecturas;
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
};


Menu::Menu(string archivo_escritores, string archivo_lecturas){
  Archivos manejo_archivos(&lista_de_escritores, &lista_de_lecturas, archivo_escritores, archivo_lecturas);
  manejo_archivos.crear_lista_escritores();
  manejo_archivos.crear_lista_lecturas();
  funciones = new Funciones_de_listas(&lista_de_escritores, &lista_de_lecturas);
}

Menu::~Menu(){
  delete funciones;
}

void Menu::opciones_interfaz(int opcion){
  switch (opcion){
    case 1:
      funciones->agregar_lectura();
      break;
    case 2:
      funciones->quitar_lectura();
      break;
    case 3:
      funciones->agregar_escritor();
      break;
    case 4:
      funciones->modificar_ano_fallecimiento_escritor();
      break;
    case 5:
      funciones->listar_escritores();
      cout << endl;
      break;
    case 6:
      funciones->sortear_lectura();
      break;
    case 7:
      funciones->listar_lecturas();
      break;
    case 8:
      funciones->listar_lectura_filtrada_por_ano();
      break;
    case 9:
      funciones->listar_lecturas_filtrado_por_escritor();
      break;
    case 10:
      funciones->listar_lecturas_filtradas_por_genero();

      break;
    case 11://COLA

      break;
    case 12:

      break;

    default:
      cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
      validar_entrada(opcion,1,12);
      break;
  }
}



void Menu::mostrar_menu(){
    cout << "Bienvenido! Elija una opcion: " << endl;
    cout << "1 - Agregar una nueva lectura a la lista" << endl;
    cout << "2 - Quitar una lectura de la lista" << endl;
    cout << "3 - Agregar un escritor" << endl;
    cout << "4 - Cambiar dato de un escritor (solo fecha de fallecimiento)" << endl;
    cout << "5 - Listar los escritores" << endl;
    cout << "6 - Sortear una lectura random para leer en una de las tertulias" << endl;
    cout << "7 - Listar todas las lecturas" << endl;
    cout << "8 - Listar las lecturas entre determinados años. " << endl;
    cout << "9 - Listar las lecturas de un determinado escritor que ingresa el usuario." << endl;
    cout << "10 - Listar las novelas de determinado género." << endl;
    cout << "11 - Armar una cola" << endl;
    cout << "12 - Salir" << endl;
}

int Menu::ingresar_opciones_interfaz(){
  int opcion = 15;
  cin >> opcion ;
  return opcion;
}

bool Menu::validar_entrada(int entrada,int parametro_minimo,int parametro_maximo){
    bool continuar = true;
    if (parametro_minimo > entrada || entrada > parametro_maximo || cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.sync();
        continuar = false;
        }
    return continuar;
}


void Menu::interfaz_usuario_con_ingreso(){
  int selector;
  while (selector != 12){
    mostrar_menu();
    selector = ingresar_opciones_interfaz();
    opciones_interfaz(selector);
  }

}






#endif //MENU_H
