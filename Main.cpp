#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "Escritor.h"
#include "funciones.h"

using namespace std;



int main(){
    int selector = 0;
    while (selector != 12){
        mostrar_menu();
        cin >> selector;
        switch (selector){

        case 3:
            cout << "opcion en desarollo" << endl;
            break;
        case 5:
            listar_escritores(crear_lista_escritores());
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

