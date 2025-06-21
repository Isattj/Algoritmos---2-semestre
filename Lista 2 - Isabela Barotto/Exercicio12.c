#include <stdio.h>

int main(){
    int num1;
    int num2;
    char operador;
    float resultado;

    printf("[CALCULADORA SIMPLEX]\n");
    printf ("Numero01 \n>");
    scanf ("%d", &num1);

    printf ("Operador \n>");
    scanf (" %c", &operador);

    printf ("Numero02 \n>");
    scanf ("%d", &num2);

    if (operador == '+'){
        resultado = (float)num1 + num2;
        printf("O resultado da operacao %d + %d = %.2f", num1, num2, resultado);
    } else if (operador == '-'){
        resultado = (float)num1 - num2;
        printf("O resultado da operacao %d - %d = %.2f", num1, num2, resultado);
    } else if (operador == '*'){
        resultado = (float)num1 * num2;
        printf("O resultado da operacao %d * %d = %.2f", num1, num2, resultado);
    } else if (operador == '/'){
        resultado = (float)num1 / num2;
        printf("O resultado da operacao %d / %d = %.2f", num1, num2, resultado);
    } else if (operador == '%'){
        resultado = num1 % num2;
        printf("O resultado da operacao %d  %d = %.2f", num1, num2, resultado);
    }
    return 0;
}