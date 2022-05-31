#include "Novela_historica.h"


Novela_historica::Novela_historica(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor, string genero, char* tema)
:Novela(tipo_de_objeto, titulo, tiempo_lectura, anio, autor, genero)
{
    this->tema = tema;
}


void Novela_historica::mostrar(){
    Novela::mostrar();
    cout << "Tema: " << tema << endl;
}
