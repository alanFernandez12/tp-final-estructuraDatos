#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "lista.h"
#include "cliente.h"

typedef struct NodoEstructura *NodoC;

typedef struct ColaEstructura *Cola;


NodoC crearNodoC(Cola cola, void *dato);


Cola crearCola(int sizeDelDato);
void liberarCola(Cola cola);

int getSizeC(Cola cola);

int encolar(Cola cola, void *dato);
int desencolar(Cola cola, Pcliente *item);
int obtenerElementoC(Cola cola, Pcliente* item, int pos);
void mostrarCola(Cola cola);

#endif // COLA_H_INCLUDED
