#ifndef LECTURAS_Y_SUBTIPOS_H
#define LECTURAS_Y_SUBTIPOS_H

#include <iostream>
#include "Escritor.h"
#include "generos.h"

using namespace std;

class Lectura{
protected:
    string tipo_de_lectura;
    string titulo;
    int duracion_lectura; // en minutos
    int anio_publicacion;
    Escritor * autor;
public:
    Lectura(string _tipo_de_lectura,string _titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor);
    virtual ~Lectura();
    Lectura();//constructoir dcefault
    virtual void mostrar_datos() = 0;
    virtual void mostrar_filtrado_por_genero(Generos genero_a_filtrar);
    int get_anio_publicacion();
    void mostar_filtrado_por_escritor(Escritor referencia_a_escritor);
    string get_tipo_de_lectura();
    string get_titulo();
    Escritor * get_autor();
};


class Poema : public Lectura{
private:
    int cantidad_versos;
public:
    Poema(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, int _cantidad_versos);
    ~Poema();
    void mostrar_datos();
};

class Cuento : public Lectura{
private:
    string libro_publicado;
public:
    Cuento(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _libro_publicado);
    Cuento();
    ~Cuento();
    void mostrar_datos();
};

class Novela : public Lectura{
protected:
    Generos genero;
public:
    Novela(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, Generos _genero_novela);
    Novela();
    ~Novela();
    void mostrar_datos();
    void mostrar_filtrado_por_genero(Generos genero_a_filtrar);
    string de_enumerado_a_string(Generos genero);
};

class Novela_historica : public Novela{
private:
    char * descripcion;
public:
    Novela_historica(string _tipo_de_lectura,string titulo,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, Generos _genero,char* _descripcion);
    ~Novela_historica();
    void mostrar_datos();
};

#endif