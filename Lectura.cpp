#include "Lectura.h"

Lectura::Lectura (string titulo, float tiempo_lectura, int anio, Escritor * autor ){
    this->titulo = titulo;
    this->tiempo_lectura = tiempo_lectura;
    this->anio = anio;
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
float Lectura::get_tiempo_lectura(){
    return tiempo_lectura;
}

int Lectura::get_anio(){
    return anio;
}


#include "Lectura.h"
