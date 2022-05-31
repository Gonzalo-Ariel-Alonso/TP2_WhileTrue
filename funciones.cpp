#include <iostream>
#include <fstream>
#include "funciones.h"
#include "Escritor.h"
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

void crear_lista_escritores(Lista<Escritor*>*  lista_de_escritores){
    ifstream escritores;
    escritores.open("escritores.txt");
    string referencia_escritor;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    int pos = 1;
    string vacio;
    while (!escritores.eof()){
        getline(escritores,referencia_escritor);
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
        Escritor* aux = new Escritor(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
        lista_de_escritores->alta(aux,pos);
        pos++;

        anio_fallecimiento = "";
        anio_nacimiento = "";

    }

    escritores.close();
}

void listar_escritores(Lista<Escritor *> * lista_escritores){
    int cantidad_escritores = lista_escritores->obtener_cantidad();
    int pos = 1;
    for ( pos; pos <= cantidad_escritores; pos++){
            Escritor * aux = lista_escritores->consulta(pos);
            aux->mostrar_datos();
    }
}

void agregar_escritor(Lista<Escritor *> * Lista_de_escritores){
    int ultima_posicion = Lista_de_escritores->obtener_cantidad() + 1;
    string referencia_escritor = "("+to_string(ultima_posicion)+")";
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;
    cout << "Ingrese el nombre y apellido del escritor que quiere agregar" << endl;
    getline(cin>>ws,nombre);
    cout << "Nacionalidad" << endl;
    getline(cin,nacionalidad);
    cout << "Anio de nacimiento, escriba 0 si es desconocido" << endl;
    cin >> anio_nacimiento;
    cout << "Anio de fallecimiento, escriba 0 si es desconocido" << endl;
    cin >> anio_fallecimiento;


    Escritor* escritor_nuevo = new Escritor(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
    Lista_de_escritores->alta(escritor_nuevo,ultima_posicion);

    cout << "Usted agrego el escritor: " << endl;
    Escritor * aux = Lista_de_escritores->consulta(ultima_posicion);
    aux->mostrar_datos();
}

void mostrar_nombre_y_fallecimiento_escritor(Lista<Escritor *> * lista_de_escritores){
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    for (int pos = 1 ; pos <= cantidad_escritores; pos++){
        Escritor * aux = lista_de_escritores->consulta(pos);
        cout << pos << " - ";
        aux->mostrar_nombre_y_fallecimiento();
    }
}

void modificar_anio_fallecimiento_escritor(Lista<Escritor *> * lista_de_escritores){
    int pos_escritor;
    string fecha_fallecimiento_nueva;
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    cout << "Digite el numero del escritor que desea cambiarle la fecha de fallecimiento o precione 0 para volver al menu" << endl;
    cin >> pos_escritor;
    if(pos_escritor <= cantidad_escritores && pos_escritor != 0){
        cout << "Digite fecha de fallecimiento del escritor" << endl;
        cin >> fecha_fallecimiento_nueva;
        Escritor * aux = lista_de_escritores->consulta(pos_escritor);
        aux->modificar_anio_fallecimiento(fecha_fallecimiento_nueva);
        lista_de_escritores->cambiar_dato(aux,pos_escritor);
        system("cls");
        cout << "Fecha de fallecimiento modificada con exito"<< endl;
    }
    else if (pos_escritor > cantidad_escritores && pos_escritor != 0 ){
        cout << "Escritor inexistente" << endl;
    }
}

 void listar_lecturas(Lista<Escritor *> * lista_de_escritores){

 }
