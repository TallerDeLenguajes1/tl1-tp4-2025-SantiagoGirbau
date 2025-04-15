#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef tarea;

struct Nodo{
tarea T;
nodo *Siguiente;
}typedef nodo;

typedef nodo* lista;

lista crearLista(lista H);

int main(int argc, char const *argv[])
{
    lista L1,L2;
    L1=crearLista(L1);
    L2=crearLista(L2);

    return 0;
}


lista crearLista(lista H){
    return NULL;
}