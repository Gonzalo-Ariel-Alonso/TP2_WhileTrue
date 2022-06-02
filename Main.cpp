#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"
#include "Lecturas_y_subtipos.h"
#include "generos.h"
#include <cstring>
#include <typeinfo>

using namespace std;

void leer_archivo_lecturas(Lista<Escritor*> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas);

void agregar_lectura(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor*> *lista_de_escritores );

int main(){
    
    int selector;
    Lista<Escritor*> lista_de_escritores;  
    Lista<Lectura*> lista_de_lecturas;
    crear_lista_escritores(&lista_de_escritores);
    leer_archivo_lecturas(&lista_de_escritores,&lista_de_lecturas);

    while (selector != 12){
        mostrar_menu();
        cin >> selector;
        switch (selector){
        case 1:
            agregar_lectura(&lista_de_lecturas,&lista_de_escritores);
            break;
        case 2:
            quitar_lectura(&lista_de_lecturas);
            break;
        case 3:
            agregar_escritor(&lista_de_escritores);
            cout << "Escritor agregado!" << endl;
            break;
        case 4:
            mostrar_nombre_y_fallecimiento_escritor(&lista_de_escritores);
            modificar_ano_fallecimiento_escritor(&lista_de_escritores);
            break;
        case 5:
            cout << "--------LISTA DE ESCRITORES--------" << endl;
            listar_escritores(&lista_de_escritores);
            cout << endl;
            break;
        case 7:
            cout << "--------LISTA DE LECUTRAS--------" << endl;
            listar_lecturas(&lista_de_lecturas);
            break;
        case 8:
            listar_lectura_filtrada_por_ano(&lista_de_lecturas);
            break;
        case 9:
            listar_lecturas_filtrado_por_escritor(&lista_de_lecturas,&lista_de_escritores);
            break;
        case 10:

            break;
        case 12:
            lista_de_lecturas.~Lista();
            lista_de_escritores.~Lista();
            cout << "Adios!" << endl << endl;
            break;
        default:
            validar_entrada(selector,1,12);
            break;
        }
    }

    return 0;
}

void leer_archivo_lecturas(Lista<Escritor*> *lista_de_escritores, Lista<Lectura*>* lista_de_lecturas){
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
            autor_de_lectura = lista_de_escritores->consulta(pos);
            if (referencia_a_escritor ==  autor_de_lectura->obtener_referencia()){
                pos = lista_de_escritores->obtener_cantidad();
            }
        }
//Crear lista_de_lecturas con sus subtipos de clase adentro
        int posicion = comparar(stoi(ano_publicacion),lista_de_lecturas);
        if (tipo_lectura == "C"){
            Cuento* Cu = new Cuento(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,referencia_a_lectura);
            lista_de_lecturas->alta(Cu,posicion);
        }
        else if(tipo_lectura == "N"){
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
        else if(tipo_lectura == "P"){
            int cantidad_versos = stoi(referencia_a_lectura);
            Poema * Po = new Poema(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),autor_de_lectura,cantidad_versos);
            lista_de_lecturas->alta(Po,posicion);  
        }   
    }
    lecturas.close();
}


void agregar_lectura(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor*> *lista_de_escritores ){
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
        cout << lista_de_escritores->consulta(i)->obtener_referencia() << " " << lista_de_escritores->consulta(i)->devolver_nombre() << endl;
    }
    while (0 >= referencia_autor || referencia_autor > lista_de_escritores->obtener_cantidad()){
        cin >> referencia_autor;
        validar_entrada(referencia_autor,1,lista_de_escritores->obtener_cantidad());
    }
    autor = lista_de_escritores->consulta(referencia_autor);

    posicion = comparar(ano_publicacion,lista_de_lecturas);

    if (referencia_tipo_lectura == 1){
        string cuento_libro_publicado;
        tipo_de_lectura = "C";
        cout << "Ingrese el libro donde fue publicado el cuento" << endl;
        cin >> cuento_libro_publicado;
        Cuento * Nuevo_cuento = new Cuento(tipo_de_lectura,titulo,duracion_lectura,ano_publicacion,autor,cuento_libro_publicado);
        lista_de_lecturas->alta(Nuevo_cuento,posicion);
    }
    else if (referencia_tipo_lectura == 2){
        int cantidad_de_versos;
        tipo_de_lectura = "P";
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

