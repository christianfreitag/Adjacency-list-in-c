#include <stdlib.h>
#include <stdio.h>
#include "a.h"
#include <math.h>

int main()
{
	/* struct Grafo *grafo=NULL;
	printf("\n######INSERIRNDO VERTICES:#########\n");
	grafo = inserirV(grafo,'A');
	grafo = inserirV(grafo,'A');//ERRO - NÂO PODE COLOCAR 2 VERTICES COM MESMO ROTULO
	grafo = inserirV(grafo,'C');
	grafo = inserirV(grafo,'D');
	grafo = inserirV(grafo,'F');
	
	printf("\n");
	imprimirGrafoLista(grafo);
	printf("\n#######INSERIRNDO ARESTAS:########\n");
	grafo = inserirA(grafo,'A','D',5);
	grafo = inserirA(grafo,'A','B',6);//ERRO - VERTICE B NÂO EXISTE
	grafo = inserirA(grafo,'C','D',8);
	grafo = inserirA(grafo,'C','F',2);
	
	grafoMinimo(grafo);
	printf("\n");
	imprimirGrafoLista(grafo);
	printf("\n########REMOVENDO VERTICES:########\n");
	grafo = removerV(grafo,'A','*',0);
	grafo = removerV(grafo,'G','*',0);//ERRO - VERTICE G NAO EXISTE
	printf("\n\n");
	imprimirGrafoLista(grafo);

	printf("\n#######REMOVENDO ARESTAS:#########\n");
	grafo = removerA(grafo,'C','F',0);
	grafo = removerA(grafo,'C','B',0);//ERRO - NAO EXISTE VERTICE B
	printf("\n\n");
	imprimirGrafoLista(grafo);

	struct Grafo *grafo = NULL;

	printf("\n######INSERIRNDO VERTICES:#########\n");

	grafo = inserirV(grafo, 'A');
	grafo = inserirV(grafo, 'B');
	grafo = inserirV(grafo, 'C');
	grafo = inserirV(grafo, 'D');
	grafo = inserirV(grafo, 'E');
	grafo = inserirV(grafo, 'F');

	printf("\n\n");
	imprimirGrafoLista(grafo);

	printf("\n#######INSERIRNDO ARESTAS:########\n");

	grafo = inserirA(grafo, 'A', 'E', 6);
	grafo = inserirA(grafo, 'A', 'C', 10);
	grafo = inserirA(grafo, 'C', 'E', 5);
	grafo = inserirA(grafo, 'E', 'B', 2);
	grafo = inserirA(grafo, 'F', 'E', 8);
	grafo = inserirA(grafo, 'D', 'E', 8);
	grafo = inserirA(grafo, 'D', 'F', 9);
	grafo = inserirA(grafo, 'B', 'F', 4);

	printf("\n\n");
	imprimirGrafoLista(grafo);

	printf("\n####### GRAFO MINIMO ########\n");

	grafoMinimo(grafo);
	printf("\n");
	/* 
	printf("\n########REMOVENDO VERTICES: A e D ########\n");
	
	grafo = removerV(grafo, 'A', '*', 0);
	grafo = removerV(grafo, 'D', '*', 0);

	printf("\n\n");
	imprimirGrafoLista(grafo);

	printf("\n#######REMOVENDO ARESTAS:#########\n");

	grafo = removerA(grafo, 'F', 'B', 0);
	grafo = removerA(grafo, 'C', 'E', 0);

	printf("\n\n");
	imprimirGrafoLista(grafo);
	
	printf("\n#######TAMANHO GRAFO #########\n");

	printf("\n %d \n",pegarTamanhoGrafo(grafo));
	menorCaminho(grafo,'B','F',0,NULL,0);
	*/

	struct Grafo *grafo = NULL;
	printf("\n------------ INSERINDO VERTICE---------------\n");

	grafo = inserirV(grafo,'A');
	grafo = inserirV(grafo,'B');
	grafo = inserirV(grafo,'C');
	grafo = inserirV(grafo,'D');
	grafo = inserirV(grafo,'E');
	grafo = inserirV(grafo,'C');

	imprimirGrafoLista(grafo);
	printf("\n");

	printf("\n------------ INSERINDO ARESTA---------------\n");

	grafo = inserirA(grafo, 'A', 'B', 50);
	grafo = inserirA(grafo, 'A', 'C', 30);
	grafo = inserirA(grafo, 'A', 'D', 100);
	grafo = inserirA(grafo, 'A', 'E', 10);
	grafo = inserirA(grafo, 'B', 'C', 5);
	grafo = inserirA(grafo, 'D', 'B', 20);
	grafo = inserirA(grafo, 'C', 'D', 50);
	grafo = inserirA(grafo, 'D', 'E', 10);
	grafo = inserirA(grafo, 'D', 'E', 10);

	imprimirGrafoLista(grafo);
	printf("\n");

	
	//printf("\n------------ REMOVENDO VERTICE---------------\n");
	
	//grafo = removerV(grafo, 'A', '*', 0);
	//grafo = removerV(grafo, 'X', '*', 0);

	//imprimirGrafoLista(grafo);
	//printf("\n");
 
	/* printf("\n------------ REMOVENDO ARESTA---------------\n");

	grafo = removerA(grafo, 'A', 'C', 0);
	
	imprimirGrafoLista(grafo);
	printf("\n");
*/
	printf("\n------------ GRAFO MINIMO--------------\n");
	grafoMinimo(grafo);
	printf("\n\n");
	return 0;
}
