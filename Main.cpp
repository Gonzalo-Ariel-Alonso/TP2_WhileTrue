#include <iostream>
#include <fstream>
#include <string>

#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"

#include "Cuento.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Poema.h"
#include "Lectura.h"


using namespace std;

void crear_lista_lecturas();

int main(){
    int selector = 0;
    Lista<Escritor*> lista_de_escritores;
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
            modificar_anio_fallecimiento_escritor(&lista_de_escritores);
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

/*
void crear_lista_lecturas(){
    ifstream lecturas;
    string tipo_lectura;
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
    }
 //   return stoi(duracion_lectura);
}
*/
/*void crear_lista_de_lecutras(char tipo_lectura,string titulo,int duracion_lectura,int ano_publicacion,string referencia_a_lectura,string referencia_a_autor, Lista<Escritor> *lista_de_escritores,Lista<Lectura> * lista_de_lecturas){
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
        lista_de_escritores->alta(ref,pos);
    }
}*/
void crear_lista_lecturas(Lista<Lectura*> * lista_lecturas, Lista<Escritor*> * lista_escritores){
    ifstream archivo;

    archivo.open("lecturas.txt", ios::in);

    if (archivo.fail()){
      cout << "no se abrio \n" << endl;
    }

    string tipo_de_objeto;
    string titulo, quinto_dato, sexto_dato, ultimo_dato;
    string tiempo_lectura;
    string anio;

    while (!archivo.eof()){


      getline(archivo, tipo_de_objeto);
      char _tipo_de_objeto = tipo_de_objeto[0];
      getline(archivo, titulo);
      getline(archivo, tiempo_lectura);
      getline(archivo, anio);
      getline(archivo, quinto_dato); //quinto_dato va a tomar el valor
                                      // de verso, libro o genero
      getline(archivo, sexto_dato); //Este sexto dato tomara el valor de get_autor
                                    //en el caso de no tener una novela historica
                                    //toma el de Tema en caso de ser novela historica
      getline(archivo, ultimo_dato);//Toma el de autor o un espacio el blanco;
      if (ultimo_dato == "" ){
        if ( sexto_dato == "ANONIMO"){
          lista->alta(titulo, tiempo_lectura, anio , nullptr, _tipo_de_objeto, quinto_dato);
        }
        else{
          Escritor * puntero_del_escritor; //Me va a guardar la direccion de memoria
          puntero_del_escritor->consulta();//Me busca el objeto escritor
          lista_lecturas->alta(); // FALTA EL OBJETO
        }
      }
      else {
        int i = sexto_dato.size();
        char tema_auxiliar[i];//lo uso para armar el char*
        char* tema = tema_auxiliar;
        for (int j = 0; j <= i ; j++){
          tema_auxiliar[j] = sexto_dato[j];
        }
        Escritor * puntero_del_escritor;
        puntero_del_escritor->consulta();
        lista_lecturas->alta();

        getline(archivo, titulo); //me pasa a la linea vacia
      }


    }

    archivo.close();
  }
