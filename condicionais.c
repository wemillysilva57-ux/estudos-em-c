include <stdio.h>
main(){
    int idade;

    printf("digite sua idade\n");
    scanf("%d",&idade);

    if (idade>=18){
        printf("voce já esta apto a tirar a habilitação!!\n")
    }
    else{
        printf("você não pode tirar a habilitação!!\n")
    }
}