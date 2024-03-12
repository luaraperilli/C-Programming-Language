#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *li = NULL;
  int opcao, res, musica;

  printf("\nLL      uu  uu   AAAA   RRRR     AAAA     SSSS    OOO   NNN      NN   GGG    SSSS");
  printf("\nLL      uu  uu  AAAAAA  RR RR   AAAAAA   SS  SS  OO OO  NNNN     NN  GG GG  SS  SS");
  printf("\nLL      uu  uu  AA  AA  RR RR   AA  AA   SS      OO OO  NN NN    NN  GG     SS  ");
  printf("\nLL      uu  uu  AAAAAA  RRRR    AAAAAA    SS     OO OO  NN  NN   NN  GG GGG  SS  ");
  printf("\nLL      uu  uu  AA  AA  RR RR   AA  AA      SS   OO OO  NN   NN  NN  GG GGG    SS  ");
  printf("\nLL      uu  uu  AA  AA  RR  RR  AA  AA       SS  OO OO  NN    NN NN  GG  GG     SS  ");
  printf("\nLLLLLL   UuuU   AA  AA  RR  RR  AA  AA   SS  SS  OO OO  NN     NNNN  GGGGGG SS  SS  ");
  printf("\nLLLLLL   UuuU   AA  AA  RR  RR  AA  AA    SSSS    OOO   NN      NNN   GGGG   SSSS  ");
  
  do {
    
    printf("\n\nMenu de Opções:");
    printf("\n 0 - Sair");
    printf("\n 1 - Criar Playlist");
    printf("\n 2 - Excluir Playlist");
    printf("\n 3 - Adicionar música no início");
    printf("\n 4 - Adicionar música no final");
    printf("\n 5 - Remover música do inicio");
    printf("\n 6 - Remover música do final");
    printf("\n 7 - Mostrar Playlist");
    printf("\n 8 - Música anterior");
    printf("\n 9 - Próxima música");
    printf("\n\n 99 - Play");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      liberarLista(li);
      printf("\nFinalizando...\n\n");
      return 0;
      break;

    case 1:
      li = alocarLista();

      if (li != NULL)
        printf("\nPlaylist criada com sucesso!");
      else
        printf("\nPlaylist não criada!");

      break;

    case 2:
      res = liberarLista(li);
      li = NULL;

      if (res)
        printf("\nPlaylist liberada com sucesso!");
      else
        printf("\nPlaylist não liberada!");

      break;

    case 3:
      res = inserirInicioLista(li);

      if (res == 1)
        printf("\nMúsica adicionada com sucesso!");
      else
        printf("\nFalha ao adicionar!");

      break;

    case 4:
      res = inserirFinalLista(li);

      if (res == 1)
        printf("\nMúsica adicionada com sucesso!");
      else
        printf("\nFalha ao adicionar!");

      break;

    case 5:
      res = removerInicioLista(li);

      if (res == 1)
        printf("\nRemoção realizada com sucesso!");
      else
        printf("\nFalha na remoção!");

      break;

    case 6:
      res = removerFinalLista(li);

      if (res == 1)
        printf("\nRemoção realizada com sucesso!");
      else
        printf("\nFalha na remoção!");

      break;

    case 7:
      imprimirLista(li);
      break;

    case 8:
      musica = anteriorMusica(li, musica);
      break;

    case 9:
      musica = proximaMusica(li, musica);
      break;

    case 99:
      musica = play(li);
      break;

    default:
      printf("\nOpcão inválida!");
      break;
    }
  } while (1 == 1);

  return 0;
}