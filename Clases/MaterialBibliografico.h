#include <iostream>
#pragma once
using namespace std;


/**
 * Clase padre de Libro y de Revista, tiene nombre, isbn, autor, estado (si esta prestado o no) y tipo
 * aunque esta ultima es mas bien para la diferenciacion de libro y revista no para materialBibliografico en si ya 
 * que al fin y al cabo esta clase no sera instanciada mas alla de la enlazada al crear libro y revista.
*/
class MaterialBibliografico
{
    protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;
    bool tipo;

    public:

    /**
     * Constructor, toma las variables y las asigna en su posicion respectiva no retorna nada 
     * 
     * @param nombre titulo del material
     * @param isbn codigo del material
     * @param autor autor del material
     * @param prestado booleano (True = prestado, False = No esta prestado)
    */
    MaterialBibliografico(string nombre, string isbn, string autor, bool prestado);

    /** 
     * @return isbn del material
    */
    string getIsbn();

    /** 
     * @return titulo del material
    */
    string getTitulo();

    /** 
     * @return autor del material
    */
    string getAutor();

    /** 
     * Genera una funcion virtual para que revista y libro puedan devolver sus datos propios
     * por eso es virtual, en el caso de materialBibliografico no retorna nada
    */
    virtual string getExtra1();

    /** 
     * Genera una funcion virtual para que revista y libro puedan devolver sus datos propios
     * por eso es virtual, en el caso de materialBibliografico no retorna nada
    */
    virtual string getExtra2();

    /** 
     * @return el tipo en forma de booleano (True = libro, False = Revista)
    */
    bool getTipo();

    /** 
     * @return estado del material (True = prestado, False = no esta en prestamo)
    */
    bool getEstado();

    /** 
     * cambia el estado del materialen base al parametro
     * 
     * @param estado (True = prestado, False = no esta en prestamo)
    */
    void setEstado(bool estado);

    /** 
     * Este es el destructor, simplemente se destruye a si mismo
    */
    virtual ~MaterialBibliografico(); 

    /** 
     * Funcion que no retorna nada, se encarga se imprimir por pantalla las caracteristicas del material
     * es virtual para que libro y revista puedan generar sus propias impresiones de caracteristicas
    */
    virtual void mostrarInformacion() const;
};