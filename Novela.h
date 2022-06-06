#ifndef LECTURAS_NOVELA_H
#define LECTURAS_NOVELA_H


#include <iostream>
#include <string>
using namespace std;
#include "Lectura.h"
#include "Escritor.h"
#include "Genero.h"

using namespace std;

class Novela: public Lectura{
protected:
    Generos genero;
public:

  //PRE: Recibe los datos a almacenar
  //POST: Almacena los datos recibidos
    Novela(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio , Escritor * autor , Generos genero);
    ~Novela()=default;

    //PRE:
    //POST: Imprime por pantalla los datos
    virtual void mostrar();

    //PRE: Recibe un enumerado de genero
    //POST: Devuelve el nombre dentro del enumerado
    string de_enumerado_a_string(Generos genero);

    //PRE: Recibe un genero
    //POST: Imprime por pantalla los datos si coincide el genero con el almacenado
    void mostrar_filtrado_por_genero(Generos genero_a_filtrar);
};


#endif //LECTURAS_NOVELA_H
