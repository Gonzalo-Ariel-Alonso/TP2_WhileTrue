#include "Funciones_de_listas.h"
Funciones_de_listas::Funciones_de_listas(Lista< Escritor* > * lista_escritores, Lista< Lectura * > * lista_lecturas){
  lista_de_escritores = lista_escritores;
  lista_de_lecturas = lista_lecturas;
}

Funciones_de_listas::~Funciones_de_listas(){
  lista_de_escritores = 0;
  lista_de_lecturas = 0;
}

void Funciones_de_listas::listar_escritores(){
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    for (int pos = 1; pos <= cantidad_escritores; pos++){
            Escritor * aux = lista_de_escritores->consulta(pos);
            aux->mostrar_datos();
            cout << endl;
    }
}

void Funciones_de_listas::listar_lecturas(){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    for (int pos = 1; pos <= cantidad_lecturas; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        _lectura->mostrar();
        cout << endl;
    }
}


void Funciones_de_listas::agregar_escritor(){
    int ultima_posicion = lista_de_escritores->obtener_cantidad() + 1;
    string referencia_escritor = "("+to_string(ultima_posicion)+")";
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;
    cout << "Ingrese el nombre y apellido del escritor que quiere agregar: ";
    getline(cin>>ws,nombre);
    cout << "Nacionalidad: ";
    getline(cin,nacionalidad);
    cout << "Anio de nacimiento, escriba 0 si es desconocido: ";
    cin >> anio_nacimiento;
    cout << "Anio de fallecimiento, escriba 0 si es desconocido: ";
    cin >> anio_fallecimiento;


    Escritor* ref = new Escritor(referencia_escritor,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
    lista_de_escritores->alta(ref,ultima_posicion);

    cout << "Usted agrego el escritor: " << endl;
    lista_de_escritores->consulta(ultima_posicion)->mostrar_datos();
}

void Funciones_de_listas::ingresos_usuario(string* ref_lectura, string* titulo, int* duracion, int* ano  ){
  //INTERFAZ USUARIO CON INGRESOS

  while ( *ref_lectura != "1" && *ref_lectura != "2" && *ref_lectura != "3" && *ref_lectura != "4" ){
    cout << "Ingrese el tipo de lectura que desea agregar: " << endl;
    cout << "1 - Cuento " << endl << "2 - Poema " << endl <<"3 - Novela"<< endl << "4 - Novela historica " << endl;
    cout << "Ingresando : ... ";
    cin >> (*ref_lectura);
  }

  cout << "Ingrese el titulo de la lectura: ";
  cin >> (*titulo);
  cout << "Ingrese la duracion estimada de la lectura en minutos: ";
  cin >> (*duracion);
  cout << "Ingrese el año de su publicacion: ";
  cin >> (*ano);

}
void Funciones_de_listas::catalogo_escritores(){
  int longitud_lista =lista_de_escritores->obtener_cantidad();
  for (int pos = 1 ; pos <= longitud_lista ; pos++){
      cout << lista_de_escritores->consulta(pos)->obtener_referencia() << " " << lista_de_escritores->consulta(pos)->devolver_nombre() << endl;
  }

}

Escritor* Funciones_de_listas::ingreso_autor(){
  int referencia_autor ;
  Escritor* escritor_ingresado;
  cout << "Ingrese la referencia al autor que pertenece la novela o digite 0 si es desconocido." << endl;
  catalogo_escritores();
  cin >> referencia_autor;
  if (referencia_autor == 0){
    int opcion;
    cout << "1- Dejarlo desconocido" << endl;
    cout << "2- Agregar el escritor" << endl;
    while(opcion != 1 && opcion != 2){
      cout << "Elegir: ... ";
      cin >> opcion;
    }
    if (opcion == 1){
      escritor_ingresado = nullptr;
    }
    else if(opcion == 2){

      agregar_escritor();
      int ultima_posicion = lista_de_escritores->obtener_cantidad();
      escritor_ingresado = lista_de_escritores->consulta(ultima_posicion);
    }
  }
  else{
    system("clear");
    while (0 > referencia_autor || referencia_autor > lista_de_escritores->obtener_cantidad()){
        catalogo_escritores();
        cin >> referencia_autor;
        system("clear");
    }
    escritor_ingresado = lista_de_escritores->consulta(referencia_autor);
  }

  return escritor_ingresado;
}

int Funciones_de_listas::comparar(int anio_lectura_actual){
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

Generos Funciones_de_listas::de_string_a_enumerado(string genero_string){
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





void Funciones_de_listas::agregar_lectura(){
  string tipo_de_lectura, titulo;
  int duracion_lectura, ano_publicacion;
  int posicion;
  string referencia_tipo_lectura;

  Escritor * autor;

  ingresos_usuario(&referencia_tipo_lectura, &titulo, &duracion_lectura, &ano_publicacion);
  autor = ingreso_autor();

  posicion = comparar(ano_publicacion);

  if (referencia_tipo_lectura == "1"){
    string cuento_libro_publicado;
    cout << "Ingrese el libro donde fue publicado el cuento" << endl;
    cin >> cuento_libro_publicado;
    Cuento * Nuevo_cuento = new Cuento('C',titulo,duracion_lectura,ano_publicacion,autor,cuento_libro_publicado);
    lista_de_lecturas->alta(Nuevo_cuento,posicion);
  }
  else if (referencia_tipo_lectura == "2"){
    int cantidad_de_versos;
    cout << "Ingrese la cantidad de versos del poema" << endl;
    cin >> cantidad_de_versos;
    Poema * Nuevo_poema = new Poema('P',titulo,duracion_lectura,ano_publicacion,autor,cantidad_de_versos);
    lista_de_lecturas->alta(Nuevo_poema,posicion);
  }

  else{
    string genero_string;
    Generos genero;
    cout << "Ingrese el genero de la novela" << endl;
    cin >> genero_string;
    genero = de_string_a_enumerado(genero_string);
    if(genero == HISTORICA){
        string tema_novela_historica;
        cout << "Describa en pocas palabras el tema de la novela historica" << endl;
        cin >> tema_novela_historica;
        Novela_historica * Nueva_NH = new Novela_historica('N',titulo,duracion_lectura,ano_publicacion,autor,genero,tema_novela_historica);
        lista_de_lecturas->alta(Nueva_NH,posicion);
    }
    else{
        Novela *Nueva_novela = new Novela('N',titulo,duracion_lectura,ano_publicacion,autor,genero);
        lista_de_lecturas->alta(Nueva_novela,posicion);
    }

  }
}

void Funciones_de_listas::catalogo_lecturas(){
  int longitud_lista = lista_de_lecturas->obtener_cantidad();
  for (int pos = 1; pos <= longitud_lista  ; pos++){
      cout << pos << " - " << lista_de_lecturas->consulta(pos)->get_titulo() << endl;
  }
}

void Funciones_de_listas::quitar_lectura(){
    int pos;
    catalogo_lecturas();
    cout << "Digite el numero de referencia de la lectura que desea eliminar" << endl;
    while (1 > pos || pos > lista_de_lecturas->obtener_cantidad()){
        cin >> pos;
    }
    lista_de_lecturas->baja(pos);
    cout << "Lectura eliminada con exito" << endl << endl;
}



void Funciones_de_listas::mostrar_nombre_y_fallecimiento_escritor(){
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    for (int pos = 1 ; pos <= cantidad_escritores; pos++){
        cout << pos << " - ";
        lista_de_escritores->consulta(pos)->mostrar_nombre_y_fallecimiento();
    }
}

void Funciones_de_listas::modificar_ano_fallecimiento_escritor(){
    int pos_escritor;
    string fecha_fallecimiento_nueva;
    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    mostrar_nombre_y_fallecimiento_escritor();
    cout << "Digite el numero del escritor que desea cambiarle la fecha de fallecimiento o precione 0 para volver al menu" << endl;
    cin >> pos_escritor;
    if(pos_escritor <= cantidad_escritores && pos_escritor != 0){
        cout << "Digite fecha de fallecimiento del escritor" << endl;
        cin >> fecha_fallecimiento_nueva;
        Escritor * aux = lista_de_escritores->consulta(pos_escritor);
        aux->modificar_anio_fallecimiento(fecha_fallecimiento_nueva);
        system("clear");
        cout << "Fecha de fallecimiento modificada con exito"<< endl;
    }
    else if (pos_escritor > cantidad_escritores && pos_escritor != 0 ){
        system("clear");
        cout << "Escritor inexistente" << endl;
    }
}

void Funciones_de_listas::sortear_lectura(){
  int numero_random;
  numero_random = 1 + rand() % (lista_de_lecturas->obtener_cantidad() - 1 + 1);
  cout << "Su lectura de la suerte es: " << endl;
  lista_de_lecturas->consulta(numero_random)->mostrar();
}


void Funciones_de_listas::listar_lectura_filtrada_por_ano(){
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();

    int ano_inicial, ano_final;

    cout << "Ingrece el ano inicial para filtrar" << endl;
    cin >> ano_inicial;
    ano_final = ano_inicial -1;
    while (ano_final < ano_inicial){
      cout << "Ingrese el ano final" << endl;
      cin >> ano_final;
    }
    bool una_lectura_filtrada = false;
    for (int pos = 1 ; pos <= cantidad_lecturas ; pos++){
        Lectura * _lectura;
        _lectura = lista_de_lecturas->consulta(pos);
        if(ano_inicial <= _lectura->get_anio() && _lectura->get_anio() <= ano_final){
            _lectura->mostrar();
            cout << endl;
            una_lectura_filtrada = true;
        }
    }
    if (!una_lectura_filtrada){
        cout << "No hay ninguna lectura entre los anos filtrados" << endl;
    }

}

void Funciones_de_listas::listar_lecturas_filtrado_por_escritor(){
    int referencia_escritor = 0; //para que entre al while

    Escritor* aux;
    cout << "Digite el parametro del escritor del cual quiere ver sus lecturas: " << endl;
    catalogo_escritores();

    int cantidad_escritores = lista_de_escritores->obtener_cantidad();
    while ( referencia_escritor < 1  ||  referencia_escritor > cantidad_escritores ){
        cin >> referencia_escritor;
    }
    aux = lista_de_escritores->consulta(referencia_escritor);
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    for (int pos = 1; pos <= cantidad_lecturas; pos++){
        lista_de_lecturas->consulta(pos)->mostar_filtrado_por_escritor(aux);
    }
}


void Funciones_de_listas::listar_lecturas_filtradas_por_genero(){
    Generos genero_a_filtrar;
    int referencia_genero_a_filtrar = 0;
    int cantidad_de_generos = 7;


    while ( referencia_genero_a_filtrar < 1  ||  referencia_genero_a_filtrar > cantidad_de_generos){
        cout << "Ingrese la referencia del genero que desea filtrar: "<< endl;
        cout << "1 - DRAMA \n2 - COMEDIA\n3 - FICCION\n4 - SUSPENSO\n5 - TERROR\n6 - ROMANTICA\n7 - HISTORICA\n";
        cin >>  referencia_genero_a_filtrar;
    }
    genero_a_filtrar = static_cast<Generos>(referencia_genero_a_filtrar);
    int cantidad_lecturas = lista_de_lecturas->obtener_cantidad();
    for(int pos = 1; pos <= cantidad_lecturas ; pos++){
        lista_de_lecturas->consulta(pos)->mostrar_filtrado_por_genero(genero_a_filtrar);

    }
}
