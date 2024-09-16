#include <iostream>
using namespace std;

#include "Revista.h"

Revista :: Revista (string nombre, string isbn, string autor, bool prestado, string numeroEdicion,string mesPublicacion) 
        : MaterialBibliografico(nombre, isbn, autor, prestado)
{
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
    this -> tipo = false;
}

void Revista :: mostrarInformacion() const
{
    cout << "Revista: \n";
    cout << "Nombre: " << nombre << "\n";
    cout << "ISBN: " << isbn << "\n";
    cout << "Autor: " << autor << "\n";
    cout << "Prestado: " << (prestado ? "Si" : "No") << "\n";
    cout << "Numero edicion: " << numeroEdicion << "\n";
    cout << "Mes de publicacion: " << mesPublicacion << endl;
    cout << endl;
}

string Revista :: getExtra1() {return mesPublicacion;} 
string Revista :: getExtra2() {return numeroEdicion;}

Revista :: ~Revista()
{

}