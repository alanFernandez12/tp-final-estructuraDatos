#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

struct NodoEstructura
{
    void *dato;
    NodoC proximo;
};

struct ColaEstructura
{
    NodoC primero;
    int size;
    int sizeDelDato;
};


NodoC crearNodoC(Cola cola, void *dato)
{

    NodoC nodoTemp = malloc(sizeof(struct NodoEstructura));

    nodoTemp->dato = malloc(cola->sizeDelDato);

    memcpy(nodoTemp->dato, dato, cola->sizeDelDato);

    return nodoTemp;
}


Cola crearCola(int sizeDelDato)
{

    Cola cola = malloc(sizeof(struct ColaEstructura));
    cola->primero = NULL;
    cola->size = 0;
    cola->sizeDelDato = sizeDelDato;

    return cola;
}

void liberarCola(Cola cola)
{
    free(cola);
}

int getSizeC(Cola cola)
{
    return cola->size;
}

int encolar(Cola cola, void *dato)
{

    if (cola->size == 0)
    {
        cola->primero = crearNodoC(cola, dato);
    }
    else
    {
        NodoC nodoActual = cola->primero;
        for (int i = 1; i < cola->size; i++)
        {
            nodoActual = nodoActual->proximo;
        }

        nodoActual->proximo = crearNodoC(cola, dato);
    }

    cola->size++;
    return 1;
}

int desencolar(Cola cola, Pcliente *item)
{


    NodoC aux = cola->primero;
    *item = aux->dato;

    cola->primero = aux->proximo;
    free(aux);
    aux = NULL;
    cola->size--;
    return 1;
}

void mostrarCola(Cola cola)
{

    NodoC nodoActual = cola->primero;

    printf("[");
    for (int i = 0; i < cola->size; i++)
    {

        Pcliente e= *((Pcliente *)nodoActual->dato);
        mostrarCliente(e);


        nodoActual = nodoActual->proximo;
    }
    printf("]\n");
}
int obtenerElementoC(Cola cola, Pcliente* item, int pos) {

    NodoC  aux;
    aux = cola->primero;
    for(int i = 0; i < pos; i++) {
        aux = aux->proximo;
    }
    *item = aux->dato;

    return 1;

}

