#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} typedef tarea;

struct Nodo
{
    tarea T;
    struct Nodo *Siguiente;
} typedef nodo;

typedef nodo *lista;

lista crearLista(lista H);
lista cargarTareas(lista L1, int index);
void mostrarLista(lista L);

int main(int argc, char const *argv[])
{
    lista L1, L2;
    L1 = crearLista(L1);
    L2 = crearLista(L2);
    int input;
    int index = 1000;

    do
    {
        printf("\n1: Cargar tarea  0: Terminar carga\n");
        scanf("%i", &input);
        if (input != 0)
        {
            L1 = cargarTareas(L1, index);
            index=index+1;
        }
    } while (input != 0);

    mostrarLista(L1);
    return 0;
}

lista crearLista(lista H)
{
    return NULL;
}

lista cargarTareas(lista L1, int index)
{

    
    char tareaACargar[100];
    nodo *tareaNueva;

    tareaNueva = (nodo *)malloc(sizeof(nodo));
    printf("\nEscriba la tarea a cargar:\n");
    scanf("%s", tareaACargar);

    printf("\nEscriba la duracion de la tarea:\n");
    scanf("%i", &tareaNueva->T.Duracion);

    tareaNueva->T.Descripcion = (char *)malloc(strlen(tareaACargar + 1) * sizeof(char));
    strcpy(tareaNueva->T.Descripcion, tareaACargar);

    tareaNueva->T.TareaID = index;
    tareaNueva->Siguiente = L1;
    L1 = tareaNueva;
    

    return L1;
}

void mostrarLista(lista L)
{
    if (L == NULL)
    {
        printf("\nLa lista está vacía\n");
    }
    else
    {
        while (L != NULL)
        {
            printf("ID: %i \n", L->T.TareaID);
            printf("Descricion: \n%s\n", L->T.Descripcion);
            printf("Duracion: %i horas\n", L->T.Duracion);
            L = L->Siguiente;
        }
    }
}