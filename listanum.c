#include <stdio.h>
#include <stdlib.h>

int main(){

    int qtd;

    printf("digite a quantidade de números inteiros que voce deseja armazenaar?\n");
    scanf("%d",&qtd);
//só pode definir ponteiro com o tipo de dado antes.
    int *listaNum = malloc(qtd * sizeof(*listaNum));//o sizeof pode ser tanto do ponteiro quanto do tipo de dado.
//o primeiro é o tipo de dado/nome do ponteiro/malloc=aloca/qtd=num para armazenar/diz o tamanho de um elemento do determinado tipo.
//ou seja depois é necessário que multiplicar pela qtd que eu quero.
    if (listaNum == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }




    

}