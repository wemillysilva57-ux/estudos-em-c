#include <stdio.h>
//aqui está definindo o max de numeros como constante ou seja em vez de colocar um valor vai colocar uma constante por que fica mais fácil pra manutenção do código.
#define MAX_NUMEROS 100
#define MAX_HISTORICO 50

// cria um novo tipo de dado válido
typedef struct {
    char operacao;
    int qtdNumeros;
    double resultado;
} RegistroHistorico;

int main() {
    double armzmnt_numeros[MAX_NUMEROS];
    RegistroHistorico historico[MAX_HISTORICO];//array que tem os 3 tipos de dados em vez de ser separado
    int totalHistorico = 0;
    int opcaoMenu;
//mostrando as opções e recolhendo a opção escolhida pelo usuário
    do {
        printf("\n=== CALCULADORA AVANCADA ===\n");
        printf("1. Fazer um novo calculo\n");
        printf("2. Olhar historico de calculos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenu);
//se opção for == a fazer cálculo 
        if (opcaoMenu == 1) {
            int numeros = 0;//contando quantas vezes o usuário digitou
            char operacao;
            double resultado = 0;
            int erroDivisao = 0;
            int erroOperacaoInvalida = 0;

            //aqui vai entender o "total" de números que vão ser executados na operação
            printf("\nDigite os numeros (digite uma letra, ex: 'f', para finalizar a entrada):\n");
            while (numeros < MAX_NUMEROS && scanf("%lf", &armzmnt_numeros[numeros]) == 1) {
                //loop para verificar se pode receber mais um valor do usuário ou se ele já esgotou com suas possibilidades
                //se a condicional do loop for aceita adiciona mais um número dentro da variavél.
                numeros++;
            }


            if (numeros == 0) {
                printf("Nenhum numero foi digitado!\n");
            //pula para o próximo item.
                continue;
            }

            // 2. Escolher uma operacao para esses n numeros
            printf("Escolha a operacao (+, -, *, /): ");
            scanf(" %c", &operacao);

            // 3. Executar a operacao escolhida por todos os n numeros
            resultado = armzmnt_numeros[0]; // Comeca com o primeiro numero digitado
              //a i ta verificando se i é menor que a lista e dps incrementa uma unidade na var=i
            for (int i = 1; i < numeros; i++) {
                switch (operacao) {
                    case '+':
                    //soma todos os elementos da lista cujo o indice é respectivo a i e vai somar cada um de uma vez ou seja vai fazer o laço até ser menor que o total de numeros armazenados na lista armzmnt_numeros.
                        resultado += armzmnt_numeros[i];
                        break;
                    case '-':
                        resultado -= armzmnt_numeros[i];
                        break;
                    case '*':
                        resultado *= armzmnt_numeros[i];
                        break;
                    case '/':
                    
                        if (armzmnt_numeros[i] != 0) { //verifica se é 0
                            resultado /= armzmnt_numeros[i];//se não for = 0 executa
                        } else {//se for = 0 faz isso 
                            printf("Erro: Divisao por zero detectada!\n");
                            erroDivisao = 1;
                        }
                        break;
                    default:
                        printf("Operacao invalida!\n");
                        erroOperacaoInvalida = 1;
                        break;
                }
                if (erroDivisao ||erroOperacaoInvalida) break;
            }

            // 4. Mostrar o resultado e salvar no historico
            if (!erroDivisao) {
                printf("\n>> Resultado final: %.2lf\n", resultado);
               //finalizou tudo que era de calculo
                if (totalHistorico < MAX_HISTORICO) {//totalHistorico menor que o MAX_historico
                    //setar-atribuir 
                    //ta colocando os valores que recebeu do usuário na struct ou seja no registroHistorico
                    historico[totalHistorico].operacao = operacao;
                    historico[totalHistorico].qtdNumeros = numeros;
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
            //contador de total de historico para contar quantos indices o total de historico teve
                for (int i = 0; i < totalHistorico; i++) {
                    //saida para usuário exemplificada: 1)operação + com 2 numeros
                    printf("%d Operacao %c com %d numeros = %.2lf\n",//
                           i + 1,//altera o número que aparece na tela ou seja,faz isso para não ficar 0 operação e sim 1 por que vai enumerar não a quantidade de operações mas sim o número
                           historico[i].operacao,// .nome do dado declarado na struct puxa um campo da struct
                           historico[i].qtdNumeros,
                           historico[i].resultado);//o parentese se fecha quando acabar o  "resgate" dos dados do código ou seja as varia
                }
            }//parei aqui
        } else if (opcaoMenu == 0) {
            break;

        }  else  {
            printf("Opcao invalida! Tente novamente.\n");
        }

    // 5. Perguntar/repetir se o usuario quer fazer mais alguma operacao
    } while (opcaoMenu != 0);

    printf("Programa encerrado!\n");
    return 0;
}




