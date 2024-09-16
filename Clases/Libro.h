#include <iostream>
#pragma once
using namespace std;

#include "MaterialBibliografico.h"

/** 
 * Esta clase hereda de material bibliografico, por herencia incluye titulo, isbn, autor, tipo
 * y un estado de prestamo (un booleano), por si misma agrega a la herencia fecha de publicacion
 * y un resumen 
*/
class Libro: public MaterialBibliografico
{
    private:
    string fechaPublicacion;
    string resumen;

    public:

    /** 
     * Constructor, se encarga de asignar los atributos propios y los de su clase padre,tambien setea un 
     * booleano en true que indica que es un libro, no devuelve nada.
     * 
     * @param nombre titulo del libro
     * @param isbn codigo del libro
     * @param autor autor del libro
     * @param prestado booleano (True = prestado, False = no esta en prestamo)
     * @param fechaPublicacion indica en que fecha se publico (dia/mes/año)
     * @param resumen una oracion o parrafo corta sobre lo que sucede en el libro
    */
    Libro(string nombre, string isbn, string autor, bool prestado, string fechaPublicacion, string resumen);

    /** 
     * Esta funcion se encarga de entregar la fecha de publicacion del libro
     * @return fecha de publicacion
    */
    string getExtra1();

    /** 
     * Esta funcion se encarga de entregar el resumen del libro
     * @return resumen del libro
    */
    string getExtra2();

    /** 
     * Esta funcion es una version propia de mostrarInformacion en la que imprime
     * todos sus datos digase titulo, isbn, autor, estado, fecha de publicacion y resumen 
    */
    void mostrarInformacion() const;

    /** 
     * Esto se encarga de destruir la instancia de libro y la instancia de materialBibliografico asociado a ella
    */
    ~Libro();
};