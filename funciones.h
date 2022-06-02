#include "Lista.h"
#include "Escritor.h"
#include "Lecturas_y_subtipos.h"
//Pre:-
//Post: Muestra el menu del programa

void mostrar_menu();//listo

void quitar_lectura_de_una_lista(Lista<Escritor> * lista_de_escritores);//listo


void crear_lista_escritores(Lista<Escritor> * lista_de_escritores);//listo

void listar_escritores(Lista<Escritor> * lista_escritores);//listo

void agregar_escritor(Lista<Escritor> *Lista_de_escritores);//listo

void mostrar_nombre_y_fallecimiento_escritor(Lista<Escritor>* lista_de_escritores);//listo

void modificar_anio_fallecimiento_escritor(Lista<Escritor> * lista_de_escritores);//listo

//Lectura sortear_una_lectura(Lista<Escritor> * lista_de_escritores);//falta

void listar_novelas_por_genero(Lista<Escritor> * lista_de_escritores);//falta

void listar_lecturas(Lista<Escritor> * lista_de_escritores);//falta

void cambiar_dato_escritor(Lista<Escritor> * lista_de_escritores);//falta

bool validar_entrada(int entrada,int parametro_minimo,int parametro_maximo);

void quitar_lectura(Lista<Lectura*>* lista_de_lecturas);

int comparar(int anio_lectura_actual, Lista<Lectura*>* lista_de_lecturas);

void listar_lecturas(Lista<Lectura*>* lista_de_lecturas);

void listar_lectura_filtrada_por_ano(Lista<Lectura*>* lista_de_lecturas);

void listar_lecturas_filtrado_por_escritor(Lista<Lectura*>* lista_de_lecturas,Lista<Escritor> * lista_de_escritores);

Generos de_string_a_enumerado(string genero_string);