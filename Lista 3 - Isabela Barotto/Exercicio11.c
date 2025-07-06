#include <stdio.h>
#include <math.h>

int main(){
    int  num;
    int  num1 = num;
    int numNovo = 0;
    int cont = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &num);

    num1 = num;
    while(num1 != 0){
        num1 = num1/10;
        cont++;
    }

    num1 = num;

    while (cont != 0){
        numNovo += (num1 % 10)*(pow(10, cont-1));
        num1 = num1/10;
        cont--;
    }

    if (num == numNovo){
        printf("%d = %d\n", num, numNovo);
        printf("Palindromo!");
    } else {
        printf("%d != %d\n", num, numNovo);
        printf("Nao e palindromo!\n");

    }
    
    return 0;
}