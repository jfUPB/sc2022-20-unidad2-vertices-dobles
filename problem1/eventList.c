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
    
}

Event *SearchEvent(EventList *this, char *name)
{

}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty = 1)
    {
        this->isEmpty = 0;
        this->head = event->eventName;
        this->last = event->eventName;
    }
    else
    {
        char ;
    }
}

void RemoveEvent(EventList *this, char *name)
{

}

void ListEvents(EventList *this)
{

}
