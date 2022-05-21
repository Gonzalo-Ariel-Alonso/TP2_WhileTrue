#include <iostream>
#include <fstream>
#include "funciones.h"

using namespace std;

void mostrar_menu(){
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

Lista crear_lista_escritores(){
    ifstream escritores;
    escritores.open("escritores.txt");
    Lista lista_escritores;
    string _referencia;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    int pos = 1;
    string vacio;
    while (!escritores.eof()){
        getline(escritores,_referencia);
        getline(escritores,nombre);
        getline(escritores,nacionalidad);
        getline(escritores,anio_nacimiento);
        if (anio_nacimiento != ""){
            getline(escritores,anio_fallecimiento);
        }
        if (anio_fallecimiento != ""){
            getline(escritores,vacio);
        }
        //crear objeto escritor
        Escritor *ref = new Escritor(nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
        lista_escritores.alta(ref,pos);
        pos++;

        anio_fallecimiento = "";
        anio_nacimiento = "";

    }

    escritores.close();
    return lista_escritores;
}

void listar_escritores(Lista lista_escritores){
    int cantidad_escritores = lista_escritores.obtener_cantidad();
    int pos = 1;
    for ( pos; pos <= cantidad_escritores; pos++){
            Escritor* aux = lista_escritores.consulta(pos);
            aux->mostrar_datos();
    }
}