#include "Escritor.h"
#include <fstream>

Escritor::Escritor(string _nombre_y_apellido,string _nacionalidad,string _anio_nacimiento,string _anio_fallecimiento){
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

Escritor::~Escritor(){
}

void Escritor::modificar_anio_nacimiento(int anio_na){
    anio_nacimiento = anio_na;
}

void Escritor::mostrar_datos(){
    cout << "Nombre: " << nombre_y_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Ano de nacimiento: " << anio_nacimiento << endl;
    cout << "Ano de fallecimiento: " << anio_fallecimiento << endl << endl;
}
