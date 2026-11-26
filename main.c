#include <stdio.h>
#include "meu_banco.h"

int main() {
    Carteira carteiras[MAX];
    int qtd = 0;
    int aberto = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Abrir banco\n");
        printf("2 - Historico do banco\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (aberto == 0) {
                    qtd = carregarBanco(carteiras);
                    aberto = 1;
                }
                menuBanco(carteiras, &qtd);
                break;
            case 2:
                if (aberto == 1) {
                    mostrarHistorico(carteiras, qtd);
                } else {
                    printf("O banco precisa estar aberto.\n");
                }
                break;
            case 3:
                if (aberto == 1) {
                    salvarBanco(carteiras, qtd);
                }
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}