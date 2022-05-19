#include<iostream>

#include "Lista.h"
using namespace std;

int main(){
  cout << "arranco" << endl;
  Lista<int> escalera;
  for (int i = 0; i < 10; i++){
    cout<< "agregue" << i << endl;
    escalera.alta(i);

  }
  cout << "imprimo la lista" << endl;
  for (int i = 1; i <= escalera.obtener_cantidad();i++){
    cout << escalera.consulta(i) << endl;
  }
  escalera.alta(55);
  cout << "imprimo la lista" << endl;
  for (int i = 1; i <= escalera.obtener_cantidad();i++){
    cout << escalera.consulta(i) << endl;
  }
  escalera.baja(4);
  cout << "imprimo la lista" << endl;
  for (int i = 1; i <= escalera.obtener_cantidad();i++){
    cout << escalera.consulta(i) << endl;
  }
  escalera.alta(455,3);
  cout << "imprimo la lista" << endl;
  for (int i = 1; i <= escalera.obtener_cantidad();i++){
    cout << escalera.consulta(i) << endl;
  }

  return 0;
}
