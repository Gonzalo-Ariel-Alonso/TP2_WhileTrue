#include "Lecturas_y_subtipos.h"

// Implementacion Lectura (clase abstracta)
Lectura::Lectura(string _tipo_de_lectura,string _titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor){
    tipo_de_lectura = _tipo_de_lectura;
    titulo = _titulo;
    duracion_lectura = _duracion_lectura;
    anio_publicacion = _anio_publicacion;
    autor = _autor;
}

Lectura::Lectura(){}//def
Lectura::~Lectura(){
}

int Lectura::get_anio_publicacion(){
    return anio_publicacion;
}

void Lectura::mostar_filtrado_por_escritor(Escritor referencia_a_escritor){
    if (referencia_a_escritor == *autor)
        mostrar_datos();
}
void Lectura::mostrar_filtrado_por_genero(Generos genero_a_filtrar){

}

string Lectura::get_tipo_de_lectura(){
    return tipo_de_lectura;
}

string Lectura::get_titulo(){
    return titulo;
}

Escritor * Lectura::get_autor(){
    return autor;
}

//Implementacion poema
Poema::Poema(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, int _cantidad_versos): Lectura(_tipo_de_lectura, titulo,_duracion_lectura,_anio_publicacion,_autor){
    cantidad_versos = _cantidad_versos;
}

Poema::~Poema(){
}

void Poema::mostrar_datos(){
    cout << "Lectura tipo poema" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion aproximada en minutos: " << duracion_lectura << endl;
    cout << "Anio de publicacion: " << anio_publicacion << endl;
    cout << "Autor: " << autor->devolver_nombre() << endl;   
    cout << "Numero de versos: " << cantidad_versos << endl << endl;
}

// Implementacion cuento
Cuento::Cuento(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _libro_publicado) : Lectura(_tipo_de_lectura,titulo,_duracion_lectura,_anio_publicacion,_autor){
    libro_publicado = _libro_publicado;
}
Cuento::Cuento(){}
Cuento::~Cuento(){
}

void Cuento::mostrar_datos(){
    cout << "Lectura tipo cuento" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion aproximada en minutos: " << duracion_lectura << endl;
    cout << "Anio de publicacion: " << anio_publicacion << endl;
    cout << "Autor: " << autor->devolver_nombre() << endl;   
    cout << "Publicado en el libro: " << libro_publicado << endl << endl;
}

//Implementacion novela
Novela::Novela(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, Generos _genero_novela): Lectura(_tipo_de_lectura,titulo,_duracion_lectura,_anio_publicacion,_autor){
genero = _genero_novela;
}

Novela::~Novela(){
}

void Novela::mostrar_datos(){
    cout << "Lectura tipo novela" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion aproximada en minutos: " << duracion_lectura << endl;
    cout << "Anio de publicacion: " << anio_publicacion << endl; 
    cout << "Autor: " << autor->devolver_nombre() << endl; 
    cout << "Genero: " << de_enumerado_a_string(genero) << endl << endl;  
}

void Novela::mostrar_filtrado_por_genero(Generos genero_a_filtrar){
    if (genero_a_filtrar == genero)
        mostrar_datos();
}

string Novela::de_enumerado_a_string(Generos genero){
    string genero_en_string;
    if (genero == DRAMA)
        genero_en_string = "DRAMA";
    else if ( genero == COMEDIA)
        genero_en_string = "COMEDIA";
    else if ( genero == FICCION)
        genero_en_string = "FICCION";
    else if ( genero == SUSPENSO)
        genero_en_string = "SUSPENSO";
    else if ( genero == TERROR)
        genero_en_string = "TERROR";
    else if ( genero == ROMANTICA)
        genero_en_string = "ROMANTICA";
    else if ( genero == HISTORICA)
        genero_en_string = "HISTORICA";
    return genero_en_string;
}

//Implementacion novela historica
Novela_historica::Novela_historica(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, Generos _genero,char* _descripcion) : Novela(_tipo_de_lectura,titulo,_duracion_lectura,_anio_publicacion,_autor,_genero){
    descripcion = _descripcion;
}

Novela_historica::~Novela_historica(){
}

void Novela_historica::mostrar_datos(){
    cout << "Lectura tipo novela historica" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion aproximada en minutos: " << duracion_lectura << endl;
    cout << "Anio de publicacion: " << anio_publicacion << endl;
    cout << "Autor: " << autor->devolver_nombre() << endl; 
    cout << "Genero: " << de_enumerado_a_string(genero) << endl;
    cout << "Descripcion: " << descripcion << endl << endl;  

}
