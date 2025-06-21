#include <stdio.h>
#include <limits.h>
#include <math.h>

void printar_vetor(int n, int v[]){
    printf("[ ");
    for (int i = 0; i < n; i++){
       printf("%d ", v[i]);
    }
    printf("]");
    printf("\n");
}

void print_even(int n, int vet[]){
    for (int i = 0; i < n; i++){
        printf("Digite um numero: \n>");
        scanf("%d", &vet[i]);
    }
    

    for (int i = 0; i < n; i++){
        if (vet[i]%2 == 0){
            printf("O numero %d e par\n", vet[i]);
        }
    }  
}

void set_positive(int n, int vet[]){
    for (int i = 0; i < n; i++){
        printf("Digite um numero: \n>");
        scanf("%d", &vet[i]);
    }

    for(int i =0; i < n; i++){
        if (vet[i] < 0){
            vet[i]= -1 * vet[i];
        }
        printf("%d, ", vet[i]);
    }  
}

int find_max(int n, int vet[]){
    int maior = INT_MIN;

    for (int i = 0; i < n; i++){
        printf("Digite um numero: \n>");
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++){
        if (vet[i] > maior){
            maior = vet[i];
        }
    }
    return maior;
}

void replace_all(int n, int vet[], int elem){
    for (int i = 0; i < n; i++){
        printf("Digite um numero: \n>");
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n ; i++){
        if (vet[i] == elem){
            vet[i] = -1;
        }
        printf("%d, ", vet[i]);
    }

}

void read_vector(int n, int vet[]){
    for (int i = 0; i < n; i++){
        printf("Digite o valor: \n>");
        scanf("%d", vet[i]);
    }
}

int is_sorted(int n, int vet[]){
    int ver;

    for (int i = 0; i < n; i++){
        printf("Digite um numero: \n>");
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++){
        if (i > 1){
            if (vet[i] > vet[i-1]){
                ver = 1;
            } else {
                ver = 0;
                break;
            }
        }
    }
    return ver;
}

void distances(int n, int points[]){
    double dist;
    for(int i = 0; i < n; i++){
        printf("Digite um valor: \n>");
        scanf("%d", &points[i]);
    }

    for (int i = 0; i < n; i = i+2){
        if (i+3 < n){
            double x = ((double)points[i+2] - points[i])*(points[i+2] - points[i]);
            double y = (points[i+3] - points[i+1])*(points[i+3] - points[i+1]);
            dist = sqrt(x+y);
            printf("A distancia entre os pontos: (%d, %d) e (%d, %d) e: %f\n", points[i], points[i+1], points[i+2], points[i+3], dist);
        }    
    }    
}

void reverse(int n, int vet[]){
    int vet2[n]; 
    for(int i = 0; i < n; i++){
        printf("Digite um valor: \n>");
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++){
        vet2[i]= vet[i];
    }

    for (int i = 0; i < n; i++){
        vet[i]= vet2[n-(1+i)];
        printf("%d", vet[i]);
    }
}

void vector_copy(int n, int vet2[], int vet1[]){
    for(int i = 0; i < n; i++){
        printf("Digite um valor para o vetor 1: \n>");
        scanf("%d", &vet1[i]);
    }
    for(int i = 0; i < n; i++){
        printf("Digite um valor para o vetor 2: \n>");
        scanf("%d", &vet2[i]);
    }

    printf("Vetor 2 antes de copiar:\n");
    printar_vetor(n, vet2);

    for(int i = 0; i < n; i++){
        vet2[i]= vet1[i];
    }

    printf("Vetor 2 depois de copiar:\n");
    printar_vetor(n, vet2);
}

int vector_insert(int n, int vet1[], int elem){
    int ver;
    for (int i = 0; i < n; i++){
        printf("Digite um valor para o vetor: \n>");
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < n; i++){
        if (vet1[i] == -1){
            vet1[i] = elem;
            ver = 1;
            break;
        } else{
            ver = 0;
        }
    }

    printar_vetor(n, vet1);
    return ver;
}

void vector_remove(int n, int vet1[], int pos){
    if (pos <= n){
        for (int i = 0; i < n; i++){
            printf("Digite um valor para o vetor: \n>");
            scanf("%d", &vet1[i]);
        }
        vet1[pos] = -1;
        for (int i = 0; i < n; i++){
            printf("%d, ", vet1[i]);
        }
    } else {
        printf("A posicao digitada e invalida");
    }
    
}

void vector_defrag(int n, int vet[n]){
    int vAux[n];
    int k = 0;
    for (int i = 0; i < n; i++){
        printf("Digite o valor para o vetor: \n>");
        scanf("%d", &vet[i]);
        vAux[i] = vet[i];
    }

    printf("Vetor antes de organizar:\n");
    printar_vetor(n, vet);

    for(int j = 0; j < n; j++){
        if (vAux[j] != -1){
            vet[k] = vAux[j];
            k++;
        }
    }

    while (k < n){
        vet[k] = -1;
        k++;
    }


    printf("Vetor depois de organizar:\n");
    printar_vetor(n, vet);
    printf("\n");
}

void vector_concat(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    int n3 = n1 + n2;
    v3[n3];
    for (int i = 0; i < n1; i++){
        printf("digite o valor para o vetor 1: \n>");
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < n2; i++){
        printf("digite o valor para o vetor 2: \n>");
        scanf("%d", &v2[i]);
    }
    int cont = 0;
    for (int i =0; i < n1;i++){
        v3[i] = v1[i];
        cont++;
    }
    int g =0;
    for (int i = cont; i < n3;i++){
        v3[i] = v2[g];
        g++;
    }

    for (int j = 0; j <n3; j++){
        printf("%d, ", v3[j]);
    }
}

void merge(int n1, int v1[], int n2, int v2[], int v3[]){
    int n3 = n1 + n2;
    v3[n3];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2){
        if(v1[i] < v2[j]){
            v3[k] = v1[i];
            i++;
        } else{
            v3[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        v3[k] = v1[i];
        i++;
        k++;
    }
    while (j < n2){
        v3[k] = v2[j];
        j++;
        k++;
    }

    printar_vetor(n3, v3);
}

int max_sum_slice2(int n, int v[]){
    int soma = 0;
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        soma += v[i];

        if (soma < 0){
            soma = 0;
        } else if (soma > max) {
            max = soma;
        }
    }
    return max;
}

void count_elements(int n, int vet[]){
    int maior = -1;
    for(int i = 0; i < n; i++){
        if (vet[i] > maior){
            maior = vet[i];
        }
    }
    int cont[maior+1];

    for(int i = 0; i < maior+1; i++){
        cont[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int index = vet[i];
        cont[index]++;
    }

    for (int i = 0; i < n; i++){
        if(cont[i] != 0){
            printf("%d x [%d]\n", i, cont[i]);
        }
    }
}

void min_bills(int value, int n, int bills[]){
    int cont[n];

    for (int i = 0; i < n; i++){
        cont[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--){
        while (value >= bills[i]){
            value -= bills[i];
            cont[i]++;
        }
    }

    for (int i = n -1; i >= 0; i--){
        if (cont[i] > 0){
            printf("%d x [%d,00]\n", cont[i], bills[i]);
        }
    }
}

void vector_union(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    int n3 = n1 + n2;
    int j = 0, k = 0, m = 0;

    while (j < n1){
        v3[k] = v1[j];
        k++;
        j++;
    }

    for(int i = 0; i < n2; i++){
        int ver = 1;
        for (int n = 0; n < n3; n++){
            if (v3[n] == v2[i]){
                ver = 0;
                 break;
            }
        }
        if(ver == 1){
            v3[k] = v2[i];
            k++;
        }
    }
    printar_vetor(n3, v3);
}

void vector_intersection(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    int k = 0;
    for (int i = 0; i < n2; i++){
        for (int j = 0; j < n1; j++){
            if (v1[j] == v2[i]){
                v3[k] = v1[j];
                k++;
                break;
            }
        }
    }
    int n3;
    if (n1 < n2){
        n3 = n1;
    } else{
        n3 = n2;
    }

    printar_vetor(n3, v3);
}

int main(){
    int ex;
    printf ("Escolha o exercicio: \n>");
    scanf ("%d", &ex);

    switch (ex){
        case 1:{
            int n;
            printf("Digite o tamnho do  vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            print_even(n, vet);
            break;
        }
        case 2:{
            int n;
            printf("Digite o tamnho do  vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            set_positive(n, vet);
            break;
        }
        case 3:{
            int n;
            printf("Digite o tamnho do  vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            int m =find_max(n, vet);
            printf("O maior valor do vetor e: %d", m);
            break;
        }
        case 4:{
            int n;
            int elem;
            printf("Digite o tamnho do  vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            printf("Digite o valor do elemento procurado: \n>");
            scanf("%d", &elem);
            replace_all(n, vet, elem);
            break;
        }
        case 5:{
            int n;
            printf("Digite o tamnho do  vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            read_vector(n, vet);
            break;
        }
        case 6:{
            int n;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            int ver = is_sorted(n, vet);
            printf("%d", ver);
            break;
        }
        case 7:{
            int n;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            distances(n, vet);
            break;
        }
        case 8:{
            int n;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            reverse(n, vet);
            break;
        }
        case 9:{
            int n;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet1[n];
            int vet2[n];

            vector_copy(n, vet1, vet2);
            break;
        }
        case 10:{
            int n;
            int elem;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];
            printf("Digite o valor a ser inserido: \n>");
            scanf("%d", &elem);

            int ver = vector_insert(n, vet, elem);
            printf("%d", ver);
            break;
        }
        case 11:{
            int n;
            int pos;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];
            printf("Digite a posicao que deseja ser removida: \n>");
            scanf("%d", &pos);

            vector_remove(n, vet, pos);
            break;
        }
        case 12:{
            int n;
            printf("Digite o tamanho do vetor: \n>");
            scanf("%d", &n);
            int vet[n];

            vector_defrag(n, vet);
            break;
        }
        case 13:{
            int n1;
            int n2;
            printf("Digite o tamanho do vetor 1: \n>");
            scanf("%d", &n1);
            int vet1[n1];

            printf("Digite o tamanho do vetor 2: \n>");
            scanf("%d", &n2);
            int vet2[n2];
            int n3 = n1 + n2;
            int vet3[n3];

            vector_concat(n1, vet1, n2, vet2, vet3);
            break;
        }
        case 14:{
            int v1[] = {1,3,4,7,9,10};
            int v2[] = {2,3,5,7,7,14};
            int n1 = 6;
            int n2 = 6;

            int n3 = n1 + n2;
            int vet3[n3];

            merge(n1, v1, n2, v2, vet3);
            break;
        }
        case 15:{
            int n = 12;
            int v[] = {5, 2,-2,-7, 3,14,10,-3, 9,-6, 4, 1};
            int max = max_sum_slice2(n, v);
            printf("%d", max);
        }
        case 16:{
            int n = 10;
            int v[] = {2, 6, 2, 1, 7, 9, 5, 1, 6, 2};
            count_elements(n, v);
        }
        case 17:{
            int value = 209;
            int n = 5;
            int bills[] = {1, 5, 10, 50, 100};

            min_bills(value, n, bills);
        }
        case 18:{
            int n1 = 5;
            int n2 = 3;
            int v1[5] = {1,2,3,4,5};
            int v2[3] = {2,3,8};
            int v3[8] = {0};

            vector_union(n1, v1, n2, v2, v3);
        }
        case 19:{
            int n1 = 5;
            int n2 = 3;
            int v1[5] = {1,2,3,4,5};
            int v2[3] = {2,3,8};
            int v3[3] = {0};

            vector_intersection(n1, v1, n2, v2, v3);
        }
        default:
            break;
    }
    return 0;
}