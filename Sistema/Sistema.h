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

    /**
     * Este es el constructor, al llamarlo llena un array
     * de Material bibliografico de tamaño 100 y un array de Usuario de tamaño 50
     * con nullptr. No recibe ni entrega nada.
    */    
    Sistema();

    /** 
     * Esta funcion lee el texto de datos de los libros y rellena el array de 
     * Material Bibliografico, no recibe ni entrega nada.
    */
    void cargarBiblioteca(); //Listo

    /** 
     * Esta funcion lee el texto de datos de los usuarios y rellena el array de 
     * Usuario creandolos y agregandoles sus libros en posesion, no recibe ni entrega nada.
    */
    void cargarUsuarios();  //Listo

    /** 
     * Esta funcion recorre la lista de Material Bibiografico y solicita a cada material encontrado
     * que muestre su informacion completa, no recibe ni entrega nada.
    */
    void mostrarInfoBiblioteca(); //Listo

    /** 
     * Esta funcion llama a buscarUsuario para confirmar que existe, si es que existe recopila los datos del usuario en un string para luego retornarlo
     * para ser impreso en el main, si no existe entrega un mensaje de error.
     * 
     * @param nombre Nombre del usuario
     * @param id     Id del usuario
     * @param tipo   Indica si se requiere mostrar el id del usuario o no
     * @return String con los datos del usuario
    */
    string mostrarUsuario(string nombre, string id, bool tipo); //Listo

    /** 
     * Esta funcion verifica si es que la biblioteca esta llena, en caso de estarlo retorna un string dando
     * aviso, si no esta llena crea un libro en base a los parametros y lo agrega a la lista.
     * 
     * @param nombre Titulo del libro
     * @param isbn Codigo del libro
     * @param autor autor del libro
     * @param fechaPubli fecha de publicacion del libro (dia/mes/año)
     * @param resumen una oracion resumen del libro
     * @return un string avisando de si el libro fue creado o no indicando la razon
    */
    string agregarLibro(string nombre,string isbn,string autor,string fechaPubli,string resumen); //Listo

    /** 
     * Esta funcion verifica si es que la biblioteca esta llena, en caso de estarlo retorna un string dando
     * aviso, si no esta llena crea una revista en base a los parametros y la agrega a la lista.
     * 
     * 
     * @param nombre Titulo de la revista
     * @param isbn Codigo de la revista
     * @param autor autor de la revista
     * @param edicion numero de edicion de la revista
     * @param mes mes en el que fue publicada la revista
     * @return un string avisando de si la revista fue creada o no indicando la razon
    */
    string agregarRevista(string nombre,string isbn,string autor, string edicion, string mes);  //Listo

    /** 
     * Esta funcion realiza un llamado a buscarMaterialInterno para verificar la existencia de un material
     * en base a su titulo o autor, luego si el material existe recopila sus datos en un string para entregarlo al main, si no 
     * existe solo devuelve un aviso de que no existe automaticamente.
     * 
     * @param titulo Titulo del material
     * @param autor autor del material 
     * @param tipoBusqueda refiere a si se busca por autor o por titulo
     * @return los datos de el material o un error en caso de que no exista
    */
    string buscarMaterialExterno(string titulo, string autor, bool tipoBusqueda);//Listo

    /** 
     * Esta funcion realiza llamados a buscarUsuario y a buscarMaterialInterno para verificar la 
     * existencia de ambos antes de operar, en caso de existir realiza el prestamo al usuario indicado y le 
     * avisa al material que fue prestado cambiando su estado
     * 
     * @param persona nombre del usuario 
     * @param id id del usuario
     * @param titulo titulo del material
     * @param isbn codigo del material
     * @return un string que dice si es que el prestamo se pudo realizar correctamente.
    */
    string prestamo(string persona, string id, string titulo, string isbn); //Listo

    /** 
     * Esta funcion realiza llamados a buscarUsuario y a buscarMaterialInterno para verificar la 
     * existencia de ambos antes de operar, en caso de existir realiza la devolucion del material
     * cambiando su estado y eliminandolo de la lista del usuario.
     * 
     * @param persona nombre del usuario 
     * @param id id del usuario
     * @param titulo titulo del material
     * @param isbn codigo del material
     * @return un string que dice si es que la devolucion se pudo realizar correctamente.
    */
    string devolucion(string persona,string id ,string titulo, string isbn); //Listo

    /** 
     * Esta funcion es la encargada de manejar la creacion y eliminacion de usuarios basandose en su 
     * nombre o id, en el caso de la creacion primero se verifica si es que no existe ya, en caso de la eliminacion
     * primero verifica si es que si quiera existe ambos realizando llamados a buscarUsuario finalmente da aviso 
     * de si la operacion fue exitosa.
     * 
     * @param nombre nombre del usuario
     * @param id id del usuario
     * @param modo variable int (1 indica creacion del usuario, 2 indica eliminacion del usuario)
     * @return string que varia segun la operacion indicando si fue exitosa o si fallo indicando el porque
    */
    string crearEliminar(string nombre, string id, int modo); //Listo 

    /** 
     * Esta funcion se dedica a buscar cualquier tipo de material en el array de biblioteca basandose en su codigo, titulo o autor
     * en realidad solo necesita una de las tres opciones para buscar no es necesario que se introduzcan las tres al mismo tiempo.
     * 
     * @param isbn codigo del material
     * @param titulo titulo del material
     * @param autor autor del material
     * @return un puntero de tipo MaterialBibliografico hacia un material si es que existe, si no devuelve nullptr
    */
    MaterialBibliografico* buscarMaterialInterno(string isbn, string titulo, string autor); //Listo

    /** 
     * Esta funcion se encarga de tomar un string llevandolo a minusculas y quitandole los espacios para
     * facilitar comparaciones
     * 
     * @param entrada el string que se necesite minimizar y quitarle espacios
     * @return el string de entrada pero en minusculas y sin espacios 
    */
    string normalizarString(const string& entrada);//Listo

    /** 
     * Esta funcion se encarga de verificar la existencia de un usuario buscandolo en el array de Usuarios para devolverlo
     * para lo que se necesite, no es necesario tener ambos parametros, con uno ya puede buscar sin problemas
     * 
     * @param nombre nombre del usuario
     * @param id id del usuario
     * @return un puntero de tipo Usuario que referencia a la posicion del usuario en el array
    */
    Usuario* buscarUsuario(string nombre,string id); //Listo

    /** 
     * Esta funcion se dedica unicamente a recorrer la lista de materiales y de usuarios para guardar sus cambios en los diferentes
     * txt, se debe tener en cuenta que reescribe TODO el txt no solo las partes que fueron cambiadas en el transcurso del programa
    */
    void guardarDatos();

    /** 
     * Este es el destructor, primero se encarga de llamar a la funcion guardarDatos para poder mantener la confiabilidad de los mismos 
     * en los txt, luego borra los usuarios de la lista, luego elimina los materiales de la lista. Es importante tener en cuenta que el orden
     * de destruccion esta hecho aproposito, si se borran en otro orden dara errores de segmentacion.
    */
    ~Sistema();

};