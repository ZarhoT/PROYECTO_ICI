#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int tipo;
    int costo[5][5];
}tarifa;

HashMap* Carga_Tarifa(char *file_name){
    HashMap* tarifas = createHashMap(5);
    FILE* fp = fopen(file_name, "r");
    char* token = malloc(sizeof(char));
    tarifa* t = malloc(sizeof(tarifa));
    int key = 1, i=0, j=0, parar_loop=1;
    char* lectura = malloc(100*sizeof(char));

    fgets(lectura, 100, fp);
    while(key<5){
        t->tipo = key;
        fgets(lectura, 100, fp);
        i = 0;  parar_loop = 1;
        while(parar_loop < 6){
            token = strtok(lectura, ",");
            while(j<5){
                t->costo[i][j] = atoi(token);
                token = malloc(sizeof(char));
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
        t = malloc(sizeof(tarifa));
        lectura = malloc(100*sizeof(char));
    }
    return tarifas;
}

void imprimir(HashMap* Alta){
    tarifa* t = malloc(sizeof(tarifa));
    t = first_(Alta);
    int i , j;

     while(t != NULL){
        printf("%d: \n",t->tipo);
        for(i = 0; i < 5 ; i++){
            for(j = 0; j < 5; j++){
                printf("%d ",t->costo[i][j]);
            }
            printf("\n");
        }
        t = next_(Alta);
        printf("\n");
     }
}





int Valor(HashMap *Alta, HashMap * Media ,HashMap *Baja, char* estacion_1, char* estacion_2){
    int i = 0, j = 0, tipo_usuario = 0;
    tarifa* t = (tarifa*)malloc(sizeof(tarifa));
    time_t ahora;
    struct tm* hora;
    time(&ahora);
    hora = localtime(&ahora);
    float now = hora->tm_hour + (hora->tm_min / 100);
    printf("%f \n",now);
    printf("\n\n                    1 .- General \n");
    printf("                    2 .- Estudiante\n");
    printf("                    3 .- Adulto Mayor y Discapacitado\n");
    printf("                    4 .- Convenio\n");
    printf("\n                    Indique el tipo de usuario :");
    scanf("%d",&tipo_usuario);

    printf("%s - %s\n",estacion_1,estacion_2);
    if((strcmp(estacion_1, "puerto") == 0) || (strcmp(estacion_1, "bellavista") == 0) ||(strcmp(estacion_1, "francia") == 0) ||(strcmp(estacion_1, "baron") == 0) ||(strcmp(estacion_1, "portales") == 0))
        i = 0;
    else if((strcmp(estacion_1, "recreo") == 0) || (strcmp(estacion_1, "miramar") == 0) ||(strcmp(estacion_1, "vina del mar") == 0) ||(strcmp(estacion_1, "hospital") == 0) ||(strcmp(estacion_1, "chorrillos") == 0) ||(strcmp(estacion_1,"el salto") == 0))
        i = 1;
    else if((strcmp(estacion_1, "quilpue") == 0) || (strcmp(estacion_1, "el sol") == 0) ||(strcmp(estacion_1, "el belloto") == 0) )
        i = 2;
    else if((strcmp(estacion_1, "las americas") == 0) || (strcmp(estacion_1, "la concepcion") == 0) ||(strcmp(estacion_1, "villa alemana") == 0) ||(strcmp(estacion_1, "sargento aldea") == 0) ||(strcmp(estacion_1, "penablanca") == 0))
        i = 3;
    else if((strcmp(estacion_1, "limache") == 0))
        i = 4;

    if((strcmp(estacion_2, "puerto") == 0) || (strcmp(estacion_2, "bellavista") == 0) ||(strcmp(estacion_2, "francia") == 0) ||(strcmp(estacion_2, "baron") == 0) ||(strcmp(estacion_2, "portales") == 0))
        j = 0;
    else if((strcmp(estacion_2, "recreo") == 0) || (strcmp(estacion_2, "miramar") == 0) ||(strcmp(estacion_2, "vina del mar") == 0) ||(strcmp(estacion_2, "hospital") == 0) ||(strcmp(estacion_2, "chorrillos") == 0) ||(strcmp(estacion_2,"el salto") == 0))
        j = 1;
    else if((strcmp(estacion_2, "quilpue") == 0) || (strcmp(estacion_2, "el sol") == 0) ||(strcmp(estacion_2, "el belloto") == 0) )
        j = 2;
    else if((strcmp(estacion_2, "las americas") == 0) || (strcmp(estacion_2, "la concepcion") == 0) ||(strcmp(estacion_2, "villa alemana") == 0) ||(strcmp(estacion_2, "sargento aldea") == 0) ||(strcmp(estacion_2, "penablanca") == 0))
        j = 3;
    else if((strcmp(estacion_2, "limache") == 0))
        j = 4;

    if((hora->tm_hour >= 6 && hora->tm_hour <=9) || (hora->tm_hour >= 17 && hora->tm_hour <= 20)){
        t = search_(Alta, tipo_usuario);
        imprimir(Alta);
        return t->costo[i][j];
    }
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
