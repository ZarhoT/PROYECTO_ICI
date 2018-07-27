#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "metro.h"
#include "list.h"
#include "map.h"

void menu1();
void menu2();
void planificaViaje();
void consultaViaje();
void informacionGeneral();

int main(){
    int opcion;
    //sndPlaySoundA("C:\\Users\\Public\\Music\\Sample Music\\Kalimba.mp3", 1);
    int tiempoEstaciones[20] = {12,2,2,2,2,2,2,3,12,2,2,2,2,2,3,2,2,2,2};
    system ("color F9");
    menu1();
    while(1){
        system ("color F9");
        menu2();
        printf("\n                        INGRESE LA OPCION REQUERIDA: ");
        scanf("%d", &opcion);
        switch(opcion){
                case 1: system ("color F0");
                        system("cls");
                        planificaViaje();
                        break;
                case 2: system ("color F0");
                        system("cls");
                        consultaViaje();
                        break;
                case 3: system ("color F0");
                        system("cls");
                        informacionGeneral();
                        break;
                case 4: return 0;
        }
        system("cls");
    }



    return 0;
}

void menu1(){
    int i;
    printf("  %c", 201);
    for(i=0 ; i<70; i++)
        printf("%c", 205);
    printf("%c", 187);
    for(i=1; i<3; i++)
        printf("\n  %c                                                                      %c", 186, 186);
        printf("\n  %c   %c%c%c%c%c  %c   %c  %c%c%c  %c %c %c                                           %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c     %c    %c%c  %c  %c    %c   %c                                           %c", 186, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c     %c    %c  %c%c  %c%c   %c   %c                                           %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c   %c%c%c%c%c  %c   %c  %c    %c %c %c                                           %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c                                                                      %c", 186, 186);
        printf("\n  %c                             %c     %c  %c%c%c  %c %c %c  %c %c %c    %c %c %c      %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c                             %c%c   %c%c  %c%c     %c    %c %c      %c   %c      %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c                             %c  %c  %c  %c      %c    %c  %c     %c   %c      %c", 186, 223, 219, 223, 223, 223, 223, 223, 223, 223, 186);
        printf("\n  %c                             %c     %c  %c%c%c    %c    %c   %c    %c %c % c      %c", 186, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 186);
     for(i=1; i<3; i++)
        printf("\n  %c                                                                      %c", 186, 186);

    printf("\n  %c", 200);
    for(i=0 ; i<70; i++)
        printf("%c", 205);
    printf("%c\n", 188);
    printf("\n                       PULSE ENTER PARA CONTINUAR...");
    getchar();
    system("cls");

}

void menu2(){
    int i;
    printf("\n\n");
    printf("                       %c                             %c\n", 218, 191);
    printf("                          OPCIONES DE LA APLICACI%CN          \n", 224);
    printf("                       %c                             %c\n", 192, 217);
    printf("                      %c", 201);
    for(i=0 ; i<31; i++)
        printf("%c", 205);
    printf("%c", 187);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c     *PLANIFICA T%c VIAJE(1)    %c", 186, 233, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c     *CONSULTA T%c VIAJE(2)     %c", 186, 233, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c     *INFORMACI%cN GENERAL(3)   %c", 186, 224, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c     *SALIR DE LA APP(4)       %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c", 200);
    for(i=0 ; i<31; i++)
        printf("%c", 205);
    printf("%c\n", 188);

    printf("\n\n");



}

void planificaViaje(){
    int i, prueba4;
    char prueba[40], prueba2[30], prueba3[10];

    printf("\n                PLANIFIQUE SU VIAJE JUNTO A InfoMetro%c\n            ", 169);
    for(i=0 ; i<46; i++)
        printf("%c", 205);
    printf("\n\n");
    printf("              %c", 201);
    for(i=0 ; i<40; i++)
        printf("%c", 205);
    printf("%c", 187);
    printf("\n                   Estaci%cn de inicio: ", 162);
    getchar();
    fgets(prueba, 40, stdin);
    printf("              %c", 204);
    for(i=0 ; i<40; i++)
        printf("%c", 205);
    printf("%c", 185);
    printf("\n                   Estaci%cn de termino: ", 162);
    getchar();
    fgets(prueba2, 40, stdin);
    printf("              %c", 204);
    for(i=0 ; i<40; i++)
        printf("%c", 205);
    printf("%c", 185);
    printf("\n                   Fecha(dd/mm): ");
    getchar();
    fgets(prueba3, 40, stdin);
    printf("              %c", 204);
    for(i=0 ; i<40; i++)
        printf("%c", 205);
    printf("%c", 185);
    printf("\n                   Hora(hhmm): ");
    scanf("%d", &prueba4);
    printf("              %c", 200);
    for(i=0 ; i<40; i++)
        printf("%c", 205);
    printf("%c\n", 188);








    printf("\n\n");
}

void consultaViaje(){
    int opcion, i;

    printf("\n\n                            %cQU%c DESEAS CONSULTAR?\n                        ", 168, 144);
    for(i=0 ; i<29; i++)
        printf("%c", 205);
    printf("\n\n                      %c", 201);
    for(i=0 ; i<31; i++)
        printf("%c", 205);
    printf("%c", 187);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c      *COSTO DEL VIAJE(1)      %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c      *PR%cXIMO METRO(2)        %c", 186, 224, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c                               %c", 186, 186);
    printf("\n                      %c", 200);
    for(i=0 ; i<31; i++)
        printf("%c", 205);
    printf("%c\n\n", 188);
    printf("                        INGRESE LA OPCION REQUERIDA: ");
    scanf("%d", &opcion);







}

void informacionGeneral(){
    int i;
    printf("\n\n                              INFORMACI%cN GENERAL\n                          ", 224);
    for(i=0 ; i<27; i++)
        printf("%c", 205);
    printf("\n\n");
    printf("               %c", 201);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 203);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 187);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c      *HORARIOS*       %c        S%cbados        %c", 186, 186, 160, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c    Lunes a Viernes    %c     Primer servicio   %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c    Primer servicio    %c  Limache-Puerto:7:30  %c", 186, 186, 186);
    printf("\n               %c                       %c  Puerto-Limache:8:30  %c", 186, 186, 186);
    printf("\n               %c  Limache-Puerto:6:15  %c                       %c", 186, 186, 186);
    printf("\n               %c  Puerto-Limache:6:15  %c     %cltimo servicio   %c", 186, 186, 233, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c    %cltimo servicio    %c  Limache-Puerto:22:06 %c", 186, 233, 186, 186);
    printf("\n               %c                       %c  Puerto-Limache:22:24 %c", 186, 186, 186);
    printf("\n               %c Limache-Puerto: 22:15 %c                       %c", 186, 186, 186);
    printf("\n               %c Puerto-Limache: 22:30 %c                       %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c", 204);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 202);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 185);
    printf("\n               %c                                               %c", 186, 186);
    printf("\n               %c                           Primer servicio     %c", 186, 186);
    printf("\n               %c                                               %c", 186, 186);
    printf("\n               %c                         Limache-Puerto: 8:00  %c", 186, 186);
    printf("\n               %c                         Puerto-Limache: 8:55  %c", 186, 186);
    printf("\n               %c    Domingos                                   %c", 186, 186);
    printf("\n               %c            y                                  %c", 186, 186);
    printf("\n               %c              Festivos     %cltimo servicio     %c", 186, 233, 186);
    printf("\n               %c                                               %c", 186, 186);
    printf("\n               %c                         Limache-Puerto: 22:06 %c", 186, 186);
    printf("\n               %c                         Puerto-Limache: 22:12 %c", 186, 186);
    printf("\n               %c                                               %c", 186, 186);
    printf("\n               %c                                               %c", 186, 186);
    printf("\n               %c", 204);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 203);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 185);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c       *CONTACTO*      %c      *BENEFICIOS*     %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c     Redes Sociales    %c   Tarjeta estudiante  %c", 186, 186, 186);
    printf("\n               %c   'Metro Valpara%cso'  %c           -           %c", 186, 214, 186, 186);
    printf("\n               %c                       %c  Tarjeta Tercera Edad %c", 186, 186, 186);
    printf("\n               %c  Servicio al cliente  %c           -           %c", 186, 186, 186);
    printf("\n               %c   FONO: (32)2527633   %c    Tarjeta personas   %c", 186, 186, 186);
    printf("\n               %c                       %c    con discapacidad   %c", 186, 186, 186);
    printf("\n               %c   Direcci%cn central   %c           -           %c", 186, 162, 186, 186);
    printf("\n               %c                       %c  Beneficios Empresas  %c", 186, 186, 186);
    printf("\n               %c       Viana 1685      %c                       %c", 186, 186, 186);
    printf("\n               %c  Vi%ca del Mar, Chile  %c                       %c", 186, 164, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c                       %c                       %c", 186, 186, 186);
    printf("\n               %c", 200);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c", 202);
    for(i=0 ; i<23; i++)
        printf("%c", 205);
    printf("%c\n\n                    ", 188);
    system("pause");
    printf("\n\n");

}

