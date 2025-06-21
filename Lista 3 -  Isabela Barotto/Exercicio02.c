#include <stdio.h>

int main(){
    int dec;
    int oct;
    int hex;
    char chr;
    int cont = 33;

    printf("DEC   OCT   HEX   CHR\n");

    while (cont != 127){
        printf("%03d   %03o   %03X     %c \n", cont, cont, cont, cont);
        cont++;
    }
    return 0;
}