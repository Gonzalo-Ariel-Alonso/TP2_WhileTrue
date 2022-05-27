#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"
#include "Lecturas_y_subtipos.h"
#include <cstring>
using namespace std;

void listar_lecturas(Lista<Lectura*> * lista_de_lecturas);

void leer_archivo_lecturas(Lista<Escritor> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas);

void crear_lista_de_lecutras(string tipo_lectura,string titulo,int duracion_lectura,int ano_publicacion,string referencia_a_lectura,string referencia_a_escritor, Lista<Escritor> *lista_de_escritores,Lista<Lectura*> * lista_de_lecturas,char * tema_novela_historica);

int main(){
    int selector = 7;
    Lista<Escritor> lista_de_escritores;  
    Lista<Lectura*> lista_de_lecturas;
    crear_lista_escritores(&lista_de_escritores);

    while (selector != 12){
        mostrar_menu();
//        cin >> selector;
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
        case 7:
            leer_archivo_lecturas(&lista_de_escritores,&lista_de_lecturas);
            cout << "lista creada" << endl;
            listar_lecturas(&lista_de_lecturas);
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

void leer_archivo_lecturas(Lista<Escritor> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas){
    ifstream lecturas;
    lecturas.open("lecturas.txt");
    string tipo_lectura, titulo, duracion_lectura, ano_publicacion, referencia_a_lectura, tema_novela_historica, referencia_a_escritor, vacio;
    int pos = 1; // posicion*
    while (!lecturas.eof()){
        getline(lecturas,tipo_lectura);
        getline(lecturas,titulo);
        getline(lecturas,duracion_lectura);
        getline(lecturas,ano_publicacion);
        getline(lecturas,referencia_a_lectura);
        if (referencia_a_lectura == "HISTORICA"){
            getline(lecturas,tema_novela_historica);
        }
        getline(lecturas,referencia_a_escritor);
        getline(lecturas,vacio);
        char * tema_novela_historica_ch = &tema_novela_historica[0];
        crear_lista_de_lecutras(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),referencia_a_lectura,referencia_a_escritor,lista_de_escritores,lista_de_lecturas,tema_novela_historica_ch);
    }
}

void crear_lista_de_lecutras(string tipo_lectura,string titulo,int duracion_lectura,int ano_publicacion,string referencia_a_lectura,string referencia_a_escritor, Lista<Escritor> *lista_de_escritores,Lista<Lectura*> * lista_de_lecturas,char * tema_novela_historica){
    Escritor * puntero_escritor;
    int pos = 1;
    lista_de_escritores->obtener_cantidad();
    for (pos ; pos <= lista_de_escritores->obtener_cantidad() ; pos++){
        Escritor aux = lista_de_escritores->consulta(pos);
        if (referencia_a_escritor == aux.obtener_referencia())
            puntero_escritor = &aux;
            pos = lista_de_escritores->obtener_cantidad();
    }
    if (tipo_lectura == "C"){
        Lectura * puntero_cuento;
        Cuento ref_cuento(tipo_lectura,titulo,duracion_lectura,ano_publicacion,puntero_escritor,referencia_a_lectura);
        puntero_cuento = &ref_cuento;
        lista_de_lecturas->alta(puntero_cuento,pos);
        pos++;
    }
    else if(tipo_lectura == "N"){
        if (referencia_a_lectura == "HISTORICA"){
            Lectura * puntero_novela_historica;
            puntero_novela_historica = new Novela_historica(tipo_lectura,titulo,duracion_lectura,ano_publicacion,puntero_escritor,referencia_a_lectura,tema_novela_historica);
            lista_de_lecturas->alta(puntero_novela_historica,pos);
            pos++;           
        }
        else{
            Lectura * puntero_novela;
            puntero_novela = new Novela(tipo_lectura,titulo,duracion_lectura,ano_publicacion,puntero_escritor,referencia_a_lectura);
            lista_de_lecturas->alta(puntero_novela,pos);
            pos++;
        }
    }
    else if(tipo_lectura == "p"){
        int cantidad_versos = stoi(referencia_a_lectura);
        Lectura * puntero_poema;
        puntero_poema = new Poema(tipo_lectura,titulo,duracion_lectura,ano_publicacion,puntero_escritor,cantidad_versos);
        lista_de_lecturas->alta(puntero_poema,pos);
        pos++;    
    }
}

void listar_lecturas(Lista<Lectura*> * lista_de_lecturas){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    int pos = 1;
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura = lista_de_lecturas->consulta(pos);
        _lectura->mostrar_datos();
    }
    
}