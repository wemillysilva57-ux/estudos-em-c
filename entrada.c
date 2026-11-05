include <stdio.h>
int main() {
//variável
    int idade = 0;

    printf("valor inicial da idade;%d.\n",idade);
    printf("digite uma idade:\n");

//vai substituir o valor da idade pelo valor digitado
    scanf("%d",&idade);
//printa o valor recebido dentro do scanf
    printf("idade informada:%d.\n",idade);
}
