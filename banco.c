#ifndef MEU_BANCO_H
#define MEU_BANCO_H

#define MAX 100
#define ARQUIVO "banco.txt"

#define CORRENTE 1
#define SALARIO 2
#define POUPANCA 3

typedef struct {
    float valor;
    char transacao;
} Historico;

typedef struct {
    char cliente[50];
    float saldo;
    int tipo;
    Historico historico[5];
    int qtdHistorico;
    int numero;
    int emprestimo;
} Carteira;

int carregarBanco(Carteira c[]);
void salvarBanco(Carteira c[], int qtd);

void menuBanco(Carteira c[], int *qtd);
void cadastrarConta(Carteira c[], int *qtd);
void depositar(Carteira c[], int qtd);
void sacar(Carteira c[], int qtd);
void solicitarEmprestimo(Carteira c[], int qtd);
void mostrarRelatorio(Carteira c[], int qtd);
void mostrarHistorico(Carteira c[], int qtd);

int buscarConta(Carteira c[], int qtd, int numero, int tipo);
int lerConta(Carteira c[], int qtd);
void registrarHistorico(Carteira *c, float valor, char transacao);
float limiteEmprestimo(Carteira c[], int qtd, int i);

#endif