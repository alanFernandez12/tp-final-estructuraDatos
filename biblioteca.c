#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
struct BiblioEstructura{
    char nom[40];
    Cola clientes;
    Lista libros;

};;


Biblio crearBiblio(char nom[40]){
    Biblio bi=malloc(sizeof(struct BiblioEstructura));
    strcpy(bi->nom,nom);
    bi->clientes=crearCola(sizeof(Pcliente));
    bi->libros=crearLista(sizeof(Plibro));


    return bi;
};
void agregarLibros(Biblio b,Plibro l){

    insertarInicio(b->libros,&l);

};
void mostrarBiblio(Biblio b){
    mostrarLista(b->libros);
};
void agregarCliente(Biblio b,Pcliente c){

     encolar(b->clientes,&c);


};
Pcliente desencolarCliente(Biblio b){
    Pcliente aux;
    desencolar(b->clientes,&aux);
    return aux;

};
void mostrarClientes(Biblio b){
    mostrarCola(b->clientes);
};
void eliminarLibro(Biblio b,int opcion,void*backup){
    remover(b->libros, buscarLista(b->libros,opcion) ,&backup);
};

