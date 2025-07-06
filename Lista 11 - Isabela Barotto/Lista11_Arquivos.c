#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int file_exists(const char* filepath){
    FILE* file = fopen(filepath, "r");

    if(file == NULL){
        printf("ERRO, arquivo nao encontrado\n");
        fclose(file);
        return 0;
    }

    printf("O arquivo existe!\n");
    return 1;
}

int check_or_create(const char *filepath){
    FILE* file= fopen(filepath, "r");

    if(file != NULL){
        printf("Arquivo ja existe!\n");
        fclose(file);
        return 1;
    }

    file  = fopen(filepath, "w");
    if(file != NULL){
        printf("Arquivo nao existe, mas foi criado");
        fclose(file);
        return 1;
    }

    printf("O arquivo nao existe e nao foi possivel cria-lo");
    return 0;
}

int print_content(const char *filepath){
    FILE* file = fopen(filepath, "r");

    if(file == NULL){
        printf("O arquivo nao existe");
        return 0;
    }

    char c = fgetc(file);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(file);
    }
    printf("\n");
    fclose(file);
    return 1;
}

int save_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "w");

    if(file == NULL){
        printf("ERRO, nao foi possivel escrever no arquivo");
        return 0;
    }

    for(int i = 0; *(text + i) != 0; i++){
        fputc(*(text + i), file);
    }
    fclose(file);
    return 1;
}

int append_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "a");

    if(file == NULL){
        printf("ERRO, nao foi possivel abrir o arquivo");
        return 0;
    }

    for(int i = 0; *(text + i) != 0; i++){
        fputc(*(text + i), file);
    }
    fclose(file);
    return 1;
}

int save_lines(const char *filepath, int n, const char text_lines[n][51]){
    FILE* file = fopen(filepath, "w");

    if(file == NULL){
        printf("ERRO, nao foi possivel abrir o arquivo");
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        int j = 0;
        while(text_lines[i][j] != 0){
            fputc(text_lines[i][j], file);
            j++;
        }
        fputc('\n', file);
    }

    fclose(file);
    return 1;
}


char* get_content(const char *filepath){
    FILE* file = fopen(filepath, "r");
    
    if(file == NULL){
        printf("ERRO, nao foi possivel abrir o arquivo");
        return 0;
    }
    
    fseek(file, 0, SEEK_END); //Desloca o cursor para o final do arquivo
    
    int filesize = ftell(file); //obtem o deslocamento em bytes a partir do início do arquivo
    fseek(file, 0, SEEK_SET); //Coloca o cursor para o início do arquivo
    
    char *str = malloc((filesize + 1) * sizeof(char));
    
    if(str == NULL){
        fclose(file);
        return NULL;
    }
    
    int lido = fread(str, sizeof(char), filesize, file);
    str[lido] = '\0';
    
    fclose(file);
    return str;
}

int find(FILE* file, const char* ch, int whence){
    int posicao = whence;
    fseek(file, whence, SEEK_SET);
    
    char c = fgetc(file);
    while(c != EOF){
        for(int i = 0; *(ch + i) != 0; i++){
            if(*(ch + i) == c){
                return posicao;
            }
        }
        posicao++;
        c = fgetc(file);
    }
    return -1;
}

int count_lines(const char *filepath){
    int posi = -1;
    int linhas = 0;

    FILE* file = fopen(filepath, "r");

    if(file == NULL) return 0;

    posi = find(file, "\n", 0);

    while ((posi = find(file, "\n", posi + 1)) != -1){
        linhas++;
    }
    fclose(file);
    return linhas;
}

int count_words(const char *filepath){
    int palavras = 0;
    int posi = -1;
    FILE* file = fopen(filepath, "r");

    if(file == NULL) return 0;

    int posi2 = find(file, " ,\n", 0);

    while(posi2 != -1){
        if(posi2 > (posi + 1)){
            palavras++;
        }
        posi = posi2;
        posi2 = find(file, " ,\n", posi + 1);
    }

    fseek(file, 0, SEEK_END);
    int fim = ftell(file);
    if(fim > posi+1){
        palavras++;
    }

    fclose(file);
    return palavras;
}

void get_words(const char *filepath, int n, char words[n][51]){
    FILE* file = fopen(filepath, "r");
    int pos1 = -1;

    int pos2 = find(file, " ,\n", 0);
    int i = 0;

    while(pos2 != -1 && i < n){
        if(pos2 > pos1 + 1){
            int tam = pos2 - pos1 -1;
            if(tam > 50) tam = 50;

            fseek(file, pos1 + 1, SEEK_SET);
            fread(words[i], sizeof(char), tam, file);
            words[i][tam] = '\0';
            i++;
        }

        pos1 = pos2;
        pos2 = find(file, " ,\n", pos1 + 1);
    }

    fseek(file, 0, SEEK_END);
    int fim = ftell(file);
    if(fim > pos1 + 1 && i < n){
        int tam = fim - pos1 - 1;
        if (tam > 50) tam = 50;

        fseek(file, pos1 + 1, SEEK_SET);
        fread(words[i], sizeof(char), tam, file);
        words[i][tam] = '\0';
    }

    fclose(file);

    for(int i = 0; i < n; i++){
        printf("%s\n", words[i]);
    }
}

int split_lines(const char *filepath){
    char buffer[1024];
    int linhas = 1;
    char fileName[10];

    FILE* file = fopen(filepath, "r");

    if(file == NULL) return 0;

    while(fgets(buffer, sizeof(buffer), file)){
        sprintf(fileName, "line%d.txt", linhas);
        FILE* file1 = fopen(fileName, "w");

        if(file1 == NULL){
            fclose(file);
            return 0;
        }

        linhas++;
        fputs(buffer, file1);
        fclose(file1);
    }

    fclose(file);
    return 1;
}


void report_by_chars(const char* filepath){
    int n = count_words(filepath);
    char words[n][51];
    int count[51] = {0};

    get_words(filepath, n, words);

    for(int i = 0; i < n; i++){
        int letras = 0;
        for(int j = 0; words[i][j] != 0; j++){
            if(isalpha(words[i][j])){
                letras++;
            }
        }

        if(letras > 0 && letras < 51){
            count[letras]++;
        }
    }

    printf("Arquivo: %s\n", filepath);
    printf("Contagem de palavras por quantidade de letras: \n");

    for(int i = 0; i < 51; i++){
        if(count[i] > 0){
            printf("%d letras: %d\n", i, count[i]);
        }
    }
}

int word_frequency(const char* filepath, const char* word){
    FILE* file = fopen(filepath, "r");
    char words[50];
    int cont = 0;

    if(file == NULL) return 0;

    while(fscanf(file, "%50s", words) == 1){
        int len = strlen(words);

        if(len > 0 && (words[len-1]  == '.' || words[len - 1] == ',' || words[len - 1] == '\n'))
        words[len-1] = '\0';

        if(strcmp(words, word) == 0){
            cont++;
        }
    }

    fclose(file);
    return cont;
}

typedef struct{
    char palavra[100];
    int contagem;
} Palavra;

int words_report(const char* filepath, const char* word){
    FILE* file = fopen(filepath, "r");
    if(file == NULL) return 0;

    //vetor com structs palavras
    Palavra palavras[1000];
    int total = 0;
    char buffer[100];

    while(fscanf(file, "%99s", buffer) == 1){
        char limpa[100];
        int j = 0;
        for(int i = 0; buffer[i] != '\0'; i++){
            if(isalpha(buffer[i])){
                limpa[j++] = tolower(buffer[i]);
            }
        }
        limpa[j] = '\0';

        if(j == 0) continue;

        int encontrada = 0;
        for(int i = 0; i < total; i++){
            if(strcmp(palavras[i].palavra, limpa) == 0){
                palavras[i].contagem++;
                encontrada = 1;
                break;
            }
        }

        if(!encontrada){
            strcpy(palavras[total].palavra, limpa);
            palavras[total].contagem = 1;
            total++;
        }
    }

    fclose(file);

    for(int i = 0; i < total; i++){
        printf("%s: %d\n", palavras[i].palavra, palavras[i].contagem);
    }
    return 1;
}

int cont_letters(const char* word){
    int letras = 0;
    for(int i = 0; word[i] != 0; i++){
        if(isalpha(word[i])){
            letras++;
        }
    }
    return letras;
}

char* get_longest(const char *filepath){
    FILE* file = fopen(filepath, "r");

    if(file == NULL) return NULL;

    int max_tam = 0;
    char buffer[100];
    char limpa[100];
    char strMaior[100];

    while(fscanf(file, "%99s", buffer) == 1){
        int j = 0;
        for(int i = 0; buffer[i] != 0; i++){
            if(isalpha(buffer[i])){
                limpa[j++] = buffer[i];
            }
        }
        limpa[j]='\0';

        int tam = cont_letters(limpa);

        if(tam > max_tam){
            max_tam = tam;
            strcpy(strMaior, limpa);
        }
    }

    char* strMax = malloc((max_tam+1) * sizeof(char));
    strcpy(strMax, strMaior);
    return strMax;
}

int replace_word(const char* filepath, const char* old, const char* new){
    FILE* file = fopen(filepath, "r");

    if(file == NULL) return 0;
    int mudancas = 0;

    char* result = malloc(10000 * sizeof(char));

    result[0] = '\0';
    char buffer[100];

    while(fscanf(file, "%99s", buffer) == 1){
        if(strcmp(buffer, old) == 0){
            strcat(result, new);
            mudancas++;
        } else{
            strcat(result, buffer);
        }
        strcat(result, " ");
    }

    fclose(file);

    file  = fopen(filepath, "w");

    if(file == NULL){
        free(result);
        return -1;
    }

    fputs(result, file);
    fclose(file);
    free(result);
    return mudancas;
}


int main(){
    int e = 0;
    printf("Escolha o exercicio: \n>");
    scanf("%d", &e);
    switch (e)
    {
        case 1:{
            int res = file_exists("dados.txt");
            printf("%d\n", res);
            break;
        }
        case 2:{
            int res = check_or_create("dado.txt");
            printf("%d\n", res);
            break;
        }
        case 3:{
            int res = print_content("dados.txt");
            printf("%d\n", res);
            break;
        }
        case 4:{
            char *text = "Mudando o texto";
            int res = save_string("dados.txt", text);
            printf("%d\n", res);
            break;
        }
        case 5:{
            char *text = "Adicionando o texto";
            int res = append_string("dados.txt", text);
            printf("%d\n", res);
            break;
        }
        case 6:{
            int n = 3;
            char text[3][51] = {
                "1 linha",
                "Segunda linha",
                "Mais uma linha"
            };
            int res = save_lines("dados.txt", n, text);
            printf("%d\n", res);
            break;
        }
        case 7:{
            char* res = get_content("dados.txt");
            printf("%s\n", res);
            break;
        }
        case 8:{
            FILE* file = fopen("dados.txt", "r");
            if (!file) return 0;
            // procura por um dos caracteres em ".,;?!" no arquivo, a partir da posição pos
            int pos = 0;
            int count = 0;
            pos = find(file, ".,;?!", pos);
            while (pos != -1) {
            count++;
            pos = find(file, ".,:?!", pos+1);
            }
            printf("O arquivo possui %d pontuacoes.\n", count);
            fclose(file);
            break;
        }
        case 9:{
            int res = count_lines("dados.txt");
            printf("%d\n", res);
            break;
        }
        case 10:{
            int res = count_words("dados.txt");
            printf("%d\n", res);
            break;
        }
        case 11:{
            int n = count_words("dados.txt");
            char words[n][51];
            get_words("dados.txt", n, words);
            break;
        }
        case 12:{
            split_lines("dados.txt");
            break;
        }
        case 13:{
            report_by_chars("dados.txt");
            break;
        }
        case 14:{
            char word[51] = "papapa";
            int n = word_frequency("dados.txt", word);
            printf("A palavra se repete %d vezes", n);
            break;
        }
        case 15:{
            char word[51] = "papapa";
            words_report("dados.txt", word);
            break;
        }
        case 16:{
            char* str = get_longest("dados.txt");
            printf("%s", str);
            break;
        }
        case 17:{
            int mudancas = replace_word("dados.txt", "pipipi", "papapa");
            printf("%d", mudancas);
            break;
        }
        default:
            break;
    }
    return 0;
}