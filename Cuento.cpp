#include "Cuento.h"
Cuento::Cuento (string titulo, float tiempo_lectura, int anio, Escritor * autor , string titulo_de_libro)
: Lectura(titulo, tiempo_lectura, anio, autor)
{
    this->titulo_de_libro = titulo_de_libro;
}


void Cuento::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    autor->mostrar_datos();
    cout << "Titulo de libro: " << titulo_de_libro << endl;
}
