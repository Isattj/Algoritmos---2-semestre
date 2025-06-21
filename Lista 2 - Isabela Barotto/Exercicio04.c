#include <stdio.h>

int main(){
    int ano;

    printf("Digite um ano: \n>");
    scanf("%d", &ano);

    if (ano % 400 == 0){
        printf("O ano %d e bissexto", ano);
    } else{
        printf("O ano %d nao e bissexto", ano);
    }
    return 0;
}