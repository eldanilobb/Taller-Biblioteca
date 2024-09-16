#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

#include "../Clases/MaterialBibliografico.h"
#include "../Clases/Libro.h"
#include "../Clases/Revista.h"
#include "../Clases/Usuario.h"
#include "Sistema.h"

Sistema :: Sistema(){
    for (int i=0 ; i<100 ; i++)
    {
        biblioteca[i] = nullptr;
    }

     for (int i=0 ; i<50 ; i++)
    {
        Usuarios[i] = nullptr;
    }
    
}

void Sistema :: cargarBiblioteca()
{
    ifstream archivo("Sistema/Biblioteca.txt");
    string linea;
    int posicion = 0;

     if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo carga biblioteca" << endl;
        return;
    }

    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string nombre, isbn, autor, prestado, extra1, extra2, tipo;

        bool prestacion = false;

        getline(ss, tipo, ';');
        getline(ss, nombre, ';');
        getline(ss, isbn, ';');
        getline(ss, autor, ';');
        getline(ss, prestado, ';');
        getline(ss, extra1, ';');
        getline(ss, extra2, ';');

        if (prestado == "Sí") {prestacion = true;}
        if (tipo == "Libro") {biblioteca[posicion] = new Libro(nombre, isbn, autor, prestacion, extra1, extra2);}
        if (tipo == "Revista") {biblioteca[posicion] = new Revista(nombre, isbn, autor, prestacion, extra2, extra1);}
        posicion++;
    }

    archivo.close();
}

void Sistema :: cargarUsuarios()
{
    ifstream archivo("Sistema/Usuarios.txt");

    int contador = 0;
    string linea;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de usuarios" << endl;
        return;
    }


    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string id, nombre, isbnT;

        getline(ss, id, ';');
        getline(ss, nombre, ';');

        Usuarios[contador] = new Usuario(nombre, id); 
        while (getline(ss, isbnT, ';'))
        {
            MaterialBibliografico* buscado = buscarMaterialInterno(isbnT, "", "");

            if (buscado != nullptr and buscado -> getEstado() == true )
            {
                Usuarios[contador] -> prestarMaterial(buscado);
                buscado -> setEstado(true);
            }

        }
        contador++;
    }
}

void Sistema :: mostrarInfoBiblioteca()
{
    for (MaterialBibliografico* material : biblioteca)
    {
        if (material != nullptr)
        {
            material -> mostrarInformacion();
        }
    }
}

string Sistema :: mostrarUsuario(string nombre, string id, bool tipo)
{
    Usuario* encontrado = buscarUsuario(nombre, id);

    if (encontrado == nullptr) {return "El usuario no existe";}

    string entregar;
    bool tieneMaterial = false;

    if (tipo == true) {entregar += "ID: " + encontrado -> getId() + "\n";}

    MaterialBibliografico** material = encontrado -> getMateriales();

    for (int i=0 ; i<5 ; i++)
    {
        if (material[i] != nullptr)
        {   
            if (tieneMaterial == false){entregar += "Materiales asociados: \n";}

            tieneMaterial = true;

            entregar += "Titulo: " + material[i] -> getTitulo()  + ", " + "Isbn: " + material[i] -> getIsbn() + "\n";
        }
    }
    
    if (tieneMaterial == false){entregar += "No tiene materiales \n";}

    return entregar;
}

string Sistema :: agregarLibro(string nombre,string isbn,string autor,string fechaPubli,string resumen)
{
    if (biblioteca[99] != nullptr) { return "Error, la biblioteca esta llena. \n"; }

    for (MaterialBibliografico*& material : biblioteca)
    {
        if(material == nullptr)
        {
            material = new Libro(nombre, isbn, autor, false, fechaPubli, resumen);

            ofstream archivo ("Sistema/Biblioteca.txt", ios::app);

            string agregar = "\nLibro;" + nombre + ";" + isbn + ";" + autor + ";" + "No" + ";" + fechaPubli + ";" + resumen;
            archivo << agregar;
            archivo.close();

            return "Libro agregado exitosamente \n";
        }
    }
    return "El libro no se pudo agregar \n";
}

string Sistema :: agregarRevista(string nombre,string isbn,string autor, string edicion, string mes)
{
    if (biblioteca[99] != nullptr) { return "Error, la biblioteca esta llena. \n"; }

    for (MaterialBibliografico*& material : biblioteca)
    {
         if(material == nullptr)
        {
            material = new Revista(nombre, isbn, autor, false, edicion, mes);

            ofstream archivo ("Sistema/Biblioteca.txt", ios::app);
            string agregar = "\nRevista;" + nombre + ";" + isbn + ";" + autor + ";" + "No" + ";" + mes + ";" + edicion;
            archivo << agregar;
            archivo.close();

            return "Revista agregada exitosamente \n";
        }
    }  
    return "La revista no se pudo agregar";
}

string Sistema :: buscarMaterialExterno(string titulo, string autor, bool tipoBusqueda)
{
    //Si es true sera por titulo, false sera por autor.
    string entregable = "Material encontrado: \n";
    bool encontrado = false;
    MaterialBibliografico* material = buscarMaterialInterno("", titulo, autor);

    if (tipoBusqueda == true)
    {
            if (material == nullptr) {return "No existe un material con la informacion entregada";}

            bool estado = material -> getEstado(); 

            entregable += "Autor: " + material -> getAutor() + "\n";
            entregable += "ISBN: " + material -> getIsbn() + "\n";
                
            entregable += "Estado: " + (estado ? string("Prestado") : string("Disponible")) + "\n";
        
             return entregable;
        
    }

    if(tipoBusqueda == false)
    {
        if (material == nullptr) {return "No existe un material con la informacion entregada";}
            
            if (material == nullptr) {return (encontrado ? entregable : "No existe un material con la informacion entregada");}
                
            encontrado = true;

            bool estado = material -> getEstado(); 

            entregable += "Titulo: " + material -> getTitulo() + "\n";
            entregable += "ISBN: " + material -> getIsbn() + "\n";
            entregable += "Estado: " + (estado ? string("Prestado") : string("Disponible")) + "\n";
        
            return entregable;
    }

    return "No existe un material con la informacion entregada";
}

string Sistema :: prestamo(string persona,string id ,string titulo, string isbn)
{
    Usuario* usuarioEncontrado = buscarUsuario(persona, id);
    MaterialBibliografico* materialEncontrado = buscarMaterialInterno(isbn, titulo, "");

    if (usuarioEncontrado == nullptr) {return "El usuario no existe";}
    if (materialEncontrado == nullptr) {return "El material no existe";}

    if (materialEncontrado -> getEstado() == true) {return "El material ya esta prestado";}

    if(usuarioEncontrado -> prestarMaterial(materialEncontrado) == true)
    {
        materialEncontrado -> setEstado(true);
        return "El material fue añadido correctamente a la cuenta";
    }
    return "Tiene el numero maximo de materiales prestados";
}

string Sistema :: devolucion(string persona,string id ,string titulo, string isbn)
{
    Usuario* usuarioEncontrado = buscarUsuario(persona, id);
    MaterialBibliografico* materialEncontrado = buscarMaterialInterno(isbn, titulo, "");

    if (usuarioEncontrado == nullptr) {return "El usuario no existe";}
    if (materialEncontrado == nullptr) {return "El material no existe";}

    if (materialEncontrado -> getEstado() == false) {return "El material no esta en prestamo actualmente";}

    if(usuarioEncontrado -> devolverMaterial(materialEncontrado) == true)
    {
        materialEncontrado -> setEstado(false);
        return "El material fue eliminado correctamente de su cuenta";
    }
    return "No tiene ningun material que devolver o el material no es de este usuario";
}

string Sistema :: crearEliminar(string nombre, string id, int modo)
{
    Usuario* encontrado = buscarUsuario(nombre, id);

    if (modo == 1) //Creacion de usuario
    {
        if (encontrado != nullptr) {return "Este usuario ya existe.";}

        for (Usuario*& usuario : Usuarios)
        {
            if (usuario == nullptr)
            {
                usuario = new Usuario(nombre, id);

                return "Usuario creado con exito";
            }
        }
    }

    if (modo == 2) //Eliminacion de usuario
    {
        if (encontrado == nullptr) {return "El usuario no existe en los registros.";}

        for (Usuario*& usuario : Usuarios)
        {
            if (usuario == encontrado)
            {
                delete usuario;
                usuario = nullptr;
                return "El usuario fue eliminado con exito";
            }
        }
    }
    return "Error inesperado.";
}

MaterialBibliografico* Sistema :: buscarMaterialInterno(string isbn, string titulo, string autor)
{
    for (MaterialBibliografico*& material : biblioteca)
    {
        if (material == nullptr) {return nullptr;}

        if (material -> getIsbn() == isbn) {return material;}

        if (normalizarString(material->getTitulo()) == normalizarString(titulo)) {return material;}

        if (normalizarString(material->getAutor()) == normalizarString(autor)) {return material;}
    }
    return nullptr;
}

string Sistema :: normalizarString(const string& entrada) 
{
    string salida;

    for (char s : entrada) 
    {
        if (!isspace(s)) 
        { 
            salida += tolower(s);
        }
    }

    return salida;
}

Usuario* Sistema :: buscarUsuario(string usuario, string id)
{
    for(Usuario* actual : Usuarios)
    {
        if (actual!=nullptr)
        {
            if (normalizarString(actual -> getNombre()) == normalizarString(usuario) || normalizarString(actual -> getId()) == id)
            {
                return actual;
            }
        }
    }

    return nullptr;
}

void Sistema :: guardarDatos()
{
    ofstream usuarioSalida("Sistema/Usuarios.txt");

    for (Usuario* usuario : Usuarios) 
    {
        string guardar;

        if (usuario != nullptr) 
        {
            guardar += usuario -> getId() + ";";
            guardar += usuario -> getNombre() ;
            MaterialBibliografico** materiales = usuario -> getMateriales();

            for (int i=0 ; i<5 ; i++)
            {
                if (materiales[i] != nullptr)
                {
                        guardar += ";" + materiales[i] -> getIsbn();
                }
            }

            usuarioSalida << guardar << "\n";
        }
    }

    usuarioSalida.close();

    ofstream bibliotecaSalida("Sistema/Biblioteca.txt");

    for(MaterialBibliografico* materialTemporal : biblioteca)
    {
        string guardar;

        if (materialTemporal != nullptr)
        {
            if (materialTemporal -> getTipo() == true) {guardar += "Libro;";}
            else {guardar += "Revista;";}

            guardar += materialTemporal -> getTitulo();
            guardar += ";" + materialTemporal -> getIsbn();
            guardar += ";" + materialTemporal -> getAutor();
            
            if (materialTemporal -> getEstado() == true){guardar += ";Sí";}
            else {guardar += ";No";}

            guardar += ";" + materialTemporal -> getExtra1();
            guardar += ";" + materialTemporal -> getExtra2();

            bibliotecaSalida << guardar << "\n";
        }
    }

    bibliotecaSalida.close();
}

Sistema :: ~Sistema()
{
    guardarDatos();

    for (int i=0 ; i<50 ; i++)
    {
        delete Usuarios[i];
    }

    for (int i=0 ; i<100 ; i++)
    {
        delete biblioteca[i];
    }

}