#include "Novela.h"

Novela::Novela(char tipo_de_objeto, string titulo, int tiempo_lectura, int anio, Escritor * autor, Generos genero):
Lectura(tipo_de_objeto, titulo, tiempo_lectura, anio, autor) {
    this->genero = genero;
};



void Novela::mostrar(){
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << tiempo_lectura << endl;
    cout << "Año de publicacion: " << anio << endl;
    if (autor != nullptr ){autor->mostrar_datos();}
    cout << "Genero: " << de_enumerado_a_string(genero) << endl;
    //FALTARIA EL ESCRITOR PERO HAY QUE VER CON EL GRUPO
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
