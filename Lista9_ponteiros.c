#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct Product {
int id; // identificador do produto
int stock; // estoque do produto
char name[101]; // nome do produto
} Product;

void adress(){
    char c[] = "Oi";
    int n = 0;
    double d = 3.0;

    printf("Endereco do char: %p\n", (void*)c);
    printf("Endereco do inteiro: %p\n", &n);
    printf("Endereco do double: %p\n", &d);
}

void add(int* a, int* b){
    *a = *a + *b;
    printf("Soma: %d\n", *a);
}

void print_vector(int n, const int* v){
    for (int i = 0; i < n; i++){
        printf("%d ", *v);
        v++;
    }
}

void print_vector_reverse(int n, const int* v){
    const int *p = v + n - 1;
    for (int i = 0; i < n; i++){
        printf("%d ", *p);
        p--;
    }
    printf("\n");
}

void get_min_max(int n, const int* v, int* min, int* max){
    *min = INT_MAX;
    *max = INT_MIN;
    for (int i = 0;  i < n; i++){
        if(*v < *min){
            *min = *v;
        }
        if (*v > *max){
            *max = *v;
        }
        v++;
    }
    printf("O menor numero e: %d\n", *min);
    printf("O maior numero e: %d\n", *max);
}


void make_mirrored(char* str){
    int tam = strlen(str);
    char *p = str + tam;
    char *l = p - 1;
    *p = '|';
    p++;

    for (int i = 0; i < tam; i++){
        *p = *l;
        p++;
        l--;
    }

    p++;
    *p = '\0';
}

int get_hamming_distance(const char* str1, const char* str2){
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int cont = 0;
    if (tam1 != tam2){
        return -1;
    }
    for(int i = 0; i < tam1; i++){
        if (*str1 != *str2){
            cont++;
        }
        str1++;
        str2++;
    }
    return cont;
}

char* find_most_similar(const char* str, int n, char list[n][50]){
    int indMin = -1;
    int tem = 0;
    int menor = INT_MAX;
    char (*p)[50] = list;

    for (int i = 0; i < n; i++){
        tem = get_hamming_distance(str, *p);

        if (tem != -1 && tem < menor){
            indMin = i;
            menor = tem;
        }
        p++;
    }

    if (indMin == -1){
        return NULL;
    }

    return *(list + indMin);
}

typedef struct {
int id;
char name[51];
int type; // [1..10]
} Contact;

int find_by_name(int n, const Contact* vec, const char* find){
    int cont = 0;
    Contact* p = vec;

    for(int i = 0; i < n; i++){
        if(strstr(p->name, find) != 0){
            cont++;
        }
        p++;
    }
    return cont;
}

void count_types(int n, const Contact* vec){
    int cont_type[10] = {0};
    
    for(int i = 0; i < n; i++){
        int *ct = cont_type;
        int t = (vec + i)->type;
        ct = ct + t - 1;
        (*ct)++;
    }

    int *ct = cont_type;
    for(int i = 0; i < 10; i++){
        printf("%d ", *(ct+i));
    }
}

typedef struct Product{
    int id;
    int stock;
    char name[101];
} Product;

void check_stock(int n1, const Product* prods, int n2, int* orders){
    Product *p = prods;

    for(int i = 0; i < n1; i++){
        if(p->stock <= 0){
            int ver = 0;
            for(int j = 0; j < n2; j++){
                if(p->id == *(orders + j)){
                    ver = 1;
                    break;
                }
            }
            if(ver == 0){
                *(orders + n2) = p->id;
                n2++;
            }
        }
        p++;
    }
}

int main(){
    Contact v[] = {
        {1, "Um"},
        {2, "Dois"},
        {3, "Tres"},
        {4, "Quatro"},
        {5, "Cinco"},
        {6, "Seis"},
        {7, "Sete"}
    };
    int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e)
    {
        case 1:
            adress();
            break;
        case 2:
            int a = 10;
            int b = 25;
            add(&a, &b);

            break;
        case 3:
            int v1[] = {1, 2, 3, 4, 5};
            print_vector(5, v1);
            break;

        case 4:{
            int v2[] = {1, 2, 3, 4, 5};
            print_vector_reverse(5, v2);
            break;
        }
        case 5:{
            int v3[] = {1, 2, 3, 4, 5};
            int min, max;
            get_min_max(5, v3, &min, &max);
            break;
        }
        case 6:{
            char name[40] = "John Doe";
            make_mirrored(name);
            printf("%s\n", name);
            break;
        }
        case 7:
            int dist = get_hamming_distance("banann", "cabana");
            printf("%d \n", dist);
            break;
        case 8:
            char words[][50] = {"baiana", "savata", "cabana", "haluha"};
            char* most_similar = find_most_similar("banana", 4, words);
            if(most_similar == NULL){
                printf("Os tamanhos sao diferentes");
            } else{
                printf("%s\n", most_similar);
            }
            break;
        case 9:{
            char str[] = "al";
            Contact contacts[] = {
                {1, "alice", 3},
                {2, "alface", 5},
                {3, "calma", 1},
                {4, "cealia", 7},
                {5, "Eve", 2}
            };

            printf("%d", find_by_name(5, contacts, str));
            break;
        }
        case 10:{
            Contact contacts[] = {
                {1, "alice", 3},
                {2, "alface", 5},
                {3, "calma", 1},
                {4, "cealia", 7},
                {5, "Eve", 2}
            };

            count_types(5, contacts);
            break;
        }
        case 11:{
            
            break;
        }
        default:
            break;
    }
    return 0;
}