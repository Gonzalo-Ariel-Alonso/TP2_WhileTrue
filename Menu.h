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

using namespace std;

class Menu {
private:

    Lista <Escritor * > lista_de_escritores;
    Lista <Lectura * > lista_de_lecturas;
    //programa_abierto = true;

public:
  Menu(string archivo_escritor_a_escritores, string archivo_lecturas);
  ~Menu();
  void mostrar_menu();
  void opciones_interfaz(int opcion);
  int ingresar_opciones_interfaz();
  bool validar_entrada(int entrada,int parametro_minimo,int parametro_maximo);
  void interfaz_usuario_con_ingreso();
  /*
  agregar_nueva_lectura();
  quitar_lectura();
  cambiar_dato_escritor(); */
  void listar_escritores();
  //sortear_lectura(tiempo para lecturas);
  void listar_lecturas();
  /*
  listar_lecturas(int ano_minimo, int ano_maximo);
  listar_lecturas(string escritor);
  listar_novelas_genero(string genero);
  */

};


Menu::Menu(string archivo_escritores, string archivo_lecturas){
  Archivos manejo_archivos(&lista_de_escritores, &lista_de_lecturas, archivo_escritores, archivo_lecturas);
  manejo_archivos.crear_lista_escritores();
  manejo_archivos.crear_lista_lecturas();
}

Menu::~Menu(){}

void Menu::opciones_interfaz(int opcion){
  switch (opcion){
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:
      listar_escritores();
      cout << endl;
      break;
    case 6:

      break;
    case 7:
      listar_lecturas();
      break;
    case 8:

      break;
    case 9:

      break;
    case 10:

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

void Menu::listar_escritores(){
    int cantidad_escritores = lista_de_escritores.obtener_cantidad();
    int pos = 1;
    for ( pos; pos <= cantidad_escritores; pos++){
            Escritor * aux = lista_de_escritores.consulta(pos);
            aux->mostrar_datos();
            cout << endl;
    }
}

void Menu::listar_lecturas(){
    int cantidad_lecturas = lista_de_lecturas.obtener_cantidad();
    int pos = 1;
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas.consulta(pos);
        _lectura->mostrar();
        cout << endl;
    }
}




#endif //MENU_H
