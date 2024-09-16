#include <iostream>
#pragma once
using namespace std;

class MaterialBibliografico;

/** 
 * Representa a una persona dentro del sistema, como caracteristicas tiene nombre, id y un array 
 * de doble puntero de tipo MaterialBibliografico
*/
class Usuario
{
    private:
    string nombre;
    string id;
    MaterialBibliografico** materialesPrestados;

    public:

    /** 
     * Constructor de usuario, asigna las variables necesarias y asigna todas las posiciones del array propio a 
     * nullptr
     * 
     * @param nombre nombre del usuario
     * @param id identificacion del usuario (suelen ser del formato 000)
    */
    Usuario(string nombre, string id);

    /** 
     * Funcion encargada de agregar un material dado al array de materiales del usuario
     * 
     * @param material puntero de tipo MaterialBibliografico
     * @return Si se pudo agregar devuelve true, si no se pudo se devuelve false
    */
    bool prestarMaterial(MaterialBibliografico* material);

    /** 
     * Funcion encargada de eliminar un material dado en el array de materiales del usuario
     * 
     * @param material puntero de tipo MaterialBibliografico
     * @return Si se pudo eliminar devuelve true, si no se pudo se devuelve false
    */
    bool devolverMaterial(MaterialBibliografico* material);

    /** 
     * @return nombre del usuario
    */
    string getNombre();

    /** 
     * @return Id del usuario (String)
    */
    string getId();

    /** 
     * @return lista de doble puntero en la que se guardan los materiales del usuario
    */
    MaterialBibliografico** getMateriales();

    /** 
     * Imprime por pantalla los materiales del usuario, devuelve nada.
    */
    void mostrarMaterialesPrestados();

    /** 
     * Destruye el array de materiales del usuario en cuestion aparte de destruir la instancia de usuario en si
    */
    ~Usuario();
};