#include <stdio.h>

int main(){
    int  a;
    int  b;
    int menor;
    int mdc = 1;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &a);

    printf("Digite um numero inteiro \n>");
    scanf("%d", &b);

    if (a > b){
        menor = b;
    } else {menor = a;}


    for (int i = 2; i < menor; i++){
        if (a%i == 0 && b % i ==  0){
            mdc = i;
        }
    }

    printf("%d", mdc);
    return 0;
}