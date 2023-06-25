#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include "cola.h"
#include "lista.h"
#include "libro.h"
#include "cliente.h"
struct BiblioEstructura;
typedef struct BiblioEstructura *Biblio;
//pre:cargar el atributo nombre por parametro
//post: se creara la estructura junto con sus atributos ya iniciados( listas y colas)
Biblio crearBiblio(char nom[40]);
//pre: tener iniciadizada la lista de libros desde la creacion de la estructura biblioteca
//post: se agregara libros a la lista
void agregarLibros(Biblio b,Plibro l);
//pre: no tiene que estar vacia la lista de libros, se debe enviar por parametro el id del libro para buscarlo
//post: se eliminara el libro con el id que fue enviado por parametro para poder buscarlo en la lista
void eliminarLibro(Biblio b,int opcion,void*backup);
//pre: no debe estar vacia la lista de libros
//post: se mostrara toda la lista de libros de la biblioteca
void mostrarBiblio(Biblio b);
//pre:debe estar iniciada la cola de clientes desde el constructor de biblioteca
//post: se agregará clientes a la cola de la biblioteca
void agregarCliente(Biblio b,Pcliente c);
//pre: no debe estar vacia la cola de clientes.
//post: se descola el siguiente cliente de la cola
Pcliente desencolarCliente(Biblio b);
//pre: no debe estar vacia la cola de cliente
//post: se mostrara toda la cola de clientes de la biblioteca
void mostrarClientes(Biblio b);




#endif // BIBLIOTECA_H_INCLUDED
