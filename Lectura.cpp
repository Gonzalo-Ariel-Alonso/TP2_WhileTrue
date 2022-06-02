#include <iostream>
#include <string>
using namespace std;

#include "Lectura.h"

Lectura::Lectura (char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor ){
    this->tipo_de_objeto = tipo_de_objeto;
    this->titulo = titulo;
    this->tiempo_lectura = tiempo_lectura;
    this->anio = anio;
    this->autor = autor;
    leido = false;
}

void Lectura::set_leido(bool leido){
    this->leido = leido;
}

bool Lectura::get_leido(){
    return leido;
}

string Lectura::get_titulo(){
    return titulo;
}
int Lectura::get_tiempo_lectura(){
    return tiempo_lectura;
}

int Lectura::get_anio(){
    return anio;
}

Lectura::~Lectura(){
    delete autor;
}