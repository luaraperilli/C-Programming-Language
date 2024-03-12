#include "listaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Lista *li = NULL;
  int opcao, dado, ok, pos1, pos2, qtd_remover;

  // Menu de opções para execuções de operações sobre a lista
  do {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Cadastrar produto");
    printf("\n4 - Buscar produto de menor preço");
    printf("\n5 - Remover produto");
    printf("\n6 - Trocar elementos");
    printf("\n7 - Imprimir lista");
    printf("\n8 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

      // Criar lista
      li = criar_lista();

      if (li != NULL) {
        printf("\nLista criada com sucesso!");
      } else {
        printf("\nLista não criada!");
      }
      break;

    case 2:

      // Liberar lista
      ok = liberar_lista(&li);

      if (ok) {
        printf("\nLista liberada com sucesso! %p", li);
      } else {
        printf("\nLista não liberada!");
      }
      break;

    case 3:

      // Cadastrar produto
      ok = inserir_lista_inicio(li);

      if (ok == -1) {
        printf("\nFalha na inserção do produto!");
      }

      break;

    case 4:

      // Buscar produto

      printf("\nProduto de menor preço: %s",
             buscar_menor_preco(li)); // A função já retorna a string, por isso
                                      // pode estar dentro do printf()
      break;

    case 5:

      // Remover os N últimos elementos

      printf("\nQuantos elementos deseja remover? ");
      scanf("%d", &qtd_remover);

      if (qtd_remover > 0) {
        ok = remover_elementos(li, qtd_remover);

        if (ok == 1) {
          printf("\nRemoção realizada com sucesso!");
        } else {
          printf("\nFalha na remoção! Verifique as posições.");
        }
      } else {
        printf("\nQuantidade inválida de elementos a serem removidos.");
      }
      break;

    case 6:

      // Troca elementos

      printf("\nInforme a posição do primeiro elemento que deseja trocar: ");
      scanf("%d", &pos1);
      printf("\nInforme a posição do segundo elemento que deseja trocar: ");
      scanf("%d", &pos2);

      ok = trocar_elementos(li, pos1, pos2);

      if (ok == 1) {
        printf("\nTroca realizada com sucesso!");
      } else {
        printf("\nFalha na troca! Verifique as posições.");
      }
      break;

    case 7:

      // Imprime a lista
      ok = imprimir_lista(li, 0);

      break;

    case 8:

      // Libera memória e finaliza programa
      liberar_lista(li);

      printf("\nPrograma finalizado.");
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }
  } while (opcao != 8);

  return 0;
}