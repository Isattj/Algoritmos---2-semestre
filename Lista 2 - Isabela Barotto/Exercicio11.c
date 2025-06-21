#include <stdio.h>

int main(){
    char caracter;
    printf("Digite um caracter:\n>");
    scanf("%c", &caracter);

    if ((caracter >= 'a' && caracter <='z') ){
        printf("E uma letra\n");
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'){
        printf("E uma vogal\n");
        } else{printf("E uma consoante\n");}
    } else if (caracter >= 'A' && caracter <='Z'){
        printf("E uma letra\n");
        if (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U'){
            printf("E uma vogal\n");
            } else{printf("E uma consoante\n");}

    }else if (caracter  >= 48 && caracter <= 57){
        printf("E um numero");
    } else if (caracter >= 33 && caracter <= 126){
        printf("E um simbolo");
    }
    return 0;
}