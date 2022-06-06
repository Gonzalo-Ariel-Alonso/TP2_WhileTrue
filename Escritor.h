#ifndef ESCRITORES_H
#define ESCRITORES_H
#include <iostream>
//#include <string>

using namespace std;

class Escritor
{
private:
    string referencia; // (numero)
    string nombre_y_apellido;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;

public:
  //PRE:Recibe los parametros a almacenar en el objeto
  //POST: Almacena los datos
    Escritor(string _referencia, string _nombre_y_apellido,string _nacionalidad,string _anio_nacimiento,string _anio_fallecimiento);
    //PRE:
    //POST:
    ~Escritor();
    Escritor();

    //PRE:Recibe un string que representa un numero
    //POST: Modifica el anio de fallecimiento actual
    void modificar_anio_fallecimiento(string anio_fa);

    //PRE:-----
    //POST:Muestra por pantalla los datos
    void mostrar_datos();

    //PRE:-----
    //POST:Muestra por pantalla el nombre y el anio de fallecimiento
    void mostrar_nombre_y_fallecimiento();

    //PRE:-----
    //POST:Devuelve el dato nombre
    string devolver_nombre();

    //PRE:
    //POST: Devuelve la referencia almacenada
    string obtener_referencia();
};



#endif
