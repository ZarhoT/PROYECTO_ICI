#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metro.h"
#include "map.h"
#include "list.h"

typedef struct estacion{
    char name[40];
    int sig;
    int anterior;
}estacion;

typedef struct tarifa{
    int costo[5][5];
}tarifa;

HashMap* Carga_Tarifa(char *file_name){
    HashMap* tarifas = createHashMap(5);
    FILE* fp = fopen(file_name, "r");
    char* token = malloc(sizeof(char));
    tarifa* t = malloc(sizeof(tarifa));
    char lectura[100];
    int key = 1, i=0, j=0, parar_loop=1;

    fgets(lectura, 100, fp);
    while(key<5){
        fgets(lectura, 100, fp);
        i = 0;  parar_loop = 1;
        while(parar_loop < 6){
            token = strtok(lectura, ",");
            while(j<5){
                t->costo[i][j] = atoi(token);
                token = strtok(NULL, ",");
                j++;
            }
            j = 0;
            i++;
            fgets(lectura, 100, fp);
            parar_loop++;
        }
        insert_(tarifas, t, key);
        key++;
    }

    return tarifas;
}

int Valor(HashMap *Alta, HashMap * Media ,HashMap *Baja, char* estacion_1, char* estacion_2){
    int i = 0, j = 0, aux;
    tarifa* t = malloc(sizeof(tarifa));
    time_t ahora;
    struct tm* hora;
    time(&ahora);
    hora = localtime(&ahora);

    if((strcasecmp(estacion_1, "puerto") == 0) || (strcasecmp(estacion_1, "bellavista") == 0) ||(strcasecmp(estacion_1, "francia") == 0) ||(strcasecmp(estacion_1, "baron") == 0) ||(strcasecmp(estacion_1, "portales") == 0))
        i = 0;
    else if((strcasecmp(estacion_1, "recreo") == 0) || (strcasecmp(estacion_1, "miramar") == 0) ||(strcasecmp(estacion_1, "vina del mar") == 0) ||(strcasecmp(estacion_1, "hospital") == 0) ||(strcasecmp(estacion_1, "chorrillos") == 0) ||(strcasecmp(estacion_1,"el salto") == 0))
        i = 1;
    else if((strcasecmp(estacion_1, "quilpue") == 0) || (strcasecmp(estacion_1, "el sol") == 0) ||(strcasecmp(estacion_1, "el belloto") == 0) )
        i = 2;
    else if((strcasecmp(estacion_1, "las americas") == 0) || (strcasecmp(estacion_1, "la concepcion") == 0) ||(strcasecmp(estacion_1, "villa alemana") == 0) ||(strcasecmp(estacion_1, "sargento aldea") == 0) ||(strcasecmp(estacion_1, "penablanca") == 0))
        i = 3;
    else if((strcasecmp(estacion_1, "limache") == 0))
        i = 4;

    if((strcasecmp(estacion_2, "puerto") == 0) || (strcasecmp(estacion_2, "bellavista") == 0) ||(strcasecmp(estacion_2, "francia") == 0) ||(strcasecmp(estacion_2, "baron") == 0) ||(strcasecmp(estacion_2, "portales") == 0))
        j = 0;
    else if((strcasecmp(estacion_2, "recreo") == 0) || (strcasecmp(estacion_2, "miramar") == 0) ||(strcasecmp(estacion_2, "vina del mar") == 0) ||(strcasecmp(estacion_2, "hospital") == 0) ||(strcasecmp(estacion_2, "chorrillos") == 0) ||(strcasecmp(estacion_2,"el salto") == 0))
        j = 1;
    else if((strcasecmp(estacion_2, "quilpue") == 0) || (strcasecmp(estacion_2, "el sol") == 0) ||(strcasecmp(estacion_2, "el belloto") == 0) )
        j = 2;
    else if((strcasecmp(estacion_2, "las americas") == 0) || (strcasecmp(estacion_2, "la concepcion") == 0) ||(strcasecmp(estacion_2, "villa alemana") == 0) ||(strcasecmp(estacion_2, "sargento aldea") == 0) ||(strcasecmp(estacion_2, "penablanca") == 0))
        j = 3;
    else if((strcasecmp(estacion_2, "limache") == 0))
        j = 4;

    if(hora->tm_hour >= 6 && hora->tm_hour <=9 ){
        t = first_(Alta);
        aux = (int)t->costo;
        return aux;
    }
    else
        return 5;
}



estacion* Crea_recorrido(){
    FILE* fp;
    int n_estaciones=1,i=0;
    char linea[40];
    char* token;
    estacion* recorrido = (estacion*)malloc(sizeof(estacion));
    fp = fopen("r","estaciones.txt");

    fgets(linea,40,fp);//se toma la primera linea para descartar
    while(fgets(linea,40,fp)!=NULL){

        //busqueda en la linea del texto
        token = strtok(linea,"-");
        strcpy(recorrido[i].name, token);
        token = strtok(NULL,"-");
        recorrido[i].sig = atoi(token);
        token = strtok(NULL,"-");
        recorrido[i].anterior = atoi(token);

        //reasignación de memoria
        n_estaciones++;
        recorrido = (estacion*)realloc(recorrido,n_estaciones*sizeof(estacion));
        i++;
    }
    fclose(fp);
    return recorrido;
}



int tiempo_entre_estaciones(estacion* R,char name1[],char name2[]){
    int estacion1 = Busca_estacion(R,name1);
    int estacion2 = Busca_estacion(R,name2);
    int i,j,suma = 0;
    
    if(estacion1 > estacion2){
        j = estacion1;
        for(i = estacion2; i > j; i--){
            suma += R[i]->anterior;
        }
    else if(estacion1 == estacion2) return 0;
    else{
        j = estacion2;
        for(i = estacion1; i < j; i++){
            suma += R[i]->sig;
        }
        
   return suma;
}
        
int Busca_estacion(estacion* R,char name[]){
    int i = 0;
    
    while(strcmp(name,R[i]->name) != 0) i++:
	
	return i;
}














