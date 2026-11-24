#include <stdio.h>
 int main(){
//switch case só compara igualdade
    int opcao;
    float compra,desconto,valorFinal;

    printf("digite o valor da sua compra: R$ \n");
    scanf ("%f",&compra);

    printf("escolha uma opção:\n");
    printf("1-compra maior que $100\n");
    printf("2-compra maior que $200\n");
    printf("3-compra maior que $300\n");
    printf("4-compra maior que $400\n");
    printf("5-compra maior que $1000\n");
    
    printf("\nDigite uma opção:\n");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            desconto = 0.10;
            break;
        case 2:
            desconto = 0.15;
            break;
        case 3:
            desconto = 0.20;
            break;
        case 4:
            desconto = 0.25;
            break;
        case 5:
            desconto = 0.30;
            break;
        default:
        printf("\nopção inválida\n");
        return 0;
    }

    valorFinal= compra -(compra * desconto);
//esse %.0f%% serve para meio que transformar um numero decimal em uma porcentagem 
    printf ("\nparabens!voce ganhou %.0f%% de desconto!\n",desconto * 100);
//obs:se você quiser colocar o valor de uma variavel é só colocar o tipo de dado e depois ,e variavél
    printf("você iria pagar: R$ %2f\n",compra);
    printf("agora você vai somente : R$%f",valorFinal);

    return 0;

}