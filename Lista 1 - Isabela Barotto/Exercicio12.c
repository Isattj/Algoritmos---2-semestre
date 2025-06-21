#include <stdio.h>

int main(){
    int d;
    int anos;
    int semanas;
    int dias;

    printf("Digite a quantidade de dias:\n>");
    scanf("%d", &d);

    anos = d/365;

    semanas = (d - (365 * anos))/7;

    dias = d - ((365*anos) + (7 * semanas));

    printf("Em %d dias temos: %d ano(s), %d semana(s) e %d dia(s)\n", d, anos, semanas, dias);

    return 0;
}