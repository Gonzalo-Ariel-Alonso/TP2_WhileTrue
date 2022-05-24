#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"

using namespace std;



int main(){
    int selector = 0;
    Lista lista_de_escritores;
    crear_lista_escritores(&lista_de_escritores);

    while (selector != 12){
        mostrar_menu();
        cin >> selector;
        switch (selector){

        case 3:
            agregar_escritor(&lista_de_escritores);
            cout << "Escritor agregardo papa" << endl;
            break;
        case 5:
            listar_escritores(&lista_de_escritores);
            system("pause");
            cout << endl;
            break;
        case 12:
            cout << "Adios!" << endl << endl;
            break;
        default:
            cout << "Opcion en invalida. Intentelo de nuevo" << endl << endl;
            break;
        }
    }

    return 0;
}

