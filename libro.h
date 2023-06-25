#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
struct LibroE;
typedef struct LibroE * Plibro;
//pre: se debe mandar los datos por parametros
//post: se creara libro
Plibro crearLibro(char nom[40], int id, char autor[20]);
//pre: ya debe estar creado el cliente y se debe mandar por parametros
//post: se mostrara el libro
void mostrarLibro(Plibro l);
//pre: debe estar cargado el atributo nombre previamente
//post: retorna el atributo nombre
char * getNom(Plibro l);
//pre: debe estar cargado el atributo ID previamente
//post: retorna el atributo ID
int getID(Plibro l);


#endif // LIBRO_H_INCLUDED
