#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "libro.h"

typedef struct NodoEstructura *NodoP;

typedef struct PilaEstructura *Pila;

// Nodo
NodoP crearNodo(Pila pila, void *dato);

// Pila
Pila crearPila(int sizeDelDato);
void liberarPila(Pila pila);

int getSize(Pila pila);

int apilar(Pila pila, void *dato);
int desapilar(Pila pila, Plibro *item);

void mostrarPila(Pila pila);

#endif // PILA_H_INCLUDED
