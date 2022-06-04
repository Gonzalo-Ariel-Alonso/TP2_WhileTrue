#include "Menu.h"

Menu::Menu(string archivo_escritores, string archivo_lecturas){
  Archivos manejo_archivos(&lista_de_escritores, &lista_de_lecturas, archivo_escritores, archivo_lecturas);
  manejo_archivos.crear_lista_escritores();
  manejo_archivos.crear_lista_lecturas();
  funciones = new Funciones_de_listas(&lista_de_escritores, &lista_de_lecturas);
}

Menu::~Menu(){
  delete funciones;
}

void Menu::opciones_interfaz(int opcion){
  switch (opcion){
    case 1:
      funciones->agregar_lectura();
      break;
    case 2:
      funciones->quitar_lectura();
      break;
    case 3:
      funciones->agregar_escritor();
      break;
    case 4:
      funciones->modificar_ano_fallecimiento_escritor();
      break;
    case 5:
      funciones->listar_escritores();
      cout << endl;
      break;
    case 6:
      funciones->sortear_lectura();
      break;
    case 7:
      funciones->listar_lecturas();
      break;
    case 8:
      funciones->listar_lectura_filtrada_por_ano();
      break;
    case 9:
      funciones->listar_lecturas_filtrado_por_escritor();
      break;
    case 10:
      funciones->listar_lecturas_filtradas_por_genero();
      break;
    case 11://COLA
      cargar_cola_ordenada();
      leer_una_lectura_cola();
      break;
    case 12:
      cout << "Saludos" << endl;
      break;

    default:
      cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
      validar_entrada(opcion,1,12);
      break;
  }
}



void Menu::mostrar_menu(){
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

int Menu::ingresar_opciones_interfaz(){
  int opcion = 15;
  cin >> opcion ;
  return opcion;
}

bool Menu::validar_entrada(int entrada,int parametro_minimo,int parametro_maximo){
    bool continuar = true;
    if (parametro_minimo > entrada || entrada > parametro_maximo || cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.sync();
        continuar = false;
        }
    return continuar;
}


void Menu::interfaz_usuario_con_ingreso(){
  int selector;
  while (selector != 12){
    mostrar_menu();
    selector = ingresar_opciones_interfaz();
    opciones_interfaz(selector);
  }

}

void Menu::cargar_cola_ordenada(){
  int cantidad_datos = lista_de_lecturas.obtener_cantidad();
  for(int i = 1; i <= cantidad_datos; i++){
    Lectura * lectura_actual = lista_de_lecturas.consulta(i);
    if ( !(lectura_actual->get_leido()) ){
      cola_ordenada.alta(lista_de_lecturas.consulta(i));
    }
  }
  cola_ordenada.cola_sort();

}

void Menu::leer_una_lectura_cola(){

  string opcion = "H";
  while (opcion != "S" && opcion != "N"){
      system("clear");
      cout << "Quiere leer una lectura de la cola ? S/N"<< endl;
      cout << "Elegir S o N: ...";
      cin >> opcion;
  }
  if (opcion == "S"){
    Lectura * lectura_leer = cola_ordenada.consulta();
    cout << "La lectura mas corta a leer es:" << endl;
    lectura_leer->mostrar();
    lectura_leer->set_leido(true);
    cola_ordenada.baja();
    cout << endl;
    cout << endl;
  }

}
