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
lista cargarTareas(lista pendientes, int index);
void mostrarLista(lista L);
void completarTareas(lista *pendientes, lista *completadas);

int main(int argc, char const *argv[])
{
    lista pendientes, completadas;
    pendientes = crearLista(pendientes);
    completadas = crearLista(completadas);
    int input;
    int index = 1000;

    do
    {
        printf("\n1: Cargar tarea  0: Terminar carga\nEscriba lo que desea realizar: ");
        scanf("%i", &input);
        fflush(stdin);
        if (input != 0)
        {
            pendientes = cargarTareas(pendientes, index);
            index = index + 1;
        }
    } while (input != 0);

    input = 1;

    do
    {
        printf("-------------------------------Menu principal-------------------------\n\n");
        printf("1: Ver tareas pendientes  2: Ver tareas completadas 3: Ver TODAS las tareas  4: Completar tareas  0: Salir del programa\nSeleccione una opción: ");
        scanf("%i", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
            printf("\n-----------------Tareas PENDIENTES:-----------------\n");
            mostrarLista(pendientes);
            break;
        case 2:
            printf("\n----------------Tareas COMPLETADAS:-----------------\n");
            mostrarLista(completadas);
            break;
        case 3:
            printf("\n-----------------Tareas PENDIENTES:-----------------\n");
            mostrarLista(pendientes);
            printf("\n----------------Tareas COMPLETADAS:-----------------\n");
            mostrarLista(completadas);
            break;
        case 4:
            completarTareas(&pendientes, &completadas);
            break;
        case 0:
            printf("\nSaliendo...\n");
            break;
        default:
            printf("\n%i No es una opcion valida.\n", input);
            break;
        }
    } while (input != 0);

    return 0;
}

lista crearLista(lista H)
{
    return NULL;
}

lista cargarTareas(lista pendientes, int index)
{

    char tareaACargar[100];
    nodo *tareaNueva;
    tareaNueva = (nodo *)malloc(sizeof(nodo));

    printf("\nEscriba la tarea a cargar: ");
    fgets(tareaACargar, sizeof(tareaACargar), stdin);
    fflush(stdin);
    printf("\nEscriba la duracion de la tarea: ");
    scanf("%i", &tareaNueva->T.Duracion);

    tareaNueva->T.Descripcion = (char *)malloc((strlen(tareaACargar) + 1) * sizeof(char));
    strcpy(tareaNueva->T.Descripcion, tareaACargar);

    tareaNueva->T.TareaID = index;
    tareaNueva->Siguiente = pendientes;
    pendientes = tareaNueva;

    return pendientes;
}

void mostrarLista(lista L)
{
    if (L == NULL)
    {
        printf("\nLa lista esta vacia\n");
    }
    else
    {
        while (L != NULL)
        {
            printf("ID: %i \n", L->T.TareaID);
            printf("Descripcion: %s", L->T.Descripcion);
            if (L->T.Duracion == 1)
            {
                printf("Duracion: %i hora\n\n", L->T.Duracion);
            }
            else
            {
                printf("Duracion: %i horas\n\n", L->T.Duracion);
            }
            L = L->Siguiente;
        }
    }
}

void completarTareas(lista *pendientes, lista *completadas)
{
    lista listaPelotuda = *pendientes;
    int input;
    do
    {
        printf("%s", listaPelotuda->T.Descripcion);        
        printf("\n1: Tarea completada.  0: area aun pendiente.\n", input);
        scanf("%i", &input);
        
    } while (input != 0);
    
}