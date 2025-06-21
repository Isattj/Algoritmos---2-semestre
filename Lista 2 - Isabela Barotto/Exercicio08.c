#include <stdio.h>

int main(){
    int num;
    int milhar;
    int centena;
    int dezena;
    int unidade;

    printf("Digite um numero de quatro digitos:\n>");
    scanf("%d", &num);

    if (num/1000 >= 10){
        printf("O valor digitado e invalido!");
    } else{
        unidade = num % 10;

        num = num /10;
        dezena = num % 10;

        num = num /10;
        centena = num % 10;

        num = num /10;
        milhar = num % 10;

        switch (milhar){
        case 1:
            printf("Mil "); break;
        case 2:
            printf("Dois mil "); break;
        case 3:
            printf("Tres mil "); break;
        case 4:
            printf("Quatro mil "); break;
        case 5:
            printf("Cinco mil "); break;
        case 6:
            printf("Seis mil "); break;
        case 7:
            printf("Sete mil "); break;
        case 8:
            printf("Oito mil "); break;
        case 9:
            printf("Nove mil "); break;
        default:
            break;
        }

        switch (centena){
        case 1:
            printf("cem "); break;
        case 2:
            printf("duzentos "); break;
        case 3:
            printf("trezentos "); break;
        case 4:
            printf("quatrocentos "); break;
        case 5:
            printf("quinhentos "); break;
        case 6:
            printf("seicentos "); break;
        case 7:
            printf("setecentos "); break;
        case 8:
            printf("oitocentos "); break;
        case 9:
            printf("novecentos "); break;
        default:
            break;
        }

        switch (dezena){
            case 1:
                switch (unidade){
                    case 0:
                        printf("dez"); break;
                    case 1:
                        printf("onze"); break;
                    case 2:
                        printf("doze"); break;
                    case 3:
                        printf("treze"); break;
                    case 4:
                        printf("quatorze"); break;
                    case 5:
                        printf("quinze"); break;
                    case 6:
                        printf("dezesseis"); break;
                    case 7:
                        printf("dezessete"); break;
                    case 8:
                        printf("dezoito"); break;
                    case 9:
                        printf("dezenove"); break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("e vinte "); break;
            case 3:
                printf("e trinta "); break;
            case 4:
                printf("e quarenta "); break;
            case 5:
                printf("e cinquenta "); break;
            case 6:
                printf("e sessenta "); break;
            case 7:
                printf("e setenta "); break;
            case 8:
                printf("e oitenta "); break;
            case 9:
                printf("e noventa "); break;
            default:
                break;
        }

        if (dezena != 1){
            switch (unidade){
                case 1:
                    printf("e um"); break;
                case 2:
                    printf("e dois"); break;
                case 3:
                    printf("e tres"); break;
                case 4:
                    printf("e quatro"); break;
                case 5:
                    printf("e cinco"); break;
                case 6:
                    printf("e seis"); break;
                case 7:
                    printf("e sete"); break;
                case 8:
                    printf("e oito"); break;
                case 9:
                    printf("e nove"); break;
                default:
                    break;
            }
        }
    }

    return 0;
}