#include <stdio.h>
#include <stdlib.h>
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
    HashMap* tarifas = createHashMap(5);//un arreglo de 5 elementos
    char linea[40];
    char* token;
    int cont=0,j=0,k=0;
    tarifa* T = (tarifa*)malloc(sizeof(tarifa));
    FILE* fp;
    fp = fopen(file_name,"r");

    if(!fp) exit(0);

    while(cont<4){//la operacion se realizará 4 veces
        fgets(linea,40,fp);//lee la primera linea
        while(fgets(linea,40,fp)!="-"){//se recorre el texto hasta llegar al caracter -.
            token = strtok(linea,",");
            T->costo[j][k] = atoi(token);

            while(token!=NULL){
                k++;
                token = strtok(NULL,",");
                T->costo[j][k] = atoi(token);
            }
            j++;
            k=0;//reinicializa el contador
            }

        insert_(tarifas,T,cont);//insertar en el hashmap
        cont++;
        j=0;//reinicializa el contador
    }

    return tarifas;
}


estacion* Crea_recorrido(){
    FILE* fp;
    int i=0;
    char linea[40];
    char* token;
    estacion* recorrido = (estacion*)malloc(20 * sizeof(estacion));
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
        i++;
    }
    fclose(fp);
    return recorrido;
}


int tiempo_entre_estaciones(estacion* R,int estacion1,int estacion2){
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
        

















