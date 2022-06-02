#include <iostream>
#include <fstream>
#include "funciones.h"
#include "Escritor.h"
#include "Lecturas_y_subtipos.h"

using namespace std;

void mostrar_menu(){
    cout << "Bienvenido! Elija una opcion: " << endl;
    cout << "1 - Agregar una nueva lectura a la lista" << endl;
    cout << "2 - Quitar una lectura de la lista" << endl;
    cout << "3 - Agregar un escritor" << endl;
    cout << "4 - Cambiar dato de un escritor (solo fecha de fallecimiento)" << endl;
    cout << "5 - Listar los escritores" << endl;
    cout << "6 - Sortear una lectura random para leer en una de las tertulias" << endl;
    cout << "7 - Listar todas las lecturas" << endl;
    cout << "8 - Listar las lecturas entre determinados años. " << endl;
    cout << "9 - Listar las lecturas de un determinado escritor que ingresa el usuario." << endl;
    cout << "10 - Listar las novelas de determinado género." << endl;
    cout << "11 - Armar una cola" << endl;
    cout << "12 - Salir" << endl;
}   

void crear_lista_escritores(Lista<Escritor>*  lista_de_escritores){
    ifstream escritores;
    escritores.open("escritores.txt");
    string referencia_escritor;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    int pos = 1;
    string vacio;
    while (!escritores.eof()){
        getline(escritores,referencia_escritor);
        getline(escritores,nombre);
        getline(escritores,nacionalidad);
        getline(escritores,anio_nacimiento);
        if (anio_nacimiento != ""){
            getline(escritores,anio_fallecimiento);
        }
        if (anio_fallecimiento != ""){
            getline(escritores,vacio);
        }
        //crear objeto escritor
        Escritor ref(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
        lista_de_escritores->alta(ref,pos);
        pos++;

        anio_fallecimiento = "";
        anio_nacimiento = "";

    }

    escritores.close();
}

void listar_escritores(Lista<Escritor> * lista_escritores){
    int cantidad_escritores = lista_escritores->obtener_cantidad();
    int pos = 1;
    for ( pos; pos <= cantidad_escritores; pos++){
            Escritor aux = lista_escritores->consulta(pos);
            aux.mostrar_datos();
    }
}

void agregar_escritor(Lista<Escritor> * Lista_de_escritores){
    int ultima_posicion = Lista_de_escritores->obtener_cantidad() + 1;
    string referencia_escritor = "("+to_string(ultima_posicion)+")";
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;
    cout << "Ingrese el nombre y apellido del escritor que quiere agregar" << endl;
    getline(cin>>ws,nombre);
    cout << "Nacionalidad" << endl;
    getline(cin,nacionalidad);
    cout << "Anio de nacimiento, escriba 0 si es desconocido" << endl;
    cin >> anio_nacimiento;
    cout << "Anio de fallecimiento, escriba 0 si es desconocido" << endl;
    cin >> anio_fallecimiento;


    Escritor ref(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
    Lista_de_escritores->alta(ref,ultima_posicion);

    cout << "Usted agrego el escritor: " << endl;
    Escritor aux = Lista_de_escritores->consulta(ultima_posicion);
    aux.mostrar_datos();
    system("pause");
}

void mostrar_nombre_y_fallecimiento_escritor(Lista<Escritor>* lista_de_escritores){
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    for (int pos = 1 ; pos <= cantidad_escritores; pos++){
        Escritor aux = lista_de_escritores->consulta(pos);
        cout << pos << " - ";
        aux.mostrar_nombre_y_fallecimiento();
    }
}

void modificar_anio_fallecimiento_escritor(Lista<Escritor>* lista_de_escritores){
    int pos_escritor;
    string fecha_fallecimiento_nueva;
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    cout << "Digite el numero del escritor que desea cambiarle la fecha de fallecimiento o precione 0 para volver al menu" << endl;
    cin >> pos_escritor;
    if(pos_escritor <= cantidad_escritores && pos_escritor != 0){
        cout << "Digite fecha de fallecimiento del escritor" << endl;
        cin >> fecha_fallecimiento_nueva;
        Escritor aux = lista_de_escritores->consulta(pos_escritor);
        aux.modificar_anio_fallecimiento(fecha_fallecimiento_nueva);
        lista_de_escritores->cambiar_dato(aux,pos_escritor);
        system("cls");
        cout << "Fecha de fallecimiento modificada con exito"<< endl;
    }
    else if (pos_escritor > cantidad_escritores && pos_escritor != 0 ){
        system("cls");
        cout << "Escritor inexistente" << endl;
    }
}

int comparar(int anio_lectura_actual, Lista<Lectura*>* lista_de_lecturas){
    int posicion_ordenada = 1;
    if  (lista_de_lecturas->vacia())
        posicion_ordenada = 1;
    else{
        for (int pos = 1 ; pos <= lista_de_lecturas->obtener_cantidad() ; pos++ ){
            if (anio_lectura_actual < lista_de_lecturas->consulta(pos)->get_anio_publicacion()){
                posicion_ordenada = pos;
                pos = lista_de_lecturas->obtener_cantidad(); //cortar for
            }
            else if (anio_lectura_actual >= lista_de_lecturas->consulta(pos)->get_anio_publicacion())
                posicion_ordenada = pos + 1;
        }
    }
    return posicion_ordenada;
}

bool validar_entrada(int entrada,int parametro_minimo,int parametro_maximo){
    bool continuar = true;
    if (parametro_minimo > entrada || entrada > parametro_maximo || cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.sync();
        continuar = false;
        }
    return continuar;
}

void quitar_lectura(Lista<Lectura*>* lista_de_lecturas){
    int pos;
    cout << "Digite el numero de referencia de la lectuda que desea eliminar" << endl;
    for (pos = 1; pos <= lista_de_lecturas->obtener_cantidad() ; pos++){
        cout << pos << " - " << lista_de_lecturas->consulta(pos)->get_titulo() << endl;
    }
    while (1 > pos || pos > lista_de_lecturas->obtener_cantidad()){
        cin >> pos;
        validar_entrada(pos,1,lista_de_lecturas->obtener_cantidad());
    }
    lista_de_lecturas->baja(pos);
    cout << "Lectura eliminada con exito" << endl << endl;
}

void listar_lecturas(Lista<Lectura*>* lista_de_lecturas){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    int pos = 1;
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        _lectura->mostrar_datos();
    }
}

void listar_lectura_filtrada_por_ano(Lista<Lectura*>* lista_de_lecturas){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    int pos = 1;
    int ano_inicial;
    int ano_final;
    bool una_lectura_filtrada = false;
    bool continuar = false;
    while(!continuar){
        cout << "Ingrece el ano inicial para filtrar" << endl;
        cin >> ano_inicial;
        continuar = validar_entrada(ano_inicial,-9999,9999);
    }
    continuar = false;
    while(!continuar){
        cout << "Ingrese el ano final" << endl;
        cin >> ano_final;
        continuar = validar_entrada(ano_final,ano_inicial,9999);
    }
    for (pos; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        if(ano_inicial <= _lectura->get_anio_publicacion() && _lectura->get_anio_publicacion() < ano_final)
            _lectura->mostrar_datos();
            una_lectura_filtrada = true;
    }
    if (!una_lectura_filtrada){
        cout << "No hay ninguna lectura entre los anos filtrados" << endl;
    }
    
}

void listar_lecturas_filtrado_por_escritor(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor> * lista_de_escritores){
    int referencia_escritor;
    bool continuar = false;
    Escritor aux;
    cout << "Digite el parametro del escritor del cual quiere ver sus lecturas: " << endl;
    for (int i = 1;i <= lista_de_escritores->obtener_cantidad();i++){
        cout << lista_de_escritores->consulta(i).obtener_referencia() << " " << lista_de_escritores->consulta(i).devolver_nombre() << endl;
    }
    while (!continuar){
        cin >> referencia_escritor;
        continuar = validar_entrada(referencia_escritor,1,lista_de_escritores->obtener_cantidad());
    }
    aux = lista_de_escritores->consulta(referencia_escritor);
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    for (int pos = 1; pos <= cantidad_lecturas; pos++){
        lista_de_lecturas->consulta(pos)->mostar_filtrado_por_escritor(aux);
    }
}

Generos de_string_a_enumerado(string genero_string){
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

void liberar_memoria(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor> * lista_de_escritores){
    for(int pos = 1; pos <= lista_de_lecturas->obtener_cantidad(); pos++){
        delete lista_de_lecturas->consulta(pos);
    }

}