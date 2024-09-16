#include <iostream>
using namespace std;

#include "Usuario.h"
#include "MaterialBibliografico.h"
 
Usuario :: Usuario (string nombre, string id)
{
    this -> nombre = nombre;
    this -> id = id;
    this -> materialesPrestados = new MaterialBibliografico*[5];

    for (int i = 0; i < 5; i++) {
        materialesPrestados[i] = nullptr;
    }
}

bool Usuario :: prestarMaterial(MaterialBibliografico* material)
{
    for (int i=0 ; i<5 ; i++)
    {
        if (materialesPrestados[i] == nullptr)
        {
            materialesPrestados[i] = material;
            return true;
        }
    }
    return false;
}

bool Usuario :: devolverMaterial(MaterialBibliografico* material)
{
    for (int i=0 ; i<5 ; i++)
    {
        if (materialesPrestados[i] == material)
        {
            materialesPrestados[i] = nullptr;
            return true;
        }
    }
    return false;
}

void Usuario :: mostrarMaterialesPrestados()
{
    for (int i=0 ; i<5 ; i++)
    {
        if (materialesPrestados[i] != nullptr)
        {
            materialesPrestados[i] -> mostrarInformacion();
        }
    }
}

string Usuario :: getNombre(){return nombre;}

string Usuario :: getId() {return id;}

MaterialBibliografico** Usuario :: getMateriales() {return materialesPrestados;}

Usuario :: ~Usuario()
{
    delete[] materialesPrestados;
}