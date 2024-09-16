#include <iostream>
#pragma once
using namespace std;

class MaterialBibliografico;

class Usuario
{
    private:
    string nombre;
    string id;
    MaterialBibliografico** materialesPrestados;

    public:
    Usuario(string nombre, string id);
    bool prestarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(MaterialBibliografico* material);
    string getNombre();
    string getId();
    MaterialBibliografico** getMateriales();
    void mostrarMaterialesPrestados();
    ~Usuario();
};