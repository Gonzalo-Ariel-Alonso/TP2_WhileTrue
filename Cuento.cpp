#include "Cuento.h"
Cuento::Cuento (char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor , string titulo_de_libro)
: Lectura(tipo_de_objeto, titulo, tiempo_lectura, anio, autor)
{
    this->titulo_de_libro = titulo_de_libro;
}


void Cuento::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    if (autor != nullptr ){autor->mostrar_datos();}
    cout << "Titulo de libro: " << titulo_de_libro << endl;
}
