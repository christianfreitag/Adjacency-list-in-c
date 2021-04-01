#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "memory.h"

int main(){
    int valor=99;
    AberturaGame(1,0);
    system("cls");

    do{
        GerarValoresnoVerso();
        ControleGeral();
        AberturaGame(2,1);
        printf("\n>>>>>");
        scanf("%d",&valor);
        if(valor!=0){ AberturaGame(1,1);}
    }while(valor!=0);



return 0;}