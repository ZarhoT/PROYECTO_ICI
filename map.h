#ifndef HASHMAP
#define HASHMAP

typedef struct HashMap HashMap;

HashMap* createHashMap(int capacidad_inicial);

void insert_(HashMap* map, void* dato, long key);

void enlarge_(HashMap* map);

void erase_(HashMap* map, long key);

void* search_(HashMap* map, long key);

void* first_(HashMap* map);

void* next_(HashMap* map);

long hash_(long key, long capac);

#endif

