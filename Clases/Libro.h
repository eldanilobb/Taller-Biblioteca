#include <iostream>
#pragma once
using namespace std;

#include "MaterialBibliografico.h"

class Libro: public MaterialBibliografico
{
    private:
    string fechaPublicacion;
    string resumen;

    public:
    Libro(string nombre, string isbn, string autor, bool prestado, string fechaPublicacion, string resumen);
    string getExtra1();
    string getExtra2();
    void mostrarInformacion() const;
    ~Libro();
};