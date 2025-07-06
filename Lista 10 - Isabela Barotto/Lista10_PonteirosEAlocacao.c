#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void print_vector(int m, int *v){
    for (int i = 0; i < m; i++) {
        printf("%d ",*(v+i));
    }
}

void fill(int* v, int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 100;
    }
}

int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* create_vector(int n){
    int *v = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        *(v+i) = 0;
    }
    return v;
}

int* get_largest(int n, int* v, int max){
    qsort(v, n, sizeof(int), compare_desc);

    int *v1 = malloc(max * sizeof(int));

    for (int i = 0; i < max; i++) {
        *(v1 + i) = *(v + i);
    }

    return v1;
}

char* copy_string(const char* str){
    int tamanho = strlen(str) + 1;
    
    char *str1 = malloc(tamanho * sizeof(char));

    for(int i = 0; i < tamanho; i++){
        *(str1 + i) = *(str + i);
    }
    return str1;
}

char* copy_reverse(const char* str){
    int tamanho = strlen(str);
    printf("%d\n", tamanho);

    char *str1 = malloc(tamanho + 1 * sizeof(char));

    int j = 0;
    for(int i = tamanho - 1; i >= 0; i--){
        *(str1 + j) = *(str + i);
        j++;
    }

    *(str1 + j) = '\0';
    return str1;
}

char* concat_string(const char* str1, const char* str2){
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int tamanho = (tam1 + tam2 + 1);

    char *newStr = malloc(tamanho * sizeof(char));

    int j = 0;
    for(int i = 0; i < tam1; i++){
        *(newStr + j) = *(str1 + i);
        j++;
    }

    for(int i =0; i < tam2; i++){
        *(newStr + j) = *(str2 + i);
        j++;
    }

    *(newStr + j) = '\0';
    return newStr;
}

char* stringcat_all(int n, char str[n][51]){
    int tamanho = n;
    for(int i = 0; i < n; i++){
        tamanho += strlen(str[i]);
    }

    char* str1 = malloc(tamanho * sizeof(char));
    int c = 0;
    for(int i = 0; i < n; i++){
        const char* s = str[i];
        while(*s != '\0'){
            *(str1 + c) = *s;
            c++;
            s++;
        }

        if(i < n-1){
            *(str1 + c) = ' ';
            c++;
        }
    }
    *(str1 + c) = '\0';
    return str1;
}

int* array_union(const int* v1, int n1, const int* v2, int n2, int* n3){
    int *v3 = malloc((n1 + n2) * sizeof(int));

    *n3 = 0;

    for(int i = 0; i < n1; i++){
        int repetido = 0;
        for(int j = 0; j < *n3; j++){
            if(*(v1 + i) == *(v3 + j)){
                repetido = 1;
                break;
            }
        }
        if(!repetido){
            *(v3 + *n3) = *(v1 + i);
            (*n3)++;
        }
    }

    for(int i = 0; i < n2; i++){
        int repetido = 0;
        for(int j = 0; j < *n3; j++){
            if(*(v2 + i) == *(v3 + j)){
                repetido = 1;
                break;
            }
        }
        if(!repetido){
            *(v3 + *n3) = *(v2 + i);
            (*n3)++;
        }
    }
    return v3;
}

int* array_intersection(const int* v1, int n1, const int* v2, int n2, int* n3){
    int *v3 = malloc((n1+n2) * sizeof(int));
    *n3 = 0;

    for(int i = 0; i < n1; i++){
        int repetido = 0;
        for(int j = 0; j < n2; j++){
            if(*(v1 + i) == *(v2 + j)){
                for(int k = 0; k < *n3; k++){
                    if(*(v1 + i) == *(v3 + k)){
                        repetido = 1;
                        break;
                    }
                }

                if(!repetido){
                    *(v3 + *n3) = *(v1 + i);
                    (*n3)++;
                }
            }
        }
    }
    return v3;
}

int* expand(int* v, int n, int new_n){
    int *v1 = malloc(new_n * sizeof(int));

    for(int i = 0; i < new_n; i++){
        *(v1 + i) = 0;
    }

    int limite = 0;
    if(n < new_n){
        limite = n;
    } else if(n > new_n){
        limite = new_n;
    } else{
        limite = n;
    }

    for(int i = 0; i < limite; i++){
        *(v1 + i) = *(v + i);
    }

    free(v);
    return v1;
}

int* totals(int rows, int cols, int vec[rows][cols]){
    int *v2 = malloc(rows * sizeof(int));

    for(int i = 0; i < rows; i ++){
        int soma = 0;
        for(int j = 0; j < cols; j++){
            soma += vec[i][j];
        }
        *(v2 + i) = soma;
    }
    return v2;
}

int main(){
    int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e)
    {
        case 1:{
            int* v1 = create_vector(7);
            print_vector(7, v1);
            free(v1);
             break;
        }
        case 2:{
            int v0[] = {6,10,2,1,2,3,9};
            int* v1 = get_largest(7, v0, 2);
            print_vector(2, v1);
            free(v1);
            break;
        }
        case 3:{
            char str[50] = "Pao com batata";
            char* str1 = copy_string(str);
            printf("%s \n", str1);
            free(str1);
            break;
        }
        case 4:{
            char str[50] = "Pao com batata";
            char* str1 = copy_reverse(str);
            printf("%s \n", str1);
            free(str1);
            break;
        }
        case 5:{
            char str1[50] = "Pao com";
            char str2[50] = "mortadela";
            char* str3 = concat_string(str1, str2);
            printf("%s \n", str3);
            free(str3);
            break;
        }
        case 6:{
            char words[][51] = {"Um", "Dois", "Tres", "Quatro"};
            char* str = stringcat_all(4, words);
            printf("%s \n", str);
            free(str);
            break;
        }
        case 7:{
            int v1[] = {1,3,2,5,4};
            int v2[] = {3,6,7,4};
            int n3;
            int *v3 = array_union(v1, 5, v2, 4, &n3);
            print_vector(n3, v3);
            free(v3);
            break;
        }
        case 8:{
            int v1[] = {1,3,2,5,4};
            int v2[] = {3,6,7,4};
            int n3;
            int *v3 = array_intersection(v1, 5, v2, 4, &n3);
            print_vector(n3, v3);
            free(v3);
            break;
        }
        case 9:{
            int* v = malloc(10 * sizeof(int));
            fill(v, 10);
            v = expand(v, 10, 20);
            print_vector(20, v);
            break;
        }
        case 10:{
            int v[3][4] = { {1,0,3,5}, {2,4,7,1}, {5,3,3,1} };
            int *sum = totals(3, 4, v);
            print_vector(3, sum);
            break;
        }
        default:
            break;
    }
    return 0;
}