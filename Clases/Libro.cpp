#include <iostream>
using namespace std;

#include "Libro.h"

Libro :: Libro (string nombre, string isbn, string autor, bool prestado, string fechaPublicacion, string resumen)
      : MaterialBibliografico (nombre, isbn, autor, prestado)
{
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;
    this -> tipo = true;
}

void Libro :: mostrarInformacion() const
{
    cout << "Libro: " << endl;
    cout << "Nombre: " << nombre << "\n";
    cout << "ISBN: " << isbn << "\n";
    cout << "Autor: " << autor << "\n";
    cout << "Prestado: " << (prestado ? "Si" : "No") << "\n";
    cout << "Fecha de publicacion: " << fechaPublicacion << "\n";
    cout << "Resumen: " << resumen << endl;
    cout << endl;
}

string Libro :: getExtra1() {return fechaPublicacion;}
string Libro :: getExtra2() {return resumen;}

Libro:: ~Libro()
{

};