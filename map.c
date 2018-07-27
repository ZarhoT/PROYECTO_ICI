#include <stdio.h>
#include <stdlib.h>
#include "map.h"

typedef struct hashElem{
  long key;
  void* dato;
}hashElem;

typedef struct HashMap{
  hashElem** hashArray;
  int size;
  int capac;
  int current;
}HashMap;

HashMap* createHashMap(int capac){
    int i;
    HashMap* map=(HashMap*) malloc(sizeof(HashMap));
    map->capac=capac;
    map->size=0;
    map->hashArray = malloc(sizeof(hashElem*)*map->capac);
    for(i=0;i<map->capac;i++)
        map->hashArray[i]=NULL;
    return map;
}

long hash_(long key, long capac){
    float aux = 0.60 * key;
    float d;

    d = (float)aux;
    d = d - (int)aux;

  return d*capac;
}


void insert_(HashMap* map, void* dato, long key){
    int hvalue = hash_(key,map->capac);
    if(map->hashArray[hvalue]){ //se busca una casilla disponible a partir de hvalue
       int new_hvalue=-1, i;
       for(i=1;i<map->capac;i++){
          new_hvalue=(hvalue+i)%map->capac;
          if(!map->hashArray[new_hvalue] || !map->hashArray[new_hvalue]->dato){
             hvalue=new_hvalue;
             break;
          }
       }
   }

   if(!map->hashArray[hvalue]) map->hashArray[hvalue]=(hashElem*) malloc(sizeof(hashElem));
   map->hashArray[hvalue]->dato=dato;
   map->hashArray[hvalue]->key=key;
   map->size++;
   if((double)map->size/(double)map->capac > 0.7) enlarge_(map); //agranda la tabla
}

void enlarge_(HashMap* map){
    int i = 0;
    hashElem** aux = map->hashArray;
    map->hashArray = (hashElem**)calloc(1, 2*(map->capac)*sizeof(hashElem*));
    map->size = 0;
    map->capac = 2 * map->capac;
    for(i=0; i<map->capac/2; i++){
        if(aux[i]!=NULL){
            insert_(map, aux[i]->dato, aux[i]->key);
            free(aux[i]);
        }


    }
    free(aux);
}

void* search_(HashMap* map, long key){
    long i = hash_(key, map->capac);

    if(map->hashArray[i]==NULL || map->hashArray[i]->dato==NULL){
        if(map->hashArray[i]->key == key)
            return map->hashArray[i]->dato;
    }else
        while(i<map->capac){
            if(map->hashArray[i]->key == key)
                return map->hashArray[i]->dato;
            i++;
        }
    return NULL;
}

void* first_(HashMap* map){
    int i;
    for(i = 0 ; i < map->capac; i++){
        if((map->hashArray[i] != NULL) && (map->hashArray[i]->dato != NULL))
        {
            map->current = i;
            return map->hashArray[i]->dato;
        }
    }
    return NULL;
}

void* next_(HashMap* map){
    int j;
    for(j =  map->current +1; j < map->capac ; j++){
        if((map->hashArray[j] != NULL) && (map->hashArray[j]->dato != NULL))
        {
            map->current = j;
            return map->hashArray[j]->dato;
        }
    }
    return NULL;
}


