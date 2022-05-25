#ifndef LECTURAS_Y_SUBTIPOS_H
#define LECTURAS_Y_SUBTIPOS_H

#include <iostream>
#include "Escritor.h"

using namespace std;

class Lectura{
protected:
    char tipo_de_lectura;
    string titulo;
    int duracion_lectura; // en minutos
    int anio_publicacion;
    Escritor * autor;
public:
    Lectura(char _tipo_de_lectura,int _duracion_lectura,int _anio_publicacion,Escritor * _autor);
    ~Lectura();
    void virtual mostrar_datos() = 0;
    void mostar_filtrado_por_anios(int anio_inicial,int anio_final);
    void mostar_filtrado_por_escritor(string esritor_a_filtrar);
};


class Poema : public Lectura{
private:
    int cantidad_versos;
public:
    Poema(char _tipo_de_lectura,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, int _cantidad_versos);
    ~Poema();
    void mostrar_datos();
};

class Cuento : public Lectura{
private:
    string libro_publicado;
public:
    Cuento(char _tipo_de_lectura,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _libro_publicado);
    ~Cuento();
    void mostrar_datos();
};

class Novela : public Lectura{
protected:
    string genero;
public:
    Novela(char _tipo_de_lectura,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _genero);
    ~Novela();
    void mostrar_datos();
    void  mostar_filtrado_por_genero(string genero_a_filtrar);
};

class Novela_historica : public Novela{
private:
    char * descripcion;
public:
    Novela_historica(char _tipo_de_lectura,int _duracion_lectura,int _anio_publicacion,Escritor * _autor, string _genero,char* _descripcion);
    ~Novela_historica();
    void mostrar_datos();
};

#endif