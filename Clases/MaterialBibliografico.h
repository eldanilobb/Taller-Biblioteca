#include <iostream>
#pragma once
using namespace std;

class MaterialBibliografico
{
    protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;
    bool tipo;

    public:
    MaterialBibliografico();
    MaterialBibliografico(string nombre, string isbn, string autor, bool prestado);
    string getIsbn();
    string getNombre();
    string getTitulo();
    string getAutor();
    virtual string getExtra1();
    virtual string getExtra2();
    bool getTipo();
    bool getEstado();
    void setEstado(bool estado);
    virtual ~MaterialBibliografico(); 
    virtual void mostrarInformacion() const;
};