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
struct Nodo *Siguiente;
}typedef nodo;


typedef nodo* lista;

lista crearLista(lista H);
lista cargarTareas(lista L1);

int main(int argc, char const *argv[])
{
    lista L1,L2;
    L1=crearLista(L1);
    L2=crearLista(L2);

    

    L1=cargarTareas(L1);

    return 0;
}


lista crearLista(lista H){
    return NULL;
}

lista cargarTareas(lista L1){
    int input;
    int index=1000;
    char cargar[100];
    nodo *tareaNueva;
    do
    {
        printf("\n1: Cargar tarea  0: Terminar carga.    ");
        scanf("%i", &input);
        if (input!=0)
        {
            tareaNueva=(nodo*)malloc(sizeof(nodo));
            printf("\nEscriba la tarea a cargar:\n");
            scanf("%s", cargar);
            printf("\nEscriba la duracion de la tarea:\n");
            scanf("%i", &tareaNueva->T.Duracion);
            tareaNueva->T.Descripcion=(char*)malloc(sizeof(cargar+1));
            strcpy(cargar,tareaNueva->T.Descripcion);
            tareaNueva->T.TareaID=index;
            tareaNueva->Siguiente=NULL;
            index++;
        }
    } while (input!=0);
    return L1;
}