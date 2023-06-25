#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "libro.h"
#include "cliente.h"
enum Booleanos {FALSE, TRUE};


typedef struct NodoE * Nodo;

typedef struct listaE *  Lista;


Nodo crearNodoL(Lista lista, void *data);
Lista crearLista( int tamDelDatoEnBytes);
int estaVacia( Lista lista);
int obtenerTamanio( Lista lista);
void* obtenerDato( Lista lista, int pos);
int obtenerDatoEnParametro( Lista lista, int pos, void *backup);
int insertar(Lista lista, void *data, int pos);
int insertarInicio(Lista lista, void *data);
int insertarFinal(Lista lista, void *data);
int removerInicio(Lista lista, void *backup);
int removerFinal(Lista lista, void *backup);
int remover(Lista lista, int pos, void *backup);
void liberarlista(Lista lista);
void mostrarLista (Lista lista);
void ordenarLista(Lista lista);
int buscarLista(Lista lista,int id);
void copiarLista(Lista lista,Lista co);



#endif // LISTA_H_INCLUDED
