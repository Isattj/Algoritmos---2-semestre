#include <stdio.h>

typedef struct{
    int id;
    char nome[51];
} Pessoa;

int read_text(const char* filepath) {
    //ABERTURA DO ARQUIVO
    FILE* file = fopen(filepath, "r");

    if (file == NULL) {
        printf("ERRO: nao foi possivel abrir arquivo.\n");
        return 0; // false
    }
    printf("INFO: Arquivo aberto para leitura.\n");

    //FAZ ALGO
    char c = fgetc(file);
    while (c != EOF) {//EOF = final do arquivo
        printf("%c", c);
        c = fgetc(file);
    }
    printf("\n");

    fclose(file);
    return 1; // true
}

int write_text(const char* filepath, const char* text) {
    FILE* file = fopen(filepath, "w");

    if (file == NULL) {
        printf("ERRO: nao foi possivel acessar arquivo.");
        return 0;
    }
    
    printf("INFO: Arquivo aberto para escrita.\n");
    for (int i = 0; text[i] != 0; i++) {
        fputc(text[i], file);
    }

    fclose(file);
    return 1;
}

int readGetS(const char* filepath){
    FILE* file = fopen(filepath, "r");

    if (!file){
        printf("ERRO: nao foi possivel acessar arquivo.");
        return 1;
    }

    fseek(file, 0, SEEK_END); //Desloca o cursor para o final do arquivo

    int filesize = ftell(file); //obtem o deslocamento em bytes a partir do início do arquivo
    fseek(file, 0, SEEK_SET); //Coloca o cursor para o início do arquivo
    //rewind(file) faz a msm coisa

    char buff[] = "Outro texto de teste";
    //A função fget sempre retorna se é verdadeiro ou falso, então ele irá ficar no while enquanto o fgets não for nulo
    while(fputs(buff, file)){
        printf("[%s]", buff);
    }
    //Ele lê uma quantidade de caracteres de cada vez. Nesse caso por exemplo onde o buff é 10
    //ele lê até 9 caracteres, coloca o nulo \0 e vai para a próxima repetição do while
    //Porém ele para no \n
    fclose(file);
    return 0;
}

int readBin(const char* filepath){
    FILE* file = fopen(filepath, "r");

    if (!file){
        printf("ERRO: nao foi possivel acessar arquivo.");
        return 1;
    }

    //obtem o tamanho do arquivo e volta o cursor para o inicio
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    printf("file size: %d\n", filesize);
    fseek(file, 0, SEEK_SET);

    char buffer[filesize + 1];
    buffer[filesize] = 0;

    int read = fread(buffer, 1, filesize, file);
    printf("bytes lidos %d\n", read);
    printf("[%s]\n", buffer);
    fclose(file);
    printf("\n");
    return 0;
}

int writeNum(const char* filepath, const Pessoa* buffer, int n){
    FILE* file = fopen(filepath, "w");

    if (!file){
        printf("ERRO: nao foi possivel acessar arquivo.");
        return 1;
    }
    printf("\n write_file()\n");
    int read = fwrite(buffer, sizeof(Pessoa), n, file);
    printf("Elementos escritos: %d\n", read);
    fclose(file);
    printf("\n");
    return 0;
}

int ReadNum(const char* filepath){
    FILE* file = fopen(filepath, "r");

    if (!file){
        printf("ERRO: nao foi possivel acessar arquivo.");
        return 1;
    }
    printf("\n read_file()\n");
    //obtem o tamanho do arquivo e volta o cursor para o inicio
    fseek(file, 0, SEEK_END);
    int n = ftell(file)/sizeof(Pessoa);
    fseek(file, 0, SEEK_SET);

    char buffer[n];

    int read = fread(buffer, sizeof(Pessoa), n, file);
    printf("bytes lidos %d\n", read);
    for(int i = 0; i < n; i++){
        printf("[%d]\n", buffer[i]);
    }
    fclose(file);
    return 0;
}

int main() {
    //write_text("Dados.txt", "Um outro texto de teste!");
    //read_text("Dados.txt");
    //readGetS("Dados.txt");

    Pessoa v[] = {
        {1, "a"},
        {2, "a"},
        {3, "a"},
        {4, "a"},
        {5, "a"},
        {6, "a"},
        {7, "a"},
        {8, "a"},
        {9, "a"},
        {0, "a"},
    }
    //int v[] = {1,2,3,4,5,6,7,8,9,10};
    writeNum("Dados.txt", v, 10);
    ReadNum("Dados.txt");
    
    return 0;
}