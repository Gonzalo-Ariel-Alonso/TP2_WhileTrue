#include <iostream>
#include <fstream>
#include <string>

#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"
#include "Cuento.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Poema.h"
#include "Lectura.h"
#include "Genero.h"


using namespace std;

void crear_lista_lecturas();

int main(){
    int selector = 13;
    Lista<Escritor*> lista_de_escritores;
    crear_lista_escritores(&lista_de_escritores);

    while (selector != 12 && selector != 0){
        mostrar_menu();
        cin >> selector;
        switch (selector){

        case 3:
            agregar_escritor(&lista_de_escritores);
            system("clear");
            cout << "Escritor agregado!" << endl;
            break;
        case 4:
            mostrar_nombre_y_fallecimiento_escritor(&lista_de_escritores);
            modificar_anio_fallecimiento_escritor(&lista_de_escritores);
            break;
        case 5:
            listar_escritores(&lista_de_escritores);
            cout << endl;
            break;
        case 12:
            cout << "Adios!" << endl << endl;
            system("clear");
            break;
        default:
            cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
            break;
        }
    }

    return 0;
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


int comparar(int anio_lectura_actual, Lista<Lectura*>* lista_de_lecturas){
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


void leer_archivo_lecturas(Lista<Escritor> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas){
    ifstream lecturas;
    lecturas.open("lecturas.txt");
    string tipo_lectura, titulo, duracion_lectura, ano_publicacion, referencia_a_lectura, tema_novela_historica, referencia_a_escritor, vacio;
    while (!lecturas.eof()){
        getline(lecturas,tipo_lectura);
        getline(lecturas,titulo);
        getline(lecturas,duracion_lectura);
        getline(lecturas,ano_publicacion);
        getline(lecturas,referencia_a_lectura);
        if (referencia_a_lectura == "HISTORICA"){
            getline(lecturas,tema_novela_historica);
        }
        getline(lecturas,referencia_a_escritor);
        getline(lecturas,vacio);
        char * tema_novela_historica_ch = &tema_novela_historica[0];
//Buscar autor en lista de escritores
        Escritor *  autor_de_lectura = new Escritor();
        for (int pos = 1; pos <= lista_de_escritores->obtener_cantidad() ; pos++){
            *autor_de_lectura = lista_de_escritores->consulta(pos);
            if (referencia_a_escritor ==  autor_de_lectura->obtener_referencia()){
                pos = lista_de_escritores->obtener_cantidad();
            }
        }
//Crear lista_de_lecturas con sus subtipos de clase adentro
        int posicion = comparar(stoi(ano_publicacion),lista_de_lecturas);
        char tipo_lectura = tipo_lectura;
        if (tipo_lectura == 'C'){
            Cuento* Cu = new Cuento(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura);
            lista_de_lecturas->alta(Cu,posicion);
        }
        else if(tipo_lectura == 'N'){
            Generos genero = de_string_a_enumerado(referencia_a_lectura);
            if (genero == HISTORICA){
                Novela_historica* PNH = new Novela_historica(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,genero,tema_novela_historica_ch);
                lista_de_lecturas->alta(PNH,posicion);           
            }
            else{
                Novela * PN = new Novela(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,genero);
                lista_de_lecturas->alta(PN,posicion);
            }
        }
        else if(tipo_lectura == 'P'){
            int cantidad_versos = stoi(referencia_a_lectura);
            Poema * Po = new Poema(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,cantidad_versos);
            lista_de_lecturas->alta(Po,posicion);  
        }   
    }
    lecturas.close();
}


void agregar_lectura(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor> *lista_de_escritores ){
    string tipo_de_lectura;
    string titulo;
    int duracion_lectura; // en minutos
    int ano_publicacion;
    int referencia_autor;
    Escritor * autor = new Escritor();
    int posicion;
    int referencia_tipo_lectura = 0;

    cout << "Ingrese el tipo de lectura que desea agregar: " << endl;
    cout << "1 - Cuento " << endl << "2 - Poema " << endl <<"3 - Novela"<< endl << "4 - Novela historica " << endl;
    while (0 >= referencia_tipo_lectura || referencia_tipo_lectura > 4 ){
        cin >> referencia_tipo_lectura;
        validar_entrada(referencia_tipo_lectura,1,4);
    }
    cout << "Ingrese el titulo de la lectura: " << endl;    
    cin >> titulo;
    cout << "Ingrese la duracion estimada de la lectura en minutos" << endl;  
    cin >> duracion_lectura;
    cout << "Ingrese el ano de su publicacion" << endl;      
    cin >> ano_publicacion;
    cout << "Ingrese la referencia al autor que pertenece la novela o digite 0 si es desconocido" << endl;


    for (int i = 1;i <= lista_de_escritores->obtener_cantidad();i++){
        cout << lista_de_escritores->consulta(i).obtener_referencia() << " " << lista_de_escritores->consulta(i).devolver_nombre() << endl;
    }
    while (0 >= referencia_autor || referencia_autor > lista_de_escritores->obtener_cantidad()){
        cin >> referencia_autor;
        validar_entrada(referencia_autor,1,lista_de_escritores->obtener_cantidad());
    }
    *autor = lista_de_escritores->consulta(referencia_autor);

    posicion = comparar(ano_publicacion,lista_de_lecturas);

    if (referencia_tipo_lectura == 1){
        string cuento_libro_publicado;
        tipo_de_lectura = 'C';
        cout << "Ingrese el libro donde fue publicado el cuento" << endl;
        cin >> cuento_libro_publicado;
        Cuento * Nuevo_cuento = new Cuento(tipo_de_lectura,titulo,duracion_lectura,ano_publicacion,autor,cuento_libro_publicado);
        lista_de_lecturas->alta(Nuevo_cuento,posicion);
    }
    else if (referencia_tipo_lectura == 2){
        int cantidad_de_versos;
        tipo_de_lectura = 'P';
        cout << "Ingrese la cantidad de versos del poema" << endl;
        cin >> cantidad_de_versos;
        Poema * Nuevo_poema = new Poema(tipo_de_lectura,titulo,duracion_lectura,ano_publicacion,autor,cantidad_de_versos);
        lista_de_lecturas->alta(Nuevo_poema,posicion);    
    }
    else{
        string genero_string;
        Generos genero;
        tipo_de_lectura = "N";
        cout << "Ingrese el genero de la novela" << endl;
        cin >> genero_string;
        genero = de_string_a_enumerado(genero_string);
        if(genero == HISTORICA){
            char * tema_novela_historica;
            cout << "Describa en pocas palabras el tema de la novela historica" << endl;
            cin >> tema_novela_historica;
            Novela_historica * Nueva_NH = new Novela_historica(tipo_de_lectura,titulo,duracion_lectura,ano_publicacion,autor,genero,tema_novela_historica);
            lista_de_lecturas->alta(Nueva_NH,posicion);
        }
        else{
            Novela *Nueva_novela = new Novela(tipo_de_lectura,titulo,duracion_lectura,ano_publicacion,autor,genero);
            lista_de_lecturas->alta(Nueva_novela,posicion);
        }
    }
    cout << endl << "Lectura agregada!" << endl << endl;
}
