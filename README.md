# Taller-Biblioteca
Danilo Alberto Lucero Rivera, 21.548.694-k, danilo.lucero@alumnos.ucn.cl, C2 

Comando de compilacion: g++ -o Programa_Biblioteca Clases/MaterialBibliografico.cpp Clases/Libro.cpp Clases/Revista.cpp Clases/Usuario.cpp Sistema/Sistema.cpp Sistema/Main.cpp

Comando de ejecucion: ./Programa_Biblioteca 

Objetos creados al inicio

1.-Materiales Bibliograficos:

Libro{titulo: "Introducción a la Programación", isbn: "978-0-123-45678-9", autor: "Luis Fernández", prestado: "Sí", fecha de publicacion: "20/06/2019", resumen: "Una guía completa sobre los fundamentos de la programación."}
Revista{titulo: "Revista de Tecnología", isbn: "978-1-23-456789-1", autor: "Laura Sánchez", prestado: "Sí", mes de publicacion: "Julio", Edicion: "4"}
Libro{titulo: "Historia Universal", isbn: "978-0-987-65432-1", autor: "José Pérez", prestado: "Sí", fecha de publicacion: "15/02/2018", resumen: "Exploración detallada de la historia desde la antigüedad hasta la actualidad."}
Revista{titulo: "Revista de Ciencias", isbn: "978-1-23-456789-2", autor: "Pedro González", prestado: "Sí", mes de publicacion: "Agosto", Edicion: "8"}
Libro{titulo: "El Arte de la Guerra", isbn: "978-0-321-65498-7", autor: "Ana Martínez", prestado: "Sí", fecha de publicacion: "10/11/2015", resumen: "Un clásico sobre estrategias y tácticas militares."}
Revista{titulo: "Revista de Salud", isbn: "978-1-23-456789-3", autor: "Carla López", prestado: "Sí", mes de publicacion: "Mayo", Edicion: "12"}
Libro{titulo: "Física para Todos", isbn: "978-0-123-45678-8", autor: "Roberto Díaz", prestado: "Sí", fecha de publicacion: "22/09/2021", resumen: "Conceptos básicos de física explicados de manera sencilla."}
Revista{titulo: "Revista de Literatura", isbn: "978-1-23-456789-4", autor: "Gabriela Morales", prestado: "Sí", mes de publicacion: "Noviembre", Edicion: "6"}
Libro{titulo: "Cocina Internacional", isbn: "978-0-987-65432-2", autor: "Jorge Silva", prestado: "Sí", fecha de publicacion: "01/12/2020", resumen: "Recetas y técnicas de cocina de todo el mundo."}
Revista{titulo: "Revista de Arte", isbn: "978-1-23-456789-5", autor: "Isabel Fernández", prestado: "Sí", mes de publicacion: "Febrero", Edicion: "3"}
Libro{titulo: "Teoría de la Relatividad", isbn: "978-0-654-32198-7", autor: "Miguel Ruiz", prestado: "Sí", fecha de publicacion: "18/04/2017", resumen: "Explicación detallada de la teoría de Einstein."}
Revista{titulo: "Revista de Moda", isbn: "978-1-23-456789-6", autor: "Sofía Hernández", prestado: "Sí", mes de publicacion: "Septiembre", Edicion: "15"}
Libro{titulo: "Matemáticas Avanzadas", isbn: "978-0-321-65432-8", autor: "Andrés Gómez", prestado: "Sí", fecha de publicacion: "25/05/2022", resumen: "Problemas y soluciones en matemáticas avanzadas."}
Revista{titulo: "Revista de Música", isbn: "978-1-23-456789-7", autor: "Martín López", prestado: "No", mes de publicacion: "Diciembre", Edicion: "7"}
Libro{titulo: "Introducción a la Filosofía", isbn: "978-0-987-65432-3", autor: "Carmen Pérez", prestado: "Sí", fecha de publicacion: "30/10/2019", resumen: "Un recorrido por los principales conceptos filosóficos."}
Revista{titulo: "Revista de Cine", isbn: "978-1-23-456789-8", autor: "Alejandra Ruiz", prestado: "Sí", mes de publicacion: "Marzo", Edicion: "10"}
Libro{titulo: "Biología para Principiantes", isbn: "978-0-123-45678-7", autor: "Luis Martínez", prestado: "Sí", fecha de publicacion: "17/06/2021", resumen: "Conceptos básicos de biología para estudiantes."}
Revista{titulo: "Revista de Historia", isbn: "978-1-23-456789-9", autor: "Ricardo Sánchez", prestado: "Sí", mes de publicacion: "Enero", Edicion: "9"}
Libro{titulo: "La Psicología del Desarrollo", isbn: "978-0-987-65432-4", autor: "Elena González", prestado: "Sí", fecha de publicacion: "12/08/2020", resumen: "Estudio de los cambios psicológicos a lo largo de la vida."}
Revista{titulo: "Revista de Tecnología e Innovación", isbn: "978-1-23-456789-0", autor: "Rosa Martínez", prestado: "Sí", mes de publicacion: "Noviembre", Edicion: "5"}
Libro{titulo: "Fundamentos de Electrónica", isbn: "978-0-123-45678-6", autor: "Víctor Fernández", prestado: "Sí", fecha de publicacion: "03/03/2018", resumen: "Introducción a los conceptos básicos de electrónica."}
Libro{titulo: "Astronomía para Todos", isbn: "978-0-987-65432-5", autor: "Martina Gómez", prestado: "Sí", fecha de publicacion: "21/01/2022", resumen: "Un acercamiento a la astronomía para el público general."}
Libro{titulo: "El Mundo de los Insectos", isbn: "978-0-321-65432-9", autor: "Silvia López", prestado: "Sí", fecha de publicacion: "29/07/2019", resumen: "Una guía completa sobre el reino de los insectos."}
Libro{titulo: "La Evolución Humana", isbn: "978-0-987-65432-6", autor: "Álvaro Ruiz", prestado: "Sí", fecha de publicacion: "15/11/2017", resumen: "Exploración de la evolución y desarrollo de la especie humana."}
Libro{titulo: "Química Básica", isbn: "978-0-123-45678-5", autor: "Luis Auditore", prestado: "Sí", fecha de publicacion: "22/05/2021", resumen: "Fundamentos de la química para principiantes."}
Libro{titulo: "La metamorfosis", isbn: "978-0-123-45678-10", autor: "Franz Kafka", prestado: "No", fecha de publicacion: "01/09/1915", resumen: "Gregorio samsa se vuelve un insecto."}
Revista{titulo: "Forbes", isbn: "978-1-23-456789-10", autor: "Matt Craig", prestado: "No", mes de publicacion: "Julio", Edicion: "90"}
Libro{titulo: "Juego de tronos", isbn: "978-1-25-456789-10", autor: "George R. R. Martin", prestado: "No", fecha de publicacion: "01/08/1996", resumen: "Algo de reinos y dragones."}
Revista{titulo: "Revista de juegos", isbn: "978-7-23-456789-0", autor: "Faker", prestado: "No", mes de publicacion: "Diciembre", Edicion: "10"}

2.-Usuarios:

Nota: Isbn hace referencia a los codigos de los libros que tienen prestados 

Usuario{Id: "001", Nombre: "Juan Pérez", isbn: "978-0-321-65498-7, 978-1-23-456789-3"}
Usuario{Id: "002", Nombre: "Laura Martínez", isbn: "978-0-987-65432-2, 978-0-987-65432-5"}
Usuario{Id: "003", Nombre: "Andrés Gómez", isbn: "978-0-987-65432-3, 978-0-987-65432-6, 978-0-123-45678-5"}
Usuario{Id: "004", Nombre: "María López", isbn: "978-0-987-65432-1, 978-0-321-65432-8"}
Usuario{Id: "005", Nombre: "Roberto Díaz", isbn: "978-0-123-45678-8, 978-0-654-32198-7"}
Usuario{Id: "006", Nombre: "Ana Fernández", isbn: "978-1-23-456789-9, 978-1-23-456789-4"}
Usuario{Id: "007", Nombre: "Carlos Sánchez"}
Usuario{Id: "008", Nombre: "Sofía Torres", isbn: "978-0-123-45678-9, 978-1-23-456789-2, 978-0-123-45678-6"}
Usuario{Id: "009", Nombre: "Miguel Ruiz", isbn: "978-0-123-45678-7, 978-0-987-65432-4"}
Usuario{Id: "010", Nombre: "Isabel Rodríguez", isbn: "978-1-23-456789-1, 978-0-321-65432-9"}
Usuario{Id: "011", Nombre: "Pedro González"}
Usuario{Id: "012", Nombre: "Jorge Silva", isbn: "978-1-23-456789-5"}
Usuario{Id: "013", Nombre: "Gabriela Ruiz", isbn: "978-1-23-456789-8"}
Usuario{Id: "014", Nombre: "Carmen Pérez"}
Usuario{Id: "015", Nombre: "Luis Fernández"}
Usuario{Id: "016", Nombre: "Rosa Martínez"}
Usuario{Id: "017", Nombre: "José Martínez", isbn: "978-1-23-456789-6"}
Usuario{Id: "018", Nombre: "Víctor Ruiz"}
Usuario{Id: "019", Nombre: "Martina Gómez"}
Usuario{Id: "020", Nombre: "Ricardo Morales", isbn: "978-1-23-456789-0"}