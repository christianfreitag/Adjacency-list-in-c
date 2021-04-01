#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "memory.h"

int *versorCarta;
char map[20][50];
int pontuacaogame=0,combopotuacao=1;
int nivel=14;
int *doneCardsNUMB;

//--------------------------------
int cardPosition[2]={0,0};
int lastCardPosition[2]={0,0};
int valueCard=0,lastVersor1=0,lastVersor2=0;
int lastValueCard=0;
int doneCards[18][2],doneQnt=0;
int quantidadeDeErros=0;
//--------------------------------

void AberturaGame(int b,int c){
    system("cls");
    char textoabertura[476] = {"Cmd: Eai colega! Tudo legal ?\nCmd: Vamos jogar um jogo da memoria muito simples..\nCmd: Apenas escolha uma carta..\nCmd: Ah, e depois outra...\nCmd: Caso forem iguais, BINGO!\nCmd: Ah, tente nao errar muito, e desagradavel...\nCmd: No entando se acertar varias seguidas seu combo sera maior e sua pontuacao tambem!\n\nESCOLHA UM NIVEL:\n1-Nivel impossivel errar\n2-Nivel facil\n3-Nivel medio\n4-Nivel quase dificil\n5-Nivel 'Eu sou bom mas nem tanto'\n6-Nivel hard(18 cartas)"};
    char texto2[110]={"Eai denovo! parace que terminou o jogo ne...\nAperte:\n 1-Caso queira jogar novamente.\n 0-Caso queira sair.\n"};
    int opc=0;
    if(b==1){
        system("cls");
        printf("    ,     ,\n   (\\ ____/)\n   (_oo_)\n    (O)\n    __||__    \\ )\n []/______\\[] /\n  / \\ ______/ \\/\n /    /__\\\n(\\    /____\\\n");
        int i;
        printf("\n\n");
        for(i=0;i<476;i++){
            printf("%c",textoabertura[i]);
            if(c==0){delay(20);}else{}

        }
        while(opc==0){
            printf("\n>>>>>>");
            scanf("%d",&opc);
        switch(opc){
        case 1:
            nivel = 2;
            break;
        case 2:
            nivel= 6;
            break;
        case 3:
             nivel= 8;
            break;
        case 4:
             nivel= 12;
            break;
        case 5:
             nivel= 14;
            break;
        case 6:
             nivel= 18;
            break;

        default:
            printf("\nCmd: escolha uma opcao certa, estou sem paciencia...\n");
            opc = 0;
            break;

        }
        }


        printf("\n\nCmd: Aperte algo para continuar....");
        getch();
    }
    else if(b==2)
    {     system("cls");
         printf("    ,     ,\n   (\\____/)\n   (_oo_)\n    (O)\n    __||__    \\)\n []/______\\[] /\n  / \\______/ \\/\n /    /__\\\n(\\    /____\\\n");
        int i;
        printf("\n\n");
        for(i=0;i<110;i++){
            printf("%c",texto2[i]);
            delay(20);
        }
        printf("\n\nSCORE:%d\n\n",pontuacaogame);
         printf("\n\nNUMERO DE ERROS:%d\n\n",quantidadeDeErros);

    }

}


void desenharMapa(int v[2],int lv[2],int value,int lValue,int doneCards[18][2],int doneQnt){
   int boolShowed=0,i,j,contC=0,contL=0,inC=0,inL=0,contIntern,codLetterCount=65,contNivel=0;

    for(i=0;i<20;i++){

        for(j=0;j<50;j++){



            if(contC>=(9+inC) && contC<=(12+inC)){inC+=8;}
            if(contL>=(7+inL) && contL<=(11+inL)){inL+=7;}

            if((i==(2+inL)&& j==(2+inC)) || (i==(3+inL) && j==(2+inC)) || (i==(4+inL) && j==(2+inC)) ||
               (i==(2+inL) && j==(6+inC)) || (i==(3+inL) && j==(6+inC)) || (i==(4+inL) && j==(6+inC)))
            {

                    map[i][j] = '|';

            }
            else if((i==(1+inL) && j==(3+inC)) || (i==(1+inL)&& j==(4+inC)) || (i==(1+inL) && j==(5+inC)) ||
                    (i==(4+inL) && j==(3+inC)) || (i==(4+inL) && j==(4+inC)) || (i==(4+inL) && j==(5+inC)))
            {

                    map[i][j] = '_';

            }
            else if(i>0 && (j==0 || j==49))
            {
                     map[i][j] = '|';
                }
            else if(j>0 && j<49 && (i==0 || i==19 ))
            {
                      map[i][j] = '_';
                }
               else
            {
                map[i][j] = ' ';


                if(((v[0]!=0 && v[1]!=0) && (v[0]==i && v[1]==j)) && boolShowed==0 ){

                           map[v[0]-1][v[1]-1] = '/';
                           map[v[0]+1][v[1]-1] = '\\';
                           map[v[0]-1][v[1]+1] = '\\';
                           map[v[0]+1][v[1]+1] = '/';

                         map[v[0]][v[1]] = value +'0';




                        boolShowed = 1;
                         codLetterCount+=1;
                         if(contNivel<nivel){
                            contNivel++;
                         }

                }else{

                      if((i==(3+inL) && j==(4+inC))){
                        if(contNivel<nivel){
                            map[i][j] = codLetterCount;
                            codLetterCount+=1;
                                  contNivel+=1;



                        }else{

                             map[i][j] = ' ';

                        }

                      }
                }

                if(lv[0] !=0 && lv[1] !=0 ){

                         map[lv[0]-1][lv[1]-1] = '/';
                           map[lv[0]+1][lv[1]-1] = '\\';
                           map[lv[0]-1][lv[1]+1] = '\\';
                           map[lv[0]+1][lv[1]+1] = '/';

                             map[v[0]-1][v[1]-1] = '/';
                           map[v[0]+1][v[1]-1] = '\\';
                           map[v[0]-1][v[1]+1] = '\\';
                           map[v[0]+1][v[1]+1] = '/';

                          map[lv[0]][lv[1]] = lValue+'0';


                }


                }





            contC++;

        }

    contC=0;
    inC=0;
    contL++;
    }

     /***/

     if(doneQnt!=0){

            for(i=0;i<doneQnt;i++){
            //Mid
           map[doneCards[i][0]][doneCards[i][1]] = ' ';

           //#######DOWN############
           // Mid/Down
           map[(doneCards[i][0]+1)][doneCards[i][1]] = ' ';
            // Left/Down
           map[(doneCards[i][0]+1)][doneCards[i][1]-1] = ' ';
           // Right/Down
           map[(doneCards[i][0]+1)][doneCards[i][1]+1] = ' ';


           //#######UP############
           //Mid/Up
           map[(doneCards[i][0]-2)][(doneCards[i][1])] = ' ';
           //Right/Up
           map[(doneCards[i][0]-2)][(doneCards[i][1]+1)] = ' ';
            //Left/Up
           map[(doneCards[i][0]-2)][(doneCards[i][1]-1)] = ' ';

           //#######RIGHT############
           //Mid/Right
           map[doneCards[i][0]][doneCards[i][1]+2] = ' ';
            //UpMid/Right
           map[doneCards[i][0]+1][doneCards[i][1]+2] = ' ';
           //DownMid/Right
           map[doneCards[i][0]-1][doneCards[i][1]+2] = ' ';

           //#######LEFT############
           //Mid/Left
           map[doneCards[i][0]][doneCards[i][1]-2] = ' ';
           //UpMid/Left
           map[doneCards[i][0]-1][doneCards[i][1]-2] = ' ';
           //DownMid/Left
           map[doneCards[i][0]+1][doneCards[i][1]-2] = ' ';

            }
    }


    mostrarMapa();





}

void mostrarMapa(){
    int i,j;
    system("cls");
    for(i=0;i<20;i++){
        for(j=0;j<50;j++){

            printf("%c",map[i][j]);

        }
        printf("\n");
    }
    printf("##################################################\n");
             printf("#####                  ####               ########\n");
             printf("#####    COMBO: %dX     ####   PONTUACAO:%d        \n",combopotuacao,pontuacaogame);
             printf("#####                  ####               ########\n");
             printf("##################################################\n");
}

void SelecaoDcartas(int versor,int cardP1, int cardP2,int indceVersor,int c){
    if(indceVersor<nivel){

        valueCard = versor;
    cardPosition[0]=cardP1;cardPosition[1]=cardP2;
    desenharMapa(cardPosition,lastCardPosition,valueCard,lastValueCard,doneCards,doneQnt);
    lastCardPosition[0] = cardPosition[0];
    lastCardPosition[1] = cardPosition[1];
    lastValueCard = valueCard;
    if(c==0){
         lastVersor1=indceVersor;
    }
    else if(c==1){
         lastVersor2= indceVersor;
    }

    }else{
        valueCard=0;
        lastValueCard=0;
        mostrarMapa();
    }

}

void ControleGeral(){
    char chooseCard,lastChooseCard=' ';
    pontuacaogame = 0;
    combopotuacao = 1;
    int auxValueCard,cont=0,isFinishedCont=0,firstSelected=0,lastSelected=0,i,j,erroCarta=0,acertosSeguidos=0,errosSeguidos=0,cartasiguaisSeguidas=0;
    int incharcard=10;
    int firstcardPosition[2] = {0,0};

    cardPosition[0]=0;cardPosition[1]=0;
    lastCardPosition[0]=0;lastCardPosition[1]=0;
    valueCard=0;
    lastValueCard=0;
    doneCards[18][2];
    doneQnt=0;
    quantidadeDeErros=0;

    for(i=0;i<18;i++){for(j=0;j<2;j++){doneCards[i][j] = 0;}}


    desenharMapa(cardPosition,lastCardPosition,valueCard,lastValueCard,doneCards,doneQnt);
    while(isFinishedCont<nivel/2){
        system("cls");
        desenharMapa(cardPosition,lastCardPosition,valueCard,lastValueCard,doneCards,doneQnt);
        while(cont!=2){

            do{
                    if(cont>=1){
                        controleDeDialogo(6);
                    }else{
                        controleDeDialogo(5);
                    }

                printf("\n##################################################\n>>>>");
                chooseCard = getche();
                getch();
                chooseCard = toupper(chooseCard);
                incharcard = chooseCard;

            }while(incharcard< 65 || incharcard>83);


            int abc = chooseCard;
            system("cls");
            if(chooseCard!=' ' && lastChooseCard!=chooseCard){
                lastChooseCard = chooseCard;

                 switch(chooseCard){

            case 'A':

                 SelecaoDcartas(versorCarta[0],3,4,0,cont);
                break;
            case 'B':
                SelecaoDcartas(versorCarta[1],3,12,1,cont);

                break;
            case 'C':
                 SelecaoDcartas(versorCarta[2],3,20,2,cont);
                break;
            case 'D':

                 SelecaoDcartas(versorCarta[3],3,28,3,cont);
                break;
            case 'E':

                 SelecaoDcartas(versorCarta[4],3,36,4,cont);
                break;
            case 'F':

                 SelecaoDcartas(versorCarta[5],3,44,5,cont);
                break;
            case 'G':

                 SelecaoDcartas(versorCarta[6],10,4,6,cont);
                break;
            case 'H':

                 SelecaoDcartas(versorCarta[7],10,12,7,cont);
                break;
            case 'I':

                 SelecaoDcartas(versorCarta[8],10,20,8,cont);
                break;
            case 'J':

                 SelecaoDcartas(versorCarta[9],10,28,9,cont);
                break;
            case 'K':

                 SelecaoDcartas(versorCarta[10],10,36,10,cont);
                break;
            case 'L':

                 SelecaoDcartas(versorCarta[11],10,44,11,cont);
                break;
            case 'M':

                 SelecaoDcartas(versorCarta[12],17,4,12,cont);
                break;
            case 'N':

                 SelecaoDcartas(versorCarta[13],17,12,13,cont);
                break;
            case 'O':

                 SelecaoDcartas(versorCarta[14],17,20,14,cont);
                break;
            case 'P':

                 SelecaoDcartas(versorCarta[15],17,28,15,cont);
                break;
            case 'Q':

                 SelecaoDcartas(versorCarta[16],17,36,16,cont);
                break;
            case 'R':
                 SelecaoDcartas(versorCarta[17],17,44,17,cont);
                break;
            default:
                erroCarta=1;
                desenharMapa(cardPosition,lastCardPosition,valueCard,lastValueCard,doneCards,doneQnt);
                printf("\nEssa carta NAO existe!!\n");
                break;
            }

            if(cont==0){

                firstSelected = valueCard;
                firstcardPosition[0] = cardPosition[0];
                firstcardPosition[1]=cardPosition[1];
            }
            else if(cont==1)
            {
                lastSelected = valueCard;
            }

            }else{
                mostrarMapa();
                if(cartasiguaisSeguidas>=1){
                    controleDeDialogo(4);
                    cartasiguaisSeguidas=0;
                }else{
                    controleDeDialogo(3);
                    cartasiguaisSeguidas++;
                }
                printf("\n##################################################\n");

            }

            if(erroCarta!=1){cont+=1;}else{erroCarta=0;}

            chooseCard=' ';
            valueCard=0;

            }

       if(VerificarCartas(firstSelected,lastSelected)!=0){
            isFinishedCont+=1;
            acertosSeguidos+=1;
            combopotuacao = (acertosSeguidos/3)+1;
            pontuacaogame+=10*combopotuacao;

            errosSeguidos=0;


            printf("#Cmd: Isso ai !! Acertou!%d",isFinishedCont);
            printf("\n##################################################\n");
            for(i=0;i<18;i++){
                    if(doneCards[i][0]==0){
                         doneQnt+=2;
                         doneCards[i][0] = cardPosition[0];
                         doneCards[i][1] = cardPosition[1];

                         doneCards[i+1][0] = firstcardPosition[0];
                         doneCards[i+1][1] = firstcardPosition[1];
                         break;
                    }
            }
       }else if(VerificarCartas(firstSelected,lastSelected)==0 && lastSelected!=0 && firstSelected!=0){
            printf("#Cmd: Errou! que pena e.e!");
            acertosSeguidos=0;
            quantidadeDeErros++;
            combopotuacao = (acertosSeguidos/3)+1;
            errosSeguidos+=1;
            if(errosSeguidos>=4 && pontuacaogame>=5){
                    errosSeguidos=0;
                 srand(time(0));
                int abdc = RandomNumber(1,2);
                controleDeDialogo(abdc);
                 pontuacaogame-=5;

            }


       }else{
        printf("#Cmd: TENTE ESCOLHER CARTAS QUE ESTAO NO TABULEIRO!!");
        printf("\n##################################################\n");
       }
       lastCardPosition[0]=0;lastCardPosition[1]=0;
       cardPosition[0] =0;cardPosition[1]=0;

       cont=0;
       lastChooseCard=' ';
        printf("\nCmd: Aperte algo para continuar...\n");
        getch();

    }
    mostrarMapa();

}

int VerificarCartas(int card1,int card2){

    if(card1!=0 && card2!=0){
       if(card1==card2){
            versorCarta[lastVersor1] = 0;
            versorCarta[lastVersor2] = 0;

            return 1;
       }else{
            return 0;
        }
    }else{
         return 0;
    }
}

void GerarValoresnoVerso(){
 int cont=0,i,b;
    int *listacomValores;

    versorCarta = (int*) malloc(nivel*sizeof(int));
    listacomValores = (int*) malloc(nivel*sizeof(int));

     for(i=0;i<nivel;i++){listacomValores[i]=0;}
     for(i=0;i<nivel;i++){versorCarta[i]=0;}

   for(i=0,b=1;i<nivel;i++,b++){
        if(b-1>=(nivel/2)){
            b=1;
             listacomValores[i] = b;
        }else{
            listacomValores[i] = b;
        }
   }





    srand(time(0));
    while(cont<nivel){
      int r = RandomNumber(0,nivel);
      if(versorCarta[r]==0){

            versorCarta[r] = listacomValores[cont];
            cont++;
      }

    }
    for(i=0;i<nivel;i++){
        printf("\nV[%d]: %d \n",i,versorCarta[i]);
    }
    printf("\n\n");
    for(i=0;i<nivel;i++){
        printf("\nL[%d]: %d \n",i,listacomValores[i]);
    }



}

int RandomNumber(int min,int max){
    return (rand() % (max-min+1)+min);
}

void delay(int milisegundos){
    clock_t startTimer = clock();
    while(clock()<startTimer+milisegundos);
}

void controleDeDialogo(int op){

   switch(op){
    case 1:
        printf("\n#Cmd: Meu deus. Sabia que voc� e pessimo nisso? 4 erros seguidos...quero 5 pontos de volta.");
        break;
    case 2:
         printf("\n#Cmd: Serio? errou 4 vezes seguidas? me de 5 pontinhos de volta!!\n");
        break;
    case 3:
        printf("#Cmd: Tente uma carta diferente..");
        break;
    case 4:
        printf("#Cmd: Se colocar 2 cartas iguais de novo vou tirar seus pontos!!..");
        break;
    case 5:
        printf("#Cmd: Escolha uma carta(ex: a,b,c..): ");
        break;
    case 6:
        printf("#Cmd: Escolha uma outra carta agora.. :");
        break;

   }
}

