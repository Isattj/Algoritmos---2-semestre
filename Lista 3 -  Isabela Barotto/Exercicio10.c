#include <stdio.h>

int main(){
    int  num;
    int  d;
    int  dezena;
    int  unidade;
    int cont = 0;

    printf("Digite um numero inteiro \n>");
    scanf("%d", &num);

    if (num >= -999 && num <= 999){
        if (num < 0){
            printf("Menos ");
            num = num * -1;
        }
        while (cont != 4){
            if (cont == 0){
                d = (num/100)%10;
                switch (d){
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
            } else if (cont == 1){
                d = (num/10)%10;
                int unidade = num %10;
                switch (d){
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
                        printf("vinte "); break;
                    case 3:
                        printf("trinta "); break;
                    case 4:
                        printf("quarenta "); break;
                    case 5:
                        printf("cinquenta "); break;
                    case 6:
                        printf("sessenta "); break;
                    case 7:
                        printf("setenta "); break;
                    case 8:
                        printf("oitenta "); break;
                    case 9:
                        printf("noventa "); break;
                    default:
                        break;
                }
            } else if (cont == 2){
                if (dezena != 1){
                    d = num%10;
                    switch (d){
                        case 1:
                            printf("um"); break;
                        case 2:
                            printf("dois"); break;
                        case 3:
                            printf("tres"); break;
                        case 4:
                            printf("quatro"); break;
                        case 5:
                            printf("cinco"); break;
                        case 6:
                            printf("seis"); break;
                        case 7:
                            printf("sete"); break;
                        case 8:
                            printf("oito"); break;
                        case 9:
                            printf("nove"); break;
                        default:
                            break;
                    }
                }
            }
        cont++;
        }
    } else{
        printf("O valor digitado nao e permitido!");
    }

    return 0;
}