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
  void opciones_interfaz(int opcion);
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
