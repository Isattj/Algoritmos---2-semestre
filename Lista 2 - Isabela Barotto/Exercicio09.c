#include <stdio.h>

int main(){
    int num;
    int dig;

    printf("Digite um numero de cinco digitos:\n>");
    scanf("%d", &num);

    if (num >= 10000 && num <= 99999){
        dig = (num/10000)%10;
        printf("%d \n", dig);
    
        dig = (num/1000)%10;
        printf("%d \n", dig);
    
        dig = (num/100)%10;
        printf("%d \n", dig);
    
        dig = (num/10)%10;
        printf("%d \n", dig);
    
        dig = num%10;
        printf("%d \n", dig);
    } else{
        printf("O  numero digitado nao possui 5 digitos");
    }


   
    return 0;
}