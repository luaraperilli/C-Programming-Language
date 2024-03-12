#ifndef _MODULO
#define _MODULO

typedef struct celula Celula;
typedef Celula *Lista;

//  gerenciamento
int criarValor(void);
Lista *alocarLista(void);
Celula *alocarCelula(void);
int liberarLista(Lista *li);

//  inserção
int inserirInicioLista(Lista *li);
int inserirFinalLista(Lista *li);

//  remoção
int removerInicioLista(Lista *li);
int removerFinalLista(Lista *li);

//  imprimir lista
int imprimirLista(Lista *li);

// funções implementadas
int play(Lista *li);
int proximaMusica(Lista *li, int musica); 
int anteriorMusica(Lista *li, int musica);

#endif
