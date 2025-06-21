#include <stdio.h>

int main(){
    float x;

    printf("Digite o numero:\n>");
    scanf("%f", &x);

    if (x > 0){
        printf("O numero absoluto e: %.2f\n", x);
    } else if (x < 0){
        x = -1 * x;
        printf("O numero absoluto e: %.2f\n", x);
    } else{
        printf("O numero e zero\n");
    }
    return 0;

}