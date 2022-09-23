# Evaluación Unidad 2: De lenguaje de alto nivel a código ejecutable

## Equipo: Vertices dobles

## Enunciado:

Una estructura de datos típica en la solución de problemas de entretenimiento digital es la LISTA. Se va a proponer un proyecto que hace uso de LISTAS; sin embargo, el proyecto está INCOMPLETO. La misión será completar el proyecto y pasar todos los vectores de prueba. Una vez terminada la solución se debe estudiar detenidamente para preparar la sustentación. Dicha sustentación será una pregunta relacionada con el proyecto.

## Muy Importante

- No usar ninguna función para imprimir en pantalla a menos que sean las que ya están en el código o donde se pide que se usen. En la función ListEvents se deberá imprimir cada evento usando la cadena formateada "%s\n" y en caso de tener una lista vacía usar esta función printf("empty\n");. La razón de esto es que el programa será verificado automáticamente y por tanto, si se imprime información no esperada es posible que las pruebas automáticas fallen.

- Para compilar, cámbiate el directorio donde están los archivos .c y ejecuta el comando make. Ten en cuanta que con el comando make clean puedes limpiar todos los archivos compilados y luego con make volver a generarlos.

- Verificar que se esta usando correctamente la memoria dinámica. Para ello instalar valgrind y luego realizar la verificación. 

## Criterio de evaluación

Cada vector de prueba tiene un puntaje. El puntaje de cada punto se puede encontrar en el archivo .github/classroom/autograding.json que está en el repositorio.

## Explicación código

- EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 1;
    return eventList;
}
Instancia un objeto de la clase EventList y le da su tamaño segun las propiedades de EventList, las propiedades tienen un valor predeterminado de NULL e Is Empty como verdadero (1). Esta función devuelve la misma lista.

- void DestroyEventList(EventList *this)
{
    free(this);
}
Libera la lista actual del espacio de memoria.

- Event *SearchEvent(EventList *this, char *name)
{
    Event *crntEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (crntEvent != NULL)
        {
            if (strcmp(name, crntEvent->eventName)==0)
            return crntEvent;
            crntEvent = crntEvent->next;
        }
    }
    crntEvent = NULL;
    return crntEvent;
}
Recibe la lista y un nombre que sería el nombre del evento, lo busca en lo que esta apuntando la lista y si no lo encuentra continúa.

- void AddEvent(EventList *this, Event *event)
{
    Event *crntEvent = this->head;
    while (crntEvent != NULL)
    {
        if(strcmp(event->eventName, crntEvent->eventName) == 0)
        return;

        crntEvent = crntEvent->next;
    }
    
   if(this->isEmpty == 0)
   {
        this->last->next = event;
        this->last=event;
   }
   else
   {
       this->head = event;
       this->last = event;
       this->isEmpty = 0;    
   }
}
Recibe la lista y el tipo de evento. Se instancia el evento mientras el evento actual es diferente de NULL, compara los strings y apunta el evento actual hacia el próximo evento.

- void RemoveEvent(EventList *this, char *name)
{
    if (this->isEmpty == 0)
    {
         Event *crntEvent = this->head->next;  //USAMOS DOS EVENTOS PARA UBICARNOS EN EL ACTUAL Y ANTERIOR PARA MANEJAR MEJOR LA ELMINACION DE EVENTOS.
         Event *eventoAnterior = this->head;
         if(strcmp(name, eventoAnterior->eventName)==0)
         {
              if(eventoAnterior->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(eventoAnterior);
              }
              else
              {
                    this->head=crntEvent;
                    DestroyEvent(eventoAnterior);
              }
         }
         while (crntEvent != NULL)
         {
              if(strcmp(name, crntEvent->eventName)==0)
              {
                   eventoAnterior->next = crntEvent->next;
                   if (this->last->next == NULL)
                   {
                        this->last = eventoAnterior;
                        DestroyEvent(crntEvent);
                   }
              }
              eventoAnterior = crntEvent;
              crntEvent = crntEvent->next;
         }
    }
}
Verifica si la lista está vacía o no, en caso de no estar vacía busca el evento y lo libera del espacio de memoria, en caso de estar vacía no hace nada y establece las propiedades de la lista como NULL declarando la lista como vacía.

- void ListEvents(EventList *this)
{
    if (this->isEmpty == 0)
    {
        Event *crntEvent = this->head;

        while (crntEvent != NULL)
        {
            printf("%s\n", crntEvent->eventName);
            crntEvent = crntEvent->next;
        }       
    }
    else
    {
        printf("empty\n");
    }
}
Recibe la lista y verifica si está vacia o no, si no está vacía imprime el nombre del evento y establece el evento actual como próximo.
