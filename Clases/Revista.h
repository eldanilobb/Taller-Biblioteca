#include <iostream>
#pragma once
using namespace std;

#include "MaterialBibliografico.h"

class Revista :  public MaterialBibliografico
{
    private:
    string numeroEdicion;
    string mesPublicacion;
    
    public:
    Revista(string nombre, string isbn, string autor, bool prestado, string numeroEdicion,string mesPublicacion);
    string getExtra1();
    string getExtra2();
    void mostrarInformacion() const;
    ~Revista();
};