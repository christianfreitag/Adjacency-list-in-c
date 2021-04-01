#include <stdlib.h>
#include <stdio.h>

#ifndef TRABT
#define TRABT

struct No {
	char rot;
	struct No *prox;
	int val;
};
struct Grafo{
	struct Grafo *next;
	struct No *no;
	struct Grafo *prev;
};

struct Grafo *inserirV(struct Grafo *grafo, char newRot);
struct Grafo *inserirA(struct Grafo *grafo, char rot1,char rot2,int val);

struct Grafo *removerV(struct Grafo *grafo,char rot,char auxrot,int cmt);
struct Grafo *removerA(struct Grafo *grafo, char rot,char rot2,int cmt);

struct No *menorCaminho(struct Grafo *grafo, char rotIni, char rotEnd, int menor, char *pilha, int localPilha);
int grafoMinimo(struct Grafo *grafo);
//adicional
int existeAresta(struct Grafo *grafo,char p1,char p2);
int imprimirGrafoLista(struct Grafo *grafo);
int pegarTamanhoGrafo(struct Grafo *grafo);
#endif

/* */