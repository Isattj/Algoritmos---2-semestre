#include <stdio.h>

int main(){
    float num;
    int pInteira;
    float pDecimal;

    printf("Informe o numero float\n>");
    scanf("%f", &num);

    pInteira = (int)num;
    pDecimal = num - pInteira;

    printf("A parte inteira do numero %.2f e %d\n", num, pInteira);
    printf("A parte decimal do numero %.2f e %.2f\n", num, pDecimal);
    printf("O numero em notacao cientifica: %e\n", num);
    return 0;
}