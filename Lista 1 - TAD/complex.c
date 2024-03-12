// --------------------------
// Definição de bibliotecas
// --------------------------

// Bibliotecas padrões da linguagem C
#include <stdio.h>
#include <stdlib.h>

// Biblioteca que contém a definição dos protótipos das funções implementadas
// abaixo
#include "complex.h"

// --------------------------
// Definição de structs
// --------------------------
struct Complexo {
  float a;
  float b;
};

// --------------------------
// Implementação das funções
// --------------------------

// Função para crar um novo número complexo
Complexo* ComplexoCriar(float a, float b) {
  Complexo* p = (Complexo*)malloc(sizeof(Complexo));
  if (p) {
    p->a = a;
    p->b = b;
  }
  return p;
}

// Função para atribuir valores para a e b do número complexo
int ComplexoAtribuir(Complexo* p, float a, float b) {
  if (p) {
    p->a = a;
    p->b = b;
  }
  return 1;
}

// Função para acessar os valores de a e b do número complexo
int ComplexoAcessar(Complexo* p, float *a, float *b) {
  if (p) {
    *a = p->a;
    *b = p->b;
  }
  return 1;
}

// Função para realizar a soma de dois números complexos
Complexo* ComplexoSoma(Complexo *a, Complexo *b) {
  float real = a->a + b->a;
  float imag = a->b + b->b;
  return ComplexoCriar(real, imag);
}

// Função para realizar a subtração de dois números complexos
Complexo* ComplexoSubtracao(Complexo *a, Complexo *b) {
  float real = a->a - b->a;
  float imag = a->b - b->b;
  return ComplexoCriar(real, imag);
}

// Função para realizar a multiplicação de dois números complexos
Complexo* ComplexoMultiplicacao(Complexo *n1, Complexo *n2) {

  double a = n1->a;
  double b = n1->b;
  double c = n2->a;
  double d = n2->b;
  
  float real = a * c - b * d;
  float imag = b * c + a * d;
  
  return ComplexoCriar(real, imag);
}

// Função para realizar a divisão de dois números complexos
Complexo* ComplexoDivisao(Complexo *n1, Complexo *n2) {

  double a = n1->a;
  double b = n1->b;
  double c = n2->a;
  double d = n2->b;
  
  double divisor = c * c + d * d;
  if (divisor == 0.0)
    return NULL;

  double real = (a * c + b * d) / divisor;
  double imag = (b * c - a * d) / divisor;
    
  return ComplexoCriar(real, imag);
}

// Função para imprimir o número complexo
void ComplexoImprimir(Complexo *p) { 
  if (p == NULL) 
    printf("Erro!");
  else{
    if(p->b < 0){
      printf("%.2f - %.2fi\n", p->a, -1*(p->b)); 
    }else{
      printf("%.2f + %.2fi\n", p->a, p->b); 
    }
  }
}  

// Função para liberar a memória de um número complexo
void ComplexoLiberar(Complexo *p) {
  free(p); 
}