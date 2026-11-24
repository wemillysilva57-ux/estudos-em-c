#include <stdio.h>

#define MAX_NUMEROS 100
#define MAX_HISTORICO 50

// Estrutura para guardar cada calculo no historico
typedef struct {
    char operacao;
    int qtdNumeros;
    double resultado;
} RegistroHistorico;

int main() {
    double numeros[MAX_NUMEROS];
    RegistroHistorico historico[MAX_HISTORICO];
    int totalHistorico = 0;
    int opcaoMenu;

    do {
        printf("\n=== CALCULADORA AVANCADA ===\n");
        printf("1. Fazer um novo calculo\n");
        printf("2. Olhar historico de calculos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenu);

        if (opcaoMenu == 1) {
            int n = 0;
            char operacao;
            double resultado = 0;
            int erroDivisao = 0;

            // 1. Receber n numeros
            printf("\nDigite os numeros (digite uma letra, ex: 'f', para finalizar a entrada):\n");
            while (n < MAX_NUMEROS && scanf("%lf", &numeros[n]) == 1) {
                n++;
            }

            // Limpa a letra que encerrou a leitura do teclado
            while (getchar() != '\n');

            if (n == 0) {
                printf("Nenhum numero foi digitado!\n");
                continue;
            }

            // 2. Escolher uma operacao para esses n numeros
            printf("Escolha a operacao (+, -, *, /): ");
            scanf(" %c", &operacao);

            // 3. Executar a operacao escolhida por todos os n numeros
            resultado = numeros[0]; // Comeca com o primeiro numero digitado

            for (int i = 1; i < n; i++) {
                switch (operacao) {
                    case '+':
                        resultado += numeros[i];
                        break;
                    case '-':
                        resultado -= numeros[i];
                        break;
                    case '*':
                        resultado *= numeros[i];
                        break;
                    case '/':
                        if (numeros[i] != 0) {
                            resultado /= numeros[i];
                        } else {
                            printf("Erro: Divisao por zero detectada!\n");
                            erroDivisao = 1;
                        }
                        break;
                    default:
                        printf("Operacao invalida!\n");
                        erroDivisao = 1;
                        break;
                }
                if (erroDivisao) break;
            }

            // 4. Mostrar o resultado e salvar no historico
            if (!erroDivisao) {
                printf("\n>> Resultado final: %.2lf\n", resultado);

                if (totalHistorico < MAX_HISTORICO) {
                    historico[totalHistorico].operacao = operacao;
                    historico[totalHistorico].qtdNumeros = n;
                    historico[totalHistorico].resultado = resultado;
                    totalHistorico++;
                }
            }

        } else if (opcaoMenu == 2) {
            // 6. Olhar o historico de calculo
            printf("\n=== HISTORICO DE CALCULOS ===\n");
            if (totalHistorico == 0) {
                printf("Nenhum calculo realizado ainda.\n");
            } else {
                for (int i = 0; i < totalHistorico; i++) {
                    printf("%d) Operacao [%c] com %d numeros = %.2lf\n",
                           i + 1,
                           historico[i].operacao,
                           historico[i].qtdNumeros,
                           historico[i].resultado);
                }
            }
        } else if (opcaoMenu != 0) {
            printf("Opcao invalida! Tente novamente.\n");
        }

    // 5. Perguntar/repetir se o usuario quer fazer mais alguma operacao
    } while (opcaoMenu != 0);

    printf("Programa encerrado!\n");
    return 0;
}




}