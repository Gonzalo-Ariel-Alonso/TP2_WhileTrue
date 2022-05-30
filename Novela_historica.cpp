#include <iostream>
#include "Novela_historica.h"


Novela_historica::Novela_historica(string titulo, float tiempo_lectura, int anio, Escritor * autor, string genero, char* tema)
:Novela(titulo, tiempo_lectura, anio, autor, genero)
{
    this->tema = tema;
}


void Novela_historica::mostrar(){
    Novela::mostrar();
    cout << "Tema: " << tema << endl;
}

