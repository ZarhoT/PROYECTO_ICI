#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node{
   void* data;
   struct node* next;
   struct node* prev;
}node;

typedef struct Lista{
    node* first;
    node* last;
    node* current;
}Lista;

node* createNode(void* dato){
node*  N = (node*)malloc(sizeof(node));
    N->data = dato;
    N->prev = NULL;
    N->next = NULL;
return N;
}
Lista* createList(){
    Lista* lista= (Lista*)malloc(sizeof(Lista));

    lista->first = NULL;
    lista->current = NULL;
    lista->last = NULL;
return lista;
}

void* first(Lista* lista){

    if(lista->first && lista->first->data){
            lista->current=lista->first;
    return lista->first->data;
    }

return NULL;
}

void* next(Lista* lista){

    if(lista->current->next && lista->current->next->data){
            lista->current=lista->current->next;
      return lista->current->data;
    }

return NULL;
}

void* last(Lista* lista){

    if(lista->last && lista->last->data){
            lista->current=lista->last;
      return lista->last->data;
    }

return NULL;
}

void pushBack(Lista* L, void* dato){
node* n = createNode(dato);

    if(L->first==NULL){
        L->first=n;
        L->current= L->first;
    }else{
        while(L->current->next != NULL)
            L->current=L->current->next;
        L->current->next=n;
        n->prev=L->current;
        L->current=n;
    }
}
void popCurrent(Lista* L){

    L->current->prev->next=L->current->next;
    L->current->next->prev=L->current->prev;
    L->current= L->current->prev;
}

