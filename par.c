#include <stdio.h>
 int main() {
    int num;
    printf("digite um numero:");
    scanf("%d",&num);

    if (num % 2 ==0) {
        printf("seu número é par %d\n",num);
    }else {
        printf("seu número é ímpar %d\n",num);
    }
 return 0;
}