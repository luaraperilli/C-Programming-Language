// TAD para Lista Dinâmica Encadeada Circular baseado no livro "Estrutura de
// dados descomplicada em lingugem C (André Backes)"

#include "listaEncadeadaCircular.h"
#include <stdio.h>
#include <stdlib.h>

// definição do struct elemento
typedef struct elemento {
  int dado;
  struct elemento *prox;
} Elemento;

//**************************************************************************
// função para alocar memória do tipo Lista
Lista *criar_lista() {
  // 'li' é um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista *)malloc(sizeof(Lista));

  // se a alocação estiver correta 'li' aponta para NULL (lista vazia)
  if (li != NULL) {
    *li = NULL;
  } else {
    return NULL;
  }

  return li;
}

//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li) {
  // verifica se a lista foi alocada corretamente
  if (li == NULL) {
    return 0;
  }

  // verifica se a lista não está vazia
  if ((*li) != NULL) {
    Elemento *no, *aux;
    no = *li;

    // laço percorre a lista até o último elemento, liberando o anterior
    while (no->prox != (*li)) {
      aux = no;
      no = no->prox;
      free(aux);
    }

    // libera o último elemento
    free(no);

    // libera o ponteiro de ponteiro (Lista)
    free(li);
  }

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li) {
  // verifica se a lista foi alocada corretamente ou se a lista está vazia
  if (li == NULL || (*li) == NULL) {
    return 0;
  }

  // inicializa o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da
  // lista
  Elemento *no;
  no = *li;

  // incrementa 'cont' até acabar o último elemento da lista
  do {
    cont++;
    no = no->prox;
  } while (no != (*li));

  // retorna a quantidade de elementos da lista
  return cont;
}

//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li) {
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if (li == NULL) {
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor (lista vazia)
  if (*li == NULL) {
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}

//**************************************************************************
// função para alocar memória do tipo Elemento
Elemento *criar_elemento() {
  // 'no' é um ponteiro do tipo Elemento
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));

  // retorna ponteiro alocado
  return no;
}

//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int dado) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele
  // na lista)
  Elemento *no;
  no = criar_elemento();

  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;

  // verifica se a lista está vazia
  if ((*li) == NULL) {

    // insere elemento único no início da lista
    no->prox = no; // próximo elemento na lista circular é ele mesmo
    *li = no;      // 'no' passa a ser o primeiro elemento da lista

  } else {

    Elemento *aux;
    aux = *li;

    // percorre a lista até o último elemento
    while (aux->prox != (*li)) {
      aux = aux->prox;
    }

    // insere elemento no início da lista
    aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
    no->prox = *li; // primeiro elemento antigo '*li' é o próximo após o 'no'
    *li = no;       // 'no' passa a ser o primeiro elemento
  }

  return 1;
}

//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele
  // na lista)
  Elemento *no;
  no = criar_elemento();

  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado; // dado do ponteiro no recebe o dado inserido pelo usuário

  // verifica se a lista está vazia
  if ((*li) == NULL) {

    // insere elemento único no início da lista
    no->prox = no; // próximo elemento na lista circular é ele mesmo
    *li = no;      // 'no' passa a ser o primeiro elemento da lista

  } else {

    Elemento *aux;
    aux = *li; // *li é primeiro elemento da lista

    // percorre a lista até o último elemento
    while (aux->prox != (*li)) {
      aux = aux->prox;
    }

    // insere elemento no final da lista
    aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
    no->prox = *li; // primeiro elemento '*li' é o próximo após o 'no'
  }

  return 1;
}

//**************************************************************************
// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, int dado) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele
  // na lista)
  Elemento *no;
  no = criar_elemento();

  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;

  // verifica se a lista está vazia
  if ((*li) == NULL) {

    // insere elemento único no início da lista
    no->prox = no; // próximo elemento na lista circular é ele mesmo
    *li = no;      // 'no' passa a ser o primeiro elemento da lista

  } else {

    // primeira posição é a correta para inserção do elemento novo
    if ((*li)->dado > dado) {

      Elemento *aux;
      aux = *li;

      // percorre a lista até o último elemento
      while (aux->prox != (*li)) {
        aux = aux->prox;
      }

      // insere elemento no início da lista
      aux->prox =
          no; // 'no' é o próximo elemento na lista circular após o último
      no->prox = *li; // primeiro elemento antigo '*li' é o próximo após o 'no'
      *li = no;       // 'no' passa a ser o primeiro elemento
    }

    // senão, percorre a lista, a partir do segundo elemento, até achar o local
    // correto e insere
    Elemento *anterior, *atual;

    anterior = *li;
    atual = anterior->prox;

    // percorre a lista até o último elemento ou até encontrar um elemento maior
    // que o novo
    while (atual != (*li) && atual->dado < dado) {
      anterior = atual;
      atual = atual->prox;
    }

    // insere elemento na posição correta da lista (meio)
    anterior->prox =
        no; // 'no' é o próximo elemento na lista circular após o anterior
    no->prox = atual; // 'atual' é o próximo elemento após o 'no'
  }

  return 1;
}

//**************************************************************************
// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if ((*li) == NULL) {
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica
  // vazia)
  if ((*li)->prox == (*li)) {

    // libera elemento único
    free(*li);
    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *atual, *aux;
  atual = *li; // 'no' é o elemento a ser removido
  aux = *li;

  // percorre a lista até o último elemento
  while (aux->prox != (*li)) {
    aux = aux->prox;
  }

  // remove o primeiro elemento da lista
  aux->prox = atual->prox; // 'no->prox' é o próximo elemento na lista circular
                           // após o último
  *li =
      atual->prox; // primeiro elemento da lista '*li' passa a ser o 'no->prox'

  // libera Elemento 'no'
  free(atual);

  return 1;
}

//**************************************************************************
// função para remover elemento do final da lista
int remover_lista_final(Lista *li) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if ((*li) == NULL) {
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica
  // vazia)
  if ((*li)->prox == (*li)) {

    // libera elemento único
    free(*li);

    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *anterior, *atual;
  atual = *li; // 'no' é o elemento a ser removido

  // percorre a lista até 'no' ser o último elemento, armazenando o elemento
  // anterior
  while (atual->prox != (*li)) {
    anterior = atual;
    atual = atual->prox;
  }

  // remove o último elemento da lista
  anterior->prox = atual->prox; // 'no->prox' passa a ser o próximo elemento na
                                // lista circular após o 'anterior'

  // libera Elemento 'no'
  free(atual);

  return 1;
}

//**************************************************************************
// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if ((*li) == NULL) {
    return 0;
  }

  Elemento *atual;
  Elemento *anterior;

  atual = *li;

  // elemento a ser removido está no início da lista
  if (atual->dado == dado) {

    // verifica se existe apenas um elemento na lista (após remoção a lista fica
    // vazia)
    if (atual->prox == atual) {

      // indica que a lista ficou vazia e remove o 'no'
      *li = NULL;
      free(atual);

      // libera Elemento 'no'
      return 1;

      // remove o primeiro elemento
    } else {

      anterior = *li;

      // percorre a lista até o último elemento
      while (anterior->prox != (*li)) {
        anterior = anterior->prox;
      }

      // remove primeiro elemento 'no' (no = *li)
      anterior->prox = atual->prox;
      *li = atual->prox;

      // libera Elemento 'no'
      free(atual);

      return 1;
    }
  }

  anterior = atual;
  atual = atual->prox;

  // percorre a lista até achar o elemento a ser removido, ou até encontrar o
  // primeiro elemento
  while (atual != (*li) && atual->dado != dado) {
    anterior = atual;
    atual = atual->prox; 
  }

  // elemento a ser removido não foi encontrado
  if (atual == (*li)) {
    return 0;
  }

  // remove o elemento 'no'
  anterior->prox = atual->prox; // 'no->prox' passa a ser o próximo elemento na
                                // lista circular após o 'anterior'

  // libera Elemento 'no'
  free(atual);

  return 1;
}

//**************************************************************************
// função para buscar o elemento que está na posição 'pos' (primeiro elemento
// está na posição '1')
int buscar_lista_posicao(Lista *li, int pos, int *dado) {
  // verifica se a lista foi criada corretamente, se está vazia ou se a posição
  // 'pos' é inválida
  if (li == NULL || (*li) == NULL || pos <= 0) {
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  // percorre a lista até achar posicao desejada, ou até encontrar o último
  // elemento
  while (no->prox != (*li) && i < pos) {
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if (i != pos) {
    return 0;

  } else {
    // copia o dado da posição desejada (parâmetro passado por referência)
    *dado = no->dado;
    return 1;
  }
}

//**************************************************************************
// função para buscar o elemento "dado"
int buscar_lista_dado(Lista *li, int dado, int *pos) {
  // verifica se a lista foi criada corretamente ou se está vazia
  if (li == NULL || (*li) == NULL) {
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  // percorre a lista até achar o elemento desejado, ou até encontrar o último
  // elemento
  while (no->prox != (*li) && no->dado != dado) {
    no = no->prox;
    i++;
  }

  // verifica se dado procurado existe na lista
  if (no->dado != dado) {
    return 0;

  } else {
    // copia a posição da lista onde o dado foi encontrado (parâmetro passado
    // por referência)
    *pos = i;
    return 1;
  }
}

//**************************************************************************
// função para concatenar duas listas
int concatenar_listas(Lista *li, Lista *l2) {
  // verifica se a lista foi criada corretamente
  if (li == NULL || l2 == NULL) {
    return 0;
  }

  Elemento *anterior2, *atual2;
  atual2 = *l2;

  while (atual2->prox != (*l2)) { // while para passar pela lista 2 inteira
    inserir_lista_final(li, atual2->dado); // inserindo os dados da lista 2 no final da lista 1
    atual2 = atual2->prox;
  }

  inserir_lista_final(li, atual2->dado); // inserir elemento final da lista 2 na lista 1

  *l2 = NULL;

  return 1;
}

//**************************************************************************
// função para eliminar elementos repetidos
int eliminar_repetidos(Lista *li, Lista *l2) {
  // verifica se a lista foi criada corretamente
  if (li == NULL || l2 == NULL) {
    return 0;
  }

  // verifica se a lista está vazia
  if ((*li) == NULL) {
    return 1;
  }

  Elemento *aux = *li;
  int pos;

  // faz a verificação de elementos repetidos
  // se o dado não existe ele é inserido na lista 2
  while (aux->prox != (*li)) {
    if (buscar_lista_dado(l2, aux->dado, &pos) == 0) {
      inserir_lista_final(l2, aux->dado);
    }
    aux = aux->prox; // acessa o prox do elemento atual
  }
  if (buscar_lista_dado(l2, aux->dado, &pos) == 0) {
    inserir_lista_final(l2, aux->dado);
  }

  // remove todos os elementos da lista 1
  int tamanhoLista = tamanho_lista(li);
  for (int i = 0; i <= tamanhoLista; i++) {
    remover_lista_final(li);
  }

  Elemento *aux2 = *l2;

  // insere os elementos da lista 2 na lista 1
  for (int i = 1; i <= tamanho_lista(l2); i++) {
    inserir_lista_final(li, aux2->dado);
    aux2 = aux2->prox;
  }

  return 1;
}

//**************************************************************************
// função para inverter a lista
int inverter_lista(Lista *li, Lista *l2) {
  // verifica se a lista foi criada corretamente
  if (li == NULL || l2 == NULL) {
    return 0;
  }

  // verifica se a lista está vazia
  if ((*li) == NULL) {
    return 1;
  }

  Elemento *aux = *li;

  // inserção dos elementos da lista 1 na lista 2 invertidos
  while (aux->prox != (*li)) {
    inserir_lista_inicio(l2, aux->dado);
    aux = aux->prox;
  }
  inserir_lista_inicio(l2, aux->dado);

  // remove todos os elementos da lista 1
  int tamanhoLista = tamanho_lista(li);
  for (int i = 0; i <= tamanhoLista; i++) {
    remover_lista_final(li);
  }

  Elemento *aux2 = *l2;

  // insere os elementos da lista 2 na lista 1
  for (int i = 1; i <= tamanho_lista(l2); i++) {
    inserir_lista_final(li, aux2->dado);
    aux2 = aux2->prox;
  }

  return 1;
}

//**************************************************************************
// função para verificar ordenação
int verificar_ordenacao(Lista *li) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  // verifica se a lista está vazia
  if ((*li) == NULL) {
    return 1;
  }
  
  int cont_menor_igual = 0;
  int cont_maior = 0;
  Elemento *aux = *li;

  // executa a partir do índice i (com valor 1) até a condição tamanho_lista ser
  // atendida
  for (int i = 1; i < tamanho_lista(li); i++) {
    if (aux->dado <= aux->prox->dado) {
      cont_menor_igual++;
    } else {
      cont_maior++;
    }
    aux = aux->prox;
  }

  if (cont_menor_igual != 0 && cont_maior != 0) {
    // lista desordenada
    return 0;
  } else if (cont_menor_igual > 0) {
    // lista crescente
    return 1;
  } else {
    // lista decrescente
    return 2;
  }
}

//**************************************************************************
// função para imprimir a lista
int imprimir_lista(Lista *li) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }

  if ((*li) == NULL) {
    printf(" Lista vazia!");
  }

  // imprime primeiro elemento
  Elemento *no;
  no = (*li);

  // percorre lista até o último elemento
  while (no->prox != (*li)) {
    printf(" %d ", no->dado);
    no = no->prox;
  }

  // imprime último elemento
  printf(" %d ", no->dado);

  return 1;
}
