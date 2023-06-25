#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "libro.h"
#include "pila.h"
struct ClienteE;
typedef struct ClienteE *Pcliente;
//pre: se debe mandar los datos por parametros
//post: se creara cliente
Pcliente crearCliente(char nom[20],int dni);
//pre: ya debe estar creado el cliente y se debe mandar por parametros
//post: se mostrara el ciente
void mostrarCliente(Pcliente c);
//pre: debe estar creado la funcion crearCliente a para mandarles los datos por parametros
//post: se mandaran los datos capturados por teclado a crearCliente.
Pcliente agregarClienteTeclado();
//pre: debe estar creado el cliente
//post: agregara libro a la pila
void agregarLibro(Plibro l,Pcliente c);
//pre:debera estar creado el cliente, y no debe estar vacia la pila de libros.
//post: se mostrara la pila de libros.
void mostrarLibrosClientes(Pcliente c);
//pre: debera estar cargado el atriburo DNI previamente
//post:retorna el atributo DNI.
int getDni(Pcliente c);


#endif // CLIENTE_H_INCLUDED
