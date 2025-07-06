#include <stdio.h>
#include <string.h>

void print_string(char str[]){
    for ( int i = 0; str[i] != '\0'; i++){
        printf("%c ", str[i]);
    }
}

void print_string_reversed(char str[]){
    int compr = strlen(str);
    for (int i = compr; i >= 0; i--){
        printf("%c", str[i]);
    }
    printf("\n");

    int cont = 1;
    for(cont; str[cont] != '\0'; cont++){
        cont++;
    }

    for (int i = cont; i >= 0; i--){
        printf("%c", str[i]);
    }
}

void string_report(char str[]){
    int letras = 0;
    int digitos = 0;
     int simbolos = 0;

     for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] >= 65 && str[i]  <= 90)||(str[i] >= 97 && str[i] <= 122)){
            letras++;
        } else if (str[i] >= 48 && str[i] <= 57){
            digitos++;
        } else{
            simbolos++;
        }
     }

     printf("Letras: %d\n", letras);
     printf("Digitos: %d\n", digitos);
     printf("Simbolos: %d\n", simbolos);
}

void string_to_upper(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 32;
        }
        printf("%c", str[i]);
    }
}

int strcmp_plus(const char s1[], const char s2[]){
    int res;
    int cont1 = 0;
    int cont2 = 0;

    for(int i = 0; s1[i] != '\0'; i++){
        cont1++;
    }

    for(int i = 0; s2[i] != '\0'; i++){
        cont2++;
    }

    char s11[cont1];
    char s22[cont2];

    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] >= 97 && s1[i] <= 122){
            s11[i] = s1[i] - 32;
        } else{
            s11[i] = s1[i];
        }
        printf("%c", s11[i]);
    } 
    printf("\n");

    for(int i = 0; s2[i] != '\0'; i++){
        if(s2[i] >= 97 && s2[i] <= 122){
            s22[i] = s2[i] - 32;
        } else{
            s22[i] = s2[i];
        }
        printf("%c", s22[i]);
    }
    printf("\n");

    res = strcmp(s11, s22);
    return res;
}

int count_words_plus(const char str[]){
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == 32){
            if ((str[i+1] >= 97 && str[i+1] <= 122) || (str[i+1] >= 65 && str[i+1] <= 90)){
                cont++;
            }
        }
    }
    return cont;
}

void string_capitalize(const char str[]){
    int tamanho = 1;
    int palavra = 1;
    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }

    char str2[tamanho];
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            if(palavra == 1){
                str2[i] = str[i] - 32;
                palavra = 0;
            }else{
                str2[i] = str[i];
            } 
        } else if(str[i]>='A' && str[i]<='Z'){
            if(palavra == 1){
                str2[i] = str[i];
                palavra = 0;
            } else{
                str2[i] = str[i] + 32;
            }
        } else{
            str2[i] = str[i];
            palavra = 1;
        }
    }

    str2[tamanho - 1] = '\0';

    for (int i = 0; str2[i] != '\0'; i++){
        printf("%c", str2[i]);
    }
}

int string_compare(const char str1[], const char str2[]){
    int cont1 = 0;
    int cont2 = 0;
    int ver = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        cont1++;
    }

    for(int i = 0; str2[i] != '\0'; i++){
        cont2++;
    }
    char str11[cont1];
    char str22[cont2];

    for (int i = 0; str1[i] != '\0'; i++){
        str11[i] = str1[i];
    }

    for (int i = 0; str2[i] != '\0'; i++){
        str22[i] = str2[i];
    }

    str11[cont1-1] = '\0';
    str22[cont2-1] = '\0';

    for(int i = 0; str11[i] != '\0'; i++){
        if (str11[i] >= 'a' && str11[i] <= 'z'){
            str11[i] -= 32;
        }
    }

    for(int i = 0; str22[i] != '\0'; i++){
        if (str22[i] >= 'a' && str22[i] <= 'z'){
            str22[i] -= 32;
        }
    }

    for(int i = 0; str11[i] != '\0' && str22[i] != '\0'; i++){
        if (str11[i] == str22[i]){
            ver = 0;
        } else if (str11[i] > str22[i]) {
            ver = 1;
            break;
        } else if (str11[i] < str22[i]) {
            ver = -1;
            break;
        }
    }
    return ver;
}

void string_count(const char str[]){
    int cont = 0;
    int cont2 = 1;
    for(cont; str[cont] != '\0'; cont++);

    char str1[cont+1];

    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str1[i] = str[i] - 32;
        } else{
            str1[i] = str[i];
        }
    }

    str1[cont - 1] = '\0';

    int contador[26];
    char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < 26; i++){
        contador[i] = 0;
    }

    for(int i = 0; str1[i] != '\0'; i++){
        if (str1[i] >= 'A' && str1[i] <= 'Z'){
            cont2++;
            int index = str1[i] - 65;
            contador[index]++;
        }
    }

    for (int i = 0; i < 26; i++){
        if(contador[i] != 0){
            int percent = (100*contador[i])/cont2;
            printf("%c x %d (%d%%)\n", alfabeto[i], contador[i], percent);
        }
    }
}

void string_trim(char str[]){
    int inicio = 0;
    int final = 0;
    int i = 0;

    while (str[inicio] == ' '){
        inicio++;
    }

    final = inicio;

    while (str[final] != '\0'){
        final++;
    }

    while( str[final] == ' '){
        final--;
    }

    for (i = 0; inicio <= final; i++, inicio++){
        str[i] = str[inicio];
    }

    str[i] = '\0';

    for (int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }
}

int find_substring(const char str[], const char sub[]){
    int ver = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        while (sub[j] != '\0' && str[i+j] == sub[j]){
            j++;
        }
        if(sub[j] == '\0'){
            return 1;
        }
    }

    return 0;
}


int main(){
    int escolha;
    char str[] = "Abacate";
    char str2[] = "Abacaxi";
    char str3[] = "welCOME   To      COMPUTER programming!!";
    printf("Escolha o exercicio: \n>");
    scanf("%d", &escolha);
    switch (escolha){
    case 1:
        print_string(str);
        break;
    case 2:
        print_string_reversed(str);
    case 3:
        string_report(str);
    case 4:
        string_to_upper(str);
    case 5:
        int res = strcmp_plus(str, str2);
        printf("%d \n", res);
    case 6:
        int palavras = count_words_plus(str3);
        printf("A string possui %d palavras \n", palavras);
    case 7:
        string_capitalize(str3);
    case 8:
        int f = string_compare(str, str2);
        printf("%d \n", f);
    case 9:
        char str4[] = "Hello World of Software Development";
        string_count(str4);
    case 10:
        char s[] = "    hello world   ";
        string_trim(s);
    case 11:
        char s1[] = "first things first, second things latter";
        int ver = find_substring(s1, "ddd");
        printf("%d", ver);
    default:
        break;
    }
    return 0;
}