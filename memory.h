#ifndef DEF_ARVORE_TRAB
#define DEF_ARVORE_TRAB

void AberturaGame(int b,int c);

void desenharMapa(int v[2],int lv[2],int value,int lValue,int doneCards[18][2],int doneQnt);

void mostrarMapa();

void ControleGeral();
int VerificarCartas(int card1,int card2);
void GerarValoresnoVerso();


int RandomNumber(int min,int max);

void delay(int milisegundos);

void controleDeDialogo(int op);

#endif