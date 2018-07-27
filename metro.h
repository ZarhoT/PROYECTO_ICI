#include "map.h"
#include "list.h"

#ifndef METRO_H
#define METRO_H

typedef struct estacion estacion;
typedef struct tarifa tarifa;

estacion* Crea_recorrido();
HashMap* Carga_Tarifa(char *file_name);
/*int Busca_estacion(estacion* R,char name[]);
int tiempo_entre_estaciones(estacion* R,int estacion1,int estacion2);
int Valor(HashMap *Alta, HashMap * Media ,HashMap *Baja);
void Siguiente_Tren(estacion* R, char* name);
*/
#endif
