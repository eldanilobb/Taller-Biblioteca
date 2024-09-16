#include <iostream>
using namespace std;

#include "MaterialBibliografico.h"

MaterialBibliografico :: MaterialBibliografico(){}

MaterialBibliografico :: MaterialBibliografico (string nombre, string isbn, string autor, bool prestado)
{
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->prestado = prestado;
}
void MaterialBibliografico :: mostrarInformacion() const
{
    cout << "Nombre: " << nombre << "\n";
    cout << "ISBN: " << isbn << "\n";
    cout << "Autor: " << autor << "\n";
    cout << "Prestado: " << (prestado ? "Si" : "No") << endl;

}
string MaterialBibliografico :: getIsbn() {return isbn;}
bool MaterialBibliografico :: getEstado() {return prestado;}
string MaterialBibliografico :: getNombre() {return nombre;}
void MaterialBibliografico :: setEstado(bool estado) {this -> prestado = estado;}
string MaterialBibliografico :: getTitulo() {return nombre;}
string MaterialBibliografico :: getAutor() {return autor;}
bool MaterialBibliografico :: getTipo(){return tipo;}
string MaterialBibliografico :: getExtra1() {return "";}
string MaterialBibliografico :: getExtra2() {return "";}
MaterialBibliografico :: ~MaterialBibliografico()
{
    
}
