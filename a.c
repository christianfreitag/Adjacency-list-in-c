#include <stdlib.h>
#include <stdio.h>
#include "a.h"

struct Grafo *inserirV(struct Grafo *grafo, char newRot)
{
    struct Grafo *nwGf = (struct Grafo *)malloc(sizeof(struct Grafo));
    struct Grafo *auxGf = NULL;
    struct No *nwNo = (struct No *)malloc(sizeof(struct No));

    nwNo->prox = NULL;
    nwNo->rot = newRot;

    nwGf->next = NULL;
    nwGf->prev = NULL;
    nwGf->no = nwNo;

    if (grafo == NULL)
        return nwGf;

    auxGf = grafo;
    do
    {
        if (auxGf->no->rot == newRot)
        {
            printf("\nJA EXITE O VERTICE -> [%c]!\n", newRot);
            return grafo;
        }
        if (auxGf->next != NULL)
        {
            auxGf = auxGf->next;
        }
    } while (auxGf->next != NULL);
    auxGf->next = nwGf;
    return grafo;
}
struct Grafo *inserirA(struct Grafo *grafo, char rot1, char rot2, int val)
{
    if (grafo == NULL)
        return grafo;

    struct No *nwNo1 = NULL;
    struct No *nwNo2 = NULL;
    struct No *auxNo = NULL;

    int isR1 = 0, isR2 = 0;
    struct Grafo *auxgraf = NULL;

    nwNo1 = (struct No *)malloc(sizeof(struct No));
    //inserir valores
    nwNo1->prox = NULL;
    nwNo1->rot = rot1;
    nwNo1->val = val;

    nwNo2 = (struct No *)malloc(sizeof(struct No));
    //inserir valores
    nwNo2->prox = NULL;
    nwNo2->rot = rot2;
    nwNo2->val = val;
    //checar se existem os nós dos rotulos
    if (existeAresta(grafo, rot1, rot2) > 1)
    {
        
        auxgraf = NULL;
        auxgraf = grafo;

        while (auxgraf != NULL)
        {
            if (auxgraf->no->rot == rot1 || auxgraf->no->rot == rot2)
            {
                auxNo = auxgraf->no;
                while (auxNo->prox != NULL)
                {
                    
                   
                    auxNo = auxNo->prox;
                    if(auxNo->rot==rot1){
                         printf("\nA ARESTA ENTRE [%c] E [%c] JA EXISTEM!\n\n",rot1,rot2);
                         return grafo;
                    }else if(auxNo->rot==rot2){
                        printf("\nA ARESTA ENTRE [%c] E [%c] JA EXISTEM!\n\n",rot1,rot2);
                        return grafo;
                    }
                }
                if (auxgraf->no->rot == rot1)
                {
                    auxNo->prox = nwNo2;
                }
                else if (auxgraf->no->rot == rot2)
                {
                    auxNo->prox = nwNo1;
                }
            }
            auxgraf = auxgraf->next;
        }
    }
    else
    {
        printf("\nUM DOS VERTICES NAO EXISTE!\n");
    }
    return grafo;
}
struct Grafo *removerV(struct Grafo *grafo, char rot, char auxrot, int cmt)
{
    if (grafo == NULL)
        return grafo;

    struct Grafo *auxgraf = NULL;
    struct Grafo *auxgrafant = NULL;

    struct No *auxNoant = NULL;
    struct No *auxNo = NULL;
    struct No *auxNoprox = NULL;

    auxgraf = grafo;
    auxgrafant = auxgraf;
    while (auxgraf->next != NULL && auxgraf->no->rot != rot)
    {
        auxgrafant = auxgraf;
        auxgraf = auxgraf->next;
    }
    if (auxgraf->no->rot == rot)
    {
        if (auxrot != '*')
        {
            auxNo = auxgraf->no;
            auxNoant = auxNo;
            while (auxNo->prox != NULL && auxNo->rot != auxrot)
            {
                auxNoant = auxNo;
                auxNo = auxNo->prox;
            }
            if (auxNo->rot == auxrot)
            {
                auxNoant->prox = auxNo->prox;
                free(auxNo);
            }
        }
        else
        {
            auxNoprox = auxgraf->no->prox;
            auxNo = auxgraf->no;

            while (auxNo->prox != NULL)
            {
                grafo = removerV(grafo, auxNoprox->rot, rot, cmt);
                auxNo = auxNo->prox;
                auxNoprox = auxNoprox->prox;
            }
            if (auxgrafant == auxgraf)
            {
                grafo = grafo->next;
            }
            else
            {
                auxgrafant->next = auxgraf->next;
            }
            free(auxgraf);
        }
    }
    else
    {
        printf("\nO VERTICE NAO EXISTE!\n");
        return grafo;
    }
    return grafo;
}
struct Grafo *removerA(struct Grafo *grafo, char rot, char rot2, int cmt)
{
    if (grafo == NULL)
        return grafo;

    struct Grafo *auxgrafant = NULL;
    struct Grafo *auxgraf = NULL;

    struct No *auxNo = NULL;
    struct No *auxnoant = NULL;

    int i = 0;

    auxgraf = grafo;
    auxgrafant = grafo;
    while (auxgrafant->next != NULL)
    {
        if (auxgraf->no->rot == rot)
        {
            auxNo = auxgraf->no;
            while (auxNo->prox != NULL && auxNo->rot != rot2)
            {
                auxnoant = auxNo;
                auxNo = auxNo->prox;
            }
            if (auxNo->rot == rot2)
            {
                auxnoant->prox = auxNo->prox;
                free(auxNo);
            }
            else
            {
                printf("\nCONEXAO NAO ENCONTRADA!\n");
                return grafo;
            }
        }
        else if (auxgraf->no->rot == rot2)
        {
            auxNo = auxgraf->no;
            while (auxNo->prox != NULL && auxNo->rot != rot)
            {
                auxnoant = auxNo;
                auxNo = auxNo->prox;
            }
            if (auxNo->rot == rot)
            {
                auxnoant->prox = auxNo->prox;
                free(auxNo);
            }
            else
            {
                printf("\nCONEXAO NAO ENCONTRADA!\n");
                return grafo;
            }
        }
        else
        {

        }
        auxgrafant = auxgraf;
        auxgraf = auxgraf->next;
    }

    return grafo;
}
int grafoMinimo(struct Grafo *grafo)
{
    if (grafo == NULL)
        return 0;
    struct Grafo *auxgraf = NULL;
    struct No *auxNo = NULL;
    struct No *auxNoant = NULL;
    int menor = 0;
    char grfrot = ' ', menorRot = ' ';

    if (grafo->no->prox != NULL)
    {   

        grfrot = grafo->no->rot;
        menor = grafo->no->prox->val;
        menorRot = grafo->no->prox->rot;
    }
     auxgraf = grafo;
    auxNo = auxgraf->no;
    while (auxNo->prox != NULL)
    {   
        //printf("\n <%c> ",auxNo->rot);
        auxNo = auxNo->prox;
        
        if (auxNo->val < menor)
        {
            menor = auxNo->val;
            menorRot = auxNo->rot;
        }
    }
    printf("\n(%c)--(%c)", grfrot, menorRot);
    grafoMinimo(auxgraf->next);
}
int pegarTamanhoGrafo(struct Grafo *grafo)
{
    if (grafo == NULL)
        return 0;
    int cont = 0;
    cont++;
    cont += pegarTamanhoGrafo(grafo->next);
    return cont;
}
int existeAresta(struct Grafo *grafo, char p1, char p2)
{
    if (grafo == NULL)
        return 0;
    int cont = 0;
    cont += grafo != NULL ? existeAresta(grafo->next, p1, p2) : 0;
    if (grafo->no->rot == p1 || grafo->no->rot == p2)
        cont++;
    return cont;
}
int imprimirGrafoLista(struct Grafo *graf)
{
    if (graf == NULL)
    {
        return 0;
    }
    struct No *auxNo = NULL;
    printf("(%c)-> ", graf->no->rot);
    auxNo = graf->no->prox;
    while (auxNo != NULL)
    {
        printf("[%c/%d]", auxNo->rot, auxNo->val);
        auxNo = auxNo->prox;
    }
    printf("\n");
    graf->next != NULL ? imprimirGrafoLista(graf->next) : printf("\n");
}
