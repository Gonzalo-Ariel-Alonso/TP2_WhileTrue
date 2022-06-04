#include "Novela_historica.h"


Novela_historica::Novela_historica(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor, Generos genero, string tema_string)
:Novela(tipo_de_objeto, titulo, tiempo_lectura, anio, autor, genero)
{
  tamanio_char = tema_string.length();
  tema = new char[tamanio_char];
  for (long unsigned int j = 0; j < tamanio_char ; j++){
    tema[j] = tema_string[j];
  }

}

Novela_historica::~Novela_historica(){
  delete[] tema;
}


void Novela_historica::mostrar(){
    Novela::mostrar();
    for(long unsigned int i = 0; i < tamanio_char; i++){
      cout << tema[i];
    }
    cout << endl;
}
