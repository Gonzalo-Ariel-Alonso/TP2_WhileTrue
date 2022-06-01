#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"
#include "Lecturas_y_subtipos.h"
#include <cstring>
#include <typeinfo>
using namespace std;

void listar_lecturas(Lista<Lectura*>* lista_de_lecturas);

void leer_archivo_lecturas(Lista<Escritor> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas);

int posicion_ordenada(int anio_lectura_actual, Lista<Lectura*>* lista_de_lecturas);

int main(){
    int selector;
    Lista<Escritor> lista_de_escritores;  
    Lista<Lectura*> lista_de_lecturas;
    crear_lista_escritores(&lista_de_escritores);
    leer_archivo_lecturas(&lista_de_escritores,&lista_de_lecturas);

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
            modificar_anio_fallecimiento_escritor(&lista_de_escritores);
            break;
        case 5:
            listar_escritores(&lista_de_escritores);
            system("pause");
            cout << endl;
            break;
        case 7:
            listar_lecturas(&lista_de_lecturas);
            break;
        case 12:
            lista_de_lecturas.~Lista();
            lista_de_escritores.~Lista();
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
//Buscar autor en lista de escritores
        Escritor *  autor_de_lectura = new Escritor();
        for (int pos = 1; pos <= lista_de_escritores->obtener_cantidad() ; pos++){
            *autor_de_lectura = lista_de_escritores->consulta(pos);
            if (referencia_a_escritor ==  autor_de_lectura->obtener_referencia()){
                pos = lista_de_escritores->obtener_cantidad();
            }
        }
//Crear lista_de_lecturas con sus subtipos de clase adentro
        int posicion = posicion_ordenada(stoi(ano_publicacion),lista_de_lecturas);
        if (tipo_lectura == "C"){
            Cuento* Cu = new Cuento(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura);
            lista_de_lecturas->alta(Cu,posicion);
        }
        else if(tipo_lectura == "N"){
            if (referencia_a_lectura == "HISTORICA"){
                Novela_historica* PNH = new Novela_historica(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura,tema_novela_historica_ch);
                lista_de_lecturas->alta(PNH,posicion);           
            }
            else{
                Novela * PN = new Novela(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura);
                lista_de_lecturas->alta(PN,posicion);
            }
        }
        else if(tipo_lectura == "P"){
            int cantidad_versos = stoi(referencia_a_lectura);
            Poema * Po = new Poema(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,cantidad_versos);
            lista_de_lecturas->alta(Po,posicion);  
        }   
    }
    lecturas.close();
}

void listar_lecturas(Lista<Lectura*>* lista_de_lecturas){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    int pos = 1;
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        string referencia = _lectura->obtener_tipo_de_lectura();
        _lectura->mostrar_datos();
    }
}

int posicion_ordenada(int anio_lectura_actual, Lista<Lectura*>* lista_de_lecturas){
    int posicion_ordenada = 1;
    if  (lista_de_lecturas->vacia())
        posicion_ordenada = 1;
    else{
        for (int pos = 1 ; pos <= lista_de_lecturas->obtener_cantidad() ; pos++ ){
            if (anio_lectura_actual < lista_de_lecturas->consulta(pos)->get_anio_publicacion()){
                posicion_ordenada = pos;
                pos = lista_de_lecturas->obtener_cantidad(); //cortar for
            }
            else if (anio_lectura_actual >= lista_de_lecturas->consulta(pos)->get_anio_publicacion())
                posicion_ordenada = pos + 1;
        }
    }
    return posicion_ordenada;
}