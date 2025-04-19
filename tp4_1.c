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
lista meterTarea(lista listaDestino, nodo *tareaMover);
lista borrarTarea(lista lista, int id);
void mostrarLista(lista L);
lista completarTareas(lista pendientes, lista *completadas);
int buscarIdPorPalabra(lista lista);

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
        printf("1: Ver tareas pendientes  2: Ver tareas completadas 3: Ver TODAS las tareas  4: Completar tareas  0: Salir del programa\nSeleccione una opcion: ");
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
            pendientes = completarTareas(pendientes, &completadas);
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
    int duracion;
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

lista meterTarea(lista listaDestino, nodo *tareaMover)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->T.TareaID = tareaMover->T.TareaID;
    nuevoNodo->T.Duracion = tareaMover->T.Duracion;
    nuevoNodo->T.Descripcion = (char *)malloc(strlen(tareaMover->T.Descripcion) + 1);
    strcpy(nuevoNodo->T.Descripcion, tareaMover->T.Descripcion);
    nuevoNodo->Siguiente = listaDestino;
    return nuevoNodo;
}

lista borrarTarea(lista L, int id)
{
    nodo *actual = L;
    nodo *anterior = NULL;

    while (actual != NULL)
    {
        if (actual->T.TareaID == id)
        {
            if (anterior == NULL)
            {
                lista nuevaCabecera = actual->Siguiente;
                free(actual->T.Descripcion);
                free(actual);
                return nuevaCabecera;
            }
            else
            {
                anterior->Siguiente = actual->Siguiente;
                free(actual->T.Descripcion);
                free(actual);
                return L;
            }
        }
        anterior = actual;
        actual = actual->Siguiente;
    }

    printf("No se encontró una tarea con ese ID.\n");
    return L;
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

lista completarTareas(lista pendientes, lista *completadas)
{
    int id;
    int input;
 
    printf("1: Completar por id 2: Completar por palabra clave");
    scanf("%i", &input);
    fflush(stdin);
    if (input == 2)
    {
       id=buscarIdPorPalabra(pendientes);
    }
    else
    {
        printf("Ingrese el ID de la tarea a completar: ");
        scanf("%i", &id);
        fflush(stdin);
    }
    nodo *actual = pendientes;
    while (actual != NULL)
    {
        if (actual->T.TareaID == id)
        {
            *completadas = meterTarea(*completadas, actual);
            pendientes = borrarTarea(pendientes, id);
            printf("Tarea %i completada.\n", id);
            return pendientes;
        }
        actual = actual->Siguiente;
    }
    printf("No se encontró la tarea con ID %i.\n", id);
    return pendientes;
}

int buscarIdPorPalabra(lista Lista){
    char palabra[20];
    nodo *busqueda = Lista;
    printf("Ingrese una palabra de la tarea a completar: ");
    scanf("%s", palabra);
    while (busqueda != NULL)
    {
        if (strstr(busqueda->T.Descripcion, palabra))
        {
            return busqueda->T.TareaID;
        }
        busqueda=busqueda->Siguiente;
    }
}