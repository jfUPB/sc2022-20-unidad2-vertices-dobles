#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void){
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = NULL;
    eventList->last = NULL;
    return eventList;
}

void DestroyEventList(EventList *this){
    free(this);
}

Event *SearchEvent(EventList *this, char *name){
   if (this->isEmpty == 0){
        while (this->head != NULL){
            if (strcmp(name, this->head->eventName)==0)
            return this->head;
            this->head = this->head->next;
        }
   }
   this->head = NULL;
   return this->head;
}

void AddEvent(EventList *this, Event *event){
    Event *this->head = this->head;
    while (this->head != NULL){
        if(strcmp(event->eventName, this->head->eventName) == 0)
        return;
        this->head = this->head->next;
    }
    
    if(this->isEmpty == 0){
            this->last->next = event;
            this->last=event;
    }
    else{
           this->head = event;
           this->last = event;
           this->isEmpty = 0;    
    }
}

void RemoveEvent(EventList *this, char *name){
    EventList *listHead = this->head;
    if (this->isEmpty == 0){
       Event *this->head = listHead->next;
       if(strcmp(name, lstEvnt->eventName)==0)
       {
            if(lstEvnt->next == NULL){
                listHead = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(lstEvnt);
            }
            else{
                listHead=this->head;
                DestroyEvent(lstEvnt);
            }
       }
       while (this->head != NULL){
            if(strcmp(name, this->head->eventName)==0){
                lstEvnt->next = this->head->next;
                if (this->last->next == NULL){
                    this->last = lstEvnt;
                    DestroyEvent(this->head);
                }
            }
            lstEvnt = this->head;
            this->head = this->head->next;
       }
    }
}

void ListEvents(EventList *this){
   if(this->isEmpty == 0){
        Event *this->head = this->head;

        while (this->head != NULL){
            printf("%s\n", this->head->eventName);
            this->head = this->head->next;
        }       
   }
   else{
        printf("empty\n");
   }
}
