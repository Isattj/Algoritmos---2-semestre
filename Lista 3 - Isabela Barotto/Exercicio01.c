#include <stdio.h>

int main(){
    int  N;
    printf("Digite um numero inteiro \n>");
    scanf("%d", &N);

    while (N != 0){
        printf("Linha %d\n", N);
        N--;
    }
    return 0;
}