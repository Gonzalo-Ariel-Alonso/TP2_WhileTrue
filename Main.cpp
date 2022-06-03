#include <iostream>

#include "Menu.h"
using namespace std;

int main(){
  Menu un_menu("escritores.txt", "lecturas.txt");
  un_menu.opciones_interfaz(5);
  un_menu.opciones_interfaz(7);


  return 0;
}
