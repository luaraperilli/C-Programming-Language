// --------------------------
// Definição de structs 
// --------------------------

typedef struct Complexo Complexo;

// --------------------------
// Protótipos das funções
// --------------------------

// Função para criar um novo número complexo
Complexo* ComplexoCriar(float a, float b);

// Função para atribuir valores para um número complexo
int ComplexoAtribuir(Complexo* p, float a, float b);

// Função para acessar os valores de a e b do número complexo
int ComplexoAcessar(Complexo* p, float *a, float *b);

// Função para somar dois números complexos
Complexo* ComplexoSoma(Complexo* a, Complexo* b); 

// Função para subtrair dois números complexos
Complexo* ComplexoSubtracao(Complexo* a, Complexo* b); 

// Função para multiplicar dois números complexos
Complexo* ComplexoMultiplicacao(Complexo* a, Complexo* b); 

// Função para dividir dois números complexos
Complexo* ComplexoDivisao(Complexo* a, Complexo* b); 

// Função para imprimir o número complexo
void ComplexoImprimir(Complexo* p);

// Função para liberar a memória de um número complexo
void ComplexoLiberar(Complexo* p);

