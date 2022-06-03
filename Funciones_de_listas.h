#ifndef FUNCIONES_DE_LISTAS_H
#define FUNCIONES_DE_LISTAS_H

#include <iostream>
#include <string>


#include "Lista.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"

using namespace std;

class Funciones_de_listas{
private:
  Lista<Escritor *> * lista_de_escritores;
  Lista<Lectura *> * lista_de_lecturas;
public:

  Funciones_de_listas(Lista< Escritor* > * lista_escritores, Lista< Lectura * > * lista_lecturas);
  ~Funciones_de_listas();
  void listar_lecturas();//5
  void listar_escritores();//7
  void agregar_escritor();//3
  void agregar_lectura();//1

private:
  void ingresos_usuario(string* ref_lectura, string* titulo, int* duracion, int* ano );
  void catalogo_escritores();
  Escritor* ingreso_autor();
  int comparar(int anio_lectura_actual);
  Generos de_string_a_enumerado(string genero_string);

};

Funciones_de_listas::Funciones_de_listas(Lista< Escritor* > * lista_escritores, Lista< Lectura * > * lista_lecturas){
  lista_de_escritores = lista_escritores;
  lista_de_lecturas = lista_lecturas;
}

Funciones_de_listas::~Funciones_de_listas(){
  lista_de_escritores = 0;
  lista_de_lecturas = 0;
}

void Funciones_de_listas::listar_escritores(){
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    int pos = 1;
    for ( pos; pos <= cantidad_escritores; pos++){
            Escritor * aux = lista_de_escritores->consulta(pos);
            aux->mostrar_datos();
            cout << endl;
    }
}

void Funciones_de_listas::listar_lecturas(){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    int pos = 1;
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        _lectura->mostrar();
        cout << endl;
    }
}


void Funciones_de_listas::agregar_escritor(){
    int ultima_posicion = lista_de_escritores->obtener_cantidad() + 1;
    string referencia_escritor = "("+to_string(ultima_posicion)+")";
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;
    cout << "Ingrese el nombre y apellido del escritor que quiere agregar: ";
    getline(cin>>ws,nombre);
    cout << "Nacionalidad: ";
    getline(cin,nacionalidad);
    cout << "Anio de nacimiento, escriba 0 si es desconocido: ";
    cin >> anio_nacimiento;
    cout << "Anio de fallecimiento, escriba 0 si es desconocido: ";
    cin >> anio_fallecimiento;


    Escritor* ref = new Escritor(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
    lista_de_escritores->alta(ref,ultima_posicion);

    cout << "Usted agrego el escritor: " << endl;
    lista_de_escritores->consulta(ultima_posicion)->mostrar_datos();
}

/*









*/
void Funciones_de_listas::ingresos_usuario(string* ref_lectura, string* titulo, int* duracion, int* ano  ){
  //INTERFAZ USUARIO CON INGRESOS

  while ( *ref_lectura != "1" && *ref_lectura != "2" && *ref_lectura != "3" && *ref_lectura != "4" ){
    cout << "Ingrese el tipo de lectura que desea agregar: " << endl;
    cout << "1 - Cuento " << endl << "2 - Poema " << endl <<"3 - Novela"<< endl << "4 - Novela historica " << endl;
    cout << "Ingresando : ... ";
    cin >> (*ref_lectura);
  }

  cout << "Ingrese el titulo de la lectura: ";
  cin >> (*titulo);
  cout << "Ingrese la duracion estimada de la lectura en minutos: ";
  cin >> (*duracion);
  cout << "Ingrese el año de su publicacion: ";
  cin >> (*ano);

}
void Funciones_de_listas::catalogo_escritores(){
  for (int pos = 1 ; pos <= lista_de_escritores->obtener_cantidad() ; pos++){
      cout << lista_de_escritores->consulta(pos)->obtener_referencia() << " " << lista_de_escritores->consulta(pos)->devolver_nombre() << endl;
  }

}

Escritor* Funciones_de_listas::ingreso_autor(){
  int referencia_autor;
  Escritor* escritor_ingresado;
  cout << "Ingrese la referencia al autor que pertenece la novela o digite 0 si es desconocido" << endl;
  catalogo_escritores();
  if (referencia_autor = 0){
    int opcion;
    cout << "1- Dejarlo desconocido" << endl;
    cout << "2- Agregar el escritor" << endl;
    while(opcion != 1 && opcion != 2){
      cout << "Elegir: ... ";
      cin >> opcion;
    }
    if (opcion == 1){
      escritor_ingresado = nullptr;
    }
    else if(opcion == 2){

      agregar_escritor();
      int ultima_posicion = lista_de_escritores->obtener_cantidad();
      escritor_ingresado = lista_de_escritores->consulta(ultima_posicion);
    }
  }
  else{
    catalogo_escritores();
    while (0 > referencia_autor || referencia_autor > lista_de_escritores->obtener_cantidad()){
        cin >> referencia_autor;
    }
    escritor_ingresado = lista_de_escritores->consulta(referencia_autor);
  }

  return escritor_ingresado;
}

int Funciones_de_listas::comparar(int anio_lectura_actual){
    int posicion_ordenada = 1;
    if  (lista_de_lecturas->vacia())
        posicion_ordenada = 1;
    else{
        for (int pos = 1 ; pos <= lista_de_lecturas->obtener_cantidad() ; pos++ ){
            if (anio_lectura_actual < lista_de_lecturas->consulta(pos)->get_anio()){
                posicion_ordenada = pos;
                pos = lista_de_lecturas->obtener_cantidad(); //cortar for
            }
            else if (anio_lectura_actual >= lista_de_lecturas->consulta(pos)->get_anio())
                posicion_ordenada = pos + 1;
        }
    }
    return posicion_ordenada;
}

Generos Funciones_de_listas::de_string_a_enumerado(string genero_string){
    Generos genero;
    if(genero_string  == "DRAMA")
        genero = DRAMA;
    else if (genero_string == "COMEDIA")
        genero = COMEDIA;
    else if (genero_string  == "FICCION")
        genero = FICCION;
    else if (genero_string  == "SUSPENSO")
        genero = SUSPENSO;
    else if (genero_string  == "TERROR")
        genero = TERROR;
    else if (genero_string  == "ROMANTICA")
        genero = ROMANTICA;
    else if (genero_string  == "HISTORICA")
        genero = HISTORICA;
    return genero;
}





void Funciones_de_listas::agregar_lectura(){
  string tipo_de_lectura, titulo;
  int duracion_lectura, ano_publicacion;
  int posicion;
  string referencia_tipo_lectura;

  Escritor * autor;

  ingresos_usuario(&referencia_tipo_lectura, &titulo, &duracion_lectura, &ano_publicacion);
  autor = ingreso_autor();

  posicion = comparar(ano_publicacion);

  if (referencia_tipo_lectura == "1"){
    string cuento_libro_publicado;
    cout << "Ingrese el libro donde fue publicado el cuento" << endl;
    cin >> cuento_libro_publicado;
    Cuento * Nuevo_cuento = new Cuento('C',titulo,duracion_lectura,ano_publicacion,autor,cuento_libro_publicado);
    lista_de_lecturas->alta(Nuevo_cuento,posicion);
  }
  else if (referencia_tipo_lectura == "2"){
    int cantidad_de_versos;
    cout << "Ingrese la cantidad de versos del poema" << endl;
    cin >> cantidad_de_versos;
    Poema * Nuevo_poema = new Poema('P',titulo,duracion_lectura,ano_publicacion,autor,cantidad_de_versos);
    lista_de_lecturas->alta(Nuevo_poema,posicion);
  }

  else{
    string genero_string;
    Generos genero;
    cout << "Ingrese el genero de la novela" << endl;
    cin >> genero_string;
    genero = de_string_a_enumerado(genero_string);
    if(genero == HISTORICA){
        char tema_novela_historica;
        cout << "Describa en pocas palabras el tema de la novela historica" << endl;
        cin >> tema_novela_historica;
        Novela_historica * Nueva_NH = new Novela_historica('N',titulo,duracion_lectura,ano_publicacion,autor,genero,&tema_novela_historica);
        lista_de_lecturas->alta(Nueva_NH,posicion);
    }
    else{
        Novela *Nueva_novela = new Novela('N',titulo,duracion_lectura,ano_publicacion,autor,genero);
        lista_de_lecturas->alta(Nueva_novela,posicion);
    }


  }

}




#endif //FUNCIONES_DE_LISTAS_H
