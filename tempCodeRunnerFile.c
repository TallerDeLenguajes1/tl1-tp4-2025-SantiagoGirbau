    int input;
    nodo *nodoAMover;
    do
    {
        printf("%s", pendientes->T.Descripcion);      
        printf("\n1: Tarea completada.  0: area aun pendiente.\n", input);
        scanf("%i", &input);
        if (input==1)
        {
            nodoAMover=pendientes;
            completadas=meterTarea(completadas, nodoAMover);
            pendientes=borrarTarea(pendientes, nodoAMover);
        }
        
        
    } while (pendientes!=NULL);
    return pendientes;
}