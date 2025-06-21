#include <stdio.h>

int main(){
    int  a;
    int  b;
    int maior;
    int menor;
    int mmc = 1;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &a);

    printf("Digite um numero inteiro \n>");
    scanf("%d", &b);

    if (a > b){
        maior = a;
        menor = b;
    } else {
        maior = b;
        menor = a;
    }


    for (int i = 1; i < menor; i++){
        if ((maior * i)%menor == 0){
            mmc = maior * i;
            break;
        }
    }
    printf("%d", mmc);
    return 0;
}
