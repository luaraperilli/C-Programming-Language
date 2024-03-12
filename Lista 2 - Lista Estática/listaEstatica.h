#ifndef _LISTA_ESTATICA
#define _LISTA_ESTATICA

typedef struct lista Lista;
typedef struct Produto Produto;

// Funções para alocar e desalocar memória
Lista *criar_lista();
int liberar_lista(Lista **li);

// Funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// Função para inserção de elementos da lista
int inserir_lista_inicio(Lista *li);

// Função para buscar elementos na lista
char *buscar_menor_preco(Lista *li);

// Função para remoção de elementos da lista
int remover_elementos(Lista *li, int qtd_elementos);

// Função para trocar dois elementos
int trocar_elementos(Lista *li, int posicao1, int posicao2);

// Função para imprimir a lista
int imprimir_lista(Lista *li, int index);

#endif