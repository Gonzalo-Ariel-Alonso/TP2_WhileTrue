#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"


using namespace std;

int main(){
    ifstream escritores;
    escritores.open("escritores.txt");
    Lista lista_escritores;
    string _referencia;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    string nombre_clase_escritor;   
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
        nombre_clase_escritor = nombre;
        Escritor nombre_clase_escritor(nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
        //resetear posibles valor que esten vacios
        anio_fallecimiento = "";
        anio_nacimiento = "";
        int pos = 1;
        lista_escritores.alta(&nombre_clase_escritor,pos);
        cout << lista_escritores.consulta(pos) << endl;;
        pos++;
    }
//    system("pause");
    return 0;
}

