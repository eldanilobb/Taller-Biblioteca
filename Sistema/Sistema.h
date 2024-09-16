#include <iostream>
using namespace std;

#include "../Clases/MaterialBibliografico.h"
#include "../Clases/Usuario.h"

class Sistema
{
    private:
    MaterialBibliografico* biblioteca[100];
    Usuario* Usuarios[50];

    public:
    Sistema();

    //Llamadas fuera de sistema
    void cargarBiblioteca(); //Listo
    void cargarUsuarios();  //Listo
    void mostrarInfoBiblioteca(); //Listo
    string mostrarUsuario(string nombre, string id, bool tipo); //Listo
    string agregarLibro(string nombre,string isbn,string autor,string fechaPubli,string resumen); //Listo
    string agregarRevista(string nombre,string isbn,string autor, string edicion, string mes);  //Listo
    string buscarMaterialExterno(string titulo, string autor, bool tipoBusqueda);//Listo
    string prestamo(string persona, string id, string titulo, string isbn); //Listo
    string devolucion(string persona,string id ,string titulo, string isbn); //Listo
    string crearEliminar(string nombre, string id, int modo); //Listo 

    //Llamadas dentro de sistema
    MaterialBibliografico* buscarMaterialInterno(string isbn, string titulo, string autor); //Listo
    string normalizarString(const string& entrada);//Listo
    Usuario* buscarUsuario(string nombre,string id); //Listo
    void guardarDatos();

    void mostrarUsuarios(); //Listo pero se debe de borrar
    ~Sistema();

};