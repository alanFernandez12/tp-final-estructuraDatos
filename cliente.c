#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
struct ClienteE{
    char nombre[20];
    int dni;
    Pila libros;
};;


Pcliente crearCliente(char nom[20],int dni){
    Pcliente cl=malloc(sizeof(struct ClienteE));

    strcpy(cl->nombre,nom);
    cl->dni=dni;
    cl->libros=crearPila(sizeof(Pila));

    return cl;
};
void mostrarCliente(Pcliente c){
    printf("----------------\n");
    printf("NOMBRE: %s\n",c->nombre);
    printf("DNI: %d\n",c->dni);
    printf("-----Su pila de libros:-----\n");

};
Pcliente agregarClienteTeclado(){
    char nomAux[20];
    int dniAux;

    printf("Ingrese nombre del cliente...\n");
    fflush(stdin);
    gets(nomAux);
    printf("Ingrese su numero de dni...\n");
    scanf("%d",&dniAux);

    return crearCliente(nomAux,dniAux);
};
int getDni(Pcliente c){
    return c->dni;
};
void agregarLibro(Plibro l,Pcliente c){
    apilar(c->libros,&l);
};
void mostrarLibrosClientes(Pcliente c){
    mostrarPila(c->libros);
};

