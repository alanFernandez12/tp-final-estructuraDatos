#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libro.h"
#include "cliente.h"
#include "biblioteca.h"
#include "lista.h"
#include "pila.h"
#include "cola.h"

int main()
{
    Pcliente c;
    Pcliente backup;
    Pcliente aux;
    //Ya iniciamos con libros cargados en la lista de biblioteca
    Biblio b1=crearBiblio("Belgrano");
    Plibro l1=crearLibro("Harry Potter y la piedra filosofal",1,"J.K. Rowling");
    Plibro l2=crearLibro("El Señor De Los Anillos 2",2,"J.R.R Tolkien");
    Plibro l3=crearLibro("El Alquimista",3,"Paulo Coelho");
    Plibro l4=crearLibro("Crepusculo",4,"Stephenie Meyer");
    agregarLibros(b1,l1);
    agregarLibros(b1,l2);
    agregarLibros(b1,l3);
    agregarLibros(b1,l4);




    int opcion;
    int opc;
    //------ MENU---------------------------
    do{

    printf("----BIBLIOTECA BELGRANO-----\n");
    printf("bienvenido...\n");
    printf("1- Ver lista de libros.\n");
    printf("2- Agregar cliente a la cola.\n");
    printf("3- ver cola de Clientes.\n");
    printf("4- Agregar libro al siguiente en la cola\n");
    printf("5- Eliminar libro de la biblioteca\n");
    printf("0- Salir.\n");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        system("cls");
         mostrarBiblio(b1); break;
    case 2:
        system("cls");
         c=agregarClienteTeclado();
        agregarCliente(b1,c);break; //se envia a la cola de clientes de la biblioteca
    case 3:
        system("cls");
        mostrarClientes(b1);break;

    case 4:
        system("cls");
        aux=*((Pcliente*)desencolarCliente(b1));//sacamos al cliente de la cola para poder agregarle libros
        int op;
        do{
        printf("seleccione el id del libro para agregar al cliente...\n");
        printf("id: 1- Harry Potter y la piedra filosofal.\n");
        printf("id: 2- El Señor De Los Anillos 2.\n");
        printf("id: 3- El Alquimista.\n");
        printf("id: 4- Crepusculo.\n");
        printf("5 -ver pila de libros del cliente\n");
        printf("6- ir al siguiente cliente\n");
        printf("0- salir\n");
        scanf("%d",&op);
        // ---------------------MENU---------------------
        switch(op){
            //proceso de agregacion de libros segun el id que elija
            case 1: agregarLibro(l1,aux);break;
            case 2: agregarLibro(l2, aux);break;
            case 3: agregarLibro(l3, aux);break;
            case 4: agregarLibro(l4, aux);break;
            case 5:
            //se mostrara al cliente que descolamos
                system("cls");
                mostrarCliente(aux);
                mostrarLibrosClientes(aux);
                break;
            case 6:
                system("cls");
                 aux=*((Pcliente*)desencolarCliente(b1));break;
            }


        }while (op!=0);break;


    case 5:

        system("cls");
        do{
        printf("Escriba el id del libro que quieras eliminar..\n");
        printf("id: 1- Harry Potter y la piedra filosofal.\n");
        printf("id: 2- El Señor De Los Anillos 2.\n");
        printf("id: 3- El Alquimista.\n");
        printf("id: 4- Crepusculo.\n");
        printf("0- Salir\n");
        scanf("%d",&opc);
        Plibro l;
        eliminarLibro(b1,opc,l);//enviamos el id por parametro para buscarlo en la lista

        }while (opc!=0);break;




    }

    }while(opcion!=0);


    return 0;
}
