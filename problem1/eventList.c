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
    if (this->isEmpty == 0)
    {
       Event *crrntEvnt = this->head->next;
       Event *lstEvnt = this->head;
       if(strcmp(name, lstEvnt->eventName)==0)
       {
            if(lstEvnt->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(lstEvnt);
            }
            else
            {
                this->head=crrntEvnt;
                DestroyEvent(lstEvnt);
            }
       }
       while (crrntEvnt != NULL)
       {
            if(strcmp(name, crrntEvnt->eventName)==0)
            {
                lstEvnt->next = crrntEvnt->next;
                if (this->last->next == NULL)
                {
                    this->last = lstEvnt;
                    DestroyEvent(crrntEvnt);
                }
            }
            lstEvnt = crrntEvnt;
            crrntEvnt = crrntEvnt->next;
       }
    }
}

void ListEvents(EventList *this)
{
   if(this->isEmpty == 0)
    {
        Event *crrntEvnt = this->head;

        while (crrntEvnt != NULL)
        {
            printf("%s\n", crrntEvnt->eventName);
            crrntEvnt = crrntEvnt->next;
        }       
    }
    else
    {
        printf("empty\n");
    }
}
