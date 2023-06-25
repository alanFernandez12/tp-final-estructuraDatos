#include <stdio.h>
#include <stdlib.h>
#include "libro.h"
#include <string.h>

struct LibroE{
    char nom[40];
    int id;
    char autor[20];
};;

Plibro crearLibro(char nom[40], int id, char autor[20]){
    Plibro li=malloc(sizeof(struct LibroE));
    strcpy(li->nom,nom);
    strcpy(li->autor,autor);
    li->id=id;

    return li;
};
void mostrarLibro(Plibro l){
    printf("Nombre: %s\n",l->nom);
    printf("Autor: %s\n",l->autor);
    printf("ID: %d\n",l->id);
    printf("-------------------\n");
};

char * getNom(Plibro l){
    return l->nom;
};
int getID(Plibro l){
    return l->id;
};
