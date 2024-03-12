// --------------------------
// Definição de bibliotecas
// --------------------------

// Bibliotecas padrões da linguagem C
#include <stdio.h>
#include <stdlib.h>

// Bibliotecas que estão dentro do projeto
#include "complex.h"

// --------------------------
// Implementação das funções
// --------------------------

// Função principal do programa
int main(void) {

  Complexo *a, *b; // necessário declarar ponteiros para acessar a TAD

  // Cria dois números complexos: a e b
  a = ComplexoCriar(2, 4);
  b = ComplexoCriar(5, 12);

  // Imprime os números complexos
  printf("\nA = ");
  ComplexoImprimir(a);

  printf("\nB = ");
  ComplexoImprimir(b);

  // Realiza operações com números complexos
  Complexo *soma = ComplexoSoma(a, b);
  Complexo *diferenca = ComplexoSubtracao(a, b);
  Complexo *produto = ComplexoMultiplicacao(a, b);
  Complexo *quociente = ComplexoDivisao(a, b);

  // Imprime os resultados das operações
  printf("\nSoma = ");
  ComplexoImprimir(soma);

  printf("\nDiferença = ");
  ComplexoImprimir(diferenca);

  printf("\nProduto = ");
  ComplexoImprimir(produto);

  printf("\nQuociente = ");
  ComplexoImprimir(quociente);

  // Libera memória alocada para os números complexos e resultados
  ComplexoLiberar(a);
  ComplexoLiberar(b);
  ComplexoLiberar(soma);
  ComplexoLiberar(diferenca);
  ComplexoLiberar(produto);
  ComplexoLiberar(quociente);

  printf("\n\n");
  return 0;
}