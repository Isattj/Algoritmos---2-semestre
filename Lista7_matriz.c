#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf(" %d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_reversed(int rows, int cols, int m[rows][cols]){
    for (int i = rows-1; i >= 0; i--){
        for (int j = cols-1; j >= 0; j--){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_min_max(int rows, int cols, int m[rows][cols]){
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (m[i][j]<min){
                min = m[i][j];
            }
            if (m[i][j] > max){
                max = m[i][j];
            }
        } 
    }
    printf("O menor numero e: %d\n", min);
    printf("O maior numero e: %d\n", max);
}

float average(int rows, int cols, int m[rows][cols]){
    int soma = 0;
    int cont = rows * cols;
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            soma += m[i][j];
        }
    }
    float media = soma / cont;
    return media;
}

void init_values(int rows, int cols, int m[rows][cols], int start, int step){
    int cont = start;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m[i][j] = cont;
            cont+= step;
        }
    }
    print_matrix(rows, cols, m);
}

void init_random(int rows, int cols, int m[rows][cols], int min, int max){
    srand(time(NULL));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m[i][j] = rand() % (max - min + 1) + min;
        }
    }
    print_matrix(rows, cols, m);
}

int max_line(int rows, int cols, int m[rows][cols]){
    int somaMax = INT_MIN;
    for(int i = 0; i < rows; i++){
        int soma = 0;
        for(int j = 0; j < cols; j++){
            soma += m[i][j];
        }
        if (soma > somaMax){
            somaMax = soma;
        }
    }
    return somaMax;
}

void put_totals(int rows, int cols, int m[rows][cols]){
    for(int i = 0; i < rows; i++){
        int  soma = 0;
        for(int j = 0; j < cols; j++){
            if(j == cols - 1){
                m[i][j] = soma;
            } else{
                soma += m[i][j];
            }
        }
    }

    print_matrix(rows, cols, m);
}

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    if (r1 != r2 || c1 != c2){
        return 0;
    }
    for(int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            if (m1[i][j] != m2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    print_matrix(rows, cols, m3);
}

void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            m2[j][i] = m1[i][j];
        }
    }
    print_matrix(c1, r1, m2);
}

void switch_diagonals(int d, int m1[d][d]){
    for(int i = 0; i < d; i++){
        int temp = m1[i][i];
        m1[i][i] = m1[i][d -1 -i];
        m1[i][d - 1 - i] = temp;
    }
    print_matrix(d, d, m1);
}

void pascal_triangle(int n){
    int m[n][n+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            if(i == 0 && j == 1){
                m[i][j] = 1;
            } else{
                m[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            m[i+1][j+1] = m[i][j] + m[i][j+1];
        }
    }
    print_matrix(n, n+1, m);
}

int check_upper_triangle(int d, int m[d][d]){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < i; j++){
            if(m[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int check_identity(int rows, int cols, int m[rows][cols]){
    if (rows != cols){
        return 0;
    }

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (i == j && m[i][j] != 1){
                return 0;
            } else if (i != j && m[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int check_symmetric(int d, int m[d][d]){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if (m[i][j] != m[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

void print_strings(int n, int len, char list[n][len]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < len; j++){
            printf("%c", list[i][j]);
        }
        printf("\n");
    }
}

void print_strings_minmax(int n, int len, char list[n][len]){
    int min = INT_MAX;
    int max = INT_MIN;
    int indiceMin = -1;
    int indiceMax = -1;

    for(int i = 0; i < n; i++){
        int cont = 0;

        for(int j = 0; j < len; j++){
            if (list[i][j] =='\0'){
                break;
            }
            cont++;
        }
        if (cont < min){
            min = cont;
            indiceMin = i;
        }
        if (cont > max){
            max = cont;
            indiceMax = i;
        }
    }
    printf("Menor string: %s\n", list[indiceMin]);
    printf("Maior string: %s\n", list[indiceMax]);
}

int count_words(int n, int len, char lines[n][len]){
    int cont = 0;
    int estado = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < len; j++){
            if((lines[i][j] >= 'A' && lines[i][j] <= 'Z') ||(lines[i][j] >= 'a' && lines[i][j] <= 'z')){
                if (estado == 1){
                    cont++;
                    estado = 0;
                }
            } else{
                estado = 1;
            }
        }
    }
    return cont;
}

int count_occurrences(int n, int len, char lines[n][len], char word[]){
    int count = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < len; j++){
            if (lines[i][j] == word[0]){
                int k = 0;
                while (lines[i][j + k] == word[k] && word[k] != '\0'){
                    k++;
                }
                if (word[k] == '\0'){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e){
        case 1:{
            int mat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
            };        
            print_matrix(3, 3, mat);
            break;
        }
        case 2:{
            int mat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
            };
            print_reversed (3, 3, mat);
            break;
        }
        case 3:{
            int mat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
            };
            print_min_max(3, 3, mat);
            break;
        }
        case 4:{
            int mat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
            };
            printf("O valor da media e %.2f", average(3, 3, mat));
            break;
        }
        case 5:{
            int v[4][6];
            init_values(4, 6, v, 10, 2);
            break;
        }
        case 6:{
            int v[4][6];
            init_random(4, 6, v, 5, 50);
            break;
        }
        case 7:{
            int mat[5][5] = {
            { 1, 2, 3, 4, 5}, // soma: 15
            { 2, 4, 6, 8,10}, // soma: 30 ← esta linha possui a maior soma
            { 1, 2, 3, 4, 7}, // soma: 17
            { 2, 0, 6, 1,10}, // soma: 19
            { 7, 3, 4, 0, 0} // soma: 14
            };
            int res = max_line(5, 5, mat);
            printf("Maior soma: %d\n", res); 
            break;
        }
        case 8:{
            int mat[4][5] = {
            { 1, 2, 3, 4, 0},
            { 2, 4, 6, 8, 0},
            { 3, 6, 9, 12, 0},// O último elemento de cada linha receberá a soma
            { 4, 8, 12,16, 0} // da linha.
            };
            put_totals(4, 5, mat); 
            break;
        }
        case 9:{
            int mat1[4][4] = {
            { 1, 2, 3, 4},
            { 2, 4, 6, 8},
            { 3, 6, 9, 12},
            { 4, 8, 12,16}
            };
            int mat2[4][4] = {
            { 1, 2, 3, 4},
            { 2, 4, 6, 8},
            { 3, 6, 9, 12},
            { 4, 8, 12,16}
            };
            int  r = matrix_equals(4, 4, mat1, 4, 4, mat2); 
            printf("%d \n", r);
            break;
        }
        case 10:{
            int mat1[3][2] = {
            { 1, 3},
            { 1, 0},
            { 1, 2}
            };
            int mat2[3][2] = {
            { 0, 0},
            { 7, 5},
            { 2, 1}
            };

            int mat3[3][2];
            sum(3, 2, mat1, mat2, mat3); 
        }
        case 11:{
            int mat1[2][3] = {
            { 1, 2, 3},
            { 0, -6, 7}
            };

            int mat2[3][2];
            transpose(2, 3, mat1, 3, 2, mat2); 
        }
        case 12:{
            int mat[3][3] = {
            { 1, 2, 3},
            { 4, 5, 6},
            { 7, 8, 9}
            };
            switch_diagonals(3, mat);
        }
        case 13:{
            int n = 6;
            pascal_triangle(n);
        }
        case 14:{
            int m[3][3] = {
            { 1, 2, 3},
            { 0, 5, 6},
            { 0, 0, 9}
            };
            printf("%d\n", check_upper_triangle(3, m));
        }
        case 15:{
            int m[3][3] = {
            { 1, 0, 0},
            { 0, 1, 0},
            { 0, 0, 1}
            };
            printf("%d\n", check_identity(3,3, m));
        }
        case 16:{
            int m[3][3] = {
            { 0, 2, 3},
            { 2, 0, 5},
            { 3, 5, 0}
            };
            printf("%d\n", check_symmetric(3, m));
        }
        case 17:{
            char v[6][20] = {"John", "Mary", "Jake", "Finn", "Ada", "Michael"};
            print_strings(6, 20, v);
            break;
        }
        case 18:{
            char v[6][20] = {"Joh", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
            print_strings_minmax(6, 20, v);
            break;
        }
        case 19:{
            char v[2][200] = {
            " Computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
            " Programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language."
            };
            int count = count_words(2, 200, v);
            printf("Numero de palavras: %d\n", count);

            break;
        }
        case 20:{
            char v[5][200] = {
            "computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
            "programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language.",
            "the source code of a program is written in one or more programming languages.",
            "the purpose of programming is to find a sequence of instructions that will automate the performance of a task for solving a given problem.",
            "the process of programming thus often requires expertise in several different subjects, including knowledge of the application domain, specialized algorithms, and formal logic."
            };
            int count = count_occurrences(5, 200, v, "programming");
            printf("Numero de ocorrencias: %d\n", count);

            break;
        }
    default:
        break;
    }
    return 0;
}