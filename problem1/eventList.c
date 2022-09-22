#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = NULL;
    eventList->last = NULL;
    return eventList;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{

}

void AddEvent(EventList *this, Event *event)
{
     Event *crrntEvnt = this->head;
    while (crrntEvnt != NULL)
    {
        if(strcmp(event->eventName, crrntEvnt->eventName) == 0)
        return;

        crrntEvnt = crrntEvnt->next;
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

void RemoveEvent(EventList *this, char *name)
{
    
}

void ListEvents(EventList *this)
{
    //if empty
    printf("empty\n");
}
