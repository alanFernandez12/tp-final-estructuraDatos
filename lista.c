#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct NodoE {
    void * data;
    Nodo proximo;
};

struct listaE{
    Nodo primero;
    Nodo ultimo;
    int tamanio;
    int tamDelDatoEnBytes;
};


///Constructor del nodo
Nodo crearNodoL (Lista lista, void *data) {
    Nodo temp =  malloc(sizeof (struct NodoE));



    temp->data = malloc(lista->tamDelDatoEnBytes);

    if (!temp->data) {
        free(temp);
        return temp;
    }

   ///Analizar
    memcpy(temp->data, data, lista->tamDelDatoEnBytes);

    return temp;
}


///Constructor de la lista
Lista crearLista( int tamDelDatoEnBytes) {

    Lista lista = malloc(sizeof(struct listaE));



    lista->primero = lista->ultimo = NULL;
    lista->tamanio = 0;
    lista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return lista;
}



int estaVacia ( Lista lista) {
    if (!lista)
        return TRUE;
    return (lista->tamanio == 0);
}



int obtenerTamanio ( Lista lista) {
    if (!lista)
        return -1;
    return lista->tamanio;
}

void* obtenerDato (Lista lista, int pos) {
    if (!lista || pos < 0 || lista->tamanio <= 0 || pos >= lista->tamanio)
        return NULL;

    if (pos == 0)
        return lista->primero->data;

    if (pos == lista->tamanio - 1)
        return lista->ultimo->data;

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    return f->proximo->data;
}




int obtenerDatoEnParametro ( Lista lista, int pos, void *backup) {
    if (!lista || pos < 0 || lista->tamanio <= 0 || pos >= lista->tamanio)
        return FALSE;

    if (pos == 0) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        return TRUE;
    }

    if (pos == lista->tamanio - 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        return TRUE;
    }

    Nodo f;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    memcpy(backup, f->proximo->data, lista->tamDelDatoEnBytes);
    return TRUE;
}

int insertarInicio (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodoL(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }

    temp->proximo = lista->primero;
    lista->primero = temp;
    lista->tamanio++;

    return TRUE;
}

int insertarFinal (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodoL(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    } else {
        lista->ultimo->proximo = temp;
        lista->ultimo = temp;
        lista->ultimo->proximo = NULL;
    }

    lista->tamanio++;
    return TRUE;
}

int removerInicio (Lista lista, void *backup) {
	if (lista->tamanio == 0)
		return FALSE;
    else if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        liberarlista(lista);
    } else {
        Nodo proximoCpy = lista->primero->proximo;
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);

        free(lista->primero->data);
        free(lista->primero);
        lista->primero = proximoCpy;
        lista->tamanio--;
    }
    return TRUE;
}

int removerFinal (Lista lista, void *backup) {
    if (!lista)
        return FALSE;


    if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        liberarlista(lista);
    }

    else {
        Nodo f = NULL, ultimo = NULL;
        memcpy(backup, lista->ultimo->data, lista->tamDelDatoEnBytes);


        for (f = lista->primero; f != lista->ultimo; f = f->proximo)
            ultimo = f;



        free(lista->ultimo->data);
        free(lista->ultimo);
        lista->ultimo = ultimo;
        lista->ultimo->proximo = NULL;
        lista->tamanio--;
    }
    return TRUE;
}

int insertar (Lista lista, void *data, int pos) {

    if (!lista || pos < 0 || pos > lista->tamanio)
        return FALSE;

    if (pos == 0)
        return insertarInicio(lista, data);

    if (pos == lista->tamanio)
        return removerFinal(lista, data);



    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    Nodo temp;
    if (!(temp = crearNodoL(lista, data)))
        return FALSE;

    temp->proximo = f->proximo;
    f->proximo = temp;
    lista->tamanio++;
    return TRUE;
}

int remover (Lista lista, int pos, void *backup) {

    if (!lista || lista->tamanio<= 0 || pos < 0 || pos >= lista->tamanio)
        return FALSE;

    if (pos == lista->tamanio - 1)
        return removerFinal(lista, backup);

    if (pos == 0)
        return removerInicio(lista, backup);

    Nodo f = NULL, proximoCpy;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    proximoCpy = f->proximo->proximo;
    memcpy(backup, f->proximo->data, lista->tamDelDatoEnBytes);

    free(f->proximo->data);
    free(f->proximo);
    f->proximo = proximoCpy;
    lista->tamanio--;
    return TRUE;
}

void liberarlista (Lista lista) {
    if (!lista || lista->tamanio <= 0 || lista->primero == NULL)
        return;

    Nodo proximo;
    for ( Nodo p = lista->primero; p != NULL;) {
        proximo = p->proximo;
        free(p->data);
        free(p);
        p = proximo;
    }

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->tamanio= 0;
}
void mostrarLista (Lista lista) {
    printf("[");
    for ( int i = 0; i < obtenerTamanio(lista); ++i) {


        Plibro c=*((Plibro*)obtenerDato(lista,i));


		mostrarLibro(c);
    }
    printf("]\n");
}
void ordenarLista(Lista lista){
    void *aux;
    Nodo actual;
    for(int i=0;i<lista->tamanio;i++){
        actual=lista->primero;
        for(int j=0;j<lista->tamanio-1;j++){
            Plibro ubicacion=*((Plibro*)actual->data);
            Plibro siguiente=*((Plibro*)actual->proximo->data);
            if(strcmp(getNom(ubicacion),getNom(siguiente))>0){
                aux=actual->data;
                actual->data=actual->proximo->data;
                actual->proximo->data=aux;
            }
            actual=actual->proximo;
        }
    }
};
int buscarLista(Lista lista,int id){
    int pos=-1;
    Nodo actual=lista->primero;
    int tam=obtenerTamanio(lista);
    for(int i=0;i<tam;i++){
            Plibro li=*((Plibro*)actual->data);
        if(getID(li)==id){
            pos=i;
            i=tam;
        }
        actual=actual->proximo;
    }
    return pos;
};
void copiarLista(Lista lista,Lista co){
    liberarlista(co);
    co->tamDelDatoEnBytes=lista->tamDelDatoEnBytes;
    for(int i=0;i<lista->tamanio;i++){
        insertarInicio(co,obtenerDato(lista,i));
    }

};



