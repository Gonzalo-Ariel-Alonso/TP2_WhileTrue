#include "Lista.h"
#include "Escritor.h"
//Pre:-
//Post: Muestra el menu del programa

void mostrar_menu();

void crear_lista_escritores(Lista<Escritor> * lista_de_escritores);

void listar_escritores(Lista<Escritor> * lista_escritores);

void agregar_escritor(Lista<Escritor> *Lista_de_escritores);

void mostrar_nombre_y_fallecimiento_escritor(Lista<Escritor>* lista_de_escritores);

void modificar_ano_fallecimiento_escritor(Lista<Escritor> * lista_de_escritores);