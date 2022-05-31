#include "Novela.h"

Novela::Novela(string titulo, int tiempo_lectura, int anio, Escritor * autor, string genero):
Lectura(titulo, tiempo_lectura, anio, autor) {
    this->genero = genero;
};



void Novela::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    autor->mostrar_datos();
    cout << "Genero: " << genero << endl;
    //FALTARIA EL ESCRITOR PERO HAY QUE VER CON EL GRUPO
}
