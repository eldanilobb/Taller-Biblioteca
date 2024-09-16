#include <iostream>
#pragma once
using namespace std;

#include "MaterialBibliografico.h"


/** 
 * Esta clase hereda de material bibliografico, por herencia incluye titulo, isbn, autor, tipo
 * y un estado de prestamo (un booleano), por si misma agrega a la herencia numero de edicion
 * y el mes de publicacion de la revista 
*/
class Revista :  public MaterialBibliografico
{
    private:
    string numeroEdicion;
    string mesPublicacion;
    
    public:

    /** 
     * Constructor, se encarga de asignar los atributos propios y los de su clase padre,tambien setea un 
     * booleano en true que indica que es un libro, no devuelve nada.
     * 
     * @param nombre titulo del libro
     * @param isbn codigo del libro
     * @param autor autor del libro
     * @param prestado booleano (True = prestado, False = no esta en prestamo)
     * @param numeroEdicion indica el numero de edicion de la revista (aunque diga numero es un string)
     * @param resumen una oracion o parrafo corta sobre lo que sucede en el libro
    */
    Revista(string nombre, string isbn, string autor, bool prestado, string numeroEdicion,string mesPublicacion);

    /** 
     * @return mes de publicacion
    */
    string getExtra1();

    /** 
     * @return numero de edicion de la revista
    */
    string getExtra2();

    /** 
     * Esta funcion es una version propia de mostrarInformacion en la que imprime
     * todos sus datos digase titulo, isbn, autor, estado, mes de publicacion y numero de edicion 
    */
    void mostrarInformacion() const;

    /** 
     * Esto se encarga de destruir la instancia de revista y la instancia de materialBibliografico asociado a ella
    */
    ~Revista();
};