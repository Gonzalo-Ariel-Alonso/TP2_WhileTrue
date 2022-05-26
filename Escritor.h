#ifndef ESCRITORES_H
#define ESCRITORES_H
#include <iostream>
//#include <string>

using namespace std;

class Escritor
{
private:
    string referencia;
    string nombre_y_apellido;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;

public:
    Escritor(string _referencia, string _nombre_y_apellido,string _nacionalidad,string _anio_nacimiento,string _anio_fallecimiento);
    ~Escritor();
    void modificar_anio_fallecimiento(string anio_fa);
    void mostrar_datos();
    void mostrar_nombre_y_fallecimiento();
    string devolver_nombre();
    string obtener_referencia();
};



#endif
