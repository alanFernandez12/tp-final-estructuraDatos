#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

struct NodoEstructura
{
    void *dato;
    NodoP proximo;
};

struct PilaEstructura
{
    NodoP primero;
    int size;
    int sizeDelDato;
};

// NODO
NodoP crearNodo(Pila pila, void *dato)
{

    NodoP nodoTemp = malloc(sizeof(struct NodoEstructura));

    nodoTemp->dato = malloc(pila->sizeDelDato);

    memcpy(nodoTemp->dato, dato, pila->sizeDelDato);

    return nodoTemp;
}

// LISTA
Pila crearPila(int sizeDelDato)
{

    Pila pila = malloc(sizeof(struct PilaEstructura));
    pila->primero = NULL;
    pila->size = 0;
    pila->sizeDelDato = sizeDelDato;

    return pila;
}

void liberarPila(Pila pila)
{
    free(pila);
}

int getSize(Pila pila)
{
    return pila->size;
}

int apilar(Pila pila, void *dato)
{

    if (pila->size == 0)
    {
        pila->primero = crearNodo(pila, dato);
    }
    else
    {
        NodoP nodoActual = pila->primero;
        for (int i = 1; i < pila->size; i++)
        {
            nodoActual = nodoActual->proximo;
        }

        nodoActual->proximo = crearNodo(pila, dato);
    }

    pila->size++;
    return 1;
}

int desapilar(Pila pila, Plibro *item)
{

    NodoP nodoActual = pila->primero;
    for (int i = 1; i < pila->size; i++)
    {
        nodoActual = nodoActual->proximo;
    }

    nodoActual->proximo = NULL;


    NodoP aux = nodoActual;
    *item = aux->dato;

    free(aux);
    aux = NULL;

    pila->size--;
    return 1;
}

void mostrarPila(Pila pila)
{

    NodoP nodoActual = pila->primero;
    printf("[");
    for (int i = 0; i < pila->size; i++)
    {
        Plibro e = *((Plibro *)nodoActual->dato);
        mostrarLibro(e);


        nodoActual = nodoActual->proximo;
    }
    printf("]\n");
}
