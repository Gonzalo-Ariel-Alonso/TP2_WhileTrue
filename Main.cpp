#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"
#include "Lecturas_y_subtipos.h"
using namespace std;

void crear_lista_lecturas();

int main(){
    int selector = 0;
    Lista lista_de_escritores;
    crear_lista_escritores(&lista_de_escritores);

    while (selector != 12){
        mostrar_menu();
        cin >> selector;
        switch (selector){

        case 3:
            agregar_escritor(&lista_de_escritores);
            system("cls");
            cout << "Escritor agregado!" << endl;
            break;
        case 4:
            mostrar_nombre_y_fallecimiento_escritor(&lista_de_escritores);
            modificar_ano_fallecimiento_escritor(&lista_de_escritores);
            break;
        case 5:
            listar_escritores(&lista_de_escritores);
            system("pause");
            cout << endl;
            break;
        case 12:
            cout << "Adios!" << endl << endl;
            break;
        default:
            cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
            break;
        }
    }

    return 0;
}

void crear_lista_lecturas(){
    ifstream lecturas;
    char tipo_lectura;
    string titulo;
    string duracion_lectura;
    string ano_publicacion;
    string referencia_a_lectura; //dependiendo el tipo de lectura reprecentara algo diferente
    string referencia_a_autor;
    string vacio;
    int pos = 1; // posicion*
    while (!lecturas.eof()){
        getline(lecturas,tipo_lectura);
        getline(lecturas,titulo);
        getline(lecturas,duracion_lectura);
        getline(lecturas,ano_publicacion);
        getline(lecturas,referencia_a_lectura);
        getline(lecturas,referencia_a_autor);
        getline(lecturas,vacio);
        char asd = (char)tipo_lectura;
    }
    return stoi(duracion_lectura);
}

void crear_lista_de_lecutras(char tipo_lectura,string titulo,int duracion_lectura,int ano_publicacion,string referencia_a_lectura,string referencia_a_autor, Lista *lista_de_escritores,Lista * lista_de_lecturas){
    Escritor * puntero_escritor;
    int pos = 1;
    lista_de_escritores->obtener_cantidad();
    for (pos ; pos <= lista_de_escritores->obtener_cantidad() ; pos++){
        Escritor * aux = lista_de_escritores->consulta(pos);
        if (referencia_a_lectura == aux->obtener_referencia())
            puntero_escritor = aux;
    }
    if (tipo_lectura == 'C'){
        Cuento *ref = new Cuento(tipo_lectura,titulo,duracion_lectura,ano_publicacion,puntero_escritor,referencia_a_lectura);
        lista_de_lecturas->alta(ref,pos)
    }
}