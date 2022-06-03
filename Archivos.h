#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Lista.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"

using namespace std;

class Archivos{
private:
  Lista<Escritor *> * lista_de_escritores;
  Lista<Lectura *> * lista_de_lecturas;
  string escritores_txt, lecturas_txt;
public:
  Archivos(Lista<Escritor *> * lista_de_escritores, Lista<Lectura *> * lista_de_lecturas, string escritor_txt, string lecturas_txt);
  ~Archivos();
  void crear_lista_escritores();
  void crear_lista_lecturas();
private:
  Escritor* escritor_por_referencia(string referencia);
  int comparar(int anio_lectura_actual);
  Generos de_string_a_enumerado(string genero_string);



};

Archivos::Archivos( Lista<Escritor *> * lista_de_escritores, Lista<Lectura *> * lista_de_lecturas, string escritores_txt, string lecturas_txt ){
  this->lista_de_escritores = lista_de_escritores;
  this->lista_de_lecturas = lista_de_lecturas;
  this->escritores_txt = escritores_txt;
  this->lecturas_txt = lecturas_txt;
}

Archivos::~Archivos(){
  lista_de_escritores = 0;
  lista_de_lecturas = 0;
}

void Archivos::crear_lista_escritores(){
    ifstream escritores;
    escritores.open(escritores_txt);
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

Escritor* Archivos::escritor_por_referencia(string referencia){
  Escritor *  autor_de_lectura;
  int cantidad_escritores = lista_de_escritores->obtener_cantidad();

  for (int pos = 1; pos <= cantidad_escritores; pos++){
    Escritor * escritor_en_lista_escritores = lista_de_escritores->consulta(pos);
    if ( referencia == escritor_en_lista_escritores->obtener_referencia() ){
      autor_de_lectura = escritor_en_lista_escritores;
      pos = lista_de_escritores->obtener_cantidad();
      escritor_en_lista_escritores = 0;
    }
  }
  if (referencia == "ANONIMO"){ autor_de_lectura = nullptr;}
  return autor_de_lectura;
}

int Archivos::comparar(int anio_lectura_actual){
    int posicion_ordenada = 1;
    if  (lista_de_lecturas->vacia())
        posicion_ordenada = 1;
    else{
        for (int pos = 1 ; pos <= lista_de_lecturas->obtener_cantidad() ; pos++ ){
            if (anio_lectura_actual < lista_de_lecturas->consulta(pos)->get_anio()){
                posicion_ordenada = pos;
                pos = lista_de_lecturas->obtener_cantidad(); //cortar for
            }
            else if (anio_lectura_actual >= lista_de_lecturas->consulta(pos)->get_anio())
                posicion_ordenada = pos + 1;
        }
    }
    return posicion_ordenada;
}

Generos Archivos::de_string_a_enumerado(string genero_string){
    Generos genero;
    if(genero_string  == "DRAMA")
        genero = DRAMA;
    else if (genero_string == "COMEDIA")
        genero = COMEDIA;
    else if (genero_string  == "FICCION")
        genero = FICCION;
    else if (genero_string  == "SUSPENSO")
        genero = SUSPENSO;
    else if (genero_string  == "TERROR")
        genero = TERROR;
    else if (genero_string  == "ROMANTICA")
        genero = ROMANTICA;
    else if (genero_string  == "HISTORICA")
        genero = HISTORICA;
    return genero;
}


void Archivos::crear_lista_lecturas(){
    ifstream lecturas;
    lecturas.open(lecturas_txt);
    string tipo_lecturas, titulo, duracion_lectura, ano_publicacion, referencia_a_lectura, tema_novela_historica, referencia_a_escritor, vacio;
    while (!lecturas.eof()){
        getline(lecturas,tipo_lecturas);
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
        Escritor *  autor_de_lectura = escritor_por_referencia (referencia_a_escritor);
//Crear lista_de_lecturas con sus subtipos de clase adentro
        int posicion = comparar(stoi(ano_publicacion));
        char tipo_lectura = tipo_lecturas.at(0);


        if (tipo_lectura == 'C'){
            Cuento* nuevo_cuento = new Cuento(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura);
            lista_de_lecturas->alta(nuevo_cuento , posicion);
        }
        else if(tipo_lectura == 'N'){
            Generos genero = de_string_a_enumerado(referencia_a_lectura);
            if (genero == HISTORICA){
                Novela_historica* nueva_novela_historica = new Novela_historica(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,genero,tema_novela_historica_ch);
                lista_de_lecturas->alta(nueva_novela_historica , posicion);
            }
            else{
                Novela * nueva_novela = new Novela(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,genero);
                lista_de_lecturas->alta(nueva_novela , posicion);
            }
        }
        else if(tipo_lectura == 'P'){
            int cantidad_versos = stoi(referencia_a_lectura);
            Poema * nuevo_poema = new Poema(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,cantidad_versos);
            lista_de_lecturas->alta(nuevo_poema , posicion);
        }
    }
    lecturas.close();
}

#endif
