#include "listaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definição do tipo produto
struct Produto {
  int codigo;
  char nome[30];
  float preco;
  int qtd;
};

// Definição do tipo lista
struct lista {
  int qtd;
  Produto dados[MAX];
};
//**************************************************************************
// Função para alocar memória do tipo Lista
Lista *criar_lista() {
  // 'li' é um ponteiro do tipo Lista
  Lista *li = (Lista *)malloc(sizeof(Lista));

  // Se a alocação estiver correta a quantidade da lista é zero
  if (li != NULL) {
    li->qtd = 0;
  }

  return li;
}

//**************************************************************************
// Função para liberar memória
int liberar_lista(Lista **li) {

  // verifica se a lista foi alocada corretamente
  if (*li == NULL) {
    return 0;
  }

  // Libera o ponteiro (Lista)
  free(*li); // Libera a memória alocada
  *li = NULL; // Indica que o ponteiro "li" da função main não aponta para nada

  
  return 1;
}

//**************************************************************************
// Função para cadastrar produtos
Produto cadastrar_produto() {
  Produto produtoDigitado;
  
  printf("\nDigite o código do produto: ");
  scanf("%d", &produtoDigitado.codigo);
  printf("\nDigite o nome do produto: ");
  scanf("%s", produtoDigitado.nome);
  printf("\nDigite o preço do produto: ");
  scanf("%f", &produtoDigitado.preco);
  printf("\nDigite a quantidade do produto: ");
  scanf("%d", &produtoDigitado.qtd);

  printf("\nProduto Cadastrado:\n");
  printf("Código: %d\n", produtoDigitado.codigo);
  printf("Nome: %s\n", produtoDigitado.nome);
  printf("Preço: %1.f\n", produtoDigitado.preco);
  printf("Quantidade: %d", produtoDigitado.qtd);

  return produtoDigitado;
}

//**************************************************************************
// Função para obter o tamanho da lista
int tamanho_lista(Lista *li) {
  // Verifica se a lista foi alocada corretamente
  if (li == NULL) {
    return -1;
  } else {
    // Retorna a quantidade de elementos da lista
    return li->qtd;
  }
}

//**************************************************************************
// Função para verificar se a lista está vazia
int lista_vazia(Lista *li) {
  // Verifica se houve problema na criação da lista
  if (li == NULL) {
    return -1;
  }

  // Verifica se a lista está vazia
  if (li->qtd == 0) {
    return 1;
  }

  // Se houver elementos, retorna 0
  return 0;
}

//**************************************************************************
// Função para verificar se a lista está cheia
int lista_cheia(Lista *li) {
  // Verifica se houve problema na criação da lista
  if (li == NULL) {
    return -1;
  }

  // Verifica se a lista está cheia
  if (li->qtd == MAX) {
    return 1;
  }

  // Se não estiver cheia, retorna 0
  return 0;
}

//**************************************************************************
// Função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li) {
  // Verifica se a lista foi criada corretamente
  if (li == NULL) {
    return -1;
  }

  Produto produtoDigitado = cadastrar_produto();
  int i;

  if (lista_cheia(li) == 1) {
    return 1;
  }

  // deslocamento de todos os elementos uma posição para frente
  for (i = li->qtd; i > 0; i--) {
    li->dados[i] = li->dados[i - 1];
  }
  li->dados[0] = produtoDigitado;

  // Incrementa quantidade de elementos
  li->qtd++;

  return 0;
}

//**************************************************************************
// Função para buscar produto de menor valor
char *buscar_menor_preco(Lista *li) {

  float produto_menorpreco = li->dados[0].preco;
  int index_menorpreco = 0;

  for (int i = 0; i < li->qtd; i++) {
    if (li->dados[i].preco < produto_menorpreco) {
      produto_menorpreco = li->dados[i].preco;
      index_menorpreco = i;
    }
  }

  return li->dados[index_menorpreco].nome;
}

//**************************************************************************
// Função para remover os n últimos elementos do final da lista
int remover_elementos(Lista *li, int qtd_elementos) {

  if (li == NULL) {
    return 0;
  }

  // Verifica se a lista está vazia
  if (lista_vazia(li) == 1) {
    return 0;
  }

  if (qtd_elementos <= 0 || qtd_elementos > li->qtd) {
    return 0; // Quantidade de elementos inválida
  } else {
    li->qtd -= qtd_elementos; // Reduz a quantidade de elementos na lista
  }
  return 1; // Remoção bem-sucedida
}

//**************************************************************************
// Função para receber dois elementos da lista e trocá-los de lugar
int trocar_elementos(Lista *li, int posicao1, int posicao2) {
  if (li == NULL) {
    return 0;
  }

  // Verifica se as posições são válidas
  if (posicao1 < 0 || posicao1 >= li->qtd || posicao2 < 0 ||
      posicao2 >= li->qtd) {
    return 0; // Operação malsucedida
  }

  // Troca os elementos de lugar
  Produto temp =
      li->dados[posicao1]; // Armazena o valor do elemento na posição1
  li->dados[posicao1] =
      li->dados[posicao2]; // Atualiza o valor do elemento na posição2
  li->dados[posicao2] = temp;

  return 1;
}

//**************************************************************************
// Função para imprimir a lista de forma recursiva, ou seja, uma função que
// chama a si mesma durante sua execução
int imprimir_lista(Lista *li, int index) {
  // Verifica se a lista foi criada corretamente e se o index é valido
  if (li == NULL || index < 0 || index >= li->qtd) {
    return 0;
  }

  // Imprime as informações do elemento atual
  printf("\nCódigo: %d \n", li->dados[index].codigo);
  printf("Nome: %s \n", li->dados[index].nome);
  printf("Preço: %1.f\n", li->dados[index].preco);
  printf("Quantidade: %d\n", li->dados[index].qtd);

  // Chamada recursiva para imprimir o próximo elemento
  return imprimir_lista(li, index + 1);
}
