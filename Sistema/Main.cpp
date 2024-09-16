#include <iostream>
using namespace std;

#include "Sistema.h"

void menuMaterial(Sistema* sistema);
void menuBusquedaMaterial(Sistema* sistema);
void menuPrestamosyDevoluciones(Sistema* sistema);
void menuUsuarios(Sistema* sistema);

/** 
 * En la funcion main se inicializa el sistema mandando a cargar los archivos de biblioteca y de usuarios, se encarga de manejar 
 * el menu principal para luego derivar a los demas menus realizando llamados a sus funciones segun lo pida el usuario 
 * (la persona que ejecuta el codigo) esta termina una vez en el menu principal se seleccione el 0 cerrando asi el ciclo 
 * y mandando a destruir al sistema. 
*/
int main()
{
    Sistema* sys = new Sistema();
    
    sys -> cargarBiblioteca();
    sys -> cargarUsuarios();

    cout <<"------------------------------------- \n";
    cout << "¡Bienvenido al sistema de biblioteca! \n";
    cout <<"------------------------------------- \n";
    cout << "\n";

    int opcion;

    do
    {
        cout << "¡Selecciona una de las opciones disponibles! \n";
        cout << "\n";
        cout << "1.-Agregar material a la biblioteca. \n";
        cout << "2.-Materiales disponibles en biblioteca. \n";
        cout << "3.-Buscar material. \n";
        cout << "4.-Prestamo y devolucion de material. \n";
        cout << "5.-Gestionar usuarios. \n";
        cout << "0.-Cerrar sistema de biblioteca. " << endl;
        cout << ">";
        cin >> opcion;
        cin.ignore();

        while (opcion <0 or opcion>5) 
        {
            cout << "\n";
            cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
            cout << ">";
            cin >> opcion;
            cin.ignore();
        }

        cout <<"------------------------------------- \n";

        if (opcion == 1) {menuMaterial(sys);}
        else if (opcion ==2) {sys -> mostrarInfoBiblioteca();}
        else if (opcion ==3) {menuBusquedaMaterial(sys);}
        else if (opcion ==4) {menuPrestamosyDevoluciones(sys);}
        else if (opcion ==5) {menuUsuarios(sys);}

    } while (opcion != 0);
    
    cout <<"          ¡Hasta pronto! \n";
    cout <<"------------------------------------- \n";

    delete sys;
    return 0;
}

/** 
 * Este menu es el encargado de realizar las preguntas necesarias para la creacion de los diferentes 
 * materiales disponibles, realiza llamados a agregarLibro y agregarRevista (funciones del sistema) segun corresponda
*/
void menuMaterial(Sistema* sistema)
{
    int opcion;
    
   cout << "¿Es un libro o una revista? \n";
   cout << "1.-Libro. \n";
   cout << "2.-Revista. \n";
   cout << "0.-Cancelar. \n";
   cout << ">";
   cin >> opcion;
   cin.ignore();

   while (opcion<0 or opcion>2)
   {
        cout << "\n";
        cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
        cout << ">";
        cin >> opcion;
        cin.ignore();
   }

   if (opcion == 0) {return;}

    string nombre;
    string isbn;
    string autor;

    cout << "Titulo del material: \n";
    getline(cin, nombre);

    cout << "ISBN: \n";
    getline(cin, isbn);
    
    cout << "Autor: \n";
    getline(cin, autor);
    
    if (opcion == 1)
    {
        string fechaPubli;
        string resumen;

        cout << "Fecha de publicacion (dia/mes/año): \n";
        getline(cin, fechaPubli);
    
        cout << "Resumen: \n";
        getline(cin, resumen);

        cout << sistema ->agregarLibro(nombre, isbn, autor, fechaPubli, resumen) << endl;
        return;
    }else {

        string fechaPubli;
        string edicion;

        cout << "Mes de publicacion: \n";
        getline(cin, fechaPubli);
    
        cout << "Numero de edicion: \n";
        cin >> edicion;
    
        cout << sistema ->agregarRevista(nombre, isbn, autor, edicion, fechaPubli);
        return;
    }
}

/** 
 * Este menu se encarga de hacer preguntas al usuario para poder identificar cual es el material que esta buscando para asi
 * poder mostrarlo por pantalla (esto lo logra llamando a la funcion buscarMaterialExterno del sistema)
*/
void menuBusquedaMaterial(Sistema* sistema)
{
    int opcion;

    cout << "Desea buscar por titulo o por autor? \n";
    cout << "1.-Titulo. \n";
    cout << "2.-Autor. \n";
    cout << "0.-Cancelar. \n";
    cout << ">";
    cin >> opcion;
    cin.ignore();

    while (opcion<0 or opcion>2)
    {
        cout << "\n";
        cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
        cout << ">";
        cin >> opcion;
        cin.ignore();
    }

    if (opcion == 1)
    {
        string buscar;
        cout << "Ingrese el titulo a buscar: " << endl;
        getline(cin, buscar);
        cout << endl;

        cout << sistema ->buscarMaterialExterno(buscar, "", true);
        cout << endl;
    }

    else if (opcion == 2)
    {
        string buscar;
        cout << "Ingrese el autor a buscar: " << endl;
        getline(cin, buscar);
        cout << endl;

        cout << sistema ->buscarMaterialExterno("", buscar, false);
        cout << endl;
    }
}

/** 
 * Este menu se encarga de pedir los datos del usuario y los de un material para poder realizar el prestamo a este mismo usuario
 * o la devolucion de un material que ya tenga, esta funcion hace llamados a prestamo y a devolucion (funciones del sistema)
*/
void menuPrestamosyDevoluciones(Sistema* sistema)
{
    int opcion1;
    string nombre;
    string variable;

    cout << "¿Desea prestar o devolver material? \n";
    cout << "1.-Prestar. \n";
    cout << "2.-Devolver. \n";
    cout << "0.-Cancelar. \n";
    cout << ">";
    cin >> opcion1;
    cin.ignore();

    if (opcion1 == 0) {return;}

    while (opcion1<0 or opcion1>2)
    {
        cout << "\n";
        cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
        cout << ">";
        cin >> opcion1;
        cin.ignore();
    }

    cout << "Ingrese su nombre o id: ";
    getline(cin, nombre);

    cout << "Ingrese el titulo o el isbn del material: \n";
    cout << ">";
    getline(cin, variable);
    
    if (opcion1 == 1){cout << sistema->prestamo(nombre, nombre ,variable, variable) << endl;}

    else if (opcion1 == 2){cout << sistema->devolucion(nombre, nombre ,variable, variable) << endl;}
    
}

/** 
 * Esta funcion es como un modo de administracion en la que se puede pedir crear, buscar y eliminar usuarios aparte de poder modificar 
 * los materiales de estos, esto lo logra llamando a las funciones del sistema crearEliminar, mostrarUsuario, prestamo y devolucion  
*/
void menuUsuarios (Sistema* sistema)
{
    int opcion;

    cout << "Bienvenido a la gestion de usuarios, estas son las opciones disponibles. \n";
    cout << "1.-Crear Usuario. \n";
    cout << "2.-Eliminar usuario. \n";
    cout << "3.-Buscar usuario. \n";
    cout << "4.-Gestionar materiales de usuario especifico. \n";
    cout << "0.-Cancelar. " << endl;
    cout << ">";
    cin >> opcion;
    cin.ignore();

    while (opcion <0 or opcion>4) 
    {
        cout << "\n";
        cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
        cout << ">";
        cin >> opcion;
        cin.ignore();
    }

    string id;
    string nombre;

    if (opcion == 0){return;}

    else if (opcion == 1 || opcion == 2)
    {
        cout << "Ingrese su Nombre: ";
        getline(cin, nombre);

        cout << "Ingrese su id: ";
        getline(cin, id);

        cout << sistema ->crearEliminar(nombre, id, opcion) << endl;
    }

    else if (opcion == 3)
    {
        cout << "Ingrese su Nombre: \n";
        getline(cin, nombre);

        cout << sistema -> mostrarUsuario(nombre, nombre, true) << endl;
    }

    else if (opcion == 4)
    {
        int opcion2;

        cout << "Ingrese su Nombre o id: \n";
        getline(cin, nombre);

        string existencia = sistema -> mostrarUsuario(nombre, nombre, false);
        cout << sistema -> mostrarUsuario(nombre, nombre, false) << endl;

        if (existencia == "El usuario no existe") {return;}

        cout << "Desea agregar o eliminar materiales: \n";
        cout << "1.-Agregar. \n";
        cout << "2.-Eliminar. \n";
        cout << "0.-Cancelar. \n";
        cout << ">";
        cin >> opcion2; 
        cin.ignore();

        while (opcion2<0 or opcion2>2)
        {
            cout << "\n";
            cout << "¡Tuvimos un problema! esta opcion no existe, reintenta. \n";
            cout << ">";
            cin >> opcion2;
            cin.ignore();
        }

        if (opcion2 == 0) {return;}

        string titulo;

        cout << "Titulo del material o isbn: \n";
        getline(cin, titulo);

        if (opcion2 == 1) {cout << sistema -> prestamo(nombre, nombre, titulo, titulo) << endl;}
        else if (opcion2 == 2) {cout << sistema -> devolucion(nombre, nombre, titulo, titulo) << endl;}
    }
}