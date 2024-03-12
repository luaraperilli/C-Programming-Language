// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "listaEncadeadaCircular.h"

int criar_dado(int *dado);

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Lista *l2 = NULL;

  int opcao, dado, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do {
    printf("\n\nMenu de Opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Concatenar duas listas");
    printf("\n12 - Eliminar números repetidos");
    printf("\n13 - Inverter lista");
    printf("\n14 - Verificar ordenação da lista");
    printf("\n15 - Verificar tamanho da lista");
    printf("\n16 - Imprimir lista");
    printf("\n17 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

      // criar lista
      li = criar_lista();

      if (li != NULL) {
        printf("\n Lista criada com sucesso!");
      } else {
        printf("\n Lista não criada!");
      }

      break;

    case 2:

      // liberar lista
      ok = liberar_lista(li);
      li = NULL;

      if (ok) {
        printf("\n Lista liberada com sucesso!");
      } else {
        printf("\n Lista não liberada!");
      }
      break;

    case 3:

      // inserir elemento no início
      ok = criar_dado(&dado);
      ok = inserir_lista_inicio(li, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 4:

      // inserir elemento no final
      ok = criar_dado(&dado);
      ok = inserir_lista_final(li, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 5:

      // inserir elemento de forma ordenada
      ok = criar_dado(&dado);
      ok = inserir_lista_ordenada(li, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 6:

      // remover elemento do início
      ok = remover_lista_inicio(li);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 7:

      // remover elemento do final
      ok = remover_lista_final(li);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 8:

      // remover elemento (qualquer)
      printf("\n Código a ser removido: ");
      scanf("%d", &dado);

      ok = remover_lista_meio(li, dado);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 9:

      // busca elemento pela posicao
      printf("\n Posição do elemento a ser buscado: ");
      scanf("%d", &pos);

      ok = buscar_lista_posicao(li, pos, &dado);

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento da %dª posição: ", pos);
        printf("%d", dado);
      } else {
        printf("\n Posição não existe!");
      }

      break;
      
    case 10:

      // busca elemento pelo dado
      printf("\n Código a ser buscado: ");
      scanf("%d", &dado);

      ok = buscar_lista_dado(li, dado, &pos);

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento com código %d na lista: ", dado);
        printf("%d", pos);
      } else {
        printf("\n Elemento não encontrado!");
      }

      break;

    case 11:

      // concatenar listas

      // criar e preencher segunda lista
      l2 = criar_lista();
    
      inserir_lista_final(l2, 5);
      inserir_lista_final(l2, 6);
      inserir_lista_final(l2, 7);
      inserir_lista_final(l2, 8);
      inserir_lista_final(l2, 9);
      
      ok = concatenar_listas(li, l2);

      if (ok) {
        printf("\n Listas concatenadas com sucesso:");
        imprimir_lista(li);
      } else {
        printf("\n Falha na concatenação!\n");
      }

      break;

    case 12:

      // eliminar elementos repetidos
      l2 = criar_lista();
      ok = eliminar_repetidos(li, l2);

      if (ok) {
        printf("\n Os elementos repetidos foram removidos:");
        imprimir_lista(l2);
      } else {
        printf("\n Falha na remoção de elementos repetidos!\n");
      }

      break;

    case 13:

      // inverter lista
      l2 = criar_lista();
      ok = inverter_lista(li, l2);
      
      if (ok) {
        printf("\n Lista invertida com sucesso:");
        imprimir_lista(li);
      } else {
        printf("\n Falha na inversão!");
      }

      break;

    case 14:

      // verificar ordenação
      ok = verificar_ordenacao(li);

      if (ok == 0) {
        printf("\n A lista não está ordenada! ");
      } else if (ok == 1) {
        printf("\n A lista está em ordem crescente! ");
      } else {
        printf("\n A lista está em ordem decrescente!" );
      }

      break;

    case 15:

      // verificar tamanho da lista
      printf("\n Quantidade de elementos na lista: %d", tamanho_lista(li));
      
      break;
      
    case 16:

      // imprime a lista
      printf("\n Lista encadeada circular: ");
      ok = imprimir_lista(li);

      break;

    case 17:

      // libera memória e finaliza programa
      liberar_lista(li);

      printf("\n  Programa finalizado!");
      break;

    default:
      printf("\n Opção inválida!");
      break;
    }

  } while (opcao != 17);

  return 0;
}

int criar_dado(int *dado) {
  printf("\nDigite um valor: ");
  scanf("%d", dado);

  return 1;
}
