include <stdio.h>
int main() {

//operadores aritméticos

//declara as variavéis
 int A,B,soma,subtr,mult,divis;

//pede e recebe os valores digitados pelo usuário

 printf("digite o primeiro valor:\n");
  scanf ("%d",&A);
 printf("digite o segundo valor:\n");
  scanf ("%d",&B);
//faz operação com os valores digitados
  soma= A+B;
  subtr= A-B;
  mult= A*B;
  divis= A/B;

//Mostra o resultado com os valores digitados e as operações feitas que ficaram armanazenadas nas variáveis soma,subtr,mult,divis   
  printf("resultado:\n");
  printf("soma:%d.\n",soma);
  printf("subtração:%d.\n",subtr);  
  printf("multiplicação:%d.\n",mult);
  printf("divisão:%d.\n",divis);

//incremento '++' e decremento '--' (de 1 em 1)
  A++;
  B--;
//incremento generico '+=n' e decremento generico '-=n' (de n em n)
  A+=5;
  B-=5;
//atribuição com multiplicação '*=n' e atribuição com divisão '/=n' (de n em n)
  A*=5;
  B/=5;

}