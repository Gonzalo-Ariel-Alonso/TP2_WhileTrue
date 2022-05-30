#include "Lecturas_y_subtipos.h"

// Implementacion Lectura (clase abstracta)
Lectura::Lectura(string _tipo_de_lectura,string _titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor){
    tipo_de_lectura = _tipo_de_lectura;
    titulo = _titulo;
    duracion_lectura = _duracion_lectura;
    anio_publicacion = _anio_publicacion;
    autor = _autor;
}

/*void Lectura::mostrar_datos(){
    cout << "asd" << endl;
    
}*/
Lectura::Lectura(){}//def
Lectura::~Lectura(){
}

void Lectura::mostar_filtrado_por_anios(int anio_inicial,int anio_final){
    if (anio_inicial < anio_publicacion < anio_final){
  //      mostrar_datos();
    }
}

void Lectura::mostar_filtrado_por_escritor(string esritor_a_filtrar){
    if (esritor_a_filtrar == Lectura::autor->devolver_nombre()){
//        mostrar_datos();
    }
}

string Lectura::obtener_tipo_de_lectura(){
    return tipo_de_lectura;
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
Novela::Novela(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _genero): Lectura(_tipo_de_lectura,titulo,_duracion_lectura,_anio_publicacion,_autor){
genero = _genero;
}

Novela::~Novela(){
}

void Novela::mostrar_datos(){
    cout << "Lectura tipo novela" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion aproximada en minutos: " << duracion_lectura << endl;
    cout << "Anio de publicacion: " << anio_publicacion << endl; 
    cout << "Autor: " << autor->devolver_nombre() << endl; 
    cout << "Genero: " << genero << endl << endl;  
}

void Novela::mostar_filtrado_por_genero(string genero_a_filtrar){
    if (genero_a_filtrar == genero)
        mostrar_datos();
}

//Implementacion novela historica
Novela_historica::Novela_historica(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _genero,char * _descripcion) : Novela(_tipo_de_lectura,titulo,_duracion_lectura,_anio_publicacion,_autor,_genero){
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
    cout << "Genero: " << genero << endl << endl;  

}
