
#ifndef LECTURAS_LECTURA_H
#define LECTURAS_LECTURA_H
#include <string>
using namespace std;
class Lectura {
protected:
    string titulo;
    float tiempo_lectura;
    int anio;
    //Escritor * autor;
    bool leido;
public:
    Lectura ( string titulo, float tiempo_lectura, int anio, Escritor * autor );
    ~Lectura() = default;
    virtual void mostrar () = 0;
    bool get_leido ();
    void set_leido ( bool leido );
    string get_titulo();
    float get_tiempo_lectura();
    int get_anio();
    //Escritor* get_autor();


};


#endif //LECTURAS_LECTURA_H
