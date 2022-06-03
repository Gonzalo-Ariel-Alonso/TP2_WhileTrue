#include "Escritor.h"
#include <fstream>

Escritor::Escritor(string _referencia,string _nombre_y_apellido,string _nacionalidad,string _anio_nacimiento,string _anio_fallecimiento){
    referencia = _referencia;
    nombre_y_apellido = _nombre_y_apellido;
    nacionalidad = _nacionalidad;
    if (_anio_nacimiento == "" || _anio_nacimiento == "0")
        anio_nacimiento = "desconocido";
    else
        anio_nacimiento = _anio_nacimiento;
    if (_anio_fallecimiento == "" || _anio_nacimiento == "0")
        anio_fallecimiento = "desconocido";
    else
        anio_fallecimiento = _anio_fallecimiento;
}

Escritor::~Escritor(){}

Escritor::Escritor(){}

void Escritor::modificar_anio_fallecimiento(string anio_fallecimiento_nuevo){
    anio_fallecimiento = anio_fallecimiento_nuevo;
}

void Escritor::mostrar_datos(){
    cout << "Nombre: " << nombre_y_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Ano de nacimiento: " << anio_nacimiento << endl;
    cout << "Ano de fallecimiento: " << anio_fallecimiento << endl;
}

void Escritor::mostrar_nombre_y_fallecimiento(){
    cout << "Nombre: " << nombre_y_apellido << " - Ano de fallecimiento: " << anio_fallecimiento << endl;
}

string Escritor::devolver_nombre(){
    return nombre_y_apellido;
}

string Escritor::obtener_referencia(){
    return referencia;
}
