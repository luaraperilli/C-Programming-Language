#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

struct celula {
  struct celula *ant;
  int valor;
  struct celula *prox;
};

int criarValor(void) {
  int valor;

  printf("Digite um valor: ");
  scanf("%d", &valor);

  return valor;
}

Celula *alocarCelula() {
  Celula *no = (Celula *)malloc(sizeof(Celula));

  return no;
}

Lista *alocarLista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));

  if (li != NULL)
    *li = NULL;

  return li;
}

int liberarLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  Celula *no;
  while (*li != NULL) // percorre os nos liberando o ultimo repetidamente
  {
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li); // libera a cabeca da lista

  return 1;
}

int inserirInicioLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  int dado = criarValor();
  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if (*li == NULL) // se lista vazia, insere no comeco
  {
    no->valor = dado;
    no->prox = no->ant = NULL;
    *li = no;
  } else // senão, cabeca aponta para novo no, novo no aponta para proximo no
  {
    no->valor = dado;
    no->ant = NULL;
    no->prox = *li;
    (*li)->ant = no;
    *li = no;
  }

  return 1;
}

int inserirFinalLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  int dado = criarValor();
  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if ((*li) == NULL) // se lista vazia, insere no inicio
  {
    no->valor = dado;
    no->prox = no->ant = NULL;
    *li = no;
  } else // se cheia, insere no final
  {
    Celula *aux;
    aux = *li;

    while (aux->prox != NULL) // percorre a lista ate o final
      aux = aux->prox;

    no->valor = dado;
    no->ant = aux;
    no->prox = NULL;
    aux->prox = no;
  }

  return 1;
}

int removerInicioLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  Celula *atual;
  atual = *li;
  *li = atual->prox;

  if (atual->prox != NULL)
    atual->prox->ant = NULL;

  free(atual);

  return 1;
}

int removerFinalLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  Celula *atual;
  atual = *li;

  while (atual->prox != NULL)
    atual = atual->prox;

  if (atual->ant == NULL)
    *li = atual->prox;
  else
    atual->ant->prox = NULL;

  free(atual);

  return 1;
}

int imprimirLista(Lista *li) {
  if (li == NULL || (*li) == NULL) {
    printf("\nPlaylist não encontrada!");
    return 0;
  }

  printf("\nPlaylist: ");

  Celula *aux = (*li);

  while (aux->prox != NULL) {
    printf(" %d ", aux->valor);
    aux = aux->prox;
  }

  printf(" %d ", aux->valor);

  return 1;
}

int play(Lista *li) {
  if (li == NULL || (*li) == NULL) {
    printf("\nPlaylist não encontrada!");
    return 0;
  }

  Celula *aux = (*li);

  printf("\nMúsica %d ", aux->valor);
  printf("tocando");

  return aux->valor;
}

int proximaMusica(Lista *li, int musica) {
  if (li == NULL || (*li) == NULL) {
    printf("\nPlaylist não encontrada!");
    return 0;
  }

  Celula *no = *li;
  int musicaAtual;

  while (no != NULL && no->valor != musica) {
    no = no->prox;
  }

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if (no->prox == NULL) {
    musicaAtual = no->valor;
    printf("\nMúsica %d ", musicaAtual);
    printf("(Fim da Playlist)");
  } else {
    musicaAtual = no->prox->valor;
    printf("\nMúsica %d ", musicaAtual);
    printf("tocando");
  }

  return musicaAtual;
}

int anteriorMusica(Lista *li, int musica) {
  if (li == NULL || (*li) == NULL) {
    printf("\nPlaylist não encontrada!");
    return 0;
  }
  Celula *no = *li;
  int musicaAtual;

  while (no != NULL && no->valor != musica) {
    no = no->prox;
  }

  if (no->ant == NULL) {
    musicaAtual = no->valor;
    printf("\nMúsica %d ", musicaAtual);
    printf("(Início da Playlist)");
  } else {
    musicaAtual = no->ant->valor;
    printf("\nMúsica %d ", musicaAtual);
    printf("tocando");
  }

  return musicaAtual;
}
