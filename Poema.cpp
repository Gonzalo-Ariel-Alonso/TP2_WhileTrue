#include <iostream>
#include "Poema.h"
Poema::Poema (string titulo, float tiempo_lectura, int anio , Escritor * autor , int versos)
:Lectura(titulo, tiempo_lectura, autor, anio)
{
    this->versos = versos;
}


void Poema::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    cout << "Cantidad de versos: " << versos << endl;
}

